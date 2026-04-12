#include <bits/stdc++.h>
using namespace std;

struct node{
	int val,pri;
	node *l,*r;
	node():l(nullptr),r(nullptr){}
	node(int a,int b):val(a),pri(b),l(nullptr),r(nullptr){}
};

struct treap{
	node *root;
	treap(){ root=nullptr; }

	node* right(node *t){
		node* s = t->l;
		t->l = s->r;
		s->r = t;
		return s;
	}
	node* left(node *t){
		node* s = t->r;
		t->r = s->l;
		s->l = t;
		return s;
	}
	node* insert(node *t,int key,int priority){
		if(t==nullptr) return new node(key,priority);
		if(t->val==key) return t;
		if(key<t->val){
			t->l = insert(t->l,key,priority);
			if(t->pri < t->l->pri)t = right(t);
		}
		else{
			t->r=insert(t->r,key,priority);
			if(t->pri < t->r->pri)t = left(t);
		}
		return t;
	}
	void insert(int key,int priority){
		root = insert(root,key,priority);
	}
	node* delet(node *t,int key){
		if(t==nullptr)return nullptr;
		if(key<t->val)t->l=delet(t->l,key);
		else if(key>t->val)t->r=delet(t->r,key);
		else return _delet(t,key);
		return t;
	}
	node* _delet(node *t,int key){
		if(t->l==nullptr && t->r==nullptr) return nullptr;
		else if(t->l==nullptr)t=left(t);
		else if(t->r==nullptr)t=right(t);
		else{
			if(t->l->pri > t->r->pri) t= right(t);
			else t= left(t);
		}
		return delet(t,key);
	}
	void delet(int key){
		root=delet(root,key);
	}
	node* find(node *t,int key){
		if(t==nullptr)return nullptr;
		if(key < t->val)return find(t->l,key);
		if(key > t->val)return find(t->r,key);
		return t;
	}
	void print(node *t,int x=1){
		if(t==nullptr)return;
		if(x==1)cout<<' '<<(t->val);
		if(t->l!=nullptr)print(t->l,x);
		if(x==2)cout<<' '<<(t->val);
		if(t->r!=nullptr)print(t->r,x);
		if(x==3)cout<<' '<<(t->val);
		if(t==root)cout<<endl;
	}
};

int main(){
	treap T;
	int n,a,b;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		if(s=="insert"){
			cin>>a>>b;
			T.insert(a,b);
		}
		if(s=="find"){
			cin>>a;
			cout<<(T.find(T.root,a)==nullptr?"no":"yes")<<endl;
		}
		if(s=="delete"){
			cin>>a;
			T.delet(a);
		}
		if(s=="print"){
			T.print(T.root,2);
			T.print(T.root,1);
		}
	}
}

