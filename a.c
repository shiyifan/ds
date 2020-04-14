#include <stdio.h>
#include <stdlib.h>

// the i as the function parameter standing for the position not index starts from 1 

typedef struct LNode {
    char data;
    struct LNode* next;
} LNode, *LinkList;

void printl(LinkList l) {
    LNode *p = l;
    while (p) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

void freel(LinkList l) {
    LNode *p0 = l;
    LNode *p1 = NULL;
    while (p0) {
        p1 = p0->next;
        free(p0);
        p0 = p1;
    }
}

int nodel(LinkList l, int i, LNode** node) {
    LNode* p0 = l->next;
    int i0 = i;
    while (p0 && --i0 > 0) {
        p0 = p0->next;
    }
    if (!p0) return -1;
    *node = p0;
    return 0;
}

int getl(LinkList l, int i, char *data) {
    LNode* node;
    int res = nodel(l, i, &node);
    if (res == -1) return -1;
    *data = node->data;
    return 0;
}

int insertl(LinkList l, int i, char c) {
    LNode* target;
    int res = nodel(l, i - 1 , &target);
    if (res == -1) return -1;
    LNode* new_node = (LNode*)malloc(sizeof(LNode));
    new_node->data = c;
    new_node->next = target->next;
    target->next = new_node;
    return 0;
}

int main() {
    LinkList l = (LinkList)malloc(sizeof(LNode));
    LNode* n0 = (LNode*)malloc(sizeof(LNode));
    LNode* n1 = (LNode*)malloc(sizeof(LNode));
    LNode* n2 = (LNode*)malloc(sizeof(LNode));
    LNode* n3 = (LNode*)malloc(sizeof(LNode));
    LNode* n4 = (LNode*)malloc(sizeof(LNode));
    n0->data = 'a';
    n0->next = n1;
    n1->data = 'b';
    n1->next = n2;
    n2->data = 'c';
    n2->next = n3;
    n3->data = 'd';
    n3->next = n4;
    n4->data = 'e';
    n4->next = NULL;
    l->data = '$';
    l->next = n0;

    printl(l);
    int res = insertl(l, 6, 'z');
    if (res == -1) return -1;
    printl(l);

    freel(l);
    return 0;
}
