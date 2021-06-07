#![allow(dead_code)]

use crate::positions::{LineSpan, Span};
use crate::tree_diff::{MatchKind, MatchedPos};
use regex::Regex;
use std::fmt;

#[cfg(test)]
use pretty_assertions::assert_eq;

#[derive(Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct LineNumber {
    pub number: usize,
}

impl fmt::Debug for LineNumber {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        f.write_fmt(format_args!("LineNumber: {}", self.number))
    }
}

impl From<usize> for LineNumber {
    fn from(number: usize) -> Self {
        LineNumber { number }
    }
}

#[derive(Debug, PartialEq, Eq)]
pub struct LineGroup {
    lhs_lines: Vec<LineNumber>,
    rhs_lines: Vec<LineNumber>,
}

impl LineGroup {
    fn new() -> Self {
        Self {
            lhs_lines: vec![],
            rhs_lines: vec![],
        }
    }

    fn overlaps_lhs(&self, nl_pos: &NewlinePositions, mp: &MatchedPos) -> bool {
        if self.lhs_lines.is_empty() {
            return false;
        }

        let lines = nl_pos.lines(&mp.pos);
        assert!(!lines.is_empty());
        let first_match_line = lines[0].number;
        let last_match_line = lines.last().unwrap().number;

        let first_group_line = self.lhs_lines[0].number;
        let last_group_line = self.lhs_lines.last().unwrap().number;

        // [  ] match region
        //  []  group region
        if first_match_line <= first_group_line && last_match_line >= last_group_line {
            return true;
        }

        // [ ]  match region
        //  [ ] group region
        if first_match_line <= first_group_line && last_match_line >= first_group_line {
            return true;
        }

        //  [ ] match region
        // [ ]  group region
        if first_match_line >= first_group_line && first_match_line >= last_group_line {
            return true;
        }

        false
    }

    fn overlaps_rhs(&self, nl_pos: &NewlinePositions, mp: &MatchedPos) -> bool {
        if self.rhs_lines.is_empty() {
            return false;
        }

        let lines = nl_pos.lines(&mp.pos);
        assert!(!lines.is_empty());
        let first_match_line = lines[0].number;
        let last_match_line = lines.last().unwrap().number;

        let first_group_line = self.rhs_lines[0].number;
        let last_group_line = self.rhs_lines.last().unwrap().number;

        // [    ] match region
        //   []   group region
        if first_match_line <= first_group_line && last_match_line >= last_group_line {
            return true;
        }

        // [  ]   match region
        //   [  ] group region
        if first_match_line <= first_group_line && last_match_line >= first_group_line {
            return true;
        }

        //   [  ] match region
        // [  ]   group region
        if first_match_line >= first_group_line && first_match_line >= last_group_line {
            return true;
        }

        false
    }

    fn add_lhs_pos(&mut self, nl_pos: &NewlinePositions, span: &Span) {
        let current_highest = self
            .lhs_lines
            .last()
            .map(|ln| ln.number as isize)
            .unwrap_or(-1);
        for line in nl_pos.lines(span) {
            if (line.number as isize) > current_highest {
                self.lhs_lines.push(line);
            }
        }
    }
    fn add_rhs_pos(&mut self, nl_pos: &NewlinePositions, span: &Span) {
        let current_highest = self
            .rhs_lines
            .last()
            .map(|ln| ln.number as isize)
            .unwrap_or(-1);
        for line in nl_pos.lines(span) {
            if (line.number as isize) > current_highest {
                self.rhs_lines.push(line);
            }
        }
    }

    fn add_lhs(&mut self, nl_pos: &NewlinePositions, mp: &MatchedPos) {
        self.add_lhs_pos(nl_pos, &mp.pos);
        if let Some(opposite_pos) = mp.prev_opposite_pos {
            self.add_rhs_pos(nl_pos, &opposite_pos);
        }
    }
    fn add_rhs(&mut self, nl_pos: &NewlinePositions, mp: &MatchedPos) {
        self.add_rhs_pos(nl_pos, &mp.pos);
        if let Some(opposite_pos) = mp.prev_opposite_pos {
            self.add_lhs_pos(nl_pos, &opposite_pos);
        }
    }

    fn is_empty(&self) -> bool {
        self.lhs_lines.is_empty() && self.rhs_lines.is_empty()
    }
}

/// The exact lines that have changes, grouped into contiguous
/// sections with the corresponding line numbers of the other side.
pub fn visible_groups(
    lhs_src: &str,
    rhs_src: &str,
    lhs_positions: &[MatchedPos],
    rhs_positions: &[MatchedPos],
) -> Vec<LineGroup> {
    let lhs_positions: Vec<_> = lhs_positions
        .iter()
        .filter(|mp| mp.kind != MatchKind::Unchanged)
        .collect();
    let rhs_positions: Vec<_> = rhs_positions
        .iter()
        .filter(|mp| mp.kind != MatchKind::Unchanged)
        .collect();

    let lhs_nl_pos = NewlinePositions::from(lhs_src);
    let rhs_nl_pos = NewlinePositions::from(rhs_src);

    let mut groups = vec![];
    let mut group = LineGroup::new();

    let mut lhs_i = 0;
    let mut rhs_i = 0;
    loop {
        // If the LHS overlaps, add to the current group.
        if let Some(lhs_pos) = lhs_positions.get(lhs_i) {
            if group.is_empty() || group.overlaps_lhs(&lhs_nl_pos, lhs_pos) {
                group.add_lhs(&lhs_nl_pos, lhs_pos);
                lhs_i += 1;
                continue;
            }
        }

        // If the RHS overlaps, add to the current group.
        if let Some(rhs_pos) = rhs_positions.get(rhs_i) {
            if group.is_empty() || group.overlaps_rhs(&rhs_nl_pos, rhs_pos) {
                group.add_rhs(&rhs_nl_pos, rhs_pos);
                rhs_i += 1;
                continue;
            }
        }

        // Otherwise, start a new group.
        if let Some(lhs_pos) = lhs_positions.get(lhs_i) {
            groups.push(group);

            group = LineGroup::new();
            group.add_lhs(&lhs_nl_pos, lhs_pos);
            lhs_i += 1;
            continue;
        }
        // Likewise on RHS.
        if let Some(rhs_pos) = rhs_positions.get(rhs_i) {
            groups.push(group);

            group = LineGroup::new();
            group.add_rhs(&rhs_nl_pos, rhs_pos);
            rhs_i += 1;
            continue;
        }

        // Otherwise, no positions left.
        break;
    }

    if !group.is_empty() {
        groups.push(group);
    }

    groups
}

#[test]
fn test_visible_groups_ignores_unchanged() {
    let lhs_src = "foo\nbar";
    let rhs_src = "bar\nbar";

    let lhs_positions = vec![MatchedPos {
        kind: MatchKind::Unchanged,
        pos: Span { start: 0, end: 1 },
        prev_pos: None,
        prev_opposite_pos: None,
    }];
    let rhs_positions = vec![MatchedPos {
        kind: MatchKind::Unchanged,
        pos: Span { start: 0, end: 1 },
        prev_pos: None,
        prev_opposite_pos: None,
    }];

    let res = visible_groups(&lhs_src, &rhs_src, &lhs_positions, &rhs_positions);
    assert_eq!(res, vec![]);
}

pub fn apply_groups(lhs: &str, rhs: &str, groups: &[LineGroup]) -> String {
    let spacer = "--------------------------\n";
    dbg!(groups);

    let mut result = String::new();
    result.push_str(spacer);
    result.push_str(spacer);

    result
}

/// A position in a single line of a string.
#[derive(Debug, PartialEq, Clone, Copy)]
pub struct LinePosition {
    /// Both zero-indexed.
    pub line: LineNumber,
    column: usize,
}

/// A struct for efficiently converting absolute string positions to
/// line-relative positions.
#[derive(Debug)]
pub struct NewlinePositions {
    /// A vector of the start positions of all the lines in `s`.
    positions: Vec<usize>,
}

impl From<&str> for NewlinePositions {
    fn from(s: &str) -> Self {
        let newline_re = Regex::new("\n").unwrap();
        let mut positions: Vec<_> = newline_re.find_iter(s).map(|mat| mat.end()).collect();
        positions.insert(0, 0);

        NewlinePositions { positions }
    }
}

impl NewlinePositions {
    pub fn from_offset(self: &NewlinePositions, offset: usize) -> LinePosition {
        for line_num in (0..self.positions.len()).rev() {
            if offset >= self.positions[line_num] {
                return LinePosition {
                    line: line_num.into(),
                    column: offset - self.positions[line_num],
                };
            }
        }

        LinePosition {
            line: 0.into(),
            column: offset,
        }
    }

    // Given a range within a string, split it into ranges where each
    // range is on a single line.
    fn split_line_boundaries(
        self: &NewlinePositions,
        start: LinePosition,
        end: LinePosition,
    ) -> Vec<LineSpan> {
        let mut ranges = vec![];

        if start.line == end.line {
            ranges.push(LineSpan {
                line: start.line,
                start_col: start.column,
                end_col: end.column,
            });
            return ranges;
        } else {
            let first_line_end_pos = self.positions[start.line.number + 1] - 1;
            let first_line_length = first_line_end_pos - self.positions[start.line.number];
            ranges.push(LineSpan {
                line: start.line,
                start_col: start.column,
                end_col: first_line_length,
            });
        }

        for line_num in (start.line.number + 1)..end.line.number {
            let line_end_pos = self.positions[line_num + 1] - 1;
            let line_length = line_end_pos - self.positions[line_num];
            ranges.push(LineSpan {
                line: line_num.into(),
                start_col: 0,
                end_col: line_length,
            });
        }

        // Last line, up to end.
        ranges.push(LineSpan {
            line: end.line,
            start_col: 0,
            end_col: end.column,
        });

        ranges
    }

    pub fn lines(&self, span: &Span) -> Vec<LineNumber> {
        let start_pos = self.from_offset(span.start);
        let end_pos = self.from_offset(span.end);

        (start_pos.line.number..=end_pos.line.number)
            .map(|n| LineNumber::from(n))
            .collect()
    }

    /// Convert absolute string ranges to line-relative ranges. If the
    /// absolute range crosses a newline, split it into multiple
    /// line-relative ranges.
    pub fn from_ranges(&self, ranges: &[Span]) -> Vec<LineSpan> {
        let mut rel_positions = vec![];
        for range in ranges {
            let start_pos = self.from_offset(range.start);
            let end_pos = self.from_offset(range.end);

            rel_positions.extend(self.split_line_boundaries(start_pos, end_pos));
        }

        rel_positions
    }
}

#[test]
fn from_offset_newline_boundary() {
    let newline_positions = NewlinePositions::from("abc\nbar");
    let position = newline_positions.from_offset(4);
    assert_eq!(
        position,
        LinePosition {
            line: 1.into(),
            column: 0
        }
    );
}

#[test]
fn from_ranges_first_line() {
    let newline_positions: NewlinePositions = "foo".into();
    let relative_ranges = newline_positions.from_ranges(&vec![Span { start: 1, end: 3 }]);
    assert_eq!(
        relative_ranges,
        vec![LineSpan {
            line: 0.into(),
            start_col: 1,
            end_col: 3
        }]
    );
}

#[test]
fn from_ranges_split_over_multiple_lines() {
    let newline_positions: NewlinePositions = "foo\nbar\nbaz\naaaaaaaaaaa".into();
    let relative_ranges = newline_positions.from_ranges(&vec![Span { start: 5, end: 10 }]);

    assert_eq!(
        relative_ranges,
        vec![
            (LineSpan {
                line: 1.into(),
                start_col: 1,
                end_col: 3
            }),
            (LineSpan {
                line: 2.into(),
                start_col: 0,
                end_col: 2
            })
        ]
    );
}

pub fn max_line(s: &str) -> LineNumber {
    LineNumber::from(s.lines().count() - 1)
}

/// Ensure that every line in `s` has this length. Pad short lines and
/// truncate long lines.
pub fn enforce_length(s: &str, line_length: usize) -> String {
    let mut result = String::with_capacity(s.len());
    for line in s.lines() {
        // TODO: use length in chars not bytes.
        if line.len() > line_length {
            // Truncate.
            result.push_str(&line[0..line_length]);
            result.push('\n');
        } else {
            // Pad with spaces.
            result.push_str(&format!("{:width$}\n", line, width = line_length));
        }
    }

    result
}

#[test]
fn enforce_length_short() {
    let result = enforce_length("foo\nbar\n", 5);
    assert_eq!(result, "foo  \nbar  \n");
}

#[test]
fn enforce_length_long() {
    let result = enforce_length("foobar\nbarbaz\n", 3);
    assert_eq!(result, "foo\nbar\n");
}
