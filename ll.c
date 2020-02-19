#include "ll.h"

void insert_node(head_t *head)
{
    node_t *node = NULL;
    unsigned int input = 0;
    printf("Please enter the key to be inserted\n");
    scanf("%d", &input);

    node = (node_t *)malloc(sizeof(node_t));

    node->key = input;

    INSERT_AT_LAST(head, node);
}

void delete_node(head_t *head)
{
    node_t *node = NULL;
    int input = 0;

    printf("Please enter the key you want to delete\n");
    scanf("%d", &input);

    node = head->first;
    while(node != (void *)head) {
        if (node->key == input) {
            DELETE_NODE(head, node);
            break;
        }
        node = node->next;
    }
}

void delete_last_node(head_t *head)
{
    DELETE_LAST_NODE(head);
}

void delete_first_node(head_t *head)
{
    DELETE_FIRST_NODE(head);
}

void show_list(head_t *head)
{
    node_t *node = NULL;

    node = head->first;

    printf("\n");

    while(node != (void *)head) {
        printf("%d->", node->key);
        node = node->next;
    }

    printf("NULL\n");
}

void seprate_even_odd(head_t *head, head_t *even, head_t *odd)
{
    bool is_odd = false;
    node_t *node = NULL;

    node = head->first;
    while(node != (void *)head) {
        REMOVE_NODE(head, node);
        if(is_odd) {
            INSERT_AT_FIRST(odd, node);
        } else {
            INSERT_AT_LAST(even, node);
        }
        is_odd = !is_odd;
        node = head->first;
    }

    printf("Showing head list");
    show_list(head);

    printf("Showing even list");
    show_list(even);

    printf("Showing odd list");
    show_list(odd);
}

void join_even_odd(head_t *head, head_t *even, head_t *odd)
{
    bool is_odd = false;
    node_t *node = NULL;

    while (GET_NODE_COUNT(even) || GET_NODE_COUNT(odd)) {
        if (is_odd) {
            node = odd->last;
            if (node != (void *)odd) {
                REMOVE_NODE(odd, node);
                INSERT_AT_LAST(head, node);
            }
        } else {
            node = even->first;
            if (node != (void *)even) {
                REMOVE_NODE(even, node);
                INSERT_AT_LAST(head, node);
            }
        }
        is_odd = !is_odd;
    }

}
