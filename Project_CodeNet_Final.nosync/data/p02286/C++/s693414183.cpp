//lec05
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include<math.h> 
#include<queue>
#include<string.h>
#include<stack>


using namespace std;
struct Node {
  Node* r;
  Node* l;
  int key,priotity;
};

Node* rightRotate(Node* t){
	Node* s=t->l;
	t->l=s->r;
	s->r=t;
	return s;
}

Node* leftRotate(Node* t){
	Node* s=t->r;
	t->r=s->l;
	s->l=t;
	return s;
}

Node* insert(Node *t,int key,int priotity){
	if(t==NULL){
		Node* t=new Node;
		t->l=NULL;
		t->r=NULL;
		t->key=key;
		t->priotity=priotity;
		return t;
	}

	if(key==t->key){
		return t;
	}
	if(key < t->key){
		t->l=insert(t->l,key,priotity);
		if(t->priotity < t->l->priotity){
			t=rightRotate(t);
		}
	}
	else{
		t->r=insert(t->r,key,priotity);
		if(t->priotity < t->r->priotity){
			t=leftRotate(t);
		}
	}
	return t;
}


Node* del(Node* t,int key){
	if(t==NULL){
		return NULL;
	}
	if(key==t->key){
		if(t->l==NULL&&t->r==NULL)return NULL;
		else if(t->l==NULL)t=leftRotate(t);
		else if(t->r==NULL)t=rightRotate(t);
		else{
			if(t->l->priotity > t->r->priotity)t=rightRotate(t);
			else t=leftRotate(t);
		}
		return del(t,key);
	}
 	if(key < t->key){
 		t->l=del(t->l,key);
 	}
  	else {
  		t->r=del(t->r,key);
  	}
  	return t;
}

void find(Node* t,int key){
	while(t!=NULL&&key!=t->key){
		if(key < t->key){
			t=t->l;
		}
		else{
			t=t->r;
		}
	}
	if(t==NULL){
		cout<<"no"<<endl;
	}
	else{
		cout<<"yes"<<endl;
	}
}


void inorder(Node* t){
	if(t==NULL)return;
	inorder(t->l);
	cout<<" "<<t->key;
	inorder(t->r);
}

void preorder(Node* t){
	if(t==NULL)return;
	cout<<" "<<t->key;
	preorder(t->l);
	preorder(t->r);
}


int main(){
	int n;
	cin>>n;
	string in;
	int k,p;
	Node* root=NULL;
	for(int i=0;i<n;i++){
		cin>>in;
		if(in=="insert"){
			cin>>k>>p;
			root=insert(root,k,p);
		}
		else if(in=="find"){
			cin>>k;
			find(root,k);
		}
		else if(in=="delete"){
			cin>>k;
			root=del(root,k);
		}
		else{
			inorder(root);
			cout<<endl;
			preorder(root);
			cout<<endl;
		}
	}
}
