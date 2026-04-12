#include<iostream>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;

struct node{
  int priority,key;
  node *right, *left;
};


node* rightRotate(node* t) {
  node* s = t->left;
  t->left = s->right;
  s->right = t;
  return s;
}

node* leftRotate(node* t) {
  node* s = t->right;
  t->right = s->left;
  s->left = t;
  return s;
}

node* MakeNode(int key, int priority){
  node* t = new node;
  t->left=NULL;
  t->right = NULL;
  t->key = key;
  t->priority = priority;
  return t;
}

node* insert(node* t, int key, int priority) {

  if(t == NULL) { return MakeNode(key,priority);}
  if(key == t->key) {return t;}

  if(key < t->key) {
    t->left = insert(t->left, key, priority);
    if( (t->priority) < (t->left->priority) ){ t = rightRotate(t); }
  }
  else{
    t->right = insert(t->right, key, priority);
    if(( t->priority) < (t->right->priority) ){ t = leftRotate(t); }
  }
  return t;
}

node* _delete(node* t, int key); //プロトタイプ宣言
node* node_delete(node* t, int key){
  if( t == NULL ) {return NULL;}
  if(  (t->key) > key ) { t->left = node_delete(t->left, key); }
  else if( (t->key) < key ) { t->right = node_delete(t->right, key); }
  else { return _delete(t, key);}
  return t;
}

node* _delete(node* t, int key){

  if( t->left == NULL && t->right == NULL) { return NULL; }
  else if( t->left == NULL ) { t = leftRotate(t); }
  else if(t->right == NULL) { t = rightRotate(t); }
  else {
    if( (t->left->priority) > (t->right->priority) ) {t = rightRotate(t);}
    else t = leftRotate(t);
  }
  return node_delete(t,key);
}


void find(node* t, int key) {

  while(t != NULL && key != t->key) {
    if(key < t->key) { t = t->left; }
    else {t = t->right;}
  }

  if(t == NULL) cout << "no" << endl;
  else cout << "yes" << endl;

}

void order (node *t, int op){

  if(op==1){
    if(t==NULL) return;
    order(t->left,1);
    cout << " " << t->key;
    order(t->right,1);
  }else if(op==2){
    if(t == NULL) return;
    cout << " " << t->key;
    order(t->left,2);
    order(t->right,2);
  }

}

int main() {

  string op;
  node* root=NULL;
  int m,key,priority;

  cin >> m;
  for(int i=0; i<m; i++) {

    cin >> op;

    if(op == "insert") {
      cin >> key >> priority;
      root = insert(root, key, priority);
    }

    else if(op == "find") {
      cin >> key;
      find(root, key);
    }

    else if(op == "delete") {
      cin >> key;
      root = node_delete(root, key);
    }

    else {
      order(root,1);
      cout << endl;
      order(root,2);
      cout << endl;
    }
  }
}
