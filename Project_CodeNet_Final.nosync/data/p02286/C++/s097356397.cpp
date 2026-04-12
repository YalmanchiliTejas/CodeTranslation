#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto& x:c){cout<<x<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=int>
T in(){T x; cin >> x; return (x);}
template<typename T=int,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

class Node{
public:
	int key;
	int priority;
	list<Node>::iterator left,right;
};

class Tree{
public:
	list<Node> node_list;
	list<Node>::iterator root;
	vector<int> preorder,inorder;

	Tree(){
		root = node_list.end();
	}
	list<Node>::iterator NIL(){
		return node_list.end();
	}
	list<Node>::iterator rightRotate(list<Node>::iterator t){
		list<Node>::iterator s=t->left;
		t->left = s->right;
		s->right = t;
		return s;
	}
	list<Node>::iterator leftRotate(list<Node>::iterator t){
		list<Node>::iterator s=t->right;
		t->right = s->left;
		s->left = t;
		return s;
	}
	list<Node>::iterator insert(list<Node>::iterator t,list<Node>::iterator z){
		if(t==NIL()){
			return z;
		}
		if(z->key==t->key){
			return t;
		}

		if(z->key<t->key){
			t->left = insert(t->left,z);
			if(t->priority<t->left->priority){
				t = rightRotate(t);
			}
		}
		else{
			t->right = insert(t->right,z);
			if(t->priority<t->right->priority){
				t = leftRotate(t);
			}
		}
		return t;
	}
	void insert(list<Node>::iterator z){
		root = insert(root,z);
	}
	list<Node>::iterator find(int key,list<Node>::iterator z){
		if(z->key==key) return z;

		if(z->key>key && z->left!=NIL()){
			return find(key,z->left);
		}
		else if(z->key<key && z->right!=NIL()){
			return find(key,z->right);
		}
		return node_list.end();
	}
	bool find(int key){
		auto res = find(key,root);
		return res!=node_list.end();
	}

	list<Node>::iterator Delete2(int key,list<Node>::iterator z){
		if(z->left==NIL() && z->right==NIL()){
			node_list.erase(z);
			return NIL();
		}
		else if(z->left==NIL()){
			z = leftRotate(z);
		}
		else if(z->right==NIL()){
			z = rightRotate(z);
		}
		else{
			if(z->left->priority>z->right->priority){
				z = rightRotate(z);
			}
			else{
				z = leftRotate(z); 
			}
		}
		return Delete(key,z);
	}
	list<Node>::iterator Delete(int key,list<Node>::iterator z){
		if(z==NIL()) return z;

		if(key<z->key){
			z->left = Delete(key,z->left);
		}
		else if(key>z->key){
			z->right = Delete(key,z->right);
		}
		else{
			return Delete2(key,z);
		}
		return z;
	}
	void Delete(int key){
		root = Delete(key,root);
	}
	void DFS(list<Node>::iterator parent){
		preorder.push_back(parent->key);
		
		if(parent->left==NIL()){
			inorder.push_back(parent->key);
		}
		else{
			DFS(parent->left);
			inorder.push_back(parent->key);
		}

		if(parent->right!=NIL()){
			DFS(parent->right);
		}
	}
	void DFS(){
		preorder.clear();
		inorder.clear();
		DFS(root);
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N=in();
	Tree tree;
	REP(i,N){
		string S=in<string>();
		if(S=="insert"){
			Node n;
			n.key = in(),n.priority = in();
			n.left=n.right=tree.NIL();
			auto z = tree.node_list.insert(tree.NIL(),n);
			tree.insert(z);
		}
		else if(S=="find"){
			int key = in();
			out(tree.find(key)?"yes":"no");
		}
		else if(S=="delete"){
			int key = in();
			tree.Delete(key);
		}
		else{
			tree.DFS();
			int num = tree.preorder.size();
			REP(j,num){
				cout << ' ' << tree.inorder[j];
			}
			cout << endl;
			REP(j,num){
				cout << ' ' << tree.preorder[j];
			}
			cout << endl;
		}
	}
	
	return 0;
}

