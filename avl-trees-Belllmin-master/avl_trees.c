#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binaryTree.h"
#define ARRAY_LENGTH 10

bool check_if_tree_is_balanced(struct _NODE*);
void balance_tree(int, struct _NODE*, int);
void insert(struct _NODE*, int);
void print_tree(struct _NODE*);
int main()
{
  // Insertion in a Self-Balancing Tree - Into a binary search tree
  struct _NODE *root = NULL;
  int numbers[ARRAY_LENGTH] = { 10, 16, 22, 18, 34, 47, 33, 32, 8, 6 };

  for (int i = 0; i < ARRAY_LENGTH; i++)
  {
    insert(root, numbers[i]);
    print_tree(root);
  }
  if(check_if_tree_is_balanced(root))
  {
    balance_tree(0, root, ARRAY_LENGTH - 1);
    printf("Balanced tree: \n");
    print_tree(root);
  }
}

void print_tree(struct _NODE *root)
{
  print_tree(root->left);
  printf("%d ", root->data);
  print_tree(root->right);
}
void insert(struct _NODE *root, int data)
{
  if(root == NULL)
  {
    root = (struct _NODE*)malloc(sizeof(struct _NODE));
    root->data = data;
  }
  else if(data <= root->data)
  {
      insert(root->left, data);
  }
  else
  {
      insert(root->right, data);
  }
}
bool check_if_tree_is_balanced(struct _NODE *root)
{
  if(root == NULL) return 0;

  int left = check_if_tree_is_balanced(root->left);
  int right = check_if_tree_is_balanced(root->right);

  int mid = left - right;
  if(mid <= 1)
  {
    check_if_tree_is_balanced(root->left);
    return 1;
  }
  else
  {
    check_if_tree_is_balanced(root->right);
    return 1;
  }
  return 0;
}
void balance_tree(int start, struct _NODE *root, int end)
{
  if(start < end)
  {
    int mid = (start + end) / 2;
    insert(root->left, mid - 1);
    insert(root->right, mid + 1);
  }
}
