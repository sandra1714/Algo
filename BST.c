// This file implements the Binary Search Tree functionalities.

#include <stdlib.h>
#include <stdio.h>

typedef struct treeNode {
  int data;
  struct treeNode *left;
  struct treeNode *right;
  struct treeNode *parent;
} treeNode;

treeNode * Insert(treeNode *node, int data) {

  if (node==NULL) {
    treeNode *temp;
    temp = (treeNode *)malloc(sizeof(treeNode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
  }

  if (data > node->data)
    node->right = Insert(node->right, data);
  else if (data < node->data)
    node->left = Insert(node->left, data);

  return node; // This is needed
  
}

// The parent is used.
treeNode * InsertIter(treeNode *node, int data) {

  treeNode *y, *x, *z; //*y is the parent, *x is used to iterate, and *z is the new node.

  // Initialize the pointers to NULL
  x = NULL;
  y = NULL;
  z = NULL;
  
  // First construct a node containing data.
  z = (treeNode *)malloc(sizeof(treeNode));
  z->data = data;
  z->parent = NULL;
  z->left = NULL;
  z->right = NULL;

  // Find the position in which z should be inserted.
  x = node;
  while (x != NULL){
    y = (treeNode *)malloc(sizeof(treeNode));
    y = x; // Keep the previous value of x which will be the parent.
    if (data < x->data)
      x = x->left;
    else
      x = x->right;
    z->parent = y;
  }

  // Now insert z into the correct position found above.
  if (y == NULL) // the tree was empty
    node = z;
  else if (data < y->data)
    y->left = z;
  else
    y->right = z;

  return node;
}


void InorderTreeWalk (treeNode *node){

  if (node != NULL) {
    InorderTreeWalk(node->left);
    printf("%d ", node->data);
    InorderTreeWalk(node->right);
  }
}


treeNode * treeSearch(treeNode *node, int k){

  if (node==NULL || k==node->data)
    return node;
  else if (k < node->data)
    return treeSearch(node->left, k);
  else
    return treeSearch(node->right, k);
}


treeNode *iterTreeSearch(treeNode *node, int k){

  while (node!=NULL && k!=node->data){
    if (k < node->data)
      node = node->left;
    else
      node = node->right;
  }
  return node;
}


treeNode *treeMin(treeNode *node) {

  while (node->left != NULL)
    node = node->left;
  return node;
}


treeNode *treeMax(treeNode *node) {

  while (node->right != NULL)
    node = node->right;
  return node;
}


int main() {
  
  int array[8] = {2, 12, 18, 9, 15, 5, 19, 17};

  // Create a BST using the array.
  treeNode *root = NULL, *searchNode = NULL, *minNode = NULL, *maxNode = NULL;
  
  for (int i=0; i<8; i++){
    //root = Insert(root, array[i]);
    root = InsertIter(root, array[i]);
    if (root != NULL)
      printf("%d\n", root->data);
    else
    printf("%s\n", "NULL root");
  }
  
  InorderTreeWalk(root);
  printf("\n");

  //searchNode = treeSearch(root, 3);
  searchNode = iterTreeSearch(root, 5);
  if (searchNode != NULL)
    printf("searchNode data is %d\n", searchNode->data);
  else
    printf("key not found\n");

  minNode = treeMin(root);
  if (minNode != NULL)
    printf("minNode data is %d\n", minNode->data);
  else
    printf("key not found\n");

  maxNode = treeMax(root);
  if (maxNode != NULL)
    printf("maxNode data is %d\n", maxNode->data);
  else
    printf("key not found\n");
  
}
