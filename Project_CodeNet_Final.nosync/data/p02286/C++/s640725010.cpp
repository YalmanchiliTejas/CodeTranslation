#include <bits/stdc++.h>
#define int long long
using namespace std;

class Treap{
public:
  
  struct Node{
    int key, pri;
    Node *left, *right;
    Node():left(nullptr),right(nullptr){}
    Node(int k, int p):key(k),pri(p),left(nullptr),right(nullptr){}
  };
  
  Node *root;
  
  Treap(){ root = nullptr; }
  
  Node* rightRotate(Node *t){
    
    Node* s = (*t).left;
    
    (*t).left = (*s).right;
    
    (*s).right = t;
    
    return s;
  }
  
  Node* leftRotate(Node *t){
    
    Node* s = (*t).right;
    
    (*t).right = (*s).left;
    
    (*s).left = t;
    
    return s;
  }
  
  Node* insert(Node *t, int key, int pri){
    
    if( t == nullptr ) return new Node( key, pri );
    
    if( (*t).key == key ) return t;
    
    if( key < (*t).key  ){
      
      (*t).left = insert( (*t).left, key, pri );
      
      if( (*t).pri < (*(*t).left).pri ) t = rightRotate( t );
      
    }
    else{
      
      (*t).right = insert( (*t).right, key, pri );
      
      if( (*t).pri < (*(*t).right).pri ) t = leftRotate( t );
      
    }
    
    return t;
  }
  
  void insert(int key, int pri){ root = insert( root, key, pri ); }
  
  Node* erase(Node *t, int key){
    
    if( t == nullptr ) return nullptr;
    
    if( (*t).key == key ){
      
      if( (*t).left == nullptr && (*t).right == nullptr ) return nullptr;
      else if( (*t).left == nullptr ) t = leftRotate( t );
      else if( (*t).right == nullptr ) t = rightRotate( t );
      else{
	
	if( (*(*t).left).pri > (*(*t).right).pri ) t = rightRotate( t );
	else t = leftRotate( t );
	
      }
      
      return erase( t, key );
    }
    
    if( key < (*t).key ) (*t).left = erase( (*t).left, key );
    else (*t).right = erase( (*t).right, key );
    
    return t;
  }
  
  void erase(int key){ root = erase( root, key ); }
      
  bool find(Node *t, int key){
    
    if( t == nullptr ) return false;
    
    if( (*t).key == key ) return true;
    
    if( (*t).left == nullptr && (*t).right == nullptr ) return false;
    else if( (*t).left == nullptr ) return find( (*t).right, key );
    else if( (*t).right == nullptr ) return find( (*t).left, key );
    else{
      
      if( key < (*t).key ) return find( (*t).left, key );
      else return find( (*t).right, key );
      
    }
    
  }
  
  bool find(int key){ return find( root, key ); }
  
  void print_inorder(Node *x){
  
    if( (*x).left != nullptr ) print_inorder( (*x).left );
  
    if( x != nullptr ) cout << ' ' << (*x).key;
  
    if( (*x).right != nullptr ) print_inorder( (*x).right );
  
  }
  
  void print_inorder(){ print_inorder( root ), cout << endl; }
  
  void print_preorder(Node *x){
  
    if( x != nullptr ) cout << ' ' << (*x).key;
  
    if( (*x).left != nullptr ) print_preorder( (*x).left );
  
    if( (*x).right != nullptr ) print_preorder( (*x).right );
  
  }
  
  void print_preorder(){ print_preorder( root ), cout << endl; }
  
};

signed main(){
  
  int N;
  cin >> N;
  
  Treap treap = Treap();
  
  while( N-- ){
    
    string s;
    cin >> s;
    
    if( s == "insert" ){
      
      int key, pri;
      cin >> key >> pri;
      
      treap.insert( key, pri );
      
    }
    
    if( s == "find" ){
      
      int key;
      cin>>key;
      
      if( treap.find( key ) == true ) cout << "yes" << endl;
      else cout << "no" << endl;
      
    }
    
    if( s == "delete" ){
      
      int key;
      cin>>key;
      
      treap.erase( key );
      
    }
    
    if( s == "print" ){
      
      treap.print_inorder();
      
      treap.print_preorder();
      
    }
    
  }
  
  return 0;
}

