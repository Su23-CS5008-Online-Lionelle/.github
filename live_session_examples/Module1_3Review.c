

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define HELLO 0

typedef struct node {
    int data;
    struct node* next;
} node_t;

typedef struct list {
    node_t * head;
} list_t;

typedef list_t neu_list;

void push(neu_list * list) {  
    node_t * nw = (node_t*) malloc(sizeof(node_t));
    nw->data = HELLO;
    nw->next = list->head;
    list->head = nw;
}

void print_array(int * arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int * explore_arrays(int size) {
    int * arr = calloc(size, sizeof(int));
    arr[0] = 9;
    arr[1] = 13;
    arr[3] = 19191911;
    return arr;
}

/*int * explore_arrays2() {
    int array[] = {0, 1, 2, 3, 4, 5};

    return &array;
}*/


void pointer_games2(int ** array) {
    *array[1] = 200;
    *array = explore_arrays(10);

}

void pointer_games() {

    int * array = explore_arrays(4);

    print_array(array, 4);

    pointer_games2(&array);

    print_array(array, 4);

    free(array);    
}


int main(int argc, char const *argv[])
{
    int * my_array = explore_arrays(10);
    
    print_array(my_array, 10);
    
    free(my_array);

    pointer_games();

    // bad idea - will break your code
    // int * arr2 = explore_arrays2();
    // print_array(arr2, 6);


    return 0; // error code, no errors
}
