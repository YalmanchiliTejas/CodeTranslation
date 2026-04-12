#include <iostream>
#include <string>
using namespace std;

struct Node{
  struct Node* left;
  struct Node* right;
  int key, pri;
};

Node* create(int key, int pri){
  Node* t = new Node;
  t->key = key;
  t->pri = pri;
  t->left = t->right = NULL;
  return t;
}

Node* rightRotate(Node* t){
  Node* s = t->left;
  t->left = s->right;
  s->right = t;
  return s;
}

Node* leftRotate(Node* t){
  Node* s = t->right;
  t->right = s->left;
  s->left = t;
  return s;
}

Node* insert(Node* t, int key, int pri){
  if(t == NULL) return create(key, pri);
  if(key == t->key) return t;

  if(key < t->key){
    t->left = insert(t->left,key,pri);
    if(t->pri < t->left->pri) t = rightRotate(t);
  }
  else{
    t->right = insert(t->right,key,pri);
    if(t->pri < t->right->pri) t = leftRotate(t);
  }
  return t;
}

Node* erase(Node* t, int key){
  if(t == NULL) return NULL;

  if(key == t->key){
    if(t->left == NULL && t->right == NULL) return NULL;
    else if(t->left == NULL) t = leftRotate(t);
    else if(t->right == NULL) t = rightRotate(t);
    else{
      if(t->left->pri > t->right->pri) t = rightRotate(t);
      else t = leftRotate(t);
    }
    return erase(t,key);
  }
  if(key < t->key) t->left = erase(t->left,key);
  else t->right = erase(t->right,key);

  return t;
}

void inorder(Node* t){
  if(t == NULL) return;
  inorder(t->left);
  cout << " " << t->key;
  inorder(t->right);
}

void preorder(Node* t){
  if(t == NULL) return;
  cout << " " << t->key;
  preorder(t->left);
  preorder(t->right);
}

void print(Node* t){
  inorder(t);
  cout << endl;
  preorder(t);
  cout << endl;
}

void find(Node* t, int key){
  if(t == NULL){
    cout << "no" << endl;
    return;
  }
  if(t->key == key){
    cout << "yes" << endl;
    return;
  }
  if(t->key > key) find(t->left,key);
  else find(t->right,key);
}

int main(){
  Node* t = NULL;
  int m, key, pri;
  string str;
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> str;
    if(str == "insert"){
      cin >> key >> pri;
      t = insert(t,key,pri);
    }
    else if(str == "find"){
      cin >> key;
      find(t,key);
    }
    else if(str == "delete"){
      cin >> key;
      t = erase(t,key);
    }
    else print(t);
  }
  return 0;
}
