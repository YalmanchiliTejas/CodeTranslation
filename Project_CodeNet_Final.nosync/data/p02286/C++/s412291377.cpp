// treap

#include <iostream>
#include <stdio.h>
 
using namespace std;
 
struct Node{
    Node *left;
    Node *right;
    int key;
    int pri;
 
    Node(int k, int p) : key(k), pri(p){
        left = right = NULL;
    }
};
 
Node* rightRotate(Node *t){
    Node* s = t->left;
    t->left = s->right;
    s->right = t;
     
    return s; 
}
 
Node* leftRotate(Node *t){
    Node* s = t->right;
    t->right = s->left;
    s->left = t;
     
    return s; 
}
 
void find(Node *t, int k){
  while(t != NULL && k != t->key){
    if(k < t->key) t = t->left;
    else t = t->right;
  }
 
  if ( t != NULL ) cout << "yes" << endl;
  else cout << "no" << endl;
}
 
Node* insert(Node *t, int key, int pri){
    if(t == NULL){ return new Node(key, pri); }
    if(key == t->key){ return t; }                     
 
    if(key < t->key){                         
        t->left = insert(t->left, key, pri);  
        if(t->pri < t->left->pri){ t = rightRotate(t); }
    } else{
        t->right = insert(t->right, key, pri);
        if(t->pri < t->right->pri){ t = leftRotate(t); }
    }
     
    return t;
}
 
Node* erase(Node *t, int key){
    if(t == NULL){ return NULL; }
     
    if(key == t->key){                         
        if(t->left == NULL && t->right == NULL){ return NULL; }
        else if(t->left == NULL){ t = leftRotate(t); }
        else if(t->right == NULL){ t = rightRotate(t); }
        else{
            if(t->left->pri > t->right->pri){ t = rightRotate(t); }
            else{ t = leftRotate(t); }
        }
        return erase(t, key);
    }
     
    if(key < t->key){ t->left = erase(t->left, key); }
    else{ t->right = erase(t->right, key); }
     
    return t;
}
 
 
void Inorder(Node *t){
  if(t->left != NULL) Inorder(t->left);
  if(t->key != -1) cout << " " << t->key;
  if(t->right != NULL) Inorder(t->right);
}
    
void Preorder(Node *t){
  if(t->key != -1) cout << " " << t->key;
  if(t->left != NULL) Preorder(t->left);
  if(t->right != NULL) Preorder(t->right);
}
 
 
void print(Node *t){
    if(t != NULL) Inorder(t);
      cout <<endl;
      if(t != NULL) Preorder(t);
      cout <<endl;
}
 
int main(){
    int n;
    cin >> n;
    char ope[n];
    int k, p;
 
    Node *t=new Node(-1, -1);
 
    for(int i=0; i<n; i++){
        scanf("%s", ope);
        if(ope[0] == 'p'){ print(t); }
        else if(ope[0] == 'f'){ cin >> k; find(t, k); }
        else if(ope[0] == 'd'){ cin >> k; t = erase(t, k); }
        else if(ope[0] == 'i'){ cin >> k >> p; t = insert(t, k, p); }
    }
 
    return 0;
}
