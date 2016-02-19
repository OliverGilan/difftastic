#include "tree_sitter/parser.h"

#define STATE_COUNT 338
#define SYMBOL_COUNT 74

enum {
    sym_program = ts_builtin_sym_start,
    sym__statement,
    sym__declaration,
    sym_method_declaration,
    sym_argument_list,
    sym_class_declaration,
    sym_module_declaration,
    sym__call,
    sym__call_arguments,
    sym__command,
    sym__function_call,
    sym__expression,
    sym__argument,
    sym__primary,
    sym_scope_resolution_expression,
    sym__variable,
    sym__function_name,
    sym__terminator,
    aux_sym_program_repeat1,
    aux_sym_argument_list_repeat1,
    aux_sym_class_declaration_repeat1,
    aux_sym__call_arguments_repeat1,
    anon_sym_do,
    anon_sym_PIPE,
    anon_sym_end,
    anon_sym_undef,
    anon_sym_alias,
    anon_sym_if,
    anon_sym_while,
    anon_sym_unless,
    anon_sym_until,
    anon_sym_def,
    anon_sym_LPAREN,
    anon_sym_RPAREN,
    anon_sym_STAR,
    anon_sym_AMP,
    anon_sym_COMMA,
    anon_sym_class,
    anon_sym_LT,
    anon_sym_COLON_COLON,
    anon_sym_module,
    anon_sym_super,
    anon_sym_LBRACK,
    anon_sym_RBRACK,
    anon_sym_nil,
    anon_sym_self,
    sym_identifier,
    sym_comment,
    sym_symbol,
    anon_sym_DOT_DOT,
    anon_sym_CARET,
    anon_sym_LT_EQ_GT,
    anon_sym_EQ_EQ,
    anon_sym_EQ_EQ_EQ,
    anon_sym_EQ_TILDE,
    anon_sym_GT,
    anon_sym_GT_EQ,
    anon_sym_LT_EQ,
    anon_sym_PLUS,
    anon_sym_DASH,
    anon_sym_SLASH,
    anon_sym_PERCENT,
    anon_sym_STAR_STAR,
    anon_sym_LT_LT,
    anon_sym_GT_GT,
    anon_sym_TILDE,
    anon_sym_PLUS_AT,
    anon_sym_DASH_AT,
    anon_sym_LBRACK_RBRACK,
    anon_sym_LBRACK_RBRACK_EQ,
    sym__line_break,
    anon_sym_SEMI,
};

static const char *ts_symbol_names[] = {
    [sym_program] = "program",
    [sym__statement] = "_statement",
    [sym__declaration] = "_declaration",
    [sym_method_declaration] = "method_declaration",
    [sym_argument_list] = "argument_list",
    [sym_class_declaration] = "class_declaration",
    [sym_module_declaration] = "module_declaration",
    [sym__call] = "_call",
    [sym__call_arguments] = "_call_arguments",
    [sym__command] = "_command",
    [sym__function_call] = "_function_call",
    [sym__expression] = "_expression",
    [sym__argument] = "_argument",
    [sym__primary] = "_primary",
    [sym_scope_resolution_expression] = "scope_resolution_expression",
    [sym__variable] = "_variable",
    [sym__function_name] = "_function_name",
    [sym__terminator] = "_terminator",
    [aux_sym_program_repeat1] = "program_repeat1",
    [aux_sym_argument_list_repeat1] = "argument_list_repeat1",
    [aux_sym_class_declaration_repeat1] = "class_declaration_repeat1",
    [aux_sym__call_arguments_repeat1] = "_call_arguments_repeat1",
    [ts_builtin_sym_error] = "ERROR",
    [ts_builtin_sym_end] = "END",
    [anon_sym_do] = "do",
    [anon_sym_PIPE] = "|",
    [anon_sym_end] = "end",
    [anon_sym_undef] = "undef",
    [anon_sym_alias] = "alias",
    [anon_sym_if] = "if",
    [anon_sym_while] = "while",
    [anon_sym_unless] = "unless",
    [anon_sym_until] = "until",
    [anon_sym_def] = "def",
    [anon_sym_LPAREN] = "(",
    [anon_sym_RPAREN] = ")",
    [anon_sym_STAR] = "*",
    [anon_sym_AMP] = "&",
    [anon_sym_COMMA] = ",",
    [anon_sym_class] = "class",
    [anon_sym_LT] = "<",
    [anon_sym_COLON_COLON] = "::",
    [anon_sym_module] = "module",
    [anon_sym_super] = "super",
    [anon_sym_LBRACK] = "[",
    [anon_sym_RBRACK] = "]",
    [anon_sym_nil] = "nil",
    [anon_sym_self] = "self",
    [sym_identifier] = "identifier",
    [sym_comment] = "comment",
    [sym_symbol] = "symbol",
    [anon_sym_DOT_DOT] = "..",
    [anon_sym_CARET] = "^",
    [anon_sym_LT_EQ_GT] = "<=>",
    [anon_sym_EQ_EQ] = "==",
    [anon_sym_EQ_EQ_EQ] = "===",
    [anon_sym_EQ_TILDE] = "=~",
    [anon_sym_GT] = ">",
    [anon_sym_GT_EQ] = ">=",
    [anon_sym_LT_EQ] = "<=",
    [anon_sym_PLUS] = "+",
    [anon_sym_DASH] = "-",
    [anon_sym_SLASH] = "/",
    [anon_sym_PERCENT] = "%",
    [anon_sym_STAR_STAR] = "**",
    [anon_sym_LT_LT] = "<<",
    [anon_sym_GT_GT] = ">>",
    [anon_sym_TILDE] = "~",
    [anon_sym_PLUS_AT] = "+@",
    [anon_sym_DASH_AT] = "-@",
    [anon_sym_LBRACK_RBRACK] = "[]",
    [anon_sym_LBRACK_RBRACK_EQ] = "[]=",
    [sym__line_break] = "_line_break",
    [anon_sym_SEMI] = ";",
};

static const TSSymbolMetadata ts_symbol_metadata[SYMBOL_COUNT] = {
    [sym_program] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym__statement] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym__declaration] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym_method_declaration] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_argument_list] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_class_declaration] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_module_declaration] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym__call] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym__call_arguments] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym__command] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym__function_call] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym__expression] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym__argument] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym__primary] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym_scope_resolution_expression] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym__variable] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym__function_name] = {.visible = false, .named = false, .structural = true, .extra = false},
    [sym__terminator] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_program_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_argument_list_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym_class_declaration_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [aux_sym__call_arguments_repeat1] = {.visible = false, .named = false, .structural = true, .extra = false},
    [ts_builtin_sym_error] = {.visible = true, .named = true, .structural = false, .extra = false},
    [ts_builtin_sym_end] = {.visible = false, .named = false, .structural = true, .extra = false},
    [anon_sym_do] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_PIPE] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_end] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_undef] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_alias] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_if] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_while] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_unless] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_until] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_def] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LPAREN] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_RPAREN] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_STAR] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_AMP] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_COMMA] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_class] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_COLON_COLON] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_module] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_super] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LBRACK] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_RBRACK] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_nil] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_self] = {.visible = true, .named = false, .structural = true, .extra = false},
    [sym_identifier] = {.visible = true, .named = true, .structural = true, .extra = false},
    [sym_comment] = {.visible = true, .named = true, .structural = false, .extra = true},
    [sym_symbol] = {.visible = true, .named = true, .structural = true, .extra = false},
    [anon_sym_DOT_DOT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_CARET] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LT_EQ_GT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_EQ_EQ] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_EQ_EQ_EQ] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_EQ_TILDE] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_GT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_GT_EQ] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LT_EQ] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_PLUS] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_DASH] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_SLASH] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_PERCENT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_STAR_STAR] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LT_LT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_GT_GT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_TILDE] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_PLUS_AT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_DASH_AT] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LBRACK_RBRACK] = {.visible = true, .named = false, .structural = true, .extra = false},
    [anon_sym_LBRACK_RBRACK_EQ] = {.visible = true, .named = false, .structural = true, .extra = false},
    [sym__line_break] = {.visible = false, .named = false, .structural = true, .extra = true},
    [anon_sym_SEMI] = {.visible = true, .named = false, .structural = true, .extra = false},
};

static TSTree *ts_lex(TSLexer *lexer, TSStateId state, bool error_mode) {
    START_LEXER();
    switch (state) {
        case 0:
            START_TOKEN();
            if (lookahead == 0)
                ADVANCE(1);
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(0);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '%')
                ADVANCE(6);
            if (lookahead == '&')
                ADVANCE(7);
            if (lookahead == '(')
                ADVANCE(8);
            if (lookahead == ')')
                ADVANCE(9);
            if (lookahead == '*')
                ADVANCE(10);
            if (lookahead == '+')
                ADVANCE(12);
            if (lookahead == ',')
                ADVANCE(14);
            if (lookahead == '-')
                ADVANCE(15);
            if (lookahead == '.')
                ADVANCE(17);
            if (lookahead == '/')
                ADVANCE(19);
            if (lookahead == ':')
                ADVANCE(20);
            if (lookahead == ';')
                ADVANCE(33);
            if (lookahead == '<')
                ADVANCE(34);
            if (lookahead == '=')
                ADVANCE(38);
            if (lookahead == '>')
                ADVANCE(54);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                (lookahead == 'b') ||
                ('f' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('o' <= lookahead && lookahead <= 'r') ||
                (lookahead == 't') ||
                (lookahead == 'v') ||
                ('x' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == '[')
                ADVANCE(57);
            if (lookahead == ']')
                ADVANCE(60);
            if (lookahead == '^')
                ADVANCE(61);
            if (lookahead == 'a')
                ADVANCE(62);
            if (lookahead == 'c')
                ADVANCE(67);
            if (lookahead == 'd')
                ADVANCE(72);
            if (lookahead == 'e')
                ADVANCE(76);
            if (lookahead == 'i')
                ADVANCE(79);
            if (lookahead == 'm')
                ADVANCE(81);
            if (lookahead == 'n')
                ADVANCE(87);
            if (lookahead == 's')
                ADVANCE(90);
            if (lookahead == 'u')
                ADVANCE(98);
            if (lookahead == 'w')
                ADVANCE(110);
            if (lookahead == '|')
                ADVANCE(115);
            if (lookahead == '~')
                ADVANCE(116);
            LEX_ERROR();
        case 1:
            ACCEPT_TOKEN(ts_builtin_sym_end);
        case 2:
            ACCEPT_TOKEN(sym__line_break);
        case 3:
            if (!((lookahead == 0) ||
                (lookahead == '\n')))
                ADVANCE(3);
            ACCEPT_TOKEN(sym_comment);
        case 4:
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 5:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 6:
            ACCEPT_TOKEN(anon_sym_PERCENT);
        case 7:
            ACCEPT_TOKEN(anon_sym_AMP);
        case 8:
            ACCEPT_TOKEN(anon_sym_LPAREN);
        case 9:
            ACCEPT_TOKEN(anon_sym_RPAREN);
        case 10:
            if (lookahead == '*')
                ADVANCE(11);
            ACCEPT_TOKEN(anon_sym_STAR);
        case 11:
            ACCEPT_TOKEN(anon_sym_STAR_STAR);
        case 12:
            if (lookahead == '@')
                ADVANCE(13);
            ACCEPT_TOKEN(anon_sym_PLUS);
        case 13:
            ACCEPT_TOKEN(anon_sym_PLUS_AT);
        case 14:
            ACCEPT_TOKEN(anon_sym_COMMA);
        case 15:
            if (lookahead == '@')
                ADVANCE(16);
            ACCEPT_TOKEN(anon_sym_DASH);
        case 16:
            ACCEPT_TOKEN(anon_sym_DASH_AT);
        case 17:
            if (lookahead == '.')
                ADVANCE(18);
            LEX_ERROR();
        case 18:
            ACCEPT_TOKEN(anon_sym_DOT_DOT);
        case 19:
            ACCEPT_TOKEN(anon_sym_SLASH);
        case 20:
            if (lookahead == '%')
                ADVANCE(21);
            if (lookahead == '&')
                ADVANCE(21);
            if (lookahead == '*')
                ADVANCE(22);
            if (lookahead == '+')
                ADVANCE(23);
            if (lookahead == '-')
                ADVANCE(23);
            if (lookahead == '.')
                ADVANCE(24);
            if (lookahead == '/')
                ADVANCE(21);
            if (lookahead == ':')
                ADVANCE(25);
            if (lookahead == '<')
                ADVANCE(26);
            if (lookahead == '=')
                ADVANCE(28);
            if (lookahead == '>')
                ADVANCE(30);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(31);
            if (lookahead == '[')
                ADVANCE(32);
            if (lookahead == '^')
                ADVANCE(21);
            if (lookahead == '|')
                ADVANCE(21);
            if (lookahead == '~')
                ADVANCE(21);
            LEX_ERROR();
        case 21:
            ACCEPT_TOKEN(sym_symbol);
        case 22:
            if (lookahead == '*')
                ADVANCE(21);
            ACCEPT_TOKEN(sym_symbol);
        case 23:
            if (lookahead == '@')
                ADVANCE(21);
            ACCEPT_TOKEN(sym_symbol);
        case 24:
            if (lookahead == '.')
                ADVANCE(21);
            LEX_ERROR();
        case 25:
            ACCEPT_TOKEN(anon_sym_COLON_COLON);
        case 26:
            if (lookahead == '<')
                ADVANCE(21);
            if (lookahead == '=')
                ADVANCE(27);
            ACCEPT_TOKEN(sym_symbol);
        case 27:
            if (lookahead == '>')
                ADVANCE(21);
            ACCEPT_TOKEN(sym_symbol);
        case 28:
            if (lookahead == '=')
                ADVANCE(29);
            if (lookahead == '~')
                ADVANCE(21);
            LEX_ERROR();
        case 29:
            if (lookahead == '=')
                ADVANCE(21);
            ACCEPT_TOKEN(sym_symbol);
        case 30:
            if (lookahead == '=')
                ADVANCE(21);
            if (lookahead == '>')
                ADVANCE(21);
            ACCEPT_TOKEN(sym_symbol);
        case 31:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(31);
            ACCEPT_TOKEN(sym_symbol);
        case 32:
            if (lookahead == ']')
                ADVANCE(29);
            LEX_ERROR();
        case 33:
            ACCEPT_TOKEN(anon_sym_SEMI);
        case 34:
            if (lookahead == '<')
                ADVANCE(35);
            if (lookahead == '=')
                ADVANCE(36);
            ACCEPT_TOKEN(anon_sym_LT);
        case 35:
            ACCEPT_TOKEN(anon_sym_LT_LT);
        case 36:
            if (lookahead == '>')
                ADVANCE(37);
            ACCEPT_TOKEN(anon_sym_LT_EQ);
        case 37:
            ACCEPT_TOKEN(anon_sym_LT_EQ_GT);
        case 38:
            if (lookahead == '=')
                ADVANCE(39);
            if (lookahead == 'b')
                ADVANCE(41);
            if (lookahead == '~')
                ADVANCE(53);
            LEX_ERROR();
        case 39:
            if (lookahead == '=')
                ADVANCE(40);
            ACCEPT_TOKEN(anon_sym_EQ_EQ);
        case 40:
            ACCEPT_TOKEN(anon_sym_EQ_EQ_EQ);
        case 41:
            if (lookahead == 'e')
                ADVANCE(42);
            LEX_ERROR();
        case 42:
            if (lookahead == 'g')
                ADVANCE(43);
            LEX_ERROR();
        case 43:
            if (lookahead == 'i')
                ADVANCE(44);
            LEX_ERROR();
        case 44:
            if (lookahead == 'n')
                ADVANCE(45);
            LEX_ERROR();
        case 45:
            if (lookahead == '\n')
                ADVANCE(46);
            LEX_ERROR();
        case 46:
            if (lookahead == '\n')
                ADVANCE(46);
            if (lookahead == '=')
                ADVANCE(47);
            if (!((lookahead == 0) ||
                (lookahead == '\n') ||
                (lookahead == '=')))
                ADVANCE(52);
            LEX_ERROR();
        case 47:
            if (lookahead == '\n')
                ADVANCE(46);
            if (lookahead == 'e')
                ADVANCE(48);
            if (!((lookahead == 0) ||
                (lookahead == '\n') ||
                (lookahead == 'e')))
                ADVANCE(52);
            LEX_ERROR();
        case 48:
            if (lookahead == '\n')
                ADVANCE(46);
            if (lookahead == 'n')
                ADVANCE(49);
            if (!((lookahead == 0) ||
                (lookahead == '\n') ||
                (lookahead == 'n')))
                ADVANCE(52);
            LEX_ERROR();
        case 49:
            if (lookahead == '\n')
                ADVANCE(46);
            if (lookahead == 'd')
                ADVANCE(50);
            if (!((lookahead == 0) ||
                (lookahead == '\n') ||
                (lookahead == 'd')))
                ADVANCE(52);
            LEX_ERROR();
        case 50:
            if (lookahead == '\n')
                ADVANCE(51);
            if (!((lookahead == 0) ||
                (lookahead == '\n')))
                ADVANCE(52);
            LEX_ERROR();
        case 51:
            if (lookahead == '\n')
                ADVANCE(46);
            if (lookahead == '=')
                ADVANCE(47);
            if (!((lookahead == 0) ||
                (lookahead == '\n') ||
                (lookahead == '=')))
                ADVANCE(52);
            ACCEPT_TOKEN(sym_comment);
        case 52:
            if (lookahead == '\n')
                ADVANCE(46);
            if (!((lookahead == 0) ||
                (lookahead == '\n')))
                ADVANCE(52);
            LEX_ERROR();
        case 53:
            ACCEPT_TOKEN(anon_sym_EQ_TILDE);
        case 54:
            if (lookahead == '=')
                ADVANCE(55);
            if (lookahead == '>')
                ADVANCE(56);
            ACCEPT_TOKEN(anon_sym_GT);
        case 55:
            ACCEPT_TOKEN(anon_sym_GT_EQ);
        case 56:
            ACCEPT_TOKEN(anon_sym_GT_GT);
        case 57:
            if (lookahead == ']')
                ADVANCE(58);
            ACCEPT_TOKEN(anon_sym_LBRACK);
        case 58:
            if (lookahead == '=')
                ADVANCE(59);
            ACCEPT_TOKEN(anon_sym_LBRACK_RBRACK);
        case 59:
            ACCEPT_TOKEN(anon_sym_LBRACK_RBRACK_EQ);
        case 60:
            ACCEPT_TOKEN(anon_sym_RBRACK);
        case 61:
            ACCEPT_TOKEN(anon_sym_CARET);
        case 62:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(63);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 63:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(64);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 64:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(65);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 65:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 's')
                ADVANCE(66);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 66:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_alias);
        case 67:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(68);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 68:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('b' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(69);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 69:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 's')
                ADVANCE(70);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 70:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 's')
                ADVANCE(71);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 71:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_class);
        case 72:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'n') ||
                ('p' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(73);
            if (lookahead == 'o')
                ADVANCE(75);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 73:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'e') ||
                ('g' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'f')
                ADVANCE(74);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 74:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_def);
        case 75:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_do);
        case 76:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'n')
                ADVANCE(77);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 77:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'c') ||
                ('e' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'd')
                ADVANCE(78);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 78:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_end);
        case 79:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'e') ||
                ('g' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'f')
                ADVANCE(80);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 80:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_if);
        case 81:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'n') ||
                ('p' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'o')
                ADVANCE(82);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 82:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'c') ||
                ('e' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'd')
                ADVANCE(83);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 83:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 't') ||
                ('v' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'u')
                ADVANCE(84);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 84:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(85);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 85:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(86);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 86:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_module);
        case 87:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(88);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 88:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(89);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 89:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_nil);
        case 90:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 't') ||
                ('v' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(91);
            if (lookahead == 'u')
                ADVANCE(94);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 91:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(92);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 92:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'e') ||
                ('g' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'f')
                ADVANCE(93);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 93:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_self);
        case 94:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'o') ||
                ('q' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'p')
                ADVANCE(95);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 95:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(96);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 96:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'q') ||
                ('s' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'r')
                ADVANCE(97);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 97:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_super);
        case 98:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'n')
                ADVANCE(99);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 99:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'c') ||
                ('e' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 's') ||
                ('u' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'd')
                ADVANCE(100);
            if (lookahead == 'l')
                ADVANCE(103);
            if (lookahead == 't')
                ADVANCE(107);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 100:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(101);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 101:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'e') ||
                ('g' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'f')
                ADVANCE(102);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 102:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_undef);
        case 103:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(104);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 104:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 's')
                ADVANCE(105);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 105:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 's')
                ADVANCE(106);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 106:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_unless);
        case 107:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(108);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 108:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(109);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 109:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_until);
        case 110:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'g') ||
                ('i' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'h')
                ADVANCE(111);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 111:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'i')
                ADVANCE(112);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 112:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'k') ||
                ('m' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'l')
                ADVANCE(113);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 113:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(114);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 114:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            ACCEPT_TOKEN(anon_sym_while);
        case 115:
            ACCEPT_TOKEN(anon_sym_PIPE);
        case 116:
            ACCEPT_TOKEN(anon_sym_TILDE);
        case 117:
            START_TOKEN();
            if (lookahead == 0)
                ADVANCE(1);
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(117);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '(')
                ADVANCE(8);
            if (lookahead == ':')
                ADVANCE(20);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                (lookahead == 'b') ||
                ('e' <= lookahead && lookahead <= 'l') ||
                ('o' <= lookahead && lookahead <= 'r') ||
                (lookahead == 't') ||
                ('v' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(62);
            if (lookahead == 'c')
                ADVANCE(67);
            if (lookahead == 'd')
                ADVANCE(119);
            if (lookahead == 'm')
                ADVANCE(81);
            if (lookahead == 'n')
                ADVANCE(87);
            if (lookahead == 's')
                ADVANCE(90);
            if (lookahead == 'u')
                ADVANCE(120);
            LEX_ERROR();
        case 118:
            if (lookahead == 'b')
                ADVANCE(41);
            LEX_ERROR();
        case 119:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(73);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 120:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'n')
                ADVANCE(121);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 121:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'c') ||
                ('e' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'd')
                ADVANCE(100);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 122:
            START_TOKEN();
            if (lookahead == 0)
                ADVANCE(1);
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(122);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '=')
                ADVANCE(118);
            LEX_ERROR();
        case 123:
            START_TOKEN();
            if (lookahead == 0)
                ADVANCE(1);
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(123);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == ';')
                ADVANCE(33);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == 'i')
                ADVANCE(124);
            if (lookahead == 'u')
                ADVANCE(126);
            if (lookahead == 'w')
                ADVANCE(135);
            LEX_ERROR();
        case 124:
            if (lookahead == 'f')
                ADVANCE(125);
            LEX_ERROR();
        case 125:
            ACCEPT_TOKEN(anon_sym_if);
        case 126:
            if (lookahead == 'n')
                ADVANCE(127);
            LEX_ERROR();
        case 127:
            if (lookahead == 'l')
                ADVANCE(128);
            if (lookahead == 't')
                ADVANCE(132);
            LEX_ERROR();
        case 128:
            if (lookahead == 'e')
                ADVANCE(129);
            LEX_ERROR();
        case 129:
            if (lookahead == 's')
                ADVANCE(130);
            LEX_ERROR();
        case 130:
            if (lookahead == 's')
                ADVANCE(131);
            LEX_ERROR();
        case 131:
            ACCEPT_TOKEN(anon_sym_unless);
        case 132:
            if (lookahead == 'i')
                ADVANCE(133);
            LEX_ERROR();
        case 133:
            if (lookahead == 'l')
                ADVANCE(134);
            LEX_ERROR();
        case 134:
            ACCEPT_TOKEN(anon_sym_until);
        case 135:
            if (lookahead == 'h')
                ADVANCE(136);
            LEX_ERROR();
        case 136:
            if (lookahead == 'i')
                ADVANCE(137);
            LEX_ERROR();
        case 137:
            if (lookahead == 'l')
                ADVANCE(138);
            LEX_ERROR();
        case 138:
            if (lookahead == 'e')
                ADVANCE(139);
            LEX_ERROR();
        case 139:
            ACCEPT_TOKEN(anon_sym_while);
        case 140:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(140);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == 'd')
                ADVANCE(141);
            LEX_ERROR();
        case 141:
            if (lookahead == 'o')
                ADVANCE(142);
            LEX_ERROR();
        case 142:
            ACCEPT_TOKEN(anon_sym_do);
        case 143:
            START_TOKEN();
            if (lookahead == 0)
                ADVANCE(1);
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(143);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == ':')
                ADVANCE(144);
            if (lookahead == ';')
                ADVANCE(33);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '[')
                ADVANCE(145);
            if (lookahead == 'i')
                ADVANCE(124);
            if (lookahead == 'u')
                ADVANCE(126);
            if (lookahead == 'w')
                ADVANCE(135);
            LEX_ERROR();
        case 144:
            if (lookahead == ':')
                ADVANCE(25);
            LEX_ERROR();
        case 145:
            ACCEPT_TOKEN(anon_sym_LBRACK);
        case 146:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(146);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '%')
                ADVANCE(6);
            if (lookahead == '&')
                ADVANCE(7);
            if (lookahead == '*')
                ADVANCE(10);
            if (lookahead == '+')
                ADVANCE(12);
            if (lookahead == '-')
                ADVANCE(15);
            if (lookahead == '.')
                ADVANCE(17);
            if (lookahead == '/')
                ADVANCE(19);
            if (lookahead == '<')
                ADVANCE(34);
            if (lookahead == '=')
                ADVANCE(38);
            if (lookahead == '>')
                ADVANCE(54);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == '[')
                ADVANCE(147);
            if (lookahead == '^')
                ADVANCE(61);
            if (lookahead == '|')
                ADVANCE(115);
            if (lookahead == '~')
                ADVANCE(116);
            LEX_ERROR();
        case 147:
            if (lookahead == ']')
                ADVANCE(58);
            LEX_ERROR();
        case 148:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(148);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '(')
                ADVANCE(8);
            if (lookahead == ':')
                ADVANCE(20);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                (lookahead == 'b') ||
                ('e' <= lookahead && lookahead <= 'l') ||
                ('o' <= lookahead && lookahead <= 'r') ||
                (lookahead == 't') ||
                ('v' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(62);
            if (lookahead == 'c')
                ADVANCE(67);
            if (lookahead == 'd')
                ADVANCE(119);
            if (lookahead == 'm')
                ADVANCE(81);
            if (lookahead == 'n')
                ADVANCE(87);
            if (lookahead == 's')
                ADVANCE(90);
            if (lookahead == 'u')
                ADVANCE(120);
            LEX_ERROR();
        case 149:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(149);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 150:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(150);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '(')
                ADVANCE(8);
            if (lookahead == ':')
                ADVANCE(144);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'c') ||
                ('e' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'd')
                ADVANCE(151);
            if (lookahead == 'n')
                ADVANCE(87);
            if (lookahead == 's')
                ADVANCE(90);
            LEX_ERROR();
        case 151:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'n') ||
                ('p' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'o')
                ADVANCE(75);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 152:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(152);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == ',')
                ADVANCE(14);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == 'd')
                ADVANCE(141);
            LEX_ERROR();
        case 153:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(153);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == ',')
                ADVANCE(14);
            if (lookahead == ':')
                ADVANCE(144);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '[')
                ADVANCE(145);
            if (lookahead == 'd')
                ADVANCE(141);
            LEX_ERROR();
        case 154:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(154);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '(')
                ADVANCE(8);
            if (lookahead == ':')
                ADVANCE(144);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'n')
                ADVANCE(87);
            if (lookahead == 's')
                ADVANCE(90);
            LEX_ERROR();
        case 155:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(155);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == ')')
                ADVANCE(9);
            if (lookahead == ';')
                ADVANCE(33);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == 'i')
                ADVANCE(124);
            if (lookahead == 'u')
                ADVANCE(126);
            if (lookahead == 'w')
                ADVANCE(135);
            LEX_ERROR();
        case 156:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(156);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == ')')
                ADVANCE(9);
            if (lookahead == ':')
                ADVANCE(144);
            if (lookahead == ';')
                ADVANCE(33);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '[')
                ADVANCE(145);
            if (lookahead == 'i')
                ADVANCE(124);
            if (lookahead == 'u')
                ADVANCE(126);
            if (lookahead == 'w')
                ADVANCE(135);
            LEX_ERROR();
        case 157:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(157);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == ';')
                ADVANCE(33);
            if (lookahead == '=')
                ADVANCE(118);
            LEX_ERROR();
        case 158:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(158);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '(')
                ADVANCE(8);
            if (lookahead == ':')
                ADVANCE(20);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                (lookahead == 'b') ||
                ('f' <= lookahead && lookahead <= 'l') ||
                ('o' <= lookahead && lookahead <= 'r') ||
                (lookahead == 't') ||
                ('v' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(62);
            if (lookahead == 'c')
                ADVANCE(67);
            if (lookahead == 'd')
                ADVANCE(119);
            if (lookahead == 'e')
                ADVANCE(76);
            if (lookahead == 'm')
                ADVANCE(81);
            if (lookahead == 'n')
                ADVANCE(87);
            if (lookahead == 's')
                ADVANCE(90);
            if (lookahead == 'u')
                ADVANCE(120);
            LEX_ERROR();
        case 159:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(159);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '&')
                ADVANCE(7);
            if (lookahead == '(')
                ADVANCE(8);
            if (lookahead == '*')
                ADVANCE(160);
            if (lookahead == ':')
                ADVANCE(20);
            if (lookahead == ';')
                ADVANCE(33);
            if (lookahead == '<')
                ADVANCE(161);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                (lookahead == 'b') ||
                ('f' <= lookahead && lookahead <= 'l') ||
                ('o' <= lookahead && lookahead <= 'r') ||
                (lookahead == 't') ||
                ('v' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(62);
            if (lookahead == 'c')
                ADVANCE(67);
            if (lookahead == 'd')
                ADVANCE(119);
            if (lookahead == 'e')
                ADVANCE(76);
            if (lookahead == 'm')
                ADVANCE(81);
            if (lookahead == 'n')
                ADVANCE(87);
            if (lookahead == 's')
                ADVANCE(90);
            if (lookahead == 'u')
                ADVANCE(120);
            LEX_ERROR();
        case 160:
            ACCEPT_TOKEN(anon_sym_STAR);
        case 161:
            ACCEPT_TOKEN(anon_sym_LT);
        case 162:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(162);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == ';')
                ADVANCE(33);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == 'e')
                ADVANCE(163);
            if (lookahead == 'i')
                ADVANCE(124);
            if (lookahead == 'u')
                ADVANCE(126);
            if (lookahead == 'w')
                ADVANCE(135);
            LEX_ERROR();
        case 163:
            if (lookahead == 'n')
                ADVANCE(164);
            LEX_ERROR();
        case 164:
            if (lookahead == 'd')
                ADVANCE(165);
            LEX_ERROR();
        case 165:
            ACCEPT_TOKEN(anon_sym_end);
        case 166:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(166);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == ':')
                ADVANCE(144);
            if (lookahead == ';')
                ADVANCE(33);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '[')
                ADVANCE(145);
            if (lookahead == 'e')
                ADVANCE(163);
            if (lookahead == 'i')
                ADVANCE(124);
            if (lookahead == 'u')
                ADVANCE(126);
            if (lookahead == 'w')
                ADVANCE(135);
            LEX_ERROR();
        case 167:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(167);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == 'e')
                ADVANCE(163);
            LEX_ERROR();
        case 168:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(168);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '(')
                ADVANCE(8);
            if (lookahead == ':')
                ADVANCE(20);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'n')
                ADVANCE(87);
            if (lookahead == 's')
                ADVANCE(169);
            LEX_ERROR();
        case 169:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'd') ||
                ('f' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'e')
                ADVANCE(91);
            ACCEPT_FRAGILE_TOKEN(sym_identifier);
        case 170:
            START_TOKEN();
            if (lookahead == 0)
                ADVANCE(1);
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(170);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '(')
                ADVANCE(8);
            if (lookahead == ')')
                ADVANCE(9);
            if (lookahead == ':')
                ADVANCE(20);
            if (lookahead == ';')
                ADVANCE(33);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                (lookahead == 'b') ||
                ('f' <= lookahead && lookahead <= 'h') ||
                ('j' <= lookahead && lookahead <= 'l') ||
                ('o' <= lookahead && lookahead <= 'r') ||
                (lookahead == 't') ||
                (lookahead == 'v') ||
                ('x' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(62);
            if (lookahead == 'c')
                ADVANCE(67);
            if (lookahead == 'd')
                ADVANCE(119);
            if (lookahead == 'e')
                ADVANCE(76);
            if (lookahead == 'i')
                ADVANCE(79);
            if (lookahead == 'm')
                ADVANCE(81);
            if (lookahead == 'n')
                ADVANCE(87);
            if (lookahead == 's')
                ADVANCE(90);
            if (lookahead == 'u')
                ADVANCE(98);
            if (lookahead == 'w')
                ADVANCE(110);
            LEX_ERROR();
        case 171:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(171);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == ';')
                ADVANCE(33);
            if (lookahead == '<')
                ADVANCE(161);
            if (lookahead == '=')
                ADVANCE(118);
            LEX_ERROR();
        case 172:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(172);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == ':')
                ADVANCE(144);
            if (lookahead == ';')
                ADVANCE(33);
            if (lookahead == '=')
                ADVANCE(118);
            LEX_ERROR();
        case 173:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(173);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == ')')
                ADVANCE(9);
            if (lookahead == '=')
                ADVANCE(118);
            LEX_ERROR();
        case 174:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(174);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '&')
                ADVANCE(7);
            if (lookahead == '(')
                ADVANCE(8);
            if (lookahead == '*')
                ADVANCE(160);
            if (lookahead == ';')
                ADVANCE(33);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 175:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(175);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '&')
                ADVANCE(7);
            if (lookahead == ')')
                ADVANCE(9);
            if (lookahead == '*')
                ADVANCE(160);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 176:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(176);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == ',')
                ADVANCE(14);
            if (lookahead == ';')
                ADVANCE(33);
            if (lookahead == '=')
                ADVANCE(118);
            LEX_ERROR();
        case 177:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(177);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '&')
                ADVANCE(7);
            if (lookahead == '*')
                ADVANCE(160);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            LEX_ERROR();
        case 178:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(178);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == ')')
                ADVANCE(9);
            if (lookahead == ',')
                ADVANCE(14);
            if (lookahead == '=')
                ADVANCE(118);
            LEX_ERROR();
        case 179:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(179);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '(')
                ADVANCE(8);
            if (lookahead == ':')
                ADVANCE(144);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == ']')
                ADVANCE(60);
            if (lookahead == 'n')
                ADVANCE(87);
            if (lookahead == 's')
                ADVANCE(169);
            LEX_ERROR();
        case 180:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(180);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == ',')
                ADVANCE(14);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == ']')
                ADVANCE(60);
            LEX_ERROR();
        case 181:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(181);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == ',')
                ADVANCE(14);
            if (lookahead == ':')
                ADVANCE(144);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '[')
                ADVANCE(145);
            if (lookahead == ']')
                ADVANCE(60);
            LEX_ERROR();
        case 182:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(182);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == ']')
                ADVANCE(60);
            LEX_ERROR();
        case 183:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(183);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '(')
                ADVANCE(8);
            if (lookahead == ':')
                ADVANCE(144);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'm') ||
                ('o' <= lookahead && lookahead <= 'r') ||
                ('t' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'n')
                ADVANCE(87);
            if (lookahead == 's')
                ADVANCE(169);
            LEX_ERROR();
        case 184:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(184);
            if (lookahead == '\n')
                ADVANCE(2);
            if (lookahead == '#')
                ADVANCE(3);
            if (lookahead == '$')
                ADVANCE(4);
            if (lookahead == '(')
                ADVANCE(8);
            if (lookahead == ':')
                ADVANCE(20);
            if (lookahead == '=')
                ADVANCE(118);
            if (lookahead == '@')
                ADVANCE(4);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                (lookahead == 'b') ||
                ('f' <= lookahead && lookahead <= 'l') ||
                ('o' <= lookahead && lookahead <= 'r') ||
                (lookahead == 't') ||
                ('v' <= lookahead && lookahead <= 'z'))
                ADVANCE(5);
            if (lookahead == 'a')
                ADVANCE(62);
            if (lookahead == 'c')
                ADVANCE(67);
            if (lookahead == 'd')
                ADVANCE(119);
            if (lookahead == 'e')
                ADVANCE(76);
            if (lookahead == 'm')
                ADVANCE(81);
            if (lookahead == 'n')
                ADVANCE(87);
            if (lookahead == 's')
                ADVANCE(90);
            if (lookahead == 'u')
                ADVANCE(120);
            if (lookahead == '|')
                ADVANCE(115);
            LEX_ERROR();
        default:
            LEX_ERROR();
    }
}

static TSStateId ts_lex_states[STATE_COUNT] = {
    [0] = 117,
    [1] = 122,
    [2] = 123,
    [3] = 123,
    [4] = 123,
    [5] = 140,
    [6] = 140,
    [7] = 123,
    [8] = 143,
    [9] = 143,
    [10] = 146,
    [11] = 146,
    [12] = 146,
    [13] = 148,
    [14] = 149,
    [15] = 149,
    [16] = 149,
    [17] = 150,
    [18] = 143,
    [19] = 140,
    [20] = 140,
    [21] = 152,
    [22] = 153,
    [23] = 153,
    [24] = 148,
    [25] = 149,
    [26] = 154,
    [27] = 153,
    [28] = 153,
    [29] = 155,
    [30] = 155,
    [31] = 155,
    [32] = 140,
    [33] = 155,
    [34] = 156,
    [35] = 156,
    [36] = 146,
    [37] = 146,
    [38] = 146,
    [39] = 148,
    [40] = 149,
    [41] = 149,
    [42] = 149,
    [43] = 156,
    [44] = 157,
    [45] = 158,
    [46] = 159,
    [47] = 158,
    [48] = 162,
    [49] = 162,
    [50] = 162,
    [51] = 140,
    [52] = 162,
    [53] = 166,
    [54] = 166,
    [55] = 155,
    [56] = 146,
    [57] = 146,
    [58] = 146,
    [59] = 148,
    [60] = 149,
    [61] = 149,
    [62] = 149,
    [63] = 166,
    [64] = 157,
    [65] = 158,
    [66] = 162,
    [67] = 162,
    [68] = 148,
    [69] = 167,
    [70] = 162,
    [71] = 168,
    [72] = 170,
    [73] = 148,
    [74] = 162,
    [75] = 162,
    [76] = 162,
    [77] = 167,
    [78] = 166,
    [79] = 171,
    [80] = 158,
    [81] = 149,
    [82] = 172,
    [83] = 158,
    [84] = 157,
    [85] = 149,
    [86] = 172,
    [87] = 157,
    [88] = 158,
    [89] = 162,
    [90] = 162,
    [91] = 167,
    [92] = 162,
    [93] = 162,
    [94] = 162,
    [95] = 162,
    [96] = 167,
    [97] = 162,
    [98] = 162,
    [99] = 167,
    [100] = 162,
    [101] = 155,
    [102] = 148,
    [103] = 173,
    [104] = 168,
    [105] = 166,
    [106] = 155,
    [107] = 166,
    [108] = 155,
    [109] = 173,
    [110] = 174,
    [111] = 174,
    [112] = 157,
    [113] = 158,
    [114] = 175,
    [115] = 149,
    [116] = 176,
    [117] = 157,
    [118] = 177,
    [119] = 149,
    [120] = 176,
    [121] = 157,
    [122] = 176,
    [123] = 157,
    [124] = 176,
    [125] = 157,
    [126] = 173,
    [127] = 158,
    [128] = 149,
    [129] = 178,
    [130] = 173,
    [131] = 177,
    [132] = 149,
    [133] = 178,
    [134] = 173,
    [135] = 178,
    [136] = 173,
    [137] = 178,
    [138] = 173,
    [139] = 162,
    [140] = 162,
    [141] = 167,
    [142] = 162,
    [143] = 162,
    [144] = 158,
    [145] = 162,
    [146] = 167,
    [147] = 162,
    [148] = 162,
    [149] = 162,
    [150] = 167,
    [151] = 146,
    [152] = 146,
    [153] = 162,
    [154] = 162,
    [155] = 149,
    [156] = 179,
    [157] = 180,
    [158] = 181,
    [159] = 181,
    [160] = 148,
    [161] = 149,
    [162] = 181,
    [163] = 181,
    [164] = 155,
    [165] = 173,
    [166] = 181,
    [167] = 181,
    [168] = 149,
    [169] = 179,
    [170] = 180,
    [171] = 182,
    [172] = 183,
    [173] = 180,
    [174] = 182,
    [175] = 181,
    [176] = 181,
    [177] = 182,
    [178] = 166,
    [179] = 166,
    [180] = 184,
    [181] = 162,
    [182] = 158,
    [183] = 162,
    [184] = 162,
    [185] = 167,
    [186] = 162,
    [187] = 162,
    [188] = 167,
    [189] = 167,
    [190] = 155,
    [191] = 155,
    [192] = 156,
    [193] = 171,
    [194] = 158,
    [195] = 149,
    [196] = 172,
    [197] = 158,
    [198] = 157,
    [199] = 158,
    [200] = 162,
    [201] = 155,
    [202] = 167,
    [203] = 155,
    [204] = 155,
    [205] = 162,
    [206] = 155,
    [207] = 167,
    [208] = 162,
    [209] = 155,
    [210] = 167,
    [211] = 155,
    [212] = 155,
    [213] = 173,
    [214] = 156,
    [215] = 156,
    [216] = 174,
    [217] = 157,
    [218] = 158,
    [219] = 175,
    [220] = 173,
    [221] = 158,
    [222] = 162,
    [223] = 155,
    [224] = 167,
    [225] = 155,
    [226] = 155,
    [227] = 158,
    [228] = 162,
    [229] = 167,
    [230] = 155,
    [231] = 162,
    [232] = 155,
    [233] = 167,
    [234] = 146,
    [235] = 155,
    [236] = 155,
    [237] = 149,
    [238] = 179,
    [239] = 180,
    [240] = 182,
    [241] = 156,
    [242] = 156,
    [243] = 184,
    [244] = 162,
    [245] = 158,
    [246] = 162,
    [247] = 155,
    [248] = 167,
    [249] = 155,
    [250] = 155,
    [251] = 167,
    [252] = 173,
    [253] = 153,
    [254] = 153,
    [255] = 149,
    [256] = 179,
    [257] = 180,
    [258] = 182,
    [259] = 153,
    [260] = 153,
    [261] = 140,
    [262] = 183,
    [263] = 152,
    [264] = 140,
    [265] = 157,
    [266] = 158,
    [267] = 162,
    [268] = 123,
    [269] = 167,
    [270] = 123,
    [271] = 123,
    [272] = 143,
    [273] = 171,
    [274] = 158,
    [275] = 149,
    [276] = 172,
    [277] = 158,
    [278] = 157,
    [279] = 158,
    [280] = 162,
    [281] = 123,
    [282] = 167,
    [283] = 123,
    [284] = 123,
    [285] = 162,
    [286] = 123,
    [287] = 167,
    [288] = 162,
    [289] = 123,
    [290] = 167,
    [291] = 123,
    [292] = 155,
    [293] = 173,
    [294] = 143,
    [295] = 143,
    [296] = 174,
    [297] = 157,
    [298] = 158,
    [299] = 175,
    [300] = 173,
    [301] = 158,
    [302] = 162,
    [303] = 123,
    [304] = 167,
    [305] = 123,
    [306] = 123,
    [307] = 158,
    [308] = 162,
    [309] = 167,
    [310] = 123,
    [311] = 162,
    [312] = 123,
    [313] = 167,
    [314] = 146,
    [315] = 123,
    [316] = 123,
    [317] = 123,
    [318] = 149,
    [319] = 179,
    [320] = 180,
    [321] = 182,
    [322] = 143,
    [323] = 143,
    [324] = 184,
    [325] = 162,
    [326] = 158,
    [327] = 162,
    [328] = 123,
    [329] = 167,
    [330] = 123,
    [331] = 123,
    [332] = 167,
    [333] = 148,
    [334] = 122,
    [335] = 168,
    [336] = 123,
    [337] = 122,
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

static unsigned short ts_parse_table[STATE_COUNT][SYMBOL_COUNT] = {
    [0] = {
        [sym_program] = 2,
        [sym__statement] = 4,
        [sym__declaration] = 6,
        [sym_method_declaration] = 8,
        [sym_class_declaration] = 8,
        [sym_module_declaration] = 8,
        [sym__call] = 10,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 6,
        [sym__argument] = 14,
        [sym__primary] = 16,
        [sym_scope_resolution_expression] = 18,
        [sym__variable] = 18,
        [ts_builtin_sym_end] = 20,
        [anon_sym_undef] = 22,
        [anon_sym_alias] = 24,
        [anon_sym_def] = 26,
        [anon_sym_LPAREN] = 28,
        [anon_sym_class] = 30,
        [anon_sym_COLON_COLON] = 32,
        [anon_sym_module] = 34,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 38,
        [anon_sym_self] = 38,
        [sym_identifier] = 38,
        [sym_comment] = 40,
        [sym_symbol] = 14,
        [sym__line_break] = 40,
    },
    [1] = {
        [ts_builtin_sym_end] = 42,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [2] = {
        [sym__terminator] = 44,
        [aux_sym_program_repeat1] = 46,
        [ts_builtin_sym_end] = 48,
        [anon_sym_if] = 50,
        [anon_sym_while] = 50,
        [anon_sym_unless] = 50,
        [anon_sym_until] = 50,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [3] = {
        [sym__terminator] = 56,
        [aux_sym_program_repeat1] = 56,
        [ts_builtin_sym_end] = 56,
        [anon_sym_if] = 56,
        [anon_sym_while] = 56,
        [anon_sym_unless] = 56,
        [anon_sym_until] = 56,
        [sym_comment] = 40,
        [sym__line_break] = 56,
        [anon_sym_SEMI] = 56,
    },
    [4] = {
        [sym__terminator] = 58,
        [aux_sym_program_repeat1] = 58,
        [ts_builtin_sym_end] = 58,
        [anon_sym_if] = 58,
        [anon_sym_while] = 58,
        [anon_sym_unless] = 58,
        [anon_sym_until] = 58,
        [sym_comment] = 40,
        [sym__line_break] = 58,
        [anon_sym_SEMI] = 58,
    },
    [5] = {
        [anon_sym_do] = 60,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [6] = {
        [anon_sym_do] = 62,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [7] = {
        [sym__terminator] = 64,
        [aux_sym_program_repeat1] = 64,
        [ts_builtin_sym_end] = 64,
        [anon_sym_if] = 64,
        [anon_sym_while] = 64,
        [anon_sym_unless] = 64,
        [anon_sym_until] = 64,
        [sym_comment] = 40,
        [sym__line_break] = 64,
        [anon_sym_SEMI] = 64,
    },
    [8] = {
        [sym__terminator] = 66,
        [aux_sym_program_repeat1] = 66,
        [ts_builtin_sym_end] = 66,
        [anon_sym_if] = 66,
        [anon_sym_while] = 66,
        [anon_sym_unless] = 66,
        [anon_sym_until] = 66,
        [anon_sym_COLON_COLON] = 68,
        [anon_sym_LBRACK] = 70,
        [sym_comment] = 40,
        [sym__line_break] = 66,
        [anon_sym_SEMI] = 66,
    },
    [9] = {
        [sym__terminator] = 72,
        [aux_sym_program_repeat1] = 72,
        [ts_builtin_sym_end] = 72,
        [anon_sym_if] = 72,
        [anon_sym_while] = 72,
        [anon_sym_unless] = 72,
        [anon_sym_until] = 72,
        [anon_sym_COLON_COLON] = 72,
        [anon_sym_LBRACK] = 72,
        [sym_comment] = 40,
        [sym__line_break] = 72,
        [anon_sym_SEMI] = 72,
    },
    [10] = {
        [sym__function_name] = 74,
        [anon_sym_PIPE] = 76,
        [anon_sym_STAR] = 76,
        [anon_sym_AMP] = 76,
        [anon_sym_LT] = 76,
        [sym_identifier] = 76,
        [sym_comment] = 40,
        [anon_sym_DOT_DOT] = 76,
        [anon_sym_CARET] = 76,
        [anon_sym_LT_EQ_GT] = 76,
        [anon_sym_EQ_EQ] = 76,
        [anon_sym_EQ_EQ_EQ] = 76,
        [anon_sym_EQ_TILDE] = 76,
        [anon_sym_GT] = 76,
        [anon_sym_GT_EQ] = 76,
        [anon_sym_LT_EQ] = 76,
        [anon_sym_PLUS] = 76,
        [anon_sym_DASH] = 76,
        [anon_sym_SLASH] = 76,
        [anon_sym_PERCENT] = 76,
        [anon_sym_STAR_STAR] = 76,
        [anon_sym_LT_LT] = 76,
        [anon_sym_GT_GT] = 76,
        [anon_sym_TILDE] = 76,
        [anon_sym_PLUS_AT] = 76,
        [anon_sym_DASH_AT] = 76,
        [anon_sym_LBRACK_RBRACK] = 76,
        [anon_sym_LBRACK_RBRACK_EQ] = 76,
        [sym__line_break] = 40,
    },
    [11] = {
        [sym__function_name] = 78,
        [anon_sym_PIPE] = 80,
        [anon_sym_STAR] = 80,
        [anon_sym_AMP] = 80,
        [anon_sym_LT] = 80,
        [sym_identifier] = 80,
        [sym_comment] = 40,
        [anon_sym_DOT_DOT] = 80,
        [anon_sym_CARET] = 80,
        [anon_sym_LT_EQ_GT] = 80,
        [anon_sym_EQ_EQ] = 80,
        [anon_sym_EQ_EQ_EQ] = 80,
        [anon_sym_EQ_TILDE] = 80,
        [anon_sym_GT] = 80,
        [anon_sym_GT_EQ] = 80,
        [anon_sym_LT_EQ] = 80,
        [anon_sym_PLUS] = 80,
        [anon_sym_DASH] = 80,
        [anon_sym_SLASH] = 80,
        [anon_sym_PERCENT] = 80,
        [anon_sym_STAR_STAR] = 80,
        [anon_sym_LT_LT] = 80,
        [anon_sym_GT_GT] = 80,
        [anon_sym_TILDE] = 80,
        [anon_sym_PLUS_AT] = 80,
        [anon_sym_DASH_AT] = 80,
        [anon_sym_LBRACK_RBRACK] = 80,
        [anon_sym_LBRACK_RBRACK_EQ] = 80,
        [sym__line_break] = 40,
    },
    [12] = {
        [sym__function_name] = 82,
        [anon_sym_PIPE] = 84,
        [anon_sym_STAR] = 84,
        [anon_sym_AMP] = 84,
        [anon_sym_LT] = 84,
        [sym_identifier] = 84,
        [sym_comment] = 40,
        [anon_sym_DOT_DOT] = 84,
        [anon_sym_CARET] = 84,
        [anon_sym_LT_EQ_GT] = 84,
        [anon_sym_EQ_EQ] = 84,
        [anon_sym_EQ_EQ_EQ] = 84,
        [anon_sym_EQ_TILDE] = 84,
        [anon_sym_GT] = 84,
        [anon_sym_GT_EQ] = 84,
        [anon_sym_LT_EQ] = 84,
        [anon_sym_PLUS] = 84,
        [anon_sym_DASH] = 84,
        [anon_sym_SLASH] = 84,
        [anon_sym_PERCENT] = 84,
        [anon_sym_STAR_STAR] = 84,
        [anon_sym_LT_LT] = 84,
        [anon_sym_GT_GT] = 84,
        [anon_sym_TILDE] = 84,
        [anon_sym_PLUS_AT] = 84,
        [anon_sym_DASH_AT] = 84,
        [anon_sym_LBRACK_RBRACK] = 84,
        [anon_sym_LBRACK_RBRACK_EQ] = 84,
        [sym__line_break] = 40,
    },
    [13] = {
        [sym__statement] = 86,
        [sym__declaration] = 88,
        [sym_method_declaration] = 90,
        [sym_class_declaration] = 90,
        [sym_module_declaration] = 90,
        [sym__call] = 92,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 88,
        [sym__argument] = 94,
        [sym__primary] = 96,
        [sym_scope_resolution_expression] = 98,
        [sym__variable] = 98,
        [anon_sym_undef] = 100,
        [anon_sym_alias] = 102,
        [anon_sym_def] = 104,
        [anon_sym_LPAREN] = 106,
        [anon_sym_class] = 108,
        [anon_sym_COLON_COLON] = 110,
        [anon_sym_module] = 112,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 114,
        [anon_sym_self] = 114,
        [sym_identifier] = 114,
        [sym_comment] = 40,
        [sym_symbol] = 94,
        [sym__line_break] = 40,
    },
    [14] = {
        [sym_identifier] = 116,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [15] = {
        [sym_identifier] = 118,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [16] = {
        [sym_identifier] = 120,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [17] = {
        [sym__call_arguments] = 122,
        [sym__command] = 124,
        [sym__argument] = 126,
        [sym__primary] = 128,
        [sym_scope_resolution_expression] = 130,
        [sym__variable] = 130,
        [anon_sym_do] = 132,
        [anon_sym_LPAREN] = 134,
        [anon_sym_COLON_COLON] = 136,
        [anon_sym_super] = 138,
        [anon_sym_nil] = 140,
        [anon_sym_self] = 140,
        [sym_identifier] = 140,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [18] = {
        [sym__terminator] = 142,
        [aux_sym_program_repeat1] = 142,
        [ts_builtin_sym_end] = 142,
        [anon_sym_if] = 142,
        [anon_sym_while] = 142,
        [anon_sym_unless] = 142,
        [anon_sym_until] = 142,
        [anon_sym_COLON_COLON] = 142,
        [anon_sym_LBRACK] = 142,
        [sym_comment] = 40,
        [sym__line_break] = 142,
        [anon_sym_SEMI] = 142,
    },
    [19] = {
        [anon_sym_do] = 144,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [20] = {
        [anon_sym_do] = 146,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [21] = {
        [aux_sym__call_arguments_repeat1] = 148,
        [anon_sym_do] = 146,
        [anon_sym_COMMA] = 150,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [22] = {
        [aux_sym__call_arguments_repeat1] = 66,
        [anon_sym_do] = 66,
        [anon_sym_COMMA] = 66,
        [anon_sym_COLON_COLON] = 152,
        [anon_sym_LBRACK] = 154,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [23] = {
        [aux_sym__call_arguments_repeat1] = 72,
        [anon_sym_do] = 72,
        [anon_sym_COMMA] = 72,
        [anon_sym_COLON_COLON] = 72,
        [anon_sym_LBRACK] = 72,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [24] = {
        [sym__statement] = 156,
        [sym__declaration] = 88,
        [sym_method_declaration] = 90,
        [sym_class_declaration] = 90,
        [sym_module_declaration] = 90,
        [sym__call] = 92,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 88,
        [sym__argument] = 94,
        [sym__primary] = 96,
        [sym_scope_resolution_expression] = 98,
        [sym__variable] = 98,
        [anon_sym_undef] = 100,
        [anon_sym_alias] = 102,
        [anon_sym_def] = 104,
        [anon_sym_LPAREN] = 106,
        [anon_sym_class] = 108,
        [anon_sym_COLON_COLON] = 110,
        [anon_sym_module] = 112,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 114,
        [anon_sym_self] = 114,
        [sym_identifier] = 114,
        [sym_comment] = 40,
        [sym_symbol] = 94,
        [sym__line_break] = 40,
    },
    [25] = {
        [sym_identifier] = 158,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [26] = {
        [sym__call_arguments] = 122,
        [sym__command] = 124,
        [sym__argument] = 126,
        [sym__primary] = 128,
        [sym_scope_resolution_expression] = 130,
        [sym__variable] = 130,
        [anon_sym_LPAREN] = 134,
        [anon_sym_COLON_COLON] = 136,
        [anon_sym_super] = 138,
        [anon_sym_nil] = 140,
        [anon_sym_self] = 140,
        [sym_identifier] = 140,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [27] = {
        [aux_sym__call_arguments_repeat1] = 142,
        [anon_sym_do] = 142,
        [anon_sym_COMMA] = 142,
        [anon_sym_COLON_COLON] = 142,
        [anon_sym_LBRACK] = 142,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [28] = {
        [aux_sym__call_arguments_repeat1] = 160,
        [anon_sym_do] = 160,
        [anon_sym_COMMA] = 160,
        [anon_sym_COLON_COLON] = 160,
        [anon_sym_LBRACK] = 160,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [29] = {
        [sym__terminator] = 162,
        [aux_sym_program_repeat1] = 164,
        [anon_sym_if] = 166,
        [anon_sym_while] = 166,
        [anon_sym_unless] = 166,
        [anon_sym_until] = 166,
        [anon_sym_RPAREN] = 168,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [30] = {
        [sym__terminator] = 56,
        [aux_sym_program_repeat1] = 56,
        [anon_sym_if] = 56,
        [anon_sym_while] = 56,
        [anon_sym_unless] = 56,
        [anon_sym_until] = 56,
        [anon_sym_RPAREN] = 56,
        [sym_comment] = 40,
        [sym__line_break] = 56,
        [anon_sym_SEMI] = 56,
    },
    [31] = {
        [sym__terminator] = 58,
        [aux_sym_program_repeat1] = 58,
        [anon_sym_if] = 58,
        [anon_sym_while] = 58,
        [anon_sym_unless] = 58,
        [anon_sym_until] = 58,
        [anon_sym_RPAREN] = 58,
        [sym_comment] = 40,
        [sym__line_break] = 58,
        [anon_sym_SEMI] = 58,
    },
    [32] = {
        [anon_sym_do] = 170,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [33] = {
        [sym__terminator] = 64,
        [aux_sym_program_repeat1] = 64,
        [anon_sym_if] = 64,
        [anon_sym_while] = 64,
        [anon_sym_unless] = 64,
        [anon_sym_until] = 64,
        [anon_sym_RPAREN] = 64,
        [sym_comment] = 40,
        [sym__line_break] = 64,
        [anon_sym_SEMI] = 64,
    },
    [34] = {
        [sym__terminator] = 66,
        [aux_sym_program_repeat1] = 66,
        [anon_sym_if] = 66,
        [anon_sym_while] = 66,
        [anon_sym_unless] = 66,
        [anon_sym_until] = 66,
        [anon_sym_RPAREN] = 66,
        [anon_sym_COLON_COLON] = 172,
        [anon_sym_LBRACK] = 174,
        [sym_comment] = 40,
        [sym__line_break] = 66,
        [anon_sym_SEMI] = 66,
    },
    [35] = {
        [sym__terminator] = 72,
        [aux_sym_program_repeat1] = 72,
        [anon_sym_if] = 72,
        [anon_sym_while] = 72,
        [anon_sym_unless] = 72,
        [anon_sym_until] = 72,
        [anon_sym_RPAREN] = 72,
        [anon_sym_COLON_COLON] = 72,
        [anon_sym_LBRACK] = 72,
        [sym_comment] = 40,
        [sym__line_break] = 72,
        [anon_sym_SEMI] = 72,
    },
    [36] = {
        [sym__function_name] = 176,
        [anon_sym_PIPE] = 178,
        [anon_sym_STAR] = 178,
        [anon_sym_AMP] = 178,
        [anon_sym_LT] = 178,
        [sym_identifier] = 178,
        [sym_comment] = 40,
        [anon_sym_DOT_DOT] = 178,
        [anon_sym_CARET] = 178,
        [anon_sym_LT_EQ_GT] = 178,
        [anon_sym_EQ_EQ] = 178,
        [anon_sym_EQ_EQ_EQ] = 178,
        [anon_sym_EQ_TILDE] = 178,
        [anon_sym_GT] = 178,
        [anon_sym_GT_EQ] = 178,
        [anon_sym_LT_EQ] = 178,
        [anon_sym_PLUS] = 178,
        [anon_sym_DASH] = 178,
        [anon_sym_SLASH] = 178,
        [anon_sym_PERCENT] = 178,
        [anon_sym_STAR_STAR] = 178,
        [anon_sym_LT_LT] = 178,
        [anon_sym_GT_GT] = 178,
        [anon_sym_TILDE] = 178,
        [anon_sym_PLUS_AT] = 178,
        [anon_sym_DASH_AT] = 178,
        [anon_sym_LBRACK_RBRACK] = 178,
        [anon_sym_LBRACK_RBRACK_EQ] = 178,
        [sym__line_break] = 40,
    },
    [37] = {
        [sym__function_name] = 180,
        [anon_sym_PIPE] = 80,
        [anon_sym_STAR] = 80,
        [anon_sym_AMP] = 80,
        [anon_sym_LT] = 80,
        [sym_identifier] = 80,
        [sym_comment] = 40,
        [anon_sym_DOT_DOT] = 80,
        [anon_sym_CARET] = 80,
        [anon_sym_LT_EQ_GT] = 80,
        [anon_sym_EQ_EQ] = 80,
        [anon_sym_EQ_EQ_EQ] = 80,
        [anon_sym_EQ_TILDE] = 80,
        [anon_sym_GT] = 80,
        [anon_sym_GT_EQ] = 80,
        [anon_sym_LT_EQ] = 80,
        [anon_sym_PLUS] = 80,
        [anon_sym_DASH] = 80,
        [anon_sym_SLASH] = 80,
        [anon_sym_PERCENT] = 80,
        [anon_sym_STAR_STAR] = 80,
        [anon_sym_LT_LT] = 80,
        [anon_sym_GT_GT] = 80,
        [anon_sym_TILDE] = 80,
        [anon_sym_PLUS_AT] = 80,
        [anon_sym_DASH_AT] = 80,
        [anon_sym_LBRACK_RBRACK] = 80,
        [anon_sym_LBRACK_RBRACK_EQ] = 80,
        [sym__line_break] = 40,
    },
    [38] = {
        [sym__function_name] = 182,
        [anon_sym_PIPE] = 84,
        [anon_sym_STAR] = 84,
        [anon_sym_AMP] = 84,
        [anon_sym_LT] = 84,
        [sym_identifier] = 84,
        [sym_comment] = 40,
        [anon_sym_DOT_DOT] = 84,
        [anon_sym_CARET] = 84,
        [anon_sym_LT_EQ_GT] = 84,
        [anon_sym_EQ_EQ] = 84,
        [anon_sym_EQ_EQ_EQ] = 84,
        [anon_sym_EQ_TILDE] = 84,
        [anon_sym_GT] = 84,
        [anon_sym_GT_EQ] = 84,
        [anon_sym_LT_EQ] = 84,
        [anon_sym_PLUS] = 84,
        [anon_sym_DASH] = 84,
        [anon_sym_SLASH] = 84,
        [anon_sym_PERCENT] = 84,
        [anon_sym_STAR_STAR] = 84,
        [anon_sym_LT_LT] = 84,
        [anon_sym_GT_GT] = 84,
        [anon_sym_TILDE] = 84,
        [anon_sym_PLUS_AT] = 84,
        [anon_sym_DASH_AT] = 84,
        [anon_sym_LBRACK_RBRACK] = 84,
        [anon_sym_LBRACK_RBRACK_EQ] = 84,
        [sym__line_break] = 40,
    },
    [39] = {
        [sym__statement] = 184,
        [sym__declaration] = 88,
        [sym_method_declaration] = 90,
        [sym_class_declaration] = 90,
        [sym_module_declaration] = 90,
        [sym__call] = 92,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 88,
        [sym__argument] = 94,
        [sym__primary] = 96,
        [sym_scope_resolution_expression] = 98,
        [sym__variable] = 98,
        [anon_sym_undef] = 100,
        [anon_sym_alias] = 102,
        [anon_sym_def] = 104,
        [anon_sym_LPAREN] = 106,
        [anon_sym_class] = 108,
        [anon_sym_COLON_COLON] = 110,
        [anon_sym_module] = 112,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 114,
        [anon_sym_self] = 114,
        [sym_identifier] = 114,
        [sym_comment] = 40,
        [sym_symbol] = 94,
        [sym__line_break] = 40,
    },
    [40] = {
        [sym_identifier] = 186,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [41] = {
        [sym_identifier] = 188,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [42] = {
        [sym_identifier] = 190,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [43] = {
        [sym__terminator] = 142,
        [aux_sym_program_repeat1] = 142,
        [anon_sym_if] = 142,
        [anon_sym_while] = 142,
        [anon_sym_unless] = 142,
        [anon_sym_until] = 142,
        [anon_sym_RPAREN] = 142,
        [anon_sym_COLON_COLON] = 142,
        [anon_sym_LBRACK] = 142,
        [sym_comment] = 40,
        [sym__line_break] = 142,
        [anon_sym_SEMI] = 142,
    },
    [44] = {
        [sym__terminator] = 192,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [45] = {
        [sym__statement] = 198,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 212,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [46] = {
        [sym__statement] = 230,
        [sym__declaration] = 230,
        [sym_method_declaration] = 230,
        [sym_argument_list] = 232,
        [sym_class_declaration] = 230,
        [sym_module_declaration] = 230,
        [sym__call] = 230,
        [sym__command] = 230,
        [sym__function_call] = 230,
        [sym__expression] = 230,
        [sym__argument] = 230,
        [sym__primary] = 230,
        [sym_scope_resolution_expression] = 230,
        [sym__variable] = 230,
        [sym__terminator] = 232,
        [aux_sym_class_declaration_repeat1] = 232,
        [anon_sym_end] = 230,
        [anon_sym_undef] = 230,
        [anon_sym_alias] = 230,
        [anon_sym_def] = 230,
        [anon_sym_LPAREN] = 230,
        [anon_sym_STAR] = 232,
        [anon_sym_AMP] = 232,
        [anon_sym_class] = 230,
        [anon_sym_LT] = 232,
        [anon_sym_COLON_COLON] = 230,
        [anon_sym_module] = 230,
        [anon_sym_super] = 230,
        [anon_sym_nil] = 230,
        [anon_sym_self] = 230,
        [sym_identifier] = 230,
        [sym_comment] = 40,
        [sym_symbol] = 230,
        [sym__line_break] = 40,
        [anon_sym_SEMI] = 232,
    },
    [47] = {
        [sym__statement] = 230,
        [sym__declaration] = 230,
        [sym_method_declaration] = 230,
        [sym_class_declaration] = 230,
        [sym_module_declaration] = 230,
        [sym__call] = 230,
        [sym__command] = 230,
        [sym__function_call] = 230,
        [sym__expression] = 230,
        [sym__argument] = 230,
        [sym__primary] = 230,
        [sym_scope_resolution_expression] = 230,
        [sym__variable] = 230,
        [anon_sym_end] = 230,
        [anon_sym_undef] = 230,
        [anon_sym_alias] = 230,
        [anon_sym_def] = 230,
        [anon_sym_LPAREN] = 230,
        [anon_sym_class] = 230,
        [anon_sym_COLON_COLON] = 230,
        [anon_sym_module] = 230,
        [anon_sym_super] = 230,
        [anon_sym_nil] = 230,
        [anon_sym_self] = 230,
        [sym_identifier] = 230,
        [sym_comment] = 40,
        [sym_symbol] = 230,
        [sym__line_break] = 40,
    },
    [48] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 236,
        [anon_sym_end] = 238,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [49] = {
        [sym__terminator] = 56,
        [aux_sym_program_repeat1] = 56,
        [anon_sym_end] = 56,
        [anon_sym_if] = 56,
        [anon_sym_while] = 56,
        [anon_sym_unless] = 56,
        [anon_sym_until] = 56,
        [sym_comment] = 40,
        [sym__line_break] = 56,
        [anon_sym_SEMI] = 56,
    },
    [50] = {
        [sym__terminator] = 58,
        [aux_sym_program_repeat1] = 58,
        [anon_sym_end] = 58,
        [anon_sym_if] = 58,
        [anon_sym_while] = 58,
        [anon_sym_unless] = 58,
        [anon_sym_until] = 58,
        [sym_comment] = 40,
        [sym__line_break] = 58,
        [anon_sym_SEMI] = 58,
    },
    [51] = {
        [anon_sym_do] = 242,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [52] = {
        [sym__terminator] = 64,
        [aux_sym_program_repeat1] = 64,
        [anon_sym_end] = 64,
        [anon_sym_if] = 64,
        [anon_sym_while] = 64,
        [anon_sym_unless] = 64,
        [anon_sym_until] = 64,
        [sym_comment] = 40,
        [sym__line_break] = 64,
        [anon_sym_SEMI] = 64,
    },
    [53] = {
        [sym__terminator] = 66,
        [aux_sym_program_repeat1] = 66,
        [anon_sym_end] = 66,
        [anon_sym_if] = 66,
        [anon_sym_while] = 66,
        [anon_sym_unless] = 66,
        [anon_sym_until] = 66,
        [anon_sym_COLON_COLON] = 244,
        [anon_sym_LBRACK] = 246,
        [sym_comment] = 40,
        [sym__line_break] = 66,
        [anon_sym_SEMI] = 66,
    },
    [54] = {
        [sym__terminator] = 72,
        [aux_sym_program_repeat1] = 72,
        [anon_sym_end] = 72,
        [anon_sym_if] = 72,
        [anon_sym_while] = 72,
        [anon_sym_unless] = 72,
        [anon_sym_until] = 72,
        [anon_sym_COLON_COLON] = 72,
        [anon_sym_LBRACK] = 72,
        [sym_comment] = 40,
        [sym__line_break] = 72,
        [anon_sym_SEMI] = 72,
    },
    [55] = {
        [sym__terminator] = 248,
        [aux_sym_program_repeat1] = 248,
        [anon_sym_if] = 248,
        [anon_sym_while] = 248,
        [anon_sym_unless] = 248,
        [anon_sym_until] = 248,
        [anon_sym_RPAREN] = 248,
        [sym_comment] = 40,
        [sym__line_break] = 248,
        [anon_sym_SEMI] = 248,
    },
    [56] = {
        [sym__function_name] = 250,
        [anon_sym_PIPE] = 252,
        [anon_sym_STAR] = 252,
        [anon_sym_AMP] = 252,
        [anon_sym_LT] = 252,
        [sym_identifier] = 252,
        [sym_comment] = 40,
        [anon_sym_DOT_DOT] = 252,
        [anon_sym_CARET] = 252,
        [anon_sym_LT_EQ_GT] = 252,
        [anon_sym_EQ_EQ] = 252,
        [anon_sym_EQ_EQ_EQ] = 252,
        [anon_sym_EQ_TILDE] = 252,
        [anon_sym_GT] = 252,
        [anon_sym_GT_EQ] = 252,
        [anon_sym_LT_EQ] = 252,
        [anon_sym_PLUS] = 252,
        [anon_sym_DASH] = 252,
        [anon_sym_SLASH] = 252,
        [anon_sym_PERCENT] = 252,
        [anon_sym_STAR_STAR] = 252,
        [anon_sym_LT_LT] = 252,
        [anon_sym_GT_GT] = 252,
        [anon_sym_TILDE] = 252,
        [anon_sym_PLUS_AT] = 252,
        [anon_sym_DASH_AT] = 252,
        [anon_sym_LBRACK_RBRACK] = 252,
        [anon_sym_LBRACK_RBRACK_EQ] = 252,
        [sym__line_break] = 40,
    },
    [57] = {
        [sym__function_name] = 254,
        [anon_sym_PIPE] = 80,
        [anon_sym_STAR] = 80,
        [anon_sym_AMP] = 80,
        [anon_sym_LT] = 80,
        [sym_identifier] = 80,
        [sym_comment] = 40,
        [anon_sym_DOT_DOT] = 80,
        [anon_sym_CARET] = 80,
        [anon_sym_LT_EQ_GT] = 80,
        [anon_sym_EQ_EQ] = 80,
        [anon_sym_EQ_EQ_EQ] = 80,
        [anon_sym_EQ_TILDE] = 80,
        [anon_sym_GT] = 80,
        [anon_sym_GT_EQ] = 80,
        [anon_sym_LT_EQ] = 80,
        [anon_sym_PLUS] = 80,
        [anon_sym_DASH] = 80,
        [anon_sym_SLASH] = 80,
        [anon_sym_PERCENT] = 80,
        [anon_sym_STAR_STAR] = 80,
        [anon_sym_LT_LT] = 80,
        [anon_sym_GT_GT] = 80,
        [anon_sym_TILDE] = 80,
        [anon_sym_PLUS_AT] = 80,
        [anon_sym_DASH_AT] = 80,
        [anon_sym_LBRACK_RBRACK] = 80,
        [anon_sym_LBRACK_RBRACK_EQ] = 80,
        [sym__line_break] = 40,
    },
    [58] = {
        [sym__function_name] = 256,
        [anon_sym_PIPE] = 84,
        [anon_sym_STAR] = 84,
        [anon_sym_AMP] = 84,
        [anon_sym_LT] = 84,
        [sym_identifier] = 84,
        [sym_comment] = 40,
        [anon_sym_DOT_DOT] = 84,
        [anon_sym_CARET] = 84,
        [anon_sym_LT_EQ_GT] = 84,
        [anon_sym_EQ_EQ] = 84,
        [anon_sym_EQ_EQ_EQ] = 84,
        [anon_sym_EQ_TILDE] = 84,
        [anon_sym_GT] = 84,
        [anon_sym_GT_EQ] = 84,
        [anon_sym_LT_EQ] = 84,
        [anon_sym_PLUS] = 84,
        [anon_sym_DASH] = 84,
        [anon_sym_SLASH] = 84,
        [anon_sym_PERCENT] = 84,
        [anon_sym_STAR_STAR] = 84,
        [anon_sym_LT_LT] = 84,
        [anon_sym_GT_GT] = 84,
        [anon_sym_TILDE] = 84,
        [anon_sym_PLUS_AT] = 84,
        [anon_sym_DASH_AT] = 84,
        [anon_sym_LBRACK_RBRACK] = 84,
        [anon_sym_LBRACK_RBRACK_EQ] = 84,
        [sym__line_break] = 40,
    },
    [59] = {
        [sym__statement] = 258,
        [sym__declaration] = 88,
        [sym_method_declaration] = 90,
        [sym_class_declaration] = 90,
        [sym_module_declaration] = 90,
        [sym__call] = 92,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 88,
        [sym__argument] = 94,
        [sym__primary] = 96,
        [sym_scope_resolution_expression] = 98,
        [sym__variable] = 98,
        [anon_sym_undef] = 100,
        [anon_sym_alias] = 102,
        [anon_sym_def] = 104,
        [anon_sym_LPAREN] = 106,
        [anon_sym_class] = 108,
        [anon_sym_COLON_COLON] = 110,
        [anon_sym_module] = 112,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 114,
        [anon_sym_self] = 114,
        [sym_identifier] = 114,
        [sym_comment] = 40,
        [sym_symbol] = 94,
        [sym__line_break] = 40,
    },
    [60] = {
        [sym_identifier] = 260,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [61] = {
        [sym_identifier] = 262,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [62] = {
        [sym_identifier] = 264,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [63] = {
        [sym__terminator] = 142,
        [aux_sym_program_repeat1] = 142,
        [anon_sym_end] = 142,
        [anon_sym_if] = 142,
        [anon_sym_while] = 142,
        [anon_sym_unless] = 142,
        [anon_sym_until] = 142,
        [anon_sym_COLON_COLON] = 142,
        [anon_sym_LBRACK] = 142,
        [sym_comment] = 40,
        [sym__line_break] = 142,
        [anon_sym_SEMI] = 142,
    },
    [64] = {
        [sym__terminator] = 266,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [65] = {
        [sym__statement] = 268,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 270,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [66] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 272,
        [anon_sym_end] = 274,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [67] = {
        [sym__terminator] = 248,
        [aux_sym_program_repeat1] = 248,
        [anon_sym_end] = 248,
        [anon_sym_if] = 248,
        [anon_sym_while] = 248,
        [anon_sym_unless] = 248,
        [anon_sym_until] = 248,
        [sym_comment] = 40,
        [sym__line_break] = 248,
        [anon_sym_SEMI] = 248,
    },
    [68] = {
        [sym__statement] = 276,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [69] = {
        [anon_sym_end] = 278,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [70] = {
        [sym__terminator] = 280,
        [aux_sym_program_repeat1] = 280,
        [anon_sym_end] = 280,
        [anon_sym_if] = 280,
        [anon_sym_while] = 280,
        [anon_sym_unless] = 280,
        [anon_sym_until] = 280,
        [sym_comment] = 40,
        [sym__line_break] = 280,
        [anon_sym_SEMI] = 280,
    },
    [71] = {
        [sym__expression] = 282,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_LPAREN] = 220,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [72] = {
        [sym__statement] = 230,
        [sym__declaration] = 230,
        [sym_method_declaration] = 230,
        [sym_class_declaration] = 230,
        [sym_module_declaration] = 230,
        [sym__call] = 230,
        [sym__command] = 230,
        [sym__function_call] = 230,
        [sym__expression] = 230,
        [sym__argument] = 230,
        [sym__primary] = 230,
        [sym_scope_resolution_expression] = 230,
        [sym__variable] = 230,
        [sym__terminator] = 232,
        [aux_sym_program_repeat1] = 232,
        [ts_builtin_sym_end] = 232,
        [anon_sym_end] = 232,
        [anon_sym_undef] = 230,
        [anon_sym_alias] = 230,
        [anon_sym_if] = 232,
        [anon_sym_while] = 232,
        [anon_sym_unless] = 232,
        [anon_sym_until] = 232,
        [anon_sym_def] = 230,
        [anon_sym_LPAREN] = 230,
        [anon_sym_RPAREN] = 232,
        [anon_sym_class] = 230,
        [anon_sym_COLON_COLON] = 230,
        [anon_sym_module] = 230,
        [anon_sym_super] = 230,
        [anon_sym_nil] = 230,
        [anon_sym_self] = 230,
        [sym_identifier] = 230,
        [sym_comment] = 40,
        [sym_symbol] = 230,
        [sym__line_break] = 40,
        [anon_sym_SEMI] = 232,
    },
    [73] = {
        [sym__statement] = 230,
        [sym__declaration] = 230,
        [sym_method_declaration] = 230,
        [sym_class_declaration] = 230,
        [sym_module_declaration] = 230,
        [sym__call] = 230,
        [sym__command] = 230,
        [sym__function_call] = 230,
        [sym__expression] = 230,
        [sym__argument] = 230,
        [sym__primary] = 230,
        [sym_scope_resolution_expression] = 230,
        [sym__variable] = 230,
        [anon_sym_undef] = 230,
        [anon_sym_alias] = 230,
        [anon_sym_def] = 230,
        [anon_sym_LPAREN] = 230,
        [anon_sym_class] = 230,
        [anon_sym_COLON_COLON] = 230,
        [anon_sym_module] = 230,
        [anon_sym_super] = 230,
        [anon_sym_nil] = 230,
        [anon_sym_self] = 230,
        [sym_identifier] = 230,
        [sym_comment] = 40,
        [sym_symbol] = 230,
        [sym__line_break] = 40,
    },
    [74] = {
        [sym__terminator] = 284,
        [aux_sym_program_repeat1] = 284,
        [anon_sym_end] = 284,
        [anon_sym_if] = 284,
        [anon_sym_while] = 284,
        [anon_sym_unless] = 284,
        [anon_sym_until] = 284,
        [sym_comment] = 40,
        [sym__line_break] = 284,
        [anon_sym_SEMI] = 284,
    },
    [75] = {
        [sym__terminator] = 286,
        [aux_sym_program_repeat1] = 286,
        [anon_sym_end] = 286,
        [anon_sym_if] = 286,
        [anon_sym_while] = 286,
        [anon_sym_unless] = 286,
        [anon_sym_until] = 286,
        [sym_comment] = 40,
        [sym__line_break] = 286,
        [anon_sym_SEMI] = 286,
    },
    [76] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 288,
        [anon_sym_end] = 290,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [77] = {
        [anon_sym_end] = 292,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [78] = {
        [sym__terminator] = 160,
        [aux_sym_program_repeat1] = 160,
        [anon_sym_end] = 160,
        [anon_sym_if] = 160,
        [anon_sym_while] = 160,
        [anon_sym_unless] = 160,
        [anon_sym_until] = 160,
        [anon_sym_COLON_COLON] = 160,
        [anon_sym_LBRACK] = 160,
        [sym_comment] = 40,
        [sym__line_break] = 160,
        [anon_sym_SEMI] = 160,
    },
    [79] = {
        [sym__terminator] = 294,
        [anon_sym_LT] = 296,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [80] = {
        [sym__statement] = 298,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 300,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [81] = {
        [sym_identifier] = 302,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [82] = {
        [sym__terminator] = 304,
        [aux_sym_class_declaration_repeat1] = 306,
        [anon_sym_COLON_COLON] = 308,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [83] = {
        [sym__statement] = 310,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 312,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [84] = {
        [sym__terminator] = 314,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [85] = {
        [sym_identifier] = 316,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [86] = {
        [sym__terminator] = 318,
        [aux_sym_class_declaration_repeat1] = 320,
        [anon_sym_COLON_COLON] = 308,
        [sym_comment] = 40,
        [sym__line_break] = 318,
        [anon_sym_SEMI] = 318,
    },
    [87] = {
        [sym__terminator] = 322,
        [sym_comment] = 40,
        [sym__line_break] = 322,
        [anon_sym_SEMI] = 322,
    },
    [88] = {
        [sym__statement] = 324,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 326,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [89] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 328,
        [anon_sym_end] = 330,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [90] = {
        [sym__terminator] = 332,
        [aux_sym_program_repeat1] = 332,
        [anon_sym_end] = 332,
        [anon_sym_if] = 332,
        [anon_sym_while] = 332,
        [anon_sym_unless] = 332,
        [anon_sym_until] = 332,
        [sym_comment] = 40,
        [sym__line_break] = 332,
        [anon_sym_SEMI] = 332,
    },
    [91] = {
        [anon_sym_end] = 334,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [92] = {
        [sym__terminator] = 336,
        [aux_sym_program_repeat1] = 336,
        [anon_sym_end] = 336,
        [anon_sym_if] = 336,
        [anon_sym_while] = 336,
        [anon_sym_unless] = 336,
        [anon_sym_until] = 336,
        [sym_comment] = 40,
        [sym__line_break] = 336,
        [anon_sym_SEMI] = 336,
    },
    [93] = {
        [sym__terminator] = 338,
        [aux_sym_program_repeat1] = 338,
        [anon_sym_end] = 338,
        [anon_sym_if] = 338,
        [anon_sym_while] = 338,
        [anon_sym_unless] = 338,
        [anon_sym_until] = 338,
        [sym_comment] = 40,
        [sym__line_break] = 338,
        [anon_sym_SEMI] = 338,
    },
    [94] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 340,
        [anon_sym_end] = 326,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [95] = {
        [sym__terminator] = 342,
        [aux_sym_program_repeat1] = 342,
        [anon_sym_end] = 342,
        [anon_sym_if] = 342,
        [anon_sym_while] = 342,
        [anon_sym_unless] = 342,
        [anon_sym_until] = 342,
        [sym_comment] = 40,
        [sym__line_break] = 342,
        [anon_sym_SEMI] = 342,
    },
    [96] = {
        [anon_sym_end] = 330,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [97] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 344,
        [anon_sym_end] = 346,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [98] = {
        [sym__terminator] = 348,
        [aux_sym_program_repeat1] = 348,
        [anon_sym_end] = 348,
        [anon_sym_if] = 348,
        [anon_sym_while] = 348,
        [anon_sym_unless] = 348,
        [anon_sym_until] = 348,
        [sym_comment] = 40,
        [sym__line_break] = 348,
        [anon_sym_SEMI] = 348,
    },
    [99] = {
        [anon_sym_end] = 312,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [100] = {
        [sym__terminator] = 350,
        [aux_sym_program_repeat1] = 350,
        [anon_sym_end] = 350,
        [anon_sym_if] = 350,
        [anon_sym_while] = 350,
        [anon_sym_unless] = 350,
        [anon_sym_until] = 350,
        [sym_comment] = 40,
        [sym__line_break] = 350,
        [anon_sym_SEMI] = 350,
    },
    [101] = {
        [sym__terminator] = 162,
        [aux_sym_program_repeat1] = 352,
        [anon_sym_if] = 166,
        [anon_sym_while] = 166,
        [anon_sym_unless] = 166,
        [anon_sym_until] = 166,
        [anon_sym_RPAREN] = 354,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [102] = {
        [sym__statement] = 356,
        [sym__declaration] = 88,
        [sym_method_declaration] = 90,
        [sym_class_declaration] = 90,
        [sym_module_declaration] = 90,
        [sym__call] = 92,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 88,
        [sym__argument] = 94,
        [sym__primary] = 96,
        [sym_scope_resolution_expression] = 98,
        [sym__variable] = 98,
        [anon_sym_undef] = 100,
        [anon_sym_alias] = 102,
        [anon_sym_def] = 104,
        [anon_sym_LPAREN] = 106,
        [anon_sym_class] = 108,
        [anon_sym_COLON_COLON] = 110,
        [anon_sym_module] = 112,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 114,
        [anon_sym_self] = 114,
        [sym_identifier] = 114,
        [sym_comment] = 40,
        [sym_symbol] = 94,
        [sym__line_break] = 40,
    },
    [103] = {
        [anon_sym_RPAREN] = 358,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [104] = {
        [sym__expression] = 360,
        [sym__argument] = 94,
        [sym__primary] = 96,
        [sym_scope_resolution_expression] = 98,
        [sym__variable] = 98,
        [anon_sym_LPAREN] = 106,
        [anon_sym_COLON_COLON] = 110,
        [anon_sym_nil] = 114,
        [anon_sym_self] = 114,
        [sym_identifier] = 114,
        [sym_comment] = 40,
        [sym_symbol] = 94,
        [sym__line_break] = 40,
    },
    [105] = {
        [sym__terminator] = 362,
        [aux_sym_program_repeat1] = 362,
        [anon_sym_end] = 362,
        [anon_sym_if] = 362,
        [anon_sym_while] = 362,
        [anon_sym_unless] = 362,
        [anon_sym_until] = 362,
        [anon_sym_COLON_COLON] = 362,
        [anon_sym_LBRACK] = 362,
        [sym_comment] = 40,
        [sym__line_break] = 362,
        [anon_sym_SEMI] = 362,
    },
    [106] = {
        [sym__terminator] = 284,
        [aux_sym_program_repeat1] = 284,
        [anon_sym_if] = 284,
        [anon_sym_while] = 284,
        [anon_sym_unless] = 284,
        [anon_sym_until] = 284,
        [anon_sym_RPAREN] = 284,
        [sym_comment] = 40,
        [sym__line_break] = 284,
        [anon_sym_SEMI] = 284,
    },
    [107] = {
        [sym__terminator] = 364,
        [aux_sym_program_repeat1] = 364,
        [anon_sym_end] = 364,
        [anon_sym_if] = 364,
        [anon_sym_while] = 364,
        [anon_sym_unless] = 364,
        [anon_sym_until] = 364,
        [anon_sym_COLON_COLON] = 364,
        [anon_sym_LBRACK] = 364,
        [sym_comment] = 40,
        [sym__line_break] = 364,
        [anon_sym_SEMI] = 364,
    },
    [108] = {
        [sym__terminator] = 162,
        [aux_sym_program_repeat1] = 366,
        [anon_sym_if] = 166,
        [anon_sym_while] = 166,
        [anon_sym_unless] = 166,
        [anon_sym_until] = 166,
        [anon_sym_RPAREN] = 290,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [109] = {
        [anon_sym_RPAREN] = 292,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [110] = {
        [sym_argument_list] = 368,
        [sym__terminator] = 370,
        [anon_sym_LPAREN] = 372,
        [anon_sym_STAR] = 374,
        [anon_sym_AMP] = 374,
        [sym_identifier] = 376,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [111] = {
        [sym_argument_list] = 378,
        [sym__terminator] = 378,
        [anon_sym_LPAREN] = 378,
        [anon_sym_STAR] = 378,
        [anon_sym_AMP] = 378,
        [sym_identifier] = 378,
        [sym_comment] = 40,
        [sym__line_break] = 378,
        [anon_sym_SEMI] = 378,
    },
    [112] = {
        [sym__terminator] = 380,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [113] = {
        [sym__statement] = 382,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 384,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [114] = {
        [sym_argument_list] = 386,
        [anon_sym_RPAREN] = 380,
        [anon_sym_STAR] = 388,
        [anon_sym_AMP] = 388,
        [sym_identifier] = 390,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [115] = {
        [sym_identifier] = 392,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [116] = {
        [sym__terminator] = 394,
        [aux_sym_argument_list_repeat1] = 396,
        [anon_sym_COMMA] = 398,
        [sym_comment] = 40,
        [sym__line_break] = 394,
        [anon_sym_SEMI] = 394,
    },
    [117] = {
        [sym__terminator] = 400,
        [sym_comment] = 40,
        [sym__line_break] = 400,
        [anon_sym_SEMI] = 400,
    },
    [118] = {
        [anon_sym_STAR] = 402,
        [anon_sym_AMP] = 402,
        [sym_identifier] = 404,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [119] = {
        [sym_identifier] = 406,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [120] = {
        [sym__terminator] = 408,
        [aux_sym_argument_list_repeat1] = 410,
        [anon_sym_COMMA] = 398,
        [sym_comment] = 40,
        [sym__line_break] = 408,
        [anon_sym_SEMI] = 408,
    },
    [121] = {
        [sym__terminator] = 412,
        [sym_comment] = 40,
        [sym__line_break] = 412,
        [anon_sym_SEMI] = 412,
    },
    [122] = {
        [sym__terminator] = 412,
        [aux_sym_argument_list_repeat1] = 414,
        [anon_sym_COMMA] = 398,
        [sym_comment] = 40,
        [sym__line_break] = 412,
        [anon_sym_SEMI] = 412,
    },
    [123] = {
        [sym__terminator] = 416,
        [sym_comment] = 40,
        [sym__line_break] = 416,
        [anon_sym_SEMI] = 416,
    },
    [124] = {
        [sym__terminator] = 400,
        [aux_sym_argument_list_repeat1] = 418,
        [anon_sym_COMMA] = 398,
        [sym_comment] = 40,
        [sym__line_break] = 400,
        [anon_sym_SEMI] = 400,
    },
    [125] = {
        [sym__terminator] = 420,
        [sym_comment] = 40,
        [sym__line_break] = 420,
        [anon_sym_SEMI] = 420,
    },
    [126] = {
        [anon_sym_RPAREN] = 422,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [127] = {
        [sym__statement] = 424,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 426,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [128] = {
        [sym_identifier] = 428,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [129] = {
        [aux_sym_argument_list_repeat1] = 430,
        [anon_sym_RPAREN] = 394,
        [anon_sym_COMMA] = 432,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [130] = {
        [anon_sym_RPAREN] = 400,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [131] = {
        [anon_sym_STAR] = 434,
        [anon_sym_AMP] = 434,
        [sym_identifier] = 436,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [132] = {
        [sym_identifier] = 438,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [133] = {
        [aux_sym_argument_list_repeat1] = 440,
        [anon_sym_RPAREN] = 408,
        [anon_sym_COMMA] = 432,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [134] = {
        [anon_sym_RPAREN] = 412,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [135] = {
        [aux_sym_argument_list_repeat1] = 442,
        [anon_sym_RPAREN] = 412,
        [anon_sym_COMMA] = 432,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [136] = {
        [anon_sym_RPAREN] = 416,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [137] = {
        [aux_sym_argument_list_repeat1] = 444,
        [anon_sym_RPAREN] = 400,
        [anon_sym_COMMA] = 432,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [138] = {
        [anon_sym_RPAREN] = 420,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [139] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 446,
        [anon_sym_end] = 448,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [140] = {
        [sym__terminator] = 450,
        [aux_sym_program_repeat1] = 450,
        [anon_sym_end] = 450,
        [anon_sym_if] = 450,
        [anon_sym_while] = 450,
        [anon_sym_unless] = 450,
        [anon_sym_until] = 450,
        [sym_comment] = 40,
        [sym__line_break] = 450,
        [anon_sym_SEMI] = 450,
    },
    [141] = {
        [anon_sym_end] = 452,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [142] = {
        [sym__terminator] = 454,
        [aux_sym_program_repeat1] = 454,
        [anon_sym_end] = 454,
        [anon_sym_if] = 454,
        [anon_sym_while] = 454,
        [anon_sym_unless] = 454,
        [anon_sym_until] = 454,
        [sym_comment] = 40,
        [sym__line_break] = 454,
        [anon_sym_SEMI] = 454,
    },
    [143] = {
        [sym__terminator] = 456,
        [aux_sym_program_repeat1] = 456,
        [anon_sym_end] = 456,
        [anon_sym_if] = 456,
        [anon_sym_while] = 456,
        [anon_sym_unless] = 456,
        [anon_sym_until] = 456,
        [sym_comment] = 40,
        [sym__line_break] = 456,
        [anon_sym_SEMI] = 456,
    },
    [144] = {
        [sym__statement] = 458,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 448,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [145] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 460,
        [anon_sym_end] = 452,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [146] = {
        [anon_sym_end] = 462,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [147] = {
        [sym__terminator] = 464,
        [aux_sym_program_repeat1] = 464,
        [anon_sym_end] = 464,
        [anon_sym_if] = 464,
        [anon_sym_while] = 464,
        [anon_sym_unless] = 464,
        [anon_sym_until] = 464,
        [sym_comment] = 40,
        [sym__line_break] = 464,
        [anon_sym_SEMI] = 464,
    },
    [148] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 466,
        [anon_sym_end] = 426,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [149] = {
        [sym__terminator] = 468,
        [aux_sym_program_repeat1] = 468,
        [anon_sym_end] = 468,
        [anon_sym_if] = 468,
        [anon_sym_while] = 468,
        [anon_sym_unless] = 468,
        [anon_sym_until] = 468,
        [sym_comment] = 40,
        [sym__line_break] = 468,
        [anon_sym_SEMI] = 468,
    },
    [150] = {
        [anon_sym_end] = 448,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [151] = {
        [sym__function_name] = 282,
        [anon_sym_PIPE] = 252,
        [anon_sym_STAR] = 252,
        [anon_sym_AMP] = 252,
        [anon_sym_LT] = 252,
        [sym_identifier] = 252,
        [sym_comment] = 40,
        [anon_sym_DOT_DOT] = 252,
        [anon_sym_CARET] = 252,
        [anon_sym_LT_EQ_GT] = 252,
        [anon_sym_EQ_EQ] = 252,
        [anon_sym_EQ_EQ_EQ] = 252,
        [anon_sym_EQ_TILDE] = 252,
        [anon_sym_GT] = 252,
        [anon_sym_GT_EQ] = 252,
        [anon_sym_LT_EQ] = 252,
        [anon_sym_PLUS] = 252,
        [anon_sym_DASH] = 252,
        [anon_sym_SLASH] = 252,
        [anon_sym_PERCENT] = 252,
        [anon_sym_STAR_STAR] = 252,
        [anon_sym_LT_LT] = 252,
        [anon_sym_GT_GT] = 252,
        [anon_sym_TILDE] = 252,
        [anon_sym_PLUS_AT] = 252,
        [anon_sym_DASH_AT] = 252,
        [anon_sym_LBRACK_RBRACK] = 252,
        [anon_sym_LBRACK_RBRACK_EQ] = 252,
        [sym__line_break] = 40,
    },
    [152] = {
        [sym__function_name] = 378,
        [anon_sym_PIPE] = 378,
        [anon_sym_STAR] = 378,
        [anon_sym_AMP] = 378,
        [anon_sym_LT] = 378,
        [sym_identifier] = 378,
        [sym_comment] = 40,
        [anon_sym_DOT_DOT] = 378,
        [anon_sym_CARET] = 378,
        [anon_sym_LT_EQ_GT] = 378,
        [anon_sym_EQ_EQ] = 378,
        [anon_sym_EQ_EQ_EQ] = 378,
        [anon_sym_EQ_TILDE] = 378,
        [anon_sym_GT] = 378,
        [anon_sym_GT_EQ] = 378,
        [anon_sym_LT_EQ] = 378,
        [anon_sym_PLUS] = 378,
        [anon_sym_DASH] = 378,
        [anon_sym_SLASH] = 378,
        [anon_sym_PERCENT] = 378,
        [anon_sym_STAR_STAR] = 378,
        [anon_sym_LT_LT] = 378,
        [anon_sym_GT_GT] = 378,
        [anon_sym_TILDE] = 378,
        [anon_sym_PLUS_AT] = 378,
        [anon_sym_DASH_AT] = 378,
        [anon_sym_LBRACK_RBRACK] = 378,
        [anon_sym_LBRACK_RBRACK_EQ] = 378,
        [sym__line_break] = 40,
    },
    [153] = {
        [sym__terminator] = 378,
        [aux_sym_program_repeat1] = 378,
        [anon_sym_end] = 378,
        [anon_sym_if] = 378,
        [anon_sym_while] = 378,
        [anon_sym_unless] = 378,
        [anon_sym_until] = 378,
        [sym_comment] = 40,
        [sym__line_break] = 378,
        [anon_sym_SEMI] = 378,
    },
    [154] = {
        [sym__terminator] = 470,
        [aux_sym_program_repeat1] = 470,
        [anon_sym_end] = 470,
        [anon_sym_if] = 470,
        [anon_sym_while] = 470,
        [anon_sym_unless] = 470,
        [anon_sym_until] = 470,
        [sym_comment] = 40,
        [sym__line_break] = 470,
        [anon_sym_SEMI] = 470,
    },
    [155] = {
        [sym_identifier] = 472,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [156] = {
        [sym__argument] = 474,
        [sym__primary] = 476,
        [sym_scope_resolution_expression] = 478,
        [sym__variable] = 478,
        [anon_sym_LPAREN] = 480,
        [anon_sym_COLON_COLON] = 482,
        [anon_sym_RBRACK] = 354,
        [anon_sym_nil] = 484,
        [anon_sym_self] = 484,
        [sym_identifier] = 484,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [157] = {
        [aux_sym__call_arguments_repeat1] = 486,
        [anon_sym_COMMA] = 488,
        [anon_sym_RBRACK] = 358,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [158] = {
        [aux_sym__call_arguments_repeat1] = 66,
        [anon_sym_COMMA] = 66,
        [anon_sym_COLON_COLON] = 490,
        [anon_sym_LBRACK] = 492,
        [anon_sym_RBRACK] = 66,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [159] = {
        [aux_sym__call_arguments_repeat1] = 72,
        [anon_sym_COMMA] = 72,
        [anon_sym_COLON_COLON] = 72,
        [anon_sym_LBRACK] = 72,
        [anon_sym_RBRACK] = 72,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [160] = {
        [sym__statement] = 494,
        [sym__declaration] = 88,
        [sym_method_declaration] = 90,
        [sym_class_declaration] = 90,
        [sym_module_declaration] = 90,
        [sym__call] = 92,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 88,
        [sym__argument] = 94,
        [sym__primary] = 96,
        [sym_scope_resolution_expression] = 98,
        [sym__variable] = 98,
        [anon_sym_undef] = 100,
        [anon_sym_alias] = 102,
        [anon_sym_def] = 104,
        [anon_sym_LPAREN] = 106,
        [anon_sym_class] = 108,
        [anon_sym_COLON_COLON] = 110,
        [anon_sym_module] = 112,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 114,
        [anon_sym_self] = 114,
        [sym_identifier] = 114,
        [sym_comment] = 40,
        [sym_symbol] = 94,
        [sym__line_break] = 40,
    },
    [161] = {
        [sym_identifier] = 496,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [162] = {
        [aux_sym__call_arguments_repeat1] = 142,
        [anon_sym_COMMA] = 142,
        [anon_sym_COLON_COLON] = 142,
        [anon_sym_LBRACK] = 142,
        [anon_sym_RBRACK] = 142,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [163] = {
        [aux_sym__call_arguments_repeat1] = 160,
        [anon_sym_COMMA] = 160,
        [anon_sym_COLON_COLON] = 160,
        [anon_sym_LBRACK] = 160,
        [anon_sym_RBRACK] = 160,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [164] = {
        [sym__terminator] = 162,
        [aux_sym_program_repeat1] = 498,
        [anon_sym_if] = 166,
        [anon_sym_while] = 166,
        [anon_sym_unless] = 166,
        [anon_sym_until] = 166,
        [anon_sym_RPAREN] = 500,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [165] = {
        [anon_sym_RPAREN] = 502,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [166] = {
        [aux_sym__call_arguments_repeat1] = 362,
        [anon_sym_COMMA] = 362,
        [anon_sym_COLON_COLON] = 362,
        [anon_sym_LBRACK] = 362,
        [anon_sym_RBRACK] = 362,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [167] = {
        [aux_sym__call_arguments_repeat1] = 364,
        [anon_sym_COMMA] = 364,
        [anon_sym_COLON_COLON] = 364,
        [anon_sym_LBRACK] = 364,
        [anon_sym_RBRACK] = 364,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [168] = {
        [sym_identifier] = 504,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [169] = {
        [sym__argument] = 506,
        [sym__primary] = 476,
        [sym_scope_resolution_expression] = 478,
        [sym__variable] = 478,
        [anon_sym_LPAREN] = 480,
        [anon_sym_COLON_COLON] = 482,
        [anon_sym_RBRACK] = 500,
        [anon_sym_nil] = 484,
        [anon_sym_self] = 484,
        [sym_identifier] = 484,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [170] = {
        [aux_sym__call_arguments_repeat1] = 508,
        [anon_sym_COMMA] = 488,
        [anon_sym_RBRACK] = 502,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [171] = {
        [anon_sym_RBRACK] = 510,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [172] = {
        [sym__argument] = 512,
        [sym__primary] = 476,
        [sym_scope_resolution_expression] = 478,
        [sym__variable] = 478,
        [anon_sym_LPAREN] = 480,
        [anon_sym_COLON_COLON] = 482,
        [anon_sym_nil] = 484,
        [anon_sym_self] = 484,
        [sym_identifier] = 484,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [173] = {
        [aux_sym__call_arguments_repeat1] = 514,
        [anon_sym_COMMA] = 488,
        [anon_sym_RBRACK] = 516,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [174] = {
        [anon_sym_RBRACK] = 518,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [175] = {
        [aux_sym__call_arguments_repeat1] = 520,
        [anon_sym_COMMA] = 520,
        [anon_sym_COLON_COLON] = 520,
        [anon_sym_LBRACK] = 520,
        [anon_sym_RBRACK] = 520,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [176] = {
        [aux_sym__call_arguments_repeat1] = 522,
        [anon_sym_COMMA] = 522,
        [anon_sym_COLON_COLON] = 522,
        [anon_sym_LBRACK] = 522,
        [anon_sym_RBRACK] = 522,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [177] = {
        [anon_sym_RBRACK] = 524,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [178] = {
        [sym__terminator] = 520,
        [aux_sym_program_repeat1] = 520,
        [anon_sym_end] = 520,
        [anon_sym_if] = 520,
        [anon_sym_while] = 520,
        [anon_sym_unless] = 520,
        [anon_sym_until] = 520,
        [anon_sym_COLON_COLON] = 520,
        [anon_sym_LBRACK] = 520,
        [sym_comment] = 40,
        [sym__line_break] = 520,
        [anon_sym_SEMI] = 520,
    },
    [179] = {
        [sym__terminator] = 522,
        [aux_sym_program_repeat1] = 522,
        [anon_sym_end] = 522,
        [anon_sym_if] = 522,
        [anon_sym_while] = 522,
        [anon_sym_unless] = 522,
        [anon_sym_until] = 522,
        [anon_sym_COLON_COLON] = 522,
        [anon_sym_LBRACK] = 522,
        [sym_comment] = 40,
        [sym__line_break] = 522,
        [anon_sym_SEMI] = 522,
    },
    [180] = {
        [sym__statement] = 526,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_PIPE] = 528,
        [anon_sym_end] = 282,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [181] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 530,
        [anon_sym_end] = 532,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [182] = {
        [sym__statement] = 534,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 532,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [183] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 536,
        [anon_sym_end] = 538,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [184] = {
        [sym__terminator] = 540,
        [aux_sym_program_repeat1] = 540,
        [anon_sym_end] = 540,
        [anon_sym_if] = 540,
        [anon_sym_while] = 540,
        [anon_sym_unless] = 540,
        [anon_sym_until] = 540,
        [sym_comment] = 40,
        [sym__line_break] = 540,
        [anon_sym_SEMI] = 540,
    },
    [185] = {
        [anon_sym_end] = 542,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [186] = {
        [sym__terminator] = 544,
        [aux_sym_program_repeat1] = 544,
        [anon_sym_end] = 544,
        [anon_sym_if] = 544,
        [anon_sym_while] = 544,
        [anon_sym_unless] = 544,
        [anon_sym_until] = 544,
        [sym_comment] = 40,
        [sym__line_break] = 544,
        [anon_sym_SEMI] = 544,
    },
    [187] = {
        [sym__terminator] = 546,
        [aux_sym_program_repeat1] = 546,
        [anon_sym_end] = 546,
        [anon_sym_if] = 546,
        [anon_sym_while] = 546,
        [anon_sym_unless] = 546,
        [anon_sym_until] = 546,
        [sym_comment] = 40,
        [sym__line_break] = 546,
        [anon_sym_SEMI] = 546,
    },
    [188] = {
        [anon_sym_end] = 538,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [189] = {
        [anon_sym_end] = 548,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [190] = {
        [sym__terminator] = 280,
        [aux_sym_program_repeat1] = 280,
        [anon_sym_if] = 280,
        [anon_sym_while] = 280,
        [anon_sym_unless] = 280,
        [anon_sym_until] = 280,
        [anon_sym_RPAREN] = 280,
        [sym_comment] = 40,
        [sym__line_break] = 280,
        [anon_sym_SEMI] = 280,
    },
    [191] = {
        [sym__terminator] = 286,
        [aux_sym_program_repeat1] = 286,
        [anon_sym_if] = 286,
        [anon_sym_while] = 286,
        [anon_sym_unless] = 286,
        [anon_sym_until] = 286,
        [anon_sym_RPAREN] = 286,
        [sym_comment] = 40,
        [sym__line_break] = 286,
        [anon_sym_SEMI] = 286,
    },
    [192] = {
        [sym__terminator] = 160,
        [aux_sym_program_repeat1] = 160,
        [anon_sym_if] = 160,
        [anon_sym_while] = 160,
        [anon_sym_unless] = 160,
        [anon_sym_until] = 160,
        [anon_sym_RPAREN] = 160,
        [anon_sym_COLON_COLON] = 160,
        [anon_sym_LBRACK] = 160,
        [sym_comment] = 40,
        [sym__line_break] = 160,
        [anon_sym_SEMI] = 160,
    },
    [193] = {
        [sym__terminator] = 550,
        [anon_sym_LT] = 552,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [194] = {
        [sym__statement] = 554,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 556,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [195] = {
        [sym_identifier] = 558,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [196] = {
        [sym__terminator] = 560,
        [aux_sym_class_declaration_repeat1] = 562,
        [anon_sym_COLON_COLON] = 308,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [197] = {
        [sym__statement] = 564,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 566,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [198] = {
        [sym__terminator] = 568,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [199] = {
        [sym__statement] = 570,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 572,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [200] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 574,
        [anon_sym_end] = 576,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [201] = {
        [sym__terminator] = 332,
        [aux_sym_program_repeat1] = 332,
        [anon_sym_if] = 332,
        [anon_sym_while] = 332,
        [anon_sym_unless] = 332,
        [anon_sym_until] = 332,
        [anon_sym_RPAREN] = 332,
        [sym_comment] = 40,
        [sym__line_break] = 332,
        [anon_sym_SEMI] = 332,
    },
    [202] = {
        [anon_sym_end] = 578,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [203] = {
        [sym__terminator] = 336,
        [aux_sym_program_repeat1] = 336,
        [anon_sym_if] = 336,
        [anon_sym_while] = 336,
        [anon_sym_unless] = 336,
        [anon_sym_until] = 336,
        [anon_sym_RPAREN] = 336,
        [sym_comment] = 40,
        [sym__line_break] = 336,
        [anon_sym_SEMI] = 336,
    },
    [204] = {
        [sym__terminator] = 338,
        [aux_sym_program_repeat1] = 338,
        [anon_sym_if] = 338,
        [anon_sym_while] = 338,
        [anon_sym_unless] = 338,
        [anon_sym_until] = 338,
        [anon_sym_RPAREN] = 338,
        [sym_comment] = 40,
        [sym__line_break] = 338,
        [anon_sym_SEMI] = 338,
    },
    [205] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 580,
        [anon_sym_end] = 572,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [206] = {
        [sym__terminator] = 342,
        [aux_sym_program_repeat1] = 342,
        [anon_sym_if] = 342,
        [anon_sym_while] = 342,
        [anon_sym_unless] = 342,
        [anon_sym_until] = 342,
        [anon_sym_RPAREN] = 342,
        [sym_comment] = 40,
        [sym__line_break] = 342,
        [anon_sym_SEMI] = 342,
    },
    [207] = {
        [anon_sym_end] = 576,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [208] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 582,
        [anon_sym_end] = 584,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [209] = {
        [sym__terminator] = 348,
        [aux_sym_program_repeat1] = 348,
        [anon_sym_if] = 348,
        [anon_sym_while] = 348,
        [anon_sym_unless] = 348,
        [anon_sym_until] = 348,
        [anon_sym_RPAREN] = 348,
        [sym_comment] = 40,
        [sym__line_break] = 348,
        [anon_sym_SEMI] = 348,
    },
    [210] = {
        [anon_sym_end] = 566,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [211] = {
        [sym__terminator] = 350,
        [aux_sym_program_repeat1] = 350,
        [anon_sym_if] = 350,
        [anon_sym_while] = 350,
        [anon_sym_unless] = 350,
        [anon_sym_until] = 350,
        [anon_sym_RPAREN] = 350,
        [sym_comment] = 40,
        [sym__line_break] = 350,
        [anon_sym_SEMI] = 350,
    },
    [212] = {
        [sym__terminator] = 162,
        [aux_sym_program_repeat1] = 586,
        [anon_sym_if] = 166,
        [anon_sym_while] = 166,
        [anon_sym_unless] = 166,
        [anon_sym_until] = 166,
        [anon_sym_RPAREN] = 588,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [213] = {
        [anon_sym_RPAREN] = 590,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [214] = {
        [sym__terminator] = 362,
        [aux_sym_program_repeat1] = 362,
        [anon_sym_if] = 362,
        [anon_sym_while] = 362,
        [anon_sym_unless] = 362,
        [anon_sym_until] = 362,
        [anon_sym_RPAREN] = 362,
        [anon_sym_COLON_COLON] = 362,
        [anon_sym_LBRACK] = 362,
        [sym_comment] = 40,
        [sym__line_break] = 362,
        [anon_sym_SEMI] = 362,
    },
    [215] = {
        [sym__terminator] = 364,
        [aux_sym_program_repeat1] = 364,
        [anon_sym_if] = 364,
        [anon_sym_while] = 364,
        [anon_sym_unless] = 364,
        [anon_sym_until] = 364,
        [anon_sym_RPAREN] = 364,
        [anon_sym_COLON_COLON] = 364,
        [anon_sym_LBRACK] = 364,
        [sym_comment] = 40,
        [sym__line_break] = 364,
        [anon_sym_SEMI] = 364,
    },
    [216] = {
        [sym_argument_list] = 592,
        [sym__terminator] = 594,
        [anon_sym_LPAREN] = 596,
        [anon_sym_STAR] = 374,
        [anon_sym_AMP] = 374,
        [sym_identifier] = 376,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [217] = {
        [sym__terminator] = 598,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [218] = {
        [sym__statement] = 600,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 602,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [219] = {
        [sym_argument_list] = 604,
        [anon_sym_RPAREN] = 598,
        [anon_sym_STAR] = 388,
        [anon_sym_AMP] = 388,
        [sym_identifier] = 390,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [220] = {
        [anon_sym_RPAREN] = 606,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [221] = {
        [sym__statement] = 608,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 610,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [222] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 612,
        [anon_sym_end] = 614,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [223] = {
        [sym__terminator] = 450,
        [aux_sym_program_repeat1] = 450,
        [anon_sym_if] = 450,
        [anon_sym_while] = 450,
        [anon_sym_unless] = 450,
        [anon_sym_until] = 450,
        [anon_sym_RPAREN] = 450,
        [sym_comment] = 40,
        [sym__line_break] = 450,
        [anon_sym_SEMI] = 450,
    },
    [224] = {
        [anon_sym_end] = 616,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [225] = {
        [sym__terminator] = 454,
        [aux_sym_program_repeat1] = 454,
        [anon_sym_if] = 454,
        [anon_sym_while] = 454,
        [anon_sym_unless] = 454,
        [anon_sym_until] = 454,
        [anon_sym_RPAREN] = 454,
        [sym_comment] = 40,
        [sym__line_break] = 454,
        [anon_sym_SEMI] = 454,
    },
    [226] = {
        [sym__terminator] = 456,
        [aux_sym_program_repeat1] = 456,
        [anon_sym_if] = 456,
        [anon_sym_while] = 456,
        [anon_sym_unless] = 456,
        [anon_sym_until] = 456,
        [anon_sym_RPAREN] = 456,
        [sym_comment] = 40,
        [sym__line_break] = 456,
        [anon_sym_SEMI] = 456,
    },
    [227] = {
        [sym__statement] = 618,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 614,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [228] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 620,
        [anon_sym_end] = 616,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [229] = {
        [anon_sym_end] = 622,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [230] = {
        [sym__terminator] = 464,
        [aux_sym_program_repeat1] = 464,
        [anon_sym_if] = 464,
        [anon_sym_while] = 464,
        [anon_sym_unless] = 464,
        [anon_sym_until] = 464,
        [anon_sym_RPAREN] = 464,
        [sym_comment] = 40,
        [sym__line_break] = 464,
        [anon_sym_SEMI] = 464,
    },
    [231] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 624,
        [anon_sym_end] = 610,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [232] = {
        [sym__terminator] = 468,
        [aux_sym_program_repeat1] = 468,
        [anon_sym_if] = 468,
        [anon_sym_while] = 468,
        [anon_sym_unless] = 468,
        [anon_sym_until] = 468,
        [anon_sym_RPAREN] = 468,
        [sym_comment] = 40,
        [sym__line_break] = 468,
        [anon_sym_SEMI] = 468,
    },
    [233] = {
        [anon_sym_end] = 614,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [234] = {
        [sym__function_name] = 360,
        [anon_sym_PIPE] = 178,
        [anon_sym_STAR] = 178,
        [anon_sym_AMP] = 178,
        [anon_sym_LT] = 178,
        [sym_identifier] = 178,
        [sym_comment] = 40,
        [anon_sym_DOT_DOT] = 178,
        [anon_sym_CARET] = 178,
        [anon_sym_LT_EQ_GT] = 178,
        [anon_sym_EQ_EQ] = 178,
        [anon_sym_EQ_EQ_EQ] = 178,
        [anon_sym_EQ_TILDE] = 178,
        [anon_sym_GT] = 178,
        [anon_sym_GT_EQ] = 178,
        [anon_sym_LT_EQ] = 178,
        [anon_sym_PLUS] = 178,
        [anon_sym_DASH] = 178,
        [anon_sym_SLASH] = 178,
        [anon_sym_PERCENT] = 178,
        [anon_sym_STAR_STAR] = 178,
        [anon_sym_LT_LT] = 178,
        [anon_sym_GT_GT] = 178,
        [anon_sym_TILDE] = 178,
        [anon_sym_PLUS_AT] = 178,
        [anon_sym_DASH_AT] = 178,
        [anon_sym_LBRACK_RBRACK] = 178,
        [anon_sym_LBRACK_RBRACK_EQ] = 178,
        [sym__line_break] = 40,
    },
    [235] = {
        [sym__terminator] = 378,
        [aux_sym_program_repeat1] = 378,
        [anon_sym_if] = 378,
        [anon_sym_while] = 378,
        [anon_sym_unless] = 378,
        [anon_sym_until] = 378,
        [anon_sym_RPAREN] = 378,
        [sym_comment] = 40,
        [sym__line_break] = 378,
        [anon_sym_SEMI] = 378,
    },
    [236] = {
        [sym__terminator] = 470,
        [aux_sym_program_repeat1] = 470,
        [anon_sym_if] = 470,
        [anon_sym_while] = 470,
        [anon_sym_unless] = 470,
        [anon_sym_until] = 470,
        [anon_sym_RPAREN] = 470,
        [sym_comment] = 40,
        [sym__line_break] = 470,
        [anon_sym_SEMI] = 470,
    },
    [237] = {
        [sym_identifier] = 626,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [238] = {
        [sym__argument] = 628,
        [sym__primary] = 476,
        [sym_scope_resolution_expression] = 478,
        [sym__variable] = 478,
        [anon_sym_LPAREN] = 480,
        [anon_sym_COLON_COLON] = 482,
        [anon_sym_RBRACK] = 588,
        [anon_sym_nil] = 484,
        [anon_sym_self] = 484,
        [sym_identifier] = 484,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [239] = {
        [aux_sym__call_arguments_repeat1] = 630,
        [anon_sym_COMMA] = 488,
        [anon_sym_RBRACK] = 590,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [240] = {
        [anon_sym_RBRACK] = 632,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [241] = {
        [sym__terminator] = 520,
        [aux_sym_program_repeat1] = 520,
        [anon_sym_if] = 520,
        [anon_sym_while] = 520,
        [anon_sym_unless] = 520,
        [anon_sym_until] = 520,
        [anon_sym_RPAREN] = 520,
        [anon_sym_COLON_COLON] = 520,
        [anon_sym_LBRACK] = 520,
        [sym_comment] = 40,
        [sym__line_break] = 520,
        [anon_sym_SEMI] = 520,
    },
    [242] = {
        [sym__terminator] = 522,
        [aux_sym_program_repeat1] = 522,
        [anon_sym_if] = 522,
        [anon_sym_while] = 522,
        [anon_sym_unless] = 522,
        [anon_sym_until] = 522,
        [anon_sym_RPAREN] = 522,
        [anon_sym_COLON_COLON] = 522,
        [anon_sym_LBRACK] = 522,
        [sym_comment] = 40,
        [sym__line_break] = 522,
        [anon_sym_SEMI] = 522,
    },
    [243] = {
        [sym__statement] = 634,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_PIPE] = 636,
        [anon_sym_end] = 360,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [244] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 638,
        [anon_sym_end] = 640,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [245] = {
        [sym__statement] = 642,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 640,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [246] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 644,
        [anon_sym_end] = 646,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [247] = {
        [sym__terminator] = 540,
        [aux_sym_program_repeat1] = 540,
        [anon_sym_if] = 540,
        [anon_sym_while] = 540,
        [anon_sym_unless] = 540,
        [anon_sym_until] = 540,
        [anon_sym_RPAREN] = 540,
        [sym_comment] = 40,
        [sym__line_break] = 540,
        [anon_sym_SEMI] = 540,
    },
    [248] = {
        [anon_sym_end] = 648,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [249] = {
        [sym__terminator] = 544,
        [aux_sym_program_repeat1] = 544,
        [anon_sym_if] = 544,
        [anon_sym_while] = 544,
        [anon_sym_unless] = 544,
        [anon_sym_until] = 544,
        [anon_sym_RPAREN] = 544,
        [sym_comment] = 40,
        [sym__line_break] = 544,
        [anon_sym_SEMI] = 544,
    },
    [250] = {
        [sym__terminator] = 546,
        [aux_sym_program_repeat1] = 546,
        [anon_sym_if] = 546,
        [anon_sym_while] = 546,
        [anon_sym_unless] = 546,
        [anon_sym_until] = 546,
        [anon_sym_RPAREN] = 546,
        [sym_comment] = 40,
        [sym__line_break] = 546,
        [anon_sym_SEMI] = 546,
    },
    [251] = {
        [anon_sym_end] = 646,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [252] = {
        [anon_sym_RPAREN] = 650,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [253] = {
        [aux_sym__call_arguments_repeat1] = 362,
        [anon_sym_do] = 362,
        [anon_sym_COMMA] = 362,
        [anon_sym_COLON_COLON] = 362,
        [anon_sym_LBRACK] = 362,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [254] = {
        [aux_sym__call_arguments_repeat1] = 364,
        [anon_sym_do] = 364,
        [anon_sym_COMMA] = 364,
        [anon_sym_COLON_COLON] = 364,
        [anon_sym_LBRACK] = 364,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [255] = {
        [sym_identifier] = 652,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [256] = {
        [sym__argument] = 654,
        [sym__primary] = 476,
        [sym_scope_resolution_expression] = 478,
        [sym__variable] = 478,
        [anon_sym_LPAREN] = 480,
        [anon_sym_COLON_COLON] = 482,
        [anon_sym_RBRACK] = 168,
        [anon_sym_nil] = 484,
        [anon_sym_self] = 484,
        [sym_identifier] = 484,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [257] = {
        [aux_sym__call_arguments_repeat1] = 656,
        [anon_sym_COMMA] = 488,
        [anon_sym_RBRACK] = 650,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [258] = {
        [anon_sym_RBRACK] = 658,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [259] = {
        [aux_sym__call_arguments_repeat1] = 520,
        [anon_sym_do] = 520,
        [anon_sym_COMMA] = 520,
        [anon_sym_COLON_COLON] = 520,
        [anon_sym_LBRACK] = 520,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [260] = {
        [aux_sym__call_arguments_repeat1] = 522,
        [anon_sym_do] = 522,
        [anon_sym_COMMA] = 522,
        [anon_sym_COLON_COLON] = 522,
        [anon_sym_LBRACK] = 522,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [261] = {
        [anon_sym_do] = 660,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [262] = {
        [sym__argument] = 662,
        [sym__primary] = 128,
        [sym_scope_resolution_expression] = 130,
        [sym__variable] = 130,
        [anon_sym_LPAREN] = 134,
        [anon_sym_COLON_COLON] = 136,
        [anon_sym_nil] = 140,
        [anon_sym_self] = 140,
        [sym_identifier] = 140,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [263] = {
        [aux_sym__call_arguments_repeat1] = 664,
        [anon_sym_do] = 516,
        [anon_sym_COMMA] = 150,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [264] = {
        [anon_sym_do] = 518,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [265] = {
        [sym__terminator] = 666,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [266] = {
        [sym__statement] = 668,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 670,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [267] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 672,
        [anon_sym_end] = 674,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [268] = {
        [sym__terminator] = 248,
        [aux_sym_program_repeat1] = 248,
        [ts_builtin_sym_end] = 248,
        [anon_sym_if] = 248,
        [anon_sym_while] = 248,
        [anon_sym_unless] = 248,
        [anon_sym_until] = 248,
        [sym_comment] = 40,
        [sym__line_break] = 248,
        [anon_sym_SEMI] = 248,
    },
    [269] = {
        [anon_sym_end] = 676,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [270] = {
        [sym__terminator] = 280,
        [aux_sym_program_repeat1] = 280,
        [ts_builtin_sym_end] = 280,
        [anon_sym_if] = 280,
        [anon_sym_while] = 280,
        [anon_sym_unless] = 280,
        [anon_sym_until] = 280,
        [sym_comment] = 40,
        [sym__line_break] = 280,
        [anon_sym_SEMI] = 280,
    },
    [271] = {
        [sym__terminator] = 286,
        [aux_sym_program_repeat1] = 286,
        [ts_builtin_sym_end] = 286,
        [anon_sym_if] = 286,
        [anon_sym_while] = 286,
        [anon_sym_unless] = 286,
        [anon_sym_until] = 286,
        [sym_comment] = 40,
        [sym__line_break] = 286,
        [anon_sym_SEMI] = 286,
    },
    [272] = {
        [sym__terminator] = 160,
        [aux_sym_program_repeat1] = 160,
        [ts_builtin_sym_end] = 160,
        [anon_sym_if] = 160,
        [anon_sym_while] = 160,
        [anon_sym_unless] = 160,
        [anon_sym_until] = 160,
        [anon_sym_COLON_COLON] = 160,
        [anon_sym_LBRACK] = 160,
        [sym_comment] = 40,
        [sym__line_break] = 160,
        [anon_sym_SEMI] = 160,
    },
    [273] = {
        [sym__terminator] = 678,
        [anon_sym_LT] = 680,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [274] = {
        [sym__statement] = 682,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 684,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [275] = {
        [sym_identifier] = 686,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [276] = {
        [sym__terminator] = 688,
        [aux_sym_class_declaration_repeat1] = 690,
        [anon_sym_COLON_COLON] = 308,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [277] = {
        [sym__statement] = 692,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 694,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [278] = {
        [sym__terminator] = 696,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [279] = {
        [sym__statement] = 698,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 700,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [280] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 702,
        [anon_sym_end] = 704,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [281] = {
        [sym__terminator] = 332,
        [aux_sym_program_repeat1] = 332,
        [ts_builtin_sym_end] = 332,
        [anon_sym_if] = 332,
        [anon_sym_while] = 332,
        [anon_sym_unless] = 332,
        [anon_sym_until] = 332,
        [sym_comment] = 40,
        [sym__line_break] = 332,
        [anon_sym_SEMI] = 332,
    },
    [282] = {
        [anon_sym_end] = 706,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [283] = {
        [sym__terminator] = 336,
        [aux_sym_program_repeat1] = 336,
        [ts_builtin_sym_end] = 336,
        [anon_sym_if] = 336,
        [anon_sym_while] = 336,
        [anon_sym_unless] = 336,
        [anon_sym_until] = 336,
        [sym_comment] = 40,
        [sym__line_break] = 336,
        [anon_sym_SEMI] = 336,
    },
    [284] = {
        [sym__terminator] = 338,
        [aux_sym_program_repeat1] = 338,
        [ts_builtin_sym_end] = 338,
        [anon_sym_if] = 338,
        [anon_sym_while] = 338,
        [anon_sym_unless] = 338,
        [anon_sym_until] = 338,
        [sym_comment] = 40,
        [sym__line_break] = 338,
        [anon_sym_SEMI] = 338,
    },
    [285] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 708,
        [anon_sym_end] = 700,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [286] = {
        [sym__terminator] = 342,
        [aux_sym_program_repeat1] = 342,
        [ts_builtin_sym_end] = 342,
        [anon_sym_if] = 342,
        [anon_sym_while] = 342,
        [anon_sym_unless] = 342,
        [anon_sym_until] = 342,
        [sym_comment] = 40,
        [sym__line_break] = 342,
        [anon_sym_SEMI] = 342,
    },
    [287] = {
        [anon_sym_end] = 704,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [288] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 710,
        [anon_sym_end] = 712,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [289] = {
        [sym__terminator] = 348,
        [aux_sym_program_repeat1] = 348,
        [ts_builtin_sym_end] = 348,
        [anon_sym_if] = 348,
        [anon_sym_while] = 348,
        [anon_sym_unless] = 348,
        [anon_sym_until] = 348,
        [sym_comment] = 40,
        [sym__line_break] = 348,
        [anon_sym_SEMI] = 348,
    },
    [290] = {
        [anon_sym_end] = 694,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [291] = {
        [sym__terminator] = 350,
        [aux_sym_program_repeat1] = 350,
        [ts_builtin_sym_end] = 350,
        [anon_sym_if] = 350,
        [anon_sym_while] = 350,
        [anon_sym_unless] = 350,
        [anon_sym_until] = 350,
        [sym_comment] = 40,
        [sym__line_break] = 350,
        [anon_sym_SEMI] = 350,
    },
    [292] = {
        [sym__terminator] = 162,
        [aux_sym_program_repeat1] = 714,
        [anon_sym_if] = 166,
        [anon_sym_while] = 166,
        [anon_sym_unless] = 166,
        [anon_sym_until] = 166,
        [anon_sym_RPAREN] = 716,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [293] = {
        [anon_sym_RPAREN] = 718,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [294] = {
        [sym__terminator] = 362,
        [aux_sym_program_repeat1] = 362,
        [ts_builtin_sym_end] = 362,
        [anon_sym_if] = 362,
        [anon_sym_while] = 362,
        [anon_sym_unless] = 362,
        [anon_sym_until] = 362,
        [anon_sym_COLON_COLON] = 362,
        [anon_sym_LBRACK] = 362,
        [sym_comment] = 40,
        [sym__line_break] = 362,
        [anon_sym_SEMI] = 362,
    },
    [295] = {
        [sym__terminator] = 364,
        [aux_sym_program_repeat1] = 364,
        [ts_builtin_sym_end] = 364,
        [anon_sym_if] = 364,
        [anon_sym_while] = 364,
        [anon_sym_unless] = 364,
        [anon_sym_until] = 364,
        [anon_sym_COLON_COLON] = 364,
        [anon_sym_LBRACK] = 364,
        [sym_comment] = 40,
        [sym__line_break] = 364,
        [anon_sym_SEMI] = 364,
    },
    [296] = {
        [sym_argument_list] = 720,
        [sym__terminator] = 722,
        [anon_sym_LPAREN] = 724,
        [anon_sym_STAR] = 374,
        [anon_sym_AMP] = 374,
        [sym_identifier] = 376,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [297] = {
        [sym__terminator] = 726,
        [sym_comment] = 40,
        [sym__line_break] = 194,
        [anon_sym_SEMI] = 196,
    },
    [298] = {
        [sym__statement] = 728,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 730,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [299] = {
        [sym_argument_list] = 732,
        [anon_sym_RPAREN] = 726,
        [anon_sym_STAR] = 388,
        [anon_sym_AMP] = 388,
        [sym_identifier] = 390,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [300] = {
        [anon_sym_RPAREN] = 734,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [301] = {
        [sym__statement] = 736,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 738,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [302] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 740,
        [anon_sym_end] = 742,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [303] = {
        [sym__terminator] = 450,
        [aux_sym_program_repeat1] = 450,
        [ts_builtin_sym_end] = 450,
        [anon_sym_if] = 450,
        [anon_sym_while] = 450,
        [anon_sym_unless] = 450,
        [anon_sym_until] = 450,
        [sym_comment] = 40,
        [sym__line_break] = 450,
        [anon_sym_SEMI] = 450,
    },
    [304] = {
        [anon_sym_end] = 744,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [305] = {
        [sym__terminator] = 454,
        [aux_sym_program_repeat1] = 454,
        [ts_builtin_sym_end] = 454,
        [anon_sym_if] = 454,
        [anon_sym_while] = 454,
        [anon_sym_unless] = 454,
        [anon_sym_until] = 454,
        [sym_comment] = 40,
        [sym__line_break] = 454,
        [anon_sym_SEMI] = 454,
    },
    [306] = {
        [sym__terminator] = 456,
        [aux_sym_program_repeat1] = 456,
        [ts_builtin_sym_end] = 456,
        [anon_sym_if] = 456,
        [anon_sym_while] = 456,
        [anon_sym_unless] = 456,
        [anon_sym_until] = 456,
        [sym_comment] = 40,
        [sym__line_break] = 456,
        [anon_sym_SEMI] = 456,
    },
    [307] = {
        [sym__statement] = 746,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 742,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [308] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 748,
        [anon_sym_end] = 744,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [309] = {
        [anon_sym_end] = 750,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [310] = {
        [sym__terminator] = 464,
        [aux_sym_program_repeat1] = 464,
        [ts_builtin_sym_end] = 464,
        [anon_sym_if] = 464,
        [anon_sym_while] = 464,
        [anon_sym_unless] = 464,
        [anon_sym_until] = 464,
        [sym_comment] = 40,
        [sym__line_break] = 464,
        [anon_sym_SEMI] = 464,
    },
    [311] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 752,
        [anon_sym_end] = 738,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [312] = {
        [sym__terminator] = 468,
        [aux_sym_program_repeat1] = 468,
        [ts_builtin_sym_end] = 468,
        [anon_sym_if] = 468,
        [anon_sym_while] = 468,
        [anon_sym_unless] = 468,
        [anon_sym_until] = 468,
        [sym_comment] = 40,
        [sym__line_break] = 468,
        [anon_sym_SEMI] = 468,
    },
    [313] = {
        [anon_sym_end] = 742,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [314] = {
        [sym__function_name] = 754,
        [anon_sym_PIPE] = 76,
        [anon_sym_STAR] = 76,
        [anon_sym_AMP] = 76,
        [anon_sym_LT] = 76,
        [sym_identifier] = 76,
        [sym_comment] = 40,
        [anon_sym_DOT_DOT] = 76,
        [anon_sym_CARET] = 76,
        [anon_sym_LT_EQ_GT] = 76,
        [anon_sym_EQ_EQ] = 76,
        [anon_sym_EQ_EQ_EQ] = 76,
        [anon_sym_EQ_TILDE] = 76,
        [anon_sym_GT] = 76,
        [anon_sym_GT_EQ] = 76,
        [anon_sym_LT_EQ] = 76,
        [anon_sym_PLUS] = 76,
        [anon_sym_DASH] = 76,
        [anon_sym_SLASH] = 76,
        [anon_sym_PERCENT] = 76,
        [anon_sym_STAR_STAR] = 76,
        [anon_sym_LT_LT] = 76,
        [anon_sym_GT_GT] = 76,
        [anon_sym_TILDE] = 76,
        [anon_sym_PLUS_AT] = 76,
        [anon_sym_DASH_AT] = 76,
        [anon_sym_LBRACK_RBRACK] = 76,
        [anon_sym_LBRACK_RBRACK_EQ] = 76,
        [sym__line_break] = 40,
    },
    [315] = {
        [sym__terminator] = 284,
        [aux_sym_program_repeat1] = 284,
        [ts_builtin_sym_end] = 284,
        [anon_sym_if] = 284,
        [anon_sym_while] = 284,
        [anon_sym_unless] = 284,
        [anon_sym_until] = 284,
        [sym_comment] = 40,
        [sym__line_break] = 284,
        [anon_sym_SEMI] = 284,
    },
    [316] = {
        [sym__terminator] = 378,
        [aux_sym_program_repeat1] = 378,
        [ts_builtin_sym_end] = 378,
        [anon_sym_if] = 378,
        [anon_sym_while] = 378,
        [anon_sym_unless] = 378,
        [anon_sym_until] = 378,
        [sym_comment] = 40,
        [sym__line_break] = 378,
        [anon_sym_SEMI] = 378,
    },
    [317] = {
        [sym__terminator] = 470,
        [aux_sym_program_repeat1] = 470,
        [ts_builtin_sym_end] = 470,
        [anon_sym_if] = 470,
        [anon_sym_while] = 470,
        [anon_sym_unless] = 470,
        [anon_sym_until] = 470,
        [sym_comment] = 40,
        [sym__line_break] = 470,
        [anon_sym_SEMI] = 470,
    },
    [318] = {
        [sym_identifier] = 756,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [319] = {
        [sym__argument] = 758,
        [sym__primary] = 476,
        [sym_scope_resolution_expression] = 478,
        [sym__variable] = 478,
        [anon_sym_LPAREN] = 480,
        [anon_sym_COLON_COLON] = 482,
        [anon_sym_RBRACK] = 716,
        [anon_sym_nil] = 484,
        [anon_sym_self] = 484,
        [sym_identifier] = 484,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [320] = {
        [aux_sym__call_arguments_repeat1] = 760,
        [anon_sym_COMMA] = 488,
        [anon_sym_RBRACK] = 718,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [321] = {
        [anon_sym_RBRACK] = 762,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [322] = {
        [sym__terminator] = 520,
        [aux_sym_program_repeat1] = 520,
        [ts_builtin_sym_end] = 520,
        [anon_sym_if] = 520,
        [anon_sym_while] = 520,
        [anon_sym_unless] = 520,
        [anon_sym_until] = 520,
        [anon_sym_COLON_COLON] = 520,
        [anon_sym_LBRACK] = 520,
        [sym_comment] = 40,
        [sym__line_break] = 520,
        [anon_sym_SEMI] = 520,
    },
    [323] = {
        [sym__terminator] = 522,
        [aux_sym_program_repeat1] = 522,
        [ts_builtin_sym_end] = 522,
        [anon_sym_if] = 522,
        [anon_sym_while] = 522,
        [anon_sym_unless] = 522,
        [anon_sym_until] = 522,
        [anon_sym_COLON_COLON] = 522,
        [anon_sym_LBRACK] = 522,
        [sym_comment] = 40,
        [sym__line_break] = 522,
        [anon_sym_SEMI] = 522,
    },
    [324] = {
        [sym__statement] = 764,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_PIPE] = 766,
        [anon_sym_end] = 754,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [325] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 768,
        [anon_sym_end] = 770,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [326] = {
        [sym__statement] = 772,
        [sym__declaration] = 200,
        [sym_method_declaration] = 202,
        [sym_class_declaration] = 202,
        [sym_module_declaration] = 202,
        [sym__call] = 204,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 200,
        [sym__argument] = 206,
        [sym__primary] = 208,
        [sym_scope_resolution_expression] = 210,
        [sym__variable] = 210,
        [anon_sym_end] = 770,
        [anon_sym_undef] = 214,
        [anon_sym_alias] = 216,
        [anon_sym_def] = 218,
        [anon_sym_LPAREN] = 220,
        [anon_sym_class] = 222,
        [anon_sym_COLON_COLON] = 224,
        [anon_sym_module] = 226,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 228,
        [anon_sym_self] = 228,
        [sym_identifier] = 228,
        [sym_comment] = 40,
        [sym_symbol] = 206,
        [sym__line_break] = 40,
    },
    [327] = {
        [sym__terminator] = 234,
        [aux_sym_program_repeat1] = 774,
        [anon_sym_end] = 776,
        [anon_sym_if] = 240,
        [anon_sym_while] = 240,
        [anon_sym_unless] = 240,
        [anon_sym_until] = 240,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [328] = {
        [sym__terminator] = 540,
        [aux_sym_program_repeat1] = 540,
        [ts_builtin_sym_end] = 540,
        [anon_sym_if] = 540,
        [anon_sym_while] = 540,
        [anon_sym_unless] = 540,
        [anon_sym_until] = 540,
        [sym_comment] = 40,
        [sym__line_break] = 540,
        [anon_sym_SEMI] = 540,
    },
    [329] = {
        [anon_sym_end] = 778,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [330] = {
        [sym__terminator] = 544,
        [aux_sym_program_repeat1] = 544,
        [ts_builtin_sym_end] = 544,
        [anon_sym_if] = 544,
        [anon_sym_while] = 544,
        [anon_sym_unless] = 544,
        [anon_sym_until] = 544,
        [sym_comment] = 40,
        [sym__line_break] = 544,
        [anon_sym_SEMI] = 544,
    },
    [331] = {
        [sym__terminator] = 546,
        [aux_sym_program_repeat1] = 546,
        [ts_builtin_sym_end] = 546,
        [anon_sym_if] = 546,
        [anon_sym_while] = 546,
        [anon_sym_unless] = 546,
        [anon_sym_until] = 546,
        [sym_comment] = 40,
        [sym__line_break] = 546,
        [anon_sym_SEMI] = 546,
    },
    [332] = {
        [anon_sym_end] = 776,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [333] = {
        [sym__statement] = 780,
        [sym__declaration] = 6,
        [sym_method_declaration] = 8,
        [sym_class_declaration] = 8,
        [sym_module_declaration] = 8,
        [sym__call] = 10,
        [sym__command] = 12,
        [sym__function_call] = 12,
        [sym__expression] = 6,
        [sym__argument] = 14,
        [sym__primary] = 16,
        [sym_scope_resolution_expression] = 18,
        [sym__variable] = 18,
        [anon_sym_undef] = 22,
        [anon_sym_alias] = 24,
        [anon_sym_def] = 26,
        [anon_sym_LPAREN] = 28,
        [anon_sym_class] = 30,
        [anon_sym_COLON_COLON] = 32,
        [anon_sym_module] = 34,
        [anon_sym_super] = 36,
        [anon_sym_nil] = 38,
        [anon_sym_self] = 38,
        [sym_identifier] = 38,
        [sym_comment] = 40,
        [sym_symbol] = 14,
        [sym__line_break] = 40,
    },
    [334] = {
        [ts_builtin_sym_end] = 782,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
    [335] = {
        [sym__expression] = 754,
        [sym__argument] = 14,
        [sym__primary] = 16,
        [sym_scope_resolution_expression] = 18,
        [sym__variable] = 18,
        [anon_sym_LPAREN] = 28,
        [anon_sym_COLON_COLON] = 32,
        [anon_sym_nil] = 38,
        [anon_sym_self] = 38,
        [sym_identifier] = 38,
        [sym_comment] = 40,
        [sym_symbol] = 14,
        [sym__line_break] = 40,
    },
    [336] = {
        [sym__terminator] = 44,
        [aux_sym_program_repeat1] = 784,
        [ts_builtin_sym_end] = 290,
        [anon_sym_if] = 50,
        [anon_sym_while] = 50,
        [anon_sym_unless] = 50,
        [anon_sym_until] = 50,
        [sym_comment] = 40,
        [sym__line_break] = 52,
        [anon_sym_SEMI] = 54,
    },
    [337] = {
        [ts_builtin_sym_end] = 292,
        [sym_comment] = 40,
        [sym__line_break] = 40,
    },
};

static TSParseActionEntry ts_parse_actions[] = {
    [0] = {.count = 1}, ERROR(),
    [2] = {.count = 1}, SHIFT(1, 0),
    [4] = {.count = 1}, SHIFT(2, 0),
    [6] = {.count = 1}, SHIFT(3, 0),
    [8] = {.count = 1}, SHIFT(4, 0),
    [10] = {.count = 1}, SHIFT(5, 0),
    [12] = {.count = 1}, SHIFT(6, 0),
    [14] = {.count = 1}, SHIFT(7, 0),
    [16] = {.count = 1}, SHIFT(8, 0),
    [18] = {.count = 1}, SHIFT(9, 0),
    [20] = {.count = 1}, REDUCE(sym_program, 0, 0),
    [22] = {.count = 1}, SHIFT(10, 0),
    [24] = {.count = 1}, SHIFT(11, 0),
    [26] = {.count = 1}, SHIFT(12, 0),
    [28] = {.count = 1}, SHIFT(13, 0),
    [30] = {.count = 1}, SHIFT(14, 0),
    [32] = {.count = 1}, SHIFT(15, 0),
    [34] = {.count = 1}, SHIFT(16, 0),
    [36] = {.count = 1}, SHIFT(17, 0),
    [38] = {.count = 1}, SHIFT(18, 0),
    [40] = {.count = 1}, SHIFT_EXTRA(),
    [42] = {.count = 1}, ACCEPT_INPUT(),
    [44] = {.count = 1}, SHIFT(333, 0),
    [46] = {.count = 1}, SHIFT(334, 0),
    [48] = {.count = 1}, REDUCE(sym_program, 1, 0),
    [50] = {.count = 1}, SHIFT(335, 0),
    [52] = {.count = 1}, SHIFT(72, 0),
    [54] = {.count = 1}, SHIFT(73, 0),
    [56] = {.count = 1}, REDUCE(sym__statement, 1, 0),
    [58] = {.count = 1}, REDUCE(sym__declaration, 1, 0),
    [60] = {.count = 1}, SHIFT(324, 0),
    [62] = {.count = 1}, REDUCE(sym__call, 1, 0),
    [64] = {.count = 1}, REDUCE(sym__expression, 1, 0),
    [66] = {.count = 1}, REDUCE(sym__argument, 1, 0),
    [68] = {.count = 1}, SHIFT(318, 0),
    [70] = {.count = 1}, SHIFT(319, 0),
    [72] = {.count = 1}, REDUCE(sym__primary, 1, 0),
    [74] = {.count = 1}, SHIFT(317, 0),
    [76] = {.count = 1}, SHIFT(316, 0),
    [78] = {.count = 1}, SHIFT(314, 0),
    [80] = {.count = 1}, SHIFT(152, 0),
    [82] = {.count = 1}, SHIFT(296, 0),
    [84] = {.count = 1}, SHIFT(111, 0),
    [86] = {.count = 1}, SHIFT(292, 0),
    [88] = {.count = 1}, SHIFT(30, 0),
    [90] = {.count = 1}, SHIFT(31, 0),
    [92] = {.count = 1}, SHIFT(32, 0),
    [94] = {.count = 1}, SHIFT(33, 0),
    [96] = {.count = 1}, SHIFT(34, 0),
    [98] = {.count = 1}, SHIFT(35, 0),
    [100] = {.count = 1}, SHIFT(36, 0),
    [102] = {.count = 1}, SHIFT(37, 0),
    [104] = {.count = 1}, SHIFT(38, 0),
    [106] = {.count = 1}, SHIFT(39, 0),
    [108] = {.count = 1}, SHIFT(40, 0),
    [110] = {.count = 1}, SHIFT(41, 0),
    [112] = {.count = 1}, SHIFT(42, 0),
    [114] = {.count = 1}, SHIFT(43, 0),
    [116] = {.count = 1}, SHIFT(273, 0),
    [118] = {.count = 1}, SHIFT(272, 0),
    [120] = {.count = 1}, SHIFT(265, 0),
    [122] = {.count = 1}, SHIFT(19, 0),
    [124] = {.count = 1}, SHIFT(20, 0),
    [126] = {.count = 1}, SHIFT(21, 0),
    [128] = {.count = 1}, SHIFT(22, 0),
    [130] = {.count = 1}, SHIFT(23, 0),
    [132] = {.count = 1}, REDUCE(sym__function_call, 1, 0),
    [134] = {.count = 1}, SHIFT(24, 0),
    [136] = {.count = 1}, SHIFT(25, 0),
    [138] = {.count = 1}, SHIFT(26, 0),
    [140] = {.count = 1}, SHIFT(27, 0),
    [142] = {.count = 1}, REDUCE(sym__variable, 1, 0),
    [144] = {.count = 1}, REDUCE(sym__command, 2, 0),
    [146] = {.count = 1}, REDUCE(sym__call_arguments, 1, 0),
    [148] = {.count = 1}, SHIFT(261, 0),
    [150] = {.count = 1}, SHIFT(262, 0),
    [152] = {.count = 1}, SHIFT(255, 0),
    [154] = {.count = 1}, SHIFT(256, 0),
    [156] = {.count = 1}, SHIFT(29, 0),
    [158] = {.count = 1}, SHIFT(28, 0),
    [160] = {.count = 1}, REDUCE(sym_scope_resolution_expression, 2, 0),
    [162] = {.count = 1}, SHIFT(102, 0),
    [164] = {.count = 1}, SHIFT(252, 0),
    [166] = {.count = 1}, SHIFT(104, 0),
    [168] = {.count = 1}, SHIFT(253, 0),
    [170] = {.count = 1}, SHIFT(243, 0),
    [172] = {.count = 1}, SHIFT(237, 0),
    [174] = {.count = 1}, SHIFT(238, 0),
    [176] = {.count = 1}, SHIFT(236, 0),
    [178] = {.count = 1}, SHIFT(235, 0),
    [180] = {.count = 1}, SHIFT(234, 0),
    [182] = {.count = 1}, SHIFT(216, 0),
    [184] = {.count = 1}, SHIFT(212, 0),
    [186] = {.count = 1}, SHIFT(193, 0),
    [188] = {.count = 1}, SHIFT(192, 0),
    [190] = {.count = 1}, SHIFT(44, 0),
    [192] = {.count = 1}, SHIFT(45, 0),
    [194] = {.count = 1}, SHIFT(46, 0),
    [196] = {.count = 1}, SHIFT(47, 0),
    [198] = {.count = 1}, SHIFT(48, 0),
    [200] = {.count = 1}, SHIFT(49, 0),
    [202] = {.count = 1}, SHIFT(50, 0),
    [204] = {.count = 1}, SHIFT(51, 0),
    [206] = {.count = 1}, SHIFT(52, 0),
    [208] = {.count = 1}, SHIFT(53, 0),
    [210] = {.count = 1}, SHIFT(54, 0),
    [212] = {.count = 1}, SHIFT(55, 0),
    [214] = {.count = 1}, SHIFT(56, 0),
    [216] = {.count = 1}, SHIFT(57, 0),
    [218] = {.count = 1}, SHIFT(58, 0),
    [220] = {.count = 1}, SHIFT(59, 0),
    [222] = {.count = 1}, SHIFT(60, 0),
    [224] = {.count = 1}, SHIFT(61, 0),
    [226] = {.count = 1}, SHIFT(62, 0),
    [228] = {.count = 1}, SHIFT(63, 0),
    [230] = {.count = 1}, REDUCE(sym__terminator, 1, 0),
    [232] = {.count = 1}, REDUCE_EXTRA(sym__line_break),
    [234] = {.count = 1}, SHIFT(68, 0),
    [236] = {.count = 1}, SHIFT(189, 0),
    [238] = {.count = 1}, SHIFT(190, 0),
    [240] = {.count = 1}, SHIFT(71, 0),
    [242] = {.count = 1}, SHIFT(180, 0),
    [244] = {.count = 1}, SHIFT(155, 0),
    [246] = {.count = 1}, SHIFT(156, 0),
    [248] = {.count = 1}, REDUCE(sym_module_declaration, 4, 0),
    [250] = {.count = 1}, SHIFT(154, 0),
    [252] = {.count = 1}, SHIFT(153, 0),
    [254] = {.count = 1}, SHIFT(151, 0),
    [256] = {.count = 1}, SHIFT(110, 0),
    [258] = {.count = 1}, SHIFT(101, 0),
    [260] = {.count = 1}, SHIFT(79, 0),
    [262] = {.count = 1}, SHIFT(78, 0),
    [264] = {.count = 1}, SHIFT(64, 0),
    [266] = {.count = 1}, SHIFT(65, 0),
    [268] = {.count = 1}, SHIFT(66, 0),
    [270] = {.count = 1}, SHIFT(67, 0),
    [272] = {.count = 1}, SHIFT(69, 0),
    [274] = {.count = 1}, SHIFT(70, 0),
    [276] = {.count = 1}, SHIFT(76, 0),
    [278] = {.count = 1}, SHIFT(75, 0),
    [280] = {.count = 1}, REDUCE(sym_module_declaration, 5, 0),
    [282] = {.count = 1}, SHIFT(74, 0),
    [284] = {.count = 1}, REDUCE(sym__statement, 3, 0),
    [286] = {.count = 1}, REDUCE(sym_module_declaration, 6, 0),
    [288] = {.count = 1}, SHIFT(77, 0),
    [290] = {.count = 1}, REDUCE(aux_sym_program_repeat1, 2, 0),
    [292] = {.count = 1}, REDUCE(aux_sym_program_repeat1, 3, 0),
    [294] = {.count = 1}, SHIFT(80, 0),
    [296] = {.count = 1}, SHIFT(81, 0),
    [298] = {.count = 1}, SHIFT(97, 0),
    [300] = {.count = 1}, SHIFT(98, 0),
    [302] = {.count = 1}, SHIFT(82, 0),
    [304] = {.count = 1}, SHIFT(83, 0),
    [306] = {.count = 1}, SHIFT(84, 0),
    [308] = {.count = 1}, SHIFT(85, 0),
    [310] = {.count = 1}, SHIFT(94, 0),
    [312] = {.count = 1}, SHIFT(95, 0),
    [314] = {.count = 1}, SHIFT(88, 0),
    [316] = {.count = 1}, SHIFT(86, 0),
    [318] = {.count = 1}, REDUCE(aux_sym_class_declaration_repeat1, 2, 0),
    [320] = {.count = 1}, SHIFT(87, 0),
    [322] = {.count = 1}, REDUCE(aux_sym_class_declaration_repeat1, 3, 0),
    [324] = {.count = 1}, SHIFT(89, 0),
    [326] = {.count = 1}, SHIFT(90, 0),
    [328] = {.count = 1}, SHIFT(91, 0),
    [330] = {.count = 1}, SHIFT(92, 0),
    [332] = {.count = 1}, REDUCE(sym_class_declaration, 7, 0),
    [334] = {.count = 1}, SHIFT(93, 0),
    [336] = {.count = 1}, REDUCE(sym_class_declaration, 8, 0),
    [338] = {.count = 1}, REDUCE(sym_class_declaration, 9, 0),
    [340] = {.count = 1}, SHIFT(96, 0),
    [342] = {.count = 1}, REDUCE(sym_class_declaration, 6, 0),
    [344] = {.count = 1}, SHIFT(99, 0),
    [346] = {.count = 1}, SHIFT(100, 0),
    [348] = {.count = 1}, REDUCE(sym_class_declaration, 4, 0),
    [350] = {.count = 1}, REDUCE(sym_class_declaration, 5, 0),
    [352] = {.count = 1}, SHIFT(103, 0),
    [354] = {.count = 1}, SHIFT(105, 0),
    [356] = {.count = 1}, SHIFT(108, 0),
    [358] = {.count = 1}, SHIFT(107, 0),
    [360] = {.count = 1}, SHIFT(106, 0),
    [362] = {.count = 1}, REDUCE(sym__primary, 3, 0),
    [364] = {.count = 1}, REDUCE(sym__primary, 4, 0),
    [366] = {.count = 1}, SHIFT(109, 0),
    [368] = {.count = 1}, SHIFT(112, 0),
    [370] = {.count = 1}, SHIFT(113, 0),
    [372] = {.count = 1}, SHIFT(114, 0),
    [374] = {.count = 1}, SHIFT(115, 0),
    [376] = {.count = 1}, SHIFT(116, 0),
    [378] = {.count = 1}, REDUCE(sym__function_name, 1, 0),
    [380] = {.count = 1}, SHIFT(127, 0),
    [382] = {.count = 1}, SHIFT(148, 0),
    [384] = {.count = 1}, SHIFT(149, 0),
    [386] = {.count = 1}, SHIFT(126, 0),
    [388] = {.count = 1}, SHIFT(128, 0),
    [390] = {.count = 1}, SHIFT(129, 0),
    [392] = {.count = 1}, SHIFT(124, 0),
    [394] = {.count = 1}, REDUCE(sym_argument_list, 1, 0),
    [396] = {.count = 1}, SHIFT(117, 0),
    [398] = {.count = 1}, SHIFT(118, 0),
    [400] = {.count = 1}, REDUCE(sym_argument_list, 2, 0),
    [402] = {.count = 1}, SHIFT(119, 0),
    [404] = {.count = 1}, SHIFT(120, 0),
    [406] = {.count = 1}, SHIFT(122, 0),
    [408] = {.count = 1}, REDUCE(aux_sym_argument_list_repeat1, 2, 0),
    [410] = {.count = 1}, SHIFT(121, 0),
    [412] = {.count = 1}, REDUCE(aux_sym_argument_list_repeat1, 3, 0),
    [414] = {.count = 1}, SHIFT(123, 0),
    [416] = {.count = 1}, REDUCE(aux_sym_argument_list_repeat1, 4, 0),
    [418] = {.count = 1}, SHIFT(125, 0),
    [420] = {.count = 1}, REDUCE(sym_argument_list, 3, 0),
    [422] = {.count = 1}, SHIFT(144, 0),
    [424] = {.count = 1}, SHIFT(139, 0),
    [426] = {.count = 1}, SHIFT(140, 0),
    [428] = {.count = 1}, SHIFT(137, 0),
    [430] = {.count = 1}, SHIFT(130, 0),
    [432] = {.count = 1}, SHIFT(131, 0),
    [434] = {.count = 1}, SHIFT(132, 0),
    [436] = {.count = 1}, SHIFT(133, 0),
    [438] = {.count = 1}, SHIFT(135, 0),
    [440] = {.count = 1}, SHIFT(134, 0),
    [442] = {.count = 1}, SHIFT(136, 0),
    [444] = {.count = 1}, SHIFT(138, 0),
    [446] = {.count = 1}, SHIFT(141, 0),
    [448] = {.count = 1}, SHIFT(142, 0),
    [450] = {.count = 1}, REDUCE(sym_method_declaration, 5, 0),
    [452] = {.count = 1}, SHIFT(143, 0),
    [454] = {.count = 1}, REDUCE(sym_method_declaration, 6, 0),
    [456] = {.count = 1}, REDUCE(sym_method_declaration, 7, 0),
    [458] = {.count = 1}, SHIFT(145, 0),
    [460] = {.count = 1}, SHIFT(146, 0),
    [462] = {.count = 1}, SHIFT(147, 0),
    [464] = {.count = 1}, REDUCE(sym_method_declaration, 8, 0),
    [466] = {.count = 1}, SHIFT(150, 0),
    [468] = {.count = 1}, REDUCE(sym_method_declaration, 4, 0),
    [470] = {.count = 1}, REDUCE(sym__statement, 2, 0),
    [472] = {.count = 1}, SHIFT(179, 0),
    [474] = {.count = 1}, SHIFT(157, 0),
    [476] = {.count = 1}, SHIFT(158, 0),
    [478] = {.count = 1}, SHIFT(159, 0),
    [480] = {.count = 1}, SHIFT(160, 0),
    [482] = {.count = 1}, SHIFT(161, 0),
    [484] = {.count = 1}, SHIFT(162, 0),
    [486] = {.count = 1}, SHIFT(177, 0),
    [488] = {.count = 1}, SHIFT(172, 0),
    [490] = {.count = 1}, SHIFT(168, 0),
    [492] = {.count = 1}, SHIFT(169, 0),
    [494] = {.count = 1}, SHIFT(164, 0),
    [496] = {.count = 1}, SHIFT(163, 0),
    [498] = {.count = 1}, SHIFT(165, 0),
    [500] = {.count = 1}, SHIFT(166, 0),
    [502] = {.count = 1}, SHIFT(167, 0),
    [504] = {.count = 1}, SHIFT(176, 0),
    [506] = {.count = 1}, SHIFT(170, 0),
    [508] = {.count = 1}, SHIFT(171, 0),
    [510] = {.count = 1}, SHIFT(175, 0),
    [512] = {.count = 1}, SHIFT(173, 0),
    [514] = {.count = 1}, SHIFT(174, 0),
    [516] = {.count = 1}, REDUCE(aux_sym__call_arguments_repeat1, 2, 0),
    [518] = {.count = 1}, REDUCE(aux_sym__call_arguments_repeat1, 3, 0),
    [520] = {.count = 1}, REDUCE(sym__primary, 5, 0),
    [522] = {.count = 1}, REDUCE(sym_scope_resolution_expression, 3, 0),
    [524] = {.count = 1}, SHIFT(178, 0),
    [526] = {.count = 1}, SHIFT(181, 0),
    [528] = {.count = 1}, SHIFT(182, 0),
    [530] = {.count = 1}, SHIFT(188, 0),
    [532] = {.count = 1}, SHIFT(184, 0),
    [534] = {.count = 1}, SHIFT(183, 0),
    [536] = {.count = 1}, SHIFT(185, 0),
    [538] = {.count = 1}, SHIFT(186, 0),
    [540] = {.count = 1}, REDUCE(sym__statement, 4, 0),
    [542] = {.count = 1}, SHIFT(187, 0),
    [544] = {.count = 1}, REDUCE(sym__statement, 5, 0),
    [546] = {.count = 1}, REDUCE(sym__statement, 6, 0),
    [548] = {.count = 1}, SHIFT(191, 0),
    [550] = {.count = 1}, SHIFT(194, 0),
    [552] = {.count = 1}, SHIFT(195, 0),
    [554] = {.count = 1}, SHIFT(208, 0),
    [556] = {.count = 1}, SHIFT(209, 0),
    [558] = {.count = 1}, SHIFT(196, 0),
    [560] = {.count = 1}, SHIFT(197, 0),
    [562] = {.count = 1}, SHIFT(198, 0),
    [564] = {.count = 1}, SHIFT(205, 0),
    [566] = {.count = 1}, SHIFT(206, 0),
    [568] = {.count = 1}, SHIFT(199, 0),
    [570] = {.count = 1}, SHIFT(200, 0),
    [572] = {.count = 1}, SHIFT(201, 0),
    [574] = {.count = 1}, SHIFT(202, 0),
    [576] = {.count = 1}, SHIFT(203, 0),
    [578] = {.count = 1}, SHIFT(204, 0),
    [580] = {.count = 1}, SHIFT(207, 0),
    [582] = {.count = 1}, SHIFT(210, 0),
    [584] = {.count = 1}, SHIFT(211, 0),
    [586] = {.count = 1}, SHIFT(213, 0),
    [588] = {.count = 1}, SHIFT(214, 0),
    [590] = {.count = 1}, SHIFT(215, 0),
    [592] = {.count = 1}, SHIFT(217, 0),
    [594] = {.count = 1}, SHIFT(218, 0),
    [596] = {.count = 1}, SHIFT(219, 0),
    [598] = {.count = 1}, SHIFT(221, 0),
    [600] = {.count = 1}, SHIFT(231, 0),
    [602] = {.count = 1}, SHIFT(232, 0),
    [604] = {.count = 1}, SHIFT(220, 0),
    [606] = {.count = 1}, SHIFT(227, 0),
    [608] = {.count = 1}, SHIFT(222, 0),
    [610] = {.count = 1}, SHIFT(223, 0),
    [612] = {.count = 1}, SHIFT(224, 0),
    [614] = {.count = 1}, SHIFT(225, 0),
    [616] = {.count = 1}, SHIFT(226, 0),
    [618] = {.count = 1}, SHIFT(228, 0),
    [620] = {.count = 1}, SHIFT(229, 0),
    [622] = {.count = 1}, SHIFT(230, 0),
    [624] = {.count = 1}, SHIFT(233, 0),
    [626] = {.count = 1}, SHIFT(242, 0),
    [628] = {.count = 1}, SHIFT(239, 0),
    [630] = {.count = 1}, SHIFT(240, 0),
    [632] = {.count = 1}, SHIFT(241, 0),
    [634] = {.count = 1}, SHIFT(244, 0),
    [636] = {.count = 1}, SHIFT(245, 0),
    [638] = {.count = 1}, SHIFT(251, 0),
    [640] = {.count = 1}, SHIFT(247, 0),
    [642] = {.count = 1}, SHIFT(246, 0),
    [644] = {.count = 1}, SHIFT(248, 0),
    [646] = {.count = 1}, SHIFT(249, 0),
    [648] = {.count = 1}, SHIFT(250, 0),
    [650] = {.count = 1}, SHIFT(254, 0),
    [652] = {.count = 1}, SHIFT(260, 0),
    [654] = {.count = 1}, SHIFT(257, 0),
    [656] = {.count = 1}, SHIFT(258, 0),
    [658] = {.count = 1}, SHIFT(259, 0),
    [660] = {.count = 1}, REDUCE(sym__call_arguments, 2, 0),
    [662] = {.count = 1}, SHIFT(263, 0),
    [664] = {.count = 1}, SHIFT(264, 0),
    [666] = {.count = 1}, SHIFT(266, 0),
    [668] = {.count = 1}, SHIFT(267, 0),
    [670] = {.count = 1}, SHIFT(268, 0),
    [672] = {.count = 1}, SHIFT(269, 0),
    [674] = {.count = 1}, SHIFT(270, 0),
    [676] = {.count = 1}, SHIFT(271, 0),
    [678] = {.count = 1}, SHIFT(274, 0),
    [680] = {.count = 1}, SHIFT(275, 0),
    [682] = {.count = 1}, SHIFT(288, 0),
    [684] = {.count = 1}, SHIFT(289, 0),
    [686] = {.count = 1}, SHIFT(276, 0),
    [688] = {.count = 1}, SHIFT(277, 0),
    [690] = {.count = 1}, SHIFT(278, 0),
    [692] = {.count = 1}, SHIFT(285, 0),
    [694] = {.count = 1}, SHIFT(286, 0),
    [696] = {.count = 1}, SHIFT(279, 0),
    [698] = {.count = 1}, SHIFT(280, 0),
    [700] = {.count = 1}, SHIFT(281, 0),
    [702] = {.count = 1}, SHIFT(282, 0),
    [704] = {.count = 1}, SHIFT(283, 0),
    [706] = {.count = 1}, SHIFT(284, 0),
    [708] = {.count = 1}, SHIFT(287, 0),
    [710] = {.count = 1}, SHIFT(290, 0),
    [712] = {.count = 1}, SHIFT(291, 0),
    [714] = {.count = 1}, SHIFT(293, 0),
    [716] = {.count = 1}, SHIFT(294, 0),
    [718] = {.count = 1}, SHIFT(295, 0),
    [720] = {.count = 1}, SHIFT(297, 0),
    [722] = {.count = 1}, SHIFT(298, 0),
    [724] = {.count = 1}, SHIFT(299, 0),
    [726] = {.count = 1}, SHIFT(301, 0),
    [728] = {.count = 1}, SHIFT(311, 0),
    [730] = {.count = 1}, SHIFT(312, 0),
    [732] = {.count = 1}, SHIFT(300, 0),
    [734] = {.count = 1}, SHIFT(307, 0),
    [736] = {.count = 1}, SHIFT(302, 0),
    [738] = {.count = 1}, SHIFT(303, 0),
    [740] = {.count = 1}, SHIFT(304, 0),
    [742] = {.count = 1}, SHIFT(305, 0),
    [744] = {.count = 1}, SHIFT(306, 0),
    [746] = {.count = 1}, SHIFT(308, 0),
    [748] = {.count = 1}, SHIFT(309, 0),
    [750] = {.count = 1}, SHIFT(310, 0),
    [752] = {.count = 1}, SHIFT(313, 0),
    [754] = {.count = 1}, SHIFT(315, 0),
    [756] = {.count = 1}, SHIFT(323, 0),
    [758] = {.count = 1}, SHIFT(320, 0),
    [760] = {.count = 1}, SHIFT(321, 0),
    [762] = {.count = 1}, SHIFT(322, 0),
    [764] = {.count = 1}, SHIFT(325, 0),
    [766] = {.count = 1}, SHIFT(326, 0),
    [768] = {.count = 1}, SHIFT(332, 0),
    [770] = {.count = 1}, SHIFT(328, 0),
    [772] = {.count = 1}, SHIFT(327, 0),
    [774] = {.count = 1}, SHIFT(329, 0),
    [776] = {.count = 1}, SHIFT(330, 0),
    [778] = {.count = 1}, SHIFT(331, 0),
    [780] = {.count = 1}, SHIFT(336, 0),
    [782] = {.count = 1}, REDUCE(sym_program, 2, 0),
    [784] = {.count = 1}, SHIFT(337, 0),
};

#pragma GCC diagnostic pop

EXPORT_LANGUAGE(ts_language_ruby);
