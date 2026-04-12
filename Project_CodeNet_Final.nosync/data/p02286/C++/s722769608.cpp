#include<bits/stdc++.h>
using namespace std;

struct Node{
  Node *parent, *left, *right;
  int key, priority;
};

Node *deleteN(Node*,int);

Node *root, *NIL;


Node *rightRotate(Node *t){
  Node *s=t->left;
  t->left=s->right;
  s->right=t;
  return s;
}

Node *leftRotate(Node *t){
  Node *s=t->right;
  t->right=s->left;
  s->left=t;
  return s;
}

Node *insert(Node *t,int key,int priority){
  if(t==NIL){
    Node *temp;
    temp=new Node;
    temp->key=key;
    temp->priority=priority;
    temp->left=NIL;
    temp->right=NIL;
    return temp;
  }
  if(key==t->key){
    return t;
  }
  
  if(key<t->key){
    t->left=insert(t->left,key,priority);
    if(t->priority<t->left->priority)
      t=rightRotate(t);
  }else{
    t->right=insert(t->right,key,priority);
    if(t->priority<t->right->priority)
      t=leftRotate(t);
  }
  return t;
}

bool find(Node *t,int key){
  while(t!=NIL && key!=t->key){
    if(key<t->key) t=t->left;
    else t=t->right;
  }
  return t!=NIL;
}

void inorder(Node *t){
  if(t==NIL) return;
  cout<<" "<<t->key;
  inorder(t->left);
  inorder(t->right);
}

void preorder(Node *t){
  if(t==NIL)return;
  preorder(t->left);
  cout<<" "<<t->key;
  preorder(t->right);
}

void print(Node *t){
  preorder(t);
  cout<<endl;
  inorder(t);
  cout<<endl;
}

Node *_delete(Node *t, int key){
  if(t->left==NIL && t->right==NIL){
    if(t->parent!=NIL){
      if(t->parent->left->key==key) t->parent->left=NIL;
      else t->parent->right=NIL;
    }
    return NIL;
  }else if(t->left==NIL)
    t=leftRotate(t);
  else if(t->right==NIL)
    t=rightRotate(t);
  else {
    if(t->left->priority > t->right->priority)
      t=rightRotate(t);
    else
      t=leftRotate(t);
  }
  return deleteN(t,key);
}

Node *deleteN(Node *t,int key){
  if(t==NIL) return NIL;
  if(key<t->key) t->left=deleteN(t->left,key);
  else if(key>t->key) t->right=deleteN(t->right,key);
  else return _delete(t,key);
  return t;
}

int main(){
  int m,k,p;
  string s;
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>s;
    if(s=="insert"){
      cin>>k>>p;
      root=insert(root,k,p);
    }else if(s=="find"){
      cin>>k;
      if(find(root,k)) cout<<"yes"<<endl;
      else cout<<"no"<<endl;
    }else if(s=="delete"){
      cin>>k;
      root=deleteN(root,k);
    }else if(s=="print"){
      print(root);
    }
  }
  return 0;
}

