#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <tree_sitter/parser.h>

enum TokenType {
    HERE_STRING_BODY,
};

// a hand written string implmentation
// data[0], data[1], ..., data[len-1] is the content of string
// data[len] is `\0` for typical string `char*` compatibility
// So 0 <= len < cap
typedef struct {
    size_t len;
    size_t cap;
    char *data;
} String;

static void check_alloc(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Scanner: Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
}

static String string_new(void) {
    size_t init_len = 16;
    // (init_len + 1) for null terminator
    size_t cap = init_len + 1;
    void *tmp = calloc(1, sizeof(char) * cap);
    check_alloc(tmp);
    return (String){.cap = cap, .len = 0, .data = tmp};
}

static void string_resize(String *vec, size_t new_cap) {
    void *block = realloc(vec->data, new_cap * sizeof(char));
    check_alloc(block);
    vec->data = block;
    vec->cap = new_cap;
    memset(vec->data + vec->len, 0, (new_cap - vec->len) * sizeof(char));
}

static void string_push(String *vec, int32_t elem) {
    if (vec->len + sizeof(elem) >= vec->cap) {
        // vec->cap * 2 + 1 > vec->len + sizeof(elem) always holds
        // as vec->cap > 16
        string_resize(vec, vec->cap * 2 + 1);
    }
    // NOTE: we don't consider little-endian/big-endian here
    // the character in string is only for compare.
    // They only need to be store in consistent way
    memcpy(vec->data + vec->len, &elem, sizeof(elem));
    vec->len += sizeof(elem);
}

static void string_free(String *vec) {
    if (vec->data != NULL) {
        free(vec->data);
        vec->data = NULL;
        vec->len = 0;
        vec->cap = 0;
    }
}

static void string_clear(String *vec) {
    memset(vec->data, 0, vec->len * sizeof(char));
    vec->len = 0;
}

static void advance(TSLexer *lexer) {
    lexer->advance(lexer, false);
}

static void skip(TSLexer *lexer) {
    lexer->advance(lexer, true);
}

// NOTE: only "\n" is allowed as newline here,
// It implies that "\r" can also be terminator.
static bool isnewline(int32_t chr) {
    return chr == '\n';
}

// `read_line` read strings until a newline or EOF
static void read_line(String *str, TSLexer *lexer) {
    while (!isnewline(lexer->lookahead) && !lexer->eof(lexer)) {
        string_push(str, lexer->lookahead);
        advance(lexer);
    }
}

// Suppose terminator is `T`, newline (\n) is `$`,
// It should accept "#<<T$T" or "#<<T$...$T", where `...`
// is the string content.
bool scan(TSLexer *lexer, const bool *valid_symbols) {
    if (!valid_symbols[HERE_STRING_BODY]) {
        return false;
    }

    String terminator = string_new();
    read_line(&terminator, lexer);

    if (lexer->eof(lexer)) {
        return false;
    }

    // skip `\n`
    skip(lexer);

    String current_line = string_new();
    while (true) {
        read_line(&current_line, lexer);
        if (strcmp(terminator.data, current_line.data) == 0) {
            lexer->result_symbol = HERE_STRING_BODY;
            return true;
        }
        if (lexer->eof(lexer)) {
            return false;
        }
        string_clear(&current_line);
        // skip `\n`
        skip(lexer);
    }
}

void *tree_sitter_racket_external_scanner_create() {
    return NULL;
}

unsigned tree_sitter_racket_external_scanner_serialize(void *payload,
                                                       char *buffer) {
    return 0;
}

void tree_sitter_racket_external_scanner_deserialize(void *payload,
                                                     const char *buffer,
                                                     unsigned length) {
}

bool tree_sitter_racket_external_scanner_scan(void *payload,
                                              TSLexer *lexer,
                                              const bool *valid_symbols) {
    return scan(lexer, valid_symbols);
}

void tree_sitter_racket_external_scanner_destroy(void *payload) {
}
