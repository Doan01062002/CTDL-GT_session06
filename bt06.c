#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct Stack {
    char arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char value) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = value;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return '\0';
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isValidExpression(char *expr) {
    Stack s;
    initStack(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char current = expr[i];

        if (current == '(' || current == '{' || current == '[') {
            push(&s, current);
        }

        else if (current == ')' || current == '}' || current == ']') {
            if (isEmpty(&s)) {
                return 0;
            }
            char top = pop(&s);
            if (!isMatchingPair(top, current)) {
                return 0;
            }
        }
    }

    return isEmpty(&s);
}

int main() {
    char expr[MAX];

    printf("Nhap bieu thuc: ");
    fgets(expr, MAX, stdin);

    size_t len = strlen(expr);
    if (len > 0 && expr[len - 1] == '\n') {
        expr[len - 1] = '\0';
    }

    if (isValidExpression(expr)) {
        printf("Bieu thuc hop le\n");
    } else {
        printf("Bieu thuc khong hop le\n");
    }

    return 0;
}

