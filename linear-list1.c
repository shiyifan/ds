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
    // init unused nodes
    for (int i = 0; i < MAX_LENGTH - 1; i++) {
        a[i].data = '?';
        a[i].next = i + 1;
    }
    a[MAX_LENGTH - 1].data = '?';
    a[MAX_LENGTH - 1].next = 0;
    *p = a;
    return 0;
}

int destroy(Node* a) {
    free(a);
    return 0;
}

void prt(Node* a, int head) {
    int i = head;
    while (i) {
        printf("%c ", a[i].data);
        i = a[i].next;
    }
    printf("\n");
}

//return the allocated node's index
int mallok(Node* a) {
    if (!a->next) { // no remaining unused nodes
        return 0;
    }
    int i = a->next;
    a->next = a[a->next].next;
    return i;
}

void phree(Node* a, int i) {
    a[i].data = '?';
    a[i].next = a->next;
    a->next = i;
}

// a[0] points to the first node, a[1] points to the first unused node
int main() {
    Node* a = NULL;
    init(&a);
    
    int i = mallok(a);
    a[i].data = 'a';
    int j = mallok(a);
    a[j].data = 'b';
    int k = mallok(a);
    a[k].data = 'c';
    int l = mallok(a);
    a[l].data = 'd';
    a[i].next = j;
    a[j].next = k;
    a[k].next = l;
    a[l].next = 0;

    printf("collection a:\n");
    prt(a, i);

    int m = mallok(a);
    a[m].data = 'c';
    int n = mallok(a);
    a[n].data = 'd';
    int o = mallok(a);
    a[o].data = 'e';
    int p = mallok(a);
    a[p].data = 'f';
    a[m].next = n;
    a[n].next = o;
    a[o].next = p;
    a[p].next = 0;

    printf("collection b:\n");
    prt(a, m);

    return 0;
}
