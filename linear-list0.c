#include <stdio.h>
#include <stdlib.h>

// this file implements the insert and two link list merge operations
//
// the link list in this file has one head node, which doesn't store infomation.
//
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

// get the node in link list using the position i(starts from 1)
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

// merge the second link lists with the first link list in ascending order. 
// both of them are in ascending order before merged
int mergel(LinkList la, LinkList lb) {
    LNode *p = la;
    LNode *pa = la->next, *pb = lb->next;
    while (pa && pb) {
        if (pa->data < pb->data) {
            p->next = pa;
            pa = pa->next;
        } else {
            p->next = pb;
            pb = pb->next;
        }
        p = p->next;
    }
    p->next = pa ? pa : pb;
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
    n1->data = 'e';
    n1->next = n2;
    n2->data = 'h';
    n2->next = n3;
    n3->data = 'n';
    n3->next = n4;
    n4->data = 't';
    n4->next = NULL;
    l->data = '$';
    l->next = n0;

    LinkList l2 = (LinkList)malloc(sizeof(LNode));
    LNode *n20 = (LNode*)malloc(sizeof(LNode));
    LNode *n21 = (LNode*)malloc(sizeof(LNode));
    LNode *n22 = (LNode*)malloc(sizeof(LNode));
    LNode *n23 = (LNode*)malloc(sizeof(LNode));
    n20->data = 'b';
    n20->next = n21;
    n21->data = 'c';
    n21->next = n22;
    n22->data = 'f';
    n22->next = n23;
    n23->data = 'v';
    n23->next = NULL;
    l2->data = '$';
    l2->next = n20;

    printf("l: ");
    printl(l);
    printf("l2: ");
    printl(l2);

    mergel(l, l2);

    printf("merged: ");
    printl(l);

    printf("l2: ");
    printl(l2);


    freel(l);
    return 0;
}
