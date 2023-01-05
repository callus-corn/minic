#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...);

typedef enum {
    TK_RESERVED,
    TK_NUM,
    TK_EOF,
} TokenKind;
typedef struct Token Token;
struct Token {
    TokenKind kind;
    Token *next;
    int val;
    char *str;
    int len;
};
extern Token *token;
bool consume(char *op);
void expect(char *op);
int expect_number();
bool at_eof();
Token *tokenize(char *p);

typedef enum {
    ND_ADD,
    ND_SUB,
    ND_MUL,
    ND_DIV,
    ND_EQ,
    ND_NE,
    ND_LT,
    ND_LE,
    ND_NUM,
} NodeKind;
typedef struct  Node Node;
struct Node {
    NodeKind kind;
    Node *lhs;
    Node *rhs;
    int val;
};
Node *ast();
void gen(Node *node);
