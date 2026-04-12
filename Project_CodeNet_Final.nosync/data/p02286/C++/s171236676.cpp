#include<bits/stdc++.h>

using namespace std;
#define fordebug int hoge;cin>>hoge;
#define DEKAI 1000000007
#define INF (1<<28)
#define lp(i,n) for(int i=0;i<n;i++)
#define lps(i,j,n) for(int i=j;i<n;i++)
#define floot10 cout<<fixed<<setprecision(10);

//from ok 2018-12-02 must retry
//condate=18-12-5
struct Node{
	Node *parent, *left, *right;
	int key, priority;
};

Node *deleteN(Node*,int);

Node *root, *NIL;


Node *rightRotate(Node *t){
	Node *s = t->left;
	t->left = s->right;
	s->right = t;
	return s;
}

Node *leftRotate(Node *t){
	Node *s = t->right;
	t->right = s->left;
	s->left = t;
	return s;
}

Node *insert(Node *t,int key, int priority){
	if(t == NIL){//cout<<key<<" "<<priority<<endl;
		Node *temp;
		temp = new Node;
		temp->key = key;
		temp->priority = priority;
		temp->left = NIL;
		temp->right = NIL;
		return temp;
	}
	if(key == t->key){
		return t;
	}
	
	if(key < t->key){
		t->left = insert(t->left, key, priority);
		if(t->priority < t->left->priority)
			t = rightRotate(t);
	} else {
		t->right = insert(t->right, key, priority);
		if(t->priority < t->right->priority)
			t = leftRotate(t);
	}
	return t;
}

bool find(Node *t, int key){
	while(t != NIL && key != t->key){
		if(key < t->key) t = t->left;
		else t = t->right;
	}
	return t!=NIL;
}

void inorder(Node *t){
	if(t == NIL) return;
	cout<<" "<<t->key;
	inorder(t->left);
	inorder(t->right);
}

void preorder(Node *t){
	if(t == NIL)return;
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
	if(t->left == NIL && t->right == NIL){
		if(t->parent != NIL){
			if(t->parent->left->key == key) t->parent->left = NIL;
			else t->parent->right = NIL;
		}
		//delete t;
		return NIL;
	}else if(t->left == NIL)
		t = leftRotate(t);
	else if(t->right == NIL)
		t = rightRotate(t);
	else {
		if(t->left->priority > t->right->priority)
			t = rightRotate(t);
		else
			t = leftRotate(t);
	}
	return deleteN(t,key);
}

Node *deleteN(Node *t, int key){
	if(t == NIL)
		return NIL;
	if(key < t->key)
		t->left = deleteN(t->left, key);
	else if(key > t->key)
		t->right = deleteN(t->right, key);
	else 
		return _delete(t,key);
	return t;
}

int main(){
	int n, k, p;
	string order;
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>order;
		
		if(order == "insert"){
			cin>>k>>p;
			root = insert(root,k,p);
		} else if(order == "find"){
			cin>>k;
			cout<<(find(root,k)?"yes":"no")<<endl;
		} else if(order == "delete"){
			cin>>k;
			root = deleteN(root,k);
		} else if(order == "print"){
			print(root);
		}
	}
	return 0;
}
