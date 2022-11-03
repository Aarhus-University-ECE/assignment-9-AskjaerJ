/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"


void DFT (node * root) {
  stack*x = (stack*)malloc(sizeof(stack));
  x->next = NULL;
  push(x, root);
  while (!(isEmpty(x))) {
    node* temp = pop(x)->node;
    print_node(temp);
    if(temp->rchild != NULL) {
      push(x, temp->rchild);
    }
    if(temp->lchild != NULL) {
      push(x, temp->lchild);
    }
  }
  printf("\n");
	// Implement DFS
	// Hint: You can use print_node, print_tree and/or print_stack.
}

node *make_node (int num, node * left, node * right) {
  node*new = (node*)malloc(sizeof(node));
  new->num = num;
  new->lchild = left;
  new->rchild = right;
  return new;
}

void free_node (node * p) {
	
}


void print_node (node * p) {

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d, ", p->num);
}


void print_tree (node * p, int depth) {
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

stack *push (stack * topp, node * node)
{
	stack*next_node = (stack*)malloc(sizeof(stack)); /* Allocates memory to new node next_node */
  next_node->node = node; /* Sets node equal to current data  */
  next_node->next = topp->next;
  topp->next = next_node;
}

bool isEmpty (stack * topp)
{
  return topp->next == NULL;
}

node *top (stack * topp)
{
	return 0;
}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack * topp)
{
  stack*temp = 0;
  temp = topp->next;
  stack*t = topp->next;
  topp->next = topp->next->next;
  return temp;
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}
