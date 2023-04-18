//
// Created by 吴映鹏 on 2023/4/16.
//

#ifndef DCLIST_DCLIST_H
#define DCLIST_DCLIST_H

#include "common.h"

#define DcList_ElemType int

typedef struct DCListNode {
    DcList_ElemType data;
    struct DCListNode *prev;
    struct DCListNode *next;
} DCListNode, *DCList;

//函数声明
void DCListInit(DCList *phead);

void DCListPushBack(DCList phead, DcList_ElemType value);

void DCListPushFront(DCList phead, DcList_ElemType value);

void DCListPopBack(DCList phead);

void DCListPopFront(DCList phead);

void DCListShow(DCList phead);

DCListNode *DCListFind(DCList phead, DcList_ElemType key);

void DCListDeleteByVal(DCList phead, DcList_ElemType key);

size_t DCListLength(DCList phead);

void DCListInsertByVal(DCList phead, DcList_ElemType value);

void DCListReverse(DCList phead);

void DCListClear(DCList phead);

void DCListDestroy(DCList *phead);

void DCListSort(DCList phead);

//函数定义
void DCListInit(DCList *phead) {
    assert(phead != NULL);
    *phead = (DCListNode *) malloc(sizeof(DCListNode));
    (*phead)->next = *phead;
    (*phead)->prev = *phead;
}

void DCListPushBack(DCList phead, DcList_ElemType value) {
    assert(phead != NULL);
    DCListNode *s = (DCListNode *) malloc(sizeof(DCListNode));
    assert(s != NULL);
    s->data = value;

    s->next = phead;
    s->prev = phead->prev;
    s->prev->next = s;
    s->next->prev = s;
}

void DCListShow(DCList phead) {
    assert(phead != NULL);
    DCListNode *p = phead->next;
    while (p != phead) {
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("over\n");
}

void DCListPushFront(DCList phead, DcList_ElemType value) {
    assert(phead != NULL);
    DCListNode *s = (DCListNode *) malloc(sizeof(DCListNode));
    assert(s != NULL);
    s->data = value;

    s->next = phead->next;
    s->prev = phead;
    s->next->prev = s;
    s->prev->next = s;
}

DCListNode *DCListFind(DCList phead, DcList_ElemType key) {
    assert(phead != NULL);
    DCListNode *p = phead->next;
    while (p->next != phead && p->data != key)
        p = p->next;
    if (p == phead)
        return NULL;
    return p;
}

void DCListDeleteByVal(DCList phead, DcList_ElemType key) {
    assert(phead != NULL);
    DCListNode *p = DCListFind(phead, key);
    if (p != NULL) {
        p->next->prev = p->prev;
        p->prev->next = p->next;
        free(p);
    }
}

void DCListPopBack(DCList phead) {
    assert(phead != NULL);
    DCListNode *p = phead->prev;
    p->prev->next = phead;
    //phead->prev = p->prev;
    p->next->prev = p->prev;
    free(p);
}

void DCListPopFront(DCList phead) {
    assert(phead != NULL);
    DCListNode *p = phead->next;
    if (p != phead) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
}

size_t DCListLength(DCList phead) {
    assert(phead != NULL);
    DCListNode *p = phead->next;
    size_t count = 0;
    while (p != phead) {
        ++count;
        p = p->next;
    }
    return count;
}

void DCListInsertByVal(DCList phead, DcList_ElemType value) {
    assert(phead != NULL);
    DCListNode *s = (DCListNode *) malloc(sizeof(DCListNode));
    assert(s != NULL);
    s->data = value;

    DCListNode *p = phead->next;
    while (value > p->data && p != phead)
        p = p->next;

    s->next = p;
    s->prev = p->prev;
    s->prev->next = s;
    s->next->prev = s;
}

void DCListReverse(DCList phead) {
    assert(phead != NULL);
    DCListNode *p = phead->next;
    DCListNode *q = p->next;

    p->next = phead;
    phead->prev = p;

    while (q != phead) {
        p = q;
        q = q->next;

        p->next = phead->next;
        p->prev = phead;
        p->prev->next = p;
        p->next->prev = p;
    }
}

void DCListClear(DCList phead) {
    assert(phead);
    DCListNode *p = phead->next;
    while (p != phead) {
        //DCListNode *q = p->next;
        p->prev->next = p->next;
        p->next->prev = phead;
        free(p);
        p = phead->next;
        //p = q;
    }
}

void DCListDestroy(DCList *phead) {
    DCListClear(*phead);
    free(*phead);
    *phead = NULL;
}

void DCListSort(DCList phead) {
    assert(phead != NULL);
    DCListNode *p = phead->next;
    DCListNode *q = p->next;
    DCListNode *s = phead->next;
    p->next = phead;
    phead->prev = p;
    p = q;
    q = q->next;
    while (p != phead) {
        if (p->data < s->data) {
            p->next = s;
            p->prev = s->prev;
            p->next->prev = p;
            p->prev->next = p;
            s = phead->next;
        } else {
            if (s->next == phead) {
                p->next = phead;
                p->prev = s;
                p->prev->next = p;
                p->next->prev = p;
                s = phead->next;
            } else {
                s = s->next;
                continue;
            }
        }
        p = q;
        q = q->next;
    }
}

#endif //DCLIST_DCLIST_H
