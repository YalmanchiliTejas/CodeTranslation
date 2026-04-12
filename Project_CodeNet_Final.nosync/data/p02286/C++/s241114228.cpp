#include<string>
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
/*
struct Node{
  Node *right, *left;
  int key, priority;
};

Node* node(int k, int p){
  Node *newNode = new Node();//(Node *)malloc(sizeof(Node));
  newNode->right = NULL;
  newNode->left = NULL;
  newNode->key = k;
  newNode->priority = p;
  return newNode;
}
*/

class Node{
public:
  Node *right, *left;
  int key, priority;
  Node( int k, int p ) {
    right = NULL;
    left = NULL;
    key = k;
    priority = p;
  }
};

Node* rightRotate(Node *t){
  Node *s = t->left;
  t->left = s->right;
  s->right = t;
  return s; //the new root of subtree
}

Node* leftRotate(Node *t){
  Node *s = t->right;
  t->right = s->left;
  s->left = t;
  return s; //the new root of subtree
}

Node* insertT(Node *t, int k, int p){
  //when you reach the leaf
  // if(t == NULL) return node(k, p);  //create a new Node
  if(t == NULL) return new Node(k, p);  //create a new Node

  //ignore duplicated keys
  if(k == t->key) return t;

  if(k < t->key){  //move to the left child
    //update the pointer to the left child
    t->left = insertT(t->left, k, p);
    //if the left child has higher priority
    if(t->priority < t->left->priority) t = rightRotate(t);
  }else{//move to the right child
    //update the pointer t the right child
    t->right = insertT(t->right, k, p);
    //if the right child has higher priority
    if(t->priority < t->right->priority) t = leftRotate(t);
  }

  return t;
}

Node* find(Node* t, int k){
  while(t != NULL && k != t->key){//leafじゃない && みつかっていない
    if(k < t->key) t = t->left;
    else t = t->right;
  }
  return t;
}

 Node* deleteNode(Node *t, int k){
  if(t == NULL) return NULL;
  //if t is the targer node
  if(k == t->key){
    //if t is a leaf
    if(t->left == NULL && t->right == NULL) return NULL;
    //if t has only the right child
    else if(t->left == NULL) t = leftRotate(t);
    //if t has only the left child
    else if(t->right == NULL) t = rightRotate(t);
    //if t has both the left and right child
    else{
      //pull up the child with higher priority
      if(t->left->priority > t->right->priority) t = rightRotate(t);
      else t = leftRotate(t);
    }
    return deleteNode(t, k);
  }

  //search the targer recursively
  if(k < t->key) t->left = deleteNode(t->left, k);
  else t->right = deleteNode(t->right, k);

  return t;
}

void inorder(Node* t){
  if(t == NULL) return;
  inorder(t->left);
  printf(" %d", t->key);
  inorder(t->right);
}

void preorder(Node* t){
  if(t == NULL) return;
  printf(" %d", t->key);
  preorder(t->left);
  preorder(t->right);
}

void print(Node* t){
  inorder(t);
  printf("\n");
  preorder(t);
  printf("\n");
}

int main(){
  int n, k, p;
  string com;
  Node *t = NULL;//root

  cin >> n;
  for(int i=0 ; i<n ; ++i){
    cin >> com;
    if(com == "insert"){
      cin >> k >> p;
      t = insertT(t, k, p);
    }else if(com == "delete"){
      cin >> k;
      t = deleteNode(t, k);
    }else if(com == "print"){
      print(t);
    }else if(com == "find"){
      cin >> k;
      Node* n = find(t, k);
      if(n != NULL) cout << "yes" << endl;
      else cout << "no" << endl;
    }
  }
}

