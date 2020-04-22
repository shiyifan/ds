// static link list using the array

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

typedef struct {
    char data;
    int next;
} Node;

int init(Node** p) {
    Node* a = (Node*)malloc(MAX_LENGTH * sizeof(Node));
    // init head node
    a[0].next = 0;
    // init unused nodes
    for (int i = 1; i < MAX_LENGTH - 1; i++) {
        a[i].data = '?';
        a[i].next = i + 1;
    }
    a[MAX_LENGTH - 1].next = 0;
    *p = a;
    return 0;
}

int destroy(Node* a) {
    free(a);
    return 0;
}

void prt(Node* a) {
    int i = a[0].next;
    while (i) {
        printf("%c ", a[i].data);
        i = a[i].next;
    }
}

//return the allocated node's index
int mallok(Node* a) {
    Node* unused = a + 1;
    if (!unused->next) { // no remaining unused nodes
        return 0;
    }
    int i = unused->next;
    unused->next = a[unused->next].next;
    return i;
}

void phree(Node* a, int i) {
    Node* unused = a + 1;
    a[i].data = '?';
    a[i].next = unused->next;
    unused->next = i;
}

// a[0] points to the first node, a[1] points to the first unused node
int main() {
    Node* a = NULL;
    init(&a);
    int i = mallok(a);
    printf("%d\n", i);
    printf("%d\n", a[1].next);
    phree(a, i);
    printf("%d\n", a[1].next);
    return 0;
}
