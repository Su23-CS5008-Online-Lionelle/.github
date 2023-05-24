

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct list {
    node_t *head;
}list_t;

void push_using_stack(list_t* lst, int data)
{
    node_t tmp;
    tmp.data = data;
    tmp.next = lst->head;
    lst->head = &tmp;
}

void push_using_heap(list_t* lst, int data) {
    node_t* tmp = (node_t*)malloc(sizeof(node_t));
    tmp->data = data;
    tmp->next = lst->head;
    lst->head = tmp;
}

list_t * create_list() {
    list_t *lst = (list_t*)malloc(sizeof(list_t));
    lst->head = NULL;
    return lst;
}

void free_lst(list_t *lst) {
    struct node *current = lst->head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current);
        current = next;
    }
    free(lst);
}

void print_list(list_t *lst) {
    struct node *current = lst->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}



int main(int argc, char const *argv[])
{
    list_t *lst = create_list();
    push_using_heap(lst, 1);
    push_using_heap(lst, 2);
    push_using_heap(lst, 3);
 
    print_list(lst);

    push_using_stack(lst, 4);
    push_using_stack(lst, 5);
    push_using_stack(lst, 6);

    //print_list(lst);
    free_lst(lst);

    return 0; // error code, no errors
}
