#include <iostream>
#include <string>
using namespace std;

typedef struct Node{
  Node* right;
  Node* left;
  int key, priority;
}Node;



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

Node* insert(Node* t, int key, int priority){
  if(t == nullptr){
    Node* s = new Node;
    s -> key = key;
    s -> priority = priority;
    s -> left = s->right = nullptr;
    
    return s;
  }
  if(key == t->key){
    return t;
  }


  if( key < t->key){
    t->left = insert( t->left , key , priority);
    if( t->priority < t->left->priority )
      t = rightRotate(t);
  }
  else{
    t->right = insert(t->right , key, priority);
    if( t->priority < t->right->priority )
      t = leftRotate(t);
  }
  return t;
}

Node* _deleteNode(Node* t, int key);

Node* deleteNode(Node* t, int key){
  if( t == nullptr )
    return nullptr;
  if(key < t->key)
    t->left = deleteNode(t->left , key);
  else if(key > t->key)
    t->right = deleteNode(t->right , key);
  else
    return _deleteNode(t,key);

  return t;
}

Node* _deleteNode(Node* t, int key){

  if(t->left == nullptr && t->right == nullptr )
    return nullptr;

  else if( t->left == nullptr )
    t = leftRotate(t);

  else if( t->right == nullptr )
    t = rightRotate(t);

  else{
    if( t->left->priority > t->right->priority )
      t = rightRotate(t);
    else
      t = leftRotate(t);
  }
  return deleteNode(t,key);
}



Node* find(Node* t, int key){
  if(t==nullptr)return t;
  if(t->key == key)return t;
  if(t->key <  key)return find(t->right , key);
  else return find(t->left , key);
}


void inorder_print(Node* t){
  if(t == nullptr)return;
  inorder_print(t->left);
  cout << " " << t->key;
  inorder_print(t->right);
}


void preorder_print(Node* t){
  if(t == nullptr)return;
  cout << " " << t->key;
  preorder_print(t->left);
  preorder_print(t->right);
}


//===  For Test ====
bool bintree_check(Node* t){
  if(t == nullptr)return true;
  if(t->left != nullptr){
    if( t->left->key >= t->key )return false;
    if( ! bintree_check(t->left) ) return false;
  }
  if(t->right != nullptr){
    if( t->right->key <= t->key )return false;
    if( ! bintree_check(t->right) ) return false;
  }
  return true;
}

bool heap_check(Node* t){
  if(t == nullptr)return true;

  if(t->left != nullptr){
    if( t->left->priority >= t->priority )return false;
    if( ! heap_check(t->left) ) return false;
  }

  if(t->right != nullptr){
    if( t->right->priority >= t->priority )return false;
    if( ! heap_check(t->right) ) return false;
  }

  return true;
}


//============================================


int main(){

  string com;
  int k,p;
  int n;

  Node* root = nullptr;

  
  cin >> n;

  for(int i=0; i<n; i++){
    cin >> com;

    if(com == "insert"){
      cin >> k >> p;
      root = insert(root, k, p);
    }

    else if(com == "delete"){
      cin >> k;
      root = deleteNode(root, k);
    }

    else if(com == "find"){
      cin >> k;
      if( find(root, k) == nullptr ) cout << "no" << endl;
      else cout << "yes" << endl;
    }

    else if(com == "print"){
      inorder_print(root); cout << endl;
      preorder_print(root); cout << endl;
    }

    //if( !bintree_check(root) )cout << "BST Error" << endl;
    //if( !heap_check(root) )cout << "Heap Error" << endl;
  }

  return 0;

}

