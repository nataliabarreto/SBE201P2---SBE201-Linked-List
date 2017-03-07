#include <stdio.h>
#include <stdlib.h>
 
typedef struct node {
    int val;
    struct node * next;
} node_t;
 
void print_list(node_t * head) {
    if(!head) printf("empty\n");
    else{
        node_t * current = head;
        while (current != NULL) {
            printf("%d ", current->val);
            current = current->next;
        }
        printf("\n");
    }
}
 
int length(node_t *head) {
   int length = 0;
   node_t *current;
   
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
   
   return length;
}
 
void push_front(node_t ** head, int val) {
    node_t * new_node;
    new_node = malloc(sizeof(node_t));
 
    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}
 
void push(node_t * head, int index ,int val) {
    if(!index) {
        push_front(&head,val);
        return;
    }
    node_t * current = head;
    int i=0;
    while (!(current->next == NULL || i==index-1)) {
        current = current->next;
        i++;
    }
 
    /* now we can add a new variable */
    node_t * aux = current->next;
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = aux;
}
 
int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;
 
    if (*head == NULL) {
        return -1;
    }
 
    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;
 
    return retval;
}
 
int remove_by_index(node_t ** head, int n) {
    int i = 0;
    int retval = -1;
    node_t * current = *head;
    node_t * temp_node = NULL;
 
    if (n == 0) {
        return pop(head);
    }
 
    for ( i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }
 
    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);
 
    return retval;
 
}
 
int main(){
    node_t * head = NULL;
    char op,c;
    int a,b;
 
    char tmp;
    int M, N;
 
    while(scanf("%c", &tmp) && (tmp != 'q'))
    {    switch(tmp)
        {    case 'f':
                scanf("%d", &N);
                push_front(&head, N);
                break;
            case 'i':
                scanf("%d %d", &M, &N);
                push(head, N, M);
                break;
            case 'r':
                pop(&head);
                break;
            case 'd':
                scanf("%d", &M);
                remove_by_index(&head, M);
        }
 
        scanf("%c", &tmp);
        print_list(head);
    }
}
