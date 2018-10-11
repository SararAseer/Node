#include <stdio.h>
#include <stdlib.h>
struct node { int i; struct node *n; };

void print_list(struct node *h){
  while(h->n){
    printf("%d\n", h->i);
    h=h->n;
  }
}

struct node * insert_front(int x, struct node *s){
  struct node *c=malloc(sizeof(struct node));
  c->i=x;
  c->n=s;
  return  c;
}


struct node * free_list(struct node *a){
  while(a){
    struct node *b=a->n;
    free(a);
    a=b;
  }
  return a;
}


int main(){
  printf("Makes a zero'th node with 0 as its data \n");
  struct node * n = insert_front(0,0);
  print_list(n);

  printf("Makes first node and inserts a 2 at the front\n");
  struct node *n1  = insert_front(2,n);
  print_list(n1);

  printf("Second node and inserts a 1 at the front\n");
  struct node *n2  = insert_front(1, n1);
  print_list(n2);

  printf("Freeing list: %p\n", free_list(n2));

  return 0;
}
