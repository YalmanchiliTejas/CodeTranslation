#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Node{
  int value, priority;
  Node *left, *right;
} Node;

Node* Delete(Node *, int);
Node* _delete(Node *, int);

Node *NIL, *root;

Node* rightRotate(Node *t){
  Node *s = t->left;
  t->left = s->right;
  s->right = t;
  return s; // root of the subtree
}

Node* leftRotate(Node *t){
  Node *s = t->right;
  t->right = s->left;
  s->left = t;
  return s; // root of the subtree
}

Node* makenode(int key, int priority){
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = key;
  node->priority = priority;
  node->left = node->right = NIL;

  return node;
}

Node* insert(Node *t, int key, int priority){    //search recursively
  Node *x;

  if(t == NIL) return x = makenode(key, priority); //reach a leaf, make new node and return that

  if(key == t->value) return t;                //ignore duplicative key

  if(key < t->value){                          //move the left child
      t->left = insert(t->left, key, priority); //update the pointer to left child
      if(t->priority < t->left->priority) t = rightRotate(t); //when left child's priority is larger, right rotate
  }else{                                       //move the right child
      t->right = insert(t->right, key, priority); //update the pointer to right child
      if(t->priority < t->right->priority) t = leftRotate(t); //when right chil's priority is larger, left rotate
  }

  return t;
}

Node* find(Node *x, int k){
  if(x == NIL || x->value == k) return x;

  if(k < x->value) return find(x->left, k);
  else return find(x->right, k);
}

Node* Delete(Node *t, int key){
  if(t == NIL) return NIL;
  if(key < t->value) t->left = Delete(t->left, key); //search the node that should be deleted
  else if(key > t->value) t->right = Delete(t->right, key);
  else return _delete(t, key);
  return t;
}

Node* _delete(Node *t, int key){ //case of the node should be deleted
  if(t->left == NIL && t->right == NIL) return NIL; //case of leaf
  else if(t->left == NIL) t = leftRotate(t);   //if have only right child, left rotate
  else if(t->right == NIL) t = rightRotate(t); //if have only left child, right rotate
  else{                                        //if have two children, lift a node have larger priority up
    if(t->left->priority > t->right->priority) t = rightRotate(t);
    else t = leftRotate(t);
  }
  return Delete(t, key);
}

void preParse(Node *node){
  if(node == NIL) return ;

  cout << " " << node->value;
  if(node->left != NIL) preParse(node->left);
  if(node->right != NIL) preParse(node->right);
}

void inParse(Node *node){
  if(node == NIL) return ;

  if(node->left != NIL) inParse(node->left);
  cout << " " << node->value;
  if(node->right != NIL) inParse(node->right);
}

int main(){

  int n, key, priority;
  string command;

  //input
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> command;
    if(command == "insert"){
      cin >> key >> priority;
      root = insert(root, key, priority);
    }else if(command == "print"){
      inParse(root);
      cout << endl;
      preParse(root);
      cout << endl;
    }else if(command == "find"){
      cin >> key;
      if(find(root, key)) cout << "yes" << endl;
      else cout << "no" << endl;
    }else if(command == "delete"){
      cin >> key;
      root = Delete(root, key);
    }
  }

  return 0;
}


