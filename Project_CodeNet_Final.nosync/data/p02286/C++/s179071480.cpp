#include <iostream>
using namespace std;

typedef struct node{
  int key;
  int priority;
  struct node *left;
  struct node *right;
}node;

node * Delete(node **, int);
node * _delete(node **, int);

int find(node *p, int x){
  while(p != NULL){
    if(p->key == x) return 1;
    else if(p->key > x) p = p->left;
    else p = p->right;
  }
  return 0;
}

void inorder(node *p){
  if(p->left != NULL) inorder(p->left);

  cout  << " " << p->key;

  if(p->right != NULL) inorder(p->right);

  return;
}

void preorder(node *p){
  cout << " " << p->key;

  if(p->left != NULL) preorder(p->left);

  if(p->right != NULL) preorder(p->right);

  return;
}

void print(node *p){
  inorder(p);
  cout << endl;

  preorder(p);
  cout << endl;

  return;
}

node * makenode(int x, int y){
  node *n = new node;
  n->key = x;
  n->priority = y;
  n->left = NULL;
  n->right = NULL;
  return n;
}

node *rightRotate(node *p){
  node *q = p->left;
  p->left = q->right;
  q->right = p;
  return q;
}

node *leftRotate(node *p){
  node *q = p->right;
  p->right = q->left;
  q->left = p;
  return q;
}

node *insert(node **t, int key, int priority){
  node *n;

  if((*t) == NULL) return n = makenode(key, priority);

  if((*t)->key == key) return *t;

  if(key < (*t)->key){
    (*t)->left = insert(&(*t)->left, key, priority);
    if((*t)->priority < (*t)->left->priority)
      (*t) = rightRotate((*t));
  }

  else {
    (*t)->right = insert(&(*t)->right, key, priority);
    if((*t)->priority < (*t)->right->priority)
      (*t) = leftRotate((*t));
  }

  return *t;
}

node * Delete(node **t, int key){
  if((*t) == NULL) return NULL;

  if(key < (*t)->key)
    (*t)->left = Delete(&((*t)->left), key);

  else if(key > (*t)->key)
    (*t)->right = Delete(&((*t)->right), key);

  else return _delete(t, key);

  return *t;
}

node * _delete(node **t, int key){
  if((*t)->left == NULL && (*t)->right == NULL)
    return NULL;

  else if((*t)->left == NULL)
    (*t)=leftRotate(*t);

  else if((*t)->right == NULL)
    (*t)=rightRotate(*t);

  else {
    if((*t)->left->priority > (*t)->right->priority)
      (*t) = rightRotate(*t);
    else
      (*t) = leftRotate(*t);
  }
  return Delete(t, key);
}

int main(){
  int n, x, y;
  char com[8];
  node *root = NULL;

  cin >> n;

  for(int i = 0; i < n; ++i){
    cin >> com;

    switch(com[0]){

      case 'i': cin >> x >> y;
        root = insert(&root, x, y);
        break;

      case 'd': cin >> x;
        root = Delete(&root, x);
        break;

      case 'f': cin >> x;
        if(find(root, x)) cout << "yes" << endl;
        else cout << "no" << endl;
        break;

      case 'p': print(root);
        break;
    }
  }

  return 0;
}

