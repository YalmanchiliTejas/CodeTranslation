#include<iostream>
#include<cstdlib>
using namespace std;
struct node {
  int key, pri;
  node *left, *right;
};
typedef struct node* Node;
Node NIL,root;
Node _deletekey(Node, int);
Node rightRotate(Node t) {
  Node s = t->left;
  t->left = s->right;
  s->right = t;
  if (root == t) root = s;
  return s;
}
Node leftRotate(Node t) {
  Node s = t->right;
  t->right = s->left;
  s->left = t;
  if (root == t) root = s;
  return s;
}
Node newnode(int key, int pri) {
  Node newNode = (Node)malloc(sizeof(struct node));
  newNode->key = key;
  newNode->pri = pri;
  newNode->right = newNode->left = NIL;
  if (root == NIL) root = newNode;
  return newNode;
}
Node insert(Node t, int key, int pri) {
  if (t == NIL) return newnode(key,pri);
  if (key == t->key) return t;
  if (key < t->key) {
    t->left = insert(t->left, key, pri);
    if (t->pri < t->left->pri) t = rightRotate(t);
  }
  else {
    t->right = insert(t->right, key, pri);
    if (t->pri < t->right->pri) t = leftRotate(t);
  }
  return t;
}
Node deletekey(Node t,int key) {
  if (t == NIL) return NIL;
  if (key < t->key) t->left = deletekey(t->left, key);
  else if (key > t->key) t->right = deletekey(t->right, key);
  else return _deletekey(t, key);
  return t;
}
Node _deletekey(Node t, int key) {
  if (t->left == NIL && t->right == NIL) return NIL;
  if (t->left == NIL) t = leftRotate(t);
  else if (t->right == NIL) t = rightRotate(t);
  else {
    if (t->left->pri > t->right->pri) t = rightRotate(t);
    else t = leftRotate(t);
  }
  return deletekey(t,key);
}
void inorder(Node p) {
  if (p != NIL) {
    inorder(p->left);
    cout << " " << p->key;
    inorder(p->right);
  }
}
void preorder(Node p) {
  if (p != NIL) {
    cout << " " << p->key;
    preorder(p->left);
    preorder(p->right);
  }
}
Node find(int x) {
  Node r = root;
  while (r != NIL) {
    if (r->key == x) return r;
    if (r->key<x) r = r->right;
    else r = r->left;
  }
  return r;
}
int main() {
  int n, x,y;
  char s[7]; cin >> n;
  for (int i = 0; i<n; ++i) {
    cin >> s;
    if (s[0] == 'i') {
      cin >> x >> y;
      insert(root,x,y);
    }
    else if (s[0] == 'p') {
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    }
    else if (s[0] == 'f') {
      cin >> x;
      if (find(x) != NIL) cout << "yes" << endl;
      else cout << "no" << endl;
    }
    else {
      cin >> x;
      deletekey(root,x);
    }
  }
  return 0;
}

