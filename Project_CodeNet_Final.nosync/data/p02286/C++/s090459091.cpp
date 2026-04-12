#include<string>
#include<iostream>

using namespace std;


struct Node{
  int key, pri;
  Node* right;
  Node* left;
};


Node* RightRotate(Node* t){
  Node* s = t->left;
  t->left = s->right;
  s->right = t;
  return s;
}

Node* LeftRotate(Node* t){
  Node* s = t->right;
  t->right = s->left;
  s->left = t;
  return s;
}

Node* Insert(Node* t, int key, int pri){

  if(t == NULL){
    Node* t = new Node;
    t->left=NULL;
    t->right=NULL;
    t->key=key;
    t->pri=pri;
    return t;
  }
  if(key == t->key) return t;

  if(key < t->key){
    t->left = Insert(t->left, key, pri);
    if(t->pri < t->left->pri) t = RightRotate(t);
  }
  else{
    t->right = Insert(t->right, key, pri);
    if(t->pri < t->right->pri) t = LeftRotate(t);
  }
  return t;
}

Node* Erase(Node* t, int key){
  if(t == NULL) return NULL;

  if(key == t->key){
    if(t->left  == NULL && t->right == NULL) return NULL;
    else if(t->left == NULL) t = LeftRotate(t);
    else if(t->right == NULL) t = RightRotate(t);
    else{
      if(t->left->pri > t->right->pri) t = RightRotate(t);
      else t = LeftRotate(t);
    }
    return Erase(t, key);
  }
  if(key < t->key) t->left = Erase(t->left, key);
  else t->right = Erase(t->right, key);
  return t;
}

void Find(Node* t, int key){
  while(t != NULL && key != t->key){
    if(key < t->key) t = t->left;
    else t = t->right;
  }
  if(t == NULL) cout << "no" << endl;
  else cout << "yes" << endl;
}

void Inorder(Node* t){
  if(t == NULL) return;
  Inorder(t->left);
  cout << " " << t->key;
  Inorder(t->right);
}

void Preorder(Node* t){
  if(t == NULL) return;
  cout << " " << t->key;
  Preorder(t->left);
  Preorder(t->right);
}

int main(){
  Node* root=NULL;
  int n, key, pri;
  string s;

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> s;
    if(s == "insert"){
      cin >> key >> pri;
      root = Insert(root, key, pri);
    }
    else if(s == "delete"){
      cin >> key;
     root = Erase(root, key);
    }
    else if(s == "find"){
      cin >> key;
      Find(root, key);
    }
    else {
      Inorder(root);
      cout << endl;
      Preorder(root);
      cout << endl;
    }
  }

  return 0;
}

