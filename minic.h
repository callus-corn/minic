#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...);

typedef enum {
    TK_RETURN,
    TK_RESERVED,
    TK_IDENT,
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
typedef struct LVar LVar;
struct LVar{
    LVar *next;
    char *name;
    int len;
    int offset;
};
extern LVar *locals;
bool consume(char *op);
void expect(char *op);
Token *consume_ident();
int expect_number();
bool at_eof();
Token *tokenize(char *p);

typedef enum {
    ND_ADD,
    ND_SUB,
    ND_MUL,
    ND_DIV,
    ND_ASSIGN,
    ND_EQ,
    ND_NE,
    ND_LT,
    ND_LE,
    ND_RETURN,
    ND_LVAR,
    ND_NUM,
} NodeKind;
typedef struct  Node Node;
struct Node {
    NodeKind kind;
    Node *lhs;
    Node *rhs;
    int val;
    int offset;
};
extern Node *code[100];
void program();
void gen(Node *node);
