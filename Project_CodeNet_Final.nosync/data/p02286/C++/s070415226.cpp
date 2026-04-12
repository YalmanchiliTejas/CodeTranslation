#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct node {
  struct node *r;
  struct node *l;
  int key,priotity;
}Node;

Node* delete1(Node*,int);
Node* makeNode(int k,int p){
  Node* tmp=(Node* )malloc(sizeof(Node));
  tmp->key=k;
  tmp->priotity=p;
  tmp->l=tmp->r=NULL;
  return tmp;
}
Node* righRotate(Node* t){
  Node* s;
  s=t->l;
  t->l=s->r;
  s->r=t;
  return s;
}
node* leftRotate(Node* t){
  Node* s;
  s=t->r;
  t->r=s->l;
  s->l=t;
  return s;
}

Node* insert(Node *t,int key,int priotity){
  if(t==NULL){
    //cout<<key<<endl;
    return makeNode(key,priotity);
  }
  if(key==t->key){
    //cout<<"in ="<<endl;
    return t;
  }
  if(key<t->key){
    t->l= insert(t->l,key,priotity);
    //cout<<"in if"<<endl;
    if(t->priotity<t->l->priotity)
      t=righRotate(t);
  }
  else{
    t->r=insert(t->r,key,priotity);
    //cout<<"in else"<<endl;
    if(t->priotity<t->r->priotity)
      t=leftRotate(t);
  }
  return t;
}
void inorder(Node *node){
  if(node==NULL){
    return;
  }
  inorder(node->l);
  cout<<" "<<node->key;
  inorder(node->r);
}
void preorder(Node *node){
  if(node==NULL){
    return;
  }
    cout<<" "<<node->key;
    preorder(node->l);
    preorder(node->r);
}
Node* find(Node *t,int key){
  while(t!=NULL&&key!=t->key){
    if(t->key>key)t=t->l;
    else t=t->r;
  }
  return t;
}
Node* delete2(Node* t,int key){
  if(t->l==NULL&&t->r==NULL)return NULL;
  else if (t->l==NULL)t=leftRotate(t);
  else if(t->r==NULL)t=righRotate(t);
  else {
    if (t->l->priotity>t->r->priotity)
      t=righRotate(t);
    else
      t=leftRotate(t);
  }
  return delete1(t,key);
}
Node* delete1(Node* t,int key){
  if(t==NULL)return NULL;
  if(key<t->key)t->l=delete1(t->l,key);
  else if (key>t->key)t->r=delete1(t->r,key);
  else return delete2(t,key);
  return t;
}


int main(){
  int n,i,k,p;
  Node *tmp;
  Node* root=NULL;
  string str;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>str;
    //cout<<"i="<<i<<endl;
    if(str=="insert"){
      cin>>k>>p;
      //if(i>0)cout<<"rootkeybefor:"<<root->key<<endl;
      root=insert(root,k,p);
      //cout<<"rootkeyafter:"<<root->key<<endl;
    }
    else if(str=="find"){
      cin>>k;
      tmp=find(root,k);
      if(tmp!=NULL)cout<<"yes"<<endl;
      else cout<<"no"<<endl;
    }
    else if(str=="delete"){
      cin>>k;
      root=delete1(root,k);
    }
    else{
      inorder(root);
      cout<<endl;
      preorder(root);
      cout<<endl;
    }
  }


  return 0;
}

