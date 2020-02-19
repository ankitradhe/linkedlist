#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct node_t_ {
    int key;
    struct node_t_ *next;
    struct node_t_ *prev;
} node_t;

typedef struct head_t_ {
    node_t *first;
    node_t *last;
    int count;
} head_t;


#define RESET_HEAD(head)  do {    \
    (head)->first = (void *)(head);   \
    (head)->last = (void *)(head);    \
    (head)->count = 0;      \
} while(0)

#define INSERT_AT_FIRST(head, node)  do {   \
    if (!(head)->count) {                   \
        (head)->last = node;                \
        node->next = (void *)(head);        \
    } else {                                \
        node->next = (head)->first;         \
        (head)->first->prev = node;         \
    }                                       \
    node->prev = (void *)(head);            \
    (head)->first = node;                   \
    (head)->count++;                        \
} while(0)

#define INSERT_AT_LAST(head, node) do {     \
    if (!(head)->count) {                   \
        (head)->first = node;               \
        node->prev = (void *)(head);        \
    } else {                                \
        node->prev = (head)->last;          \
        (head)->last->next = node;          \
    }                                       \
    node->next = (void *)(head);            \
    (head)->last = node;                    \
    (head)->count++;                        \
} while(0)

#define DELETE_FIRST_NODE(head)  do {           \
    node_t *node;                               \
    if (head->count) {                          \
        node = head->first;                     \
        (head)->first = (head)->first->next;    \
        (head)->count--;                        \
        if (!(head)->count) {                   \
            (head)->last = (void *)(head);      \
        }                                       \
        free(node);                             \
    }                                           \
} while(0)

#define DELETE_LAST_NODE(head)  do {            \
    node_t *node;                               \
    if ((head)->count) {                        \
        node = (head)->last;                    \
        (head)->last = (head)->last->prev;      \
        (head)->count--;                        \
        if (!(head)->count) {                   \
            (head)->first = (void *)(head);     \
        }                                       \
        free(node);                             \
    }                                           \
} while (0)

#define REMOVE_NODE(head, node)  do {           \
    if (node->prev == node->next) {             \
        head->first = (void *)head;             \
        head->last = (void *)head;              \
    } else if (node->prev == (void*)head) {     \
        head->first = node->next;               \
        node->next->prev = node->prev;          \
    } else if (node->next == (void*)head) {     \
        head->last = node->prev;                \
        node->prev->next = node->next;          \
    } else {                                    \
        node->next->prev = node->prev;          \
        node->prev->next = node->next;          \
    }                                           \
    head->count--;                              \
} while(0)

#define DELETE_NODE(head, node)  do {           \
    REMOVE_NODE(head, node);                    \
    free(node);                                 \
} while(0)

#define GET_NODE_COUNT(head)    (head)->count

void insert_node(head_t *head);

void delete_node(head_t *head);

void delete_last_node(head_t *head);

void delete_first_node(head_t *head);

void show_list(head_t *head);

void seprate_even_odd(head_t *head, head_t *even, head_t *odd);

void join_even_odd(head_t *head, head_t *even, head_t *odd);
