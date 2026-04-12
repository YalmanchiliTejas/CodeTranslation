#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;

constexpr int INFI = 2000000001;

class node{
public:
	int id;
	int value;
	node* left, * right;
	node*  parent;
	int sibling;
	int depth;
	int height;
};

bool operator<=(node a, node b) {
	return a.id <= b.id;
}
bool operator<(node a, node b) {
	return a.id < b.id;
}

bool operator==(node a, node b) {
	return a.id == b.id;
}

bool operator!=(node a, node b) {
	return a.id != b.id;
}

void add(node* root,int a,int v) {
	node *newnode = new node;
	node* now = root->left;
	newnode->id = a;
	newnode->value = v;
	newnode->left = NULL;
	newnode->right = NULL;
	if (now == NULL) {
		newnode->parent = root;
		root->left = newnode;
		return;
	}
	while (1) {
		if (now->id > a) {
			if (now->left == NULL) {
				now->left = newnode;
				newnode->parent = now;
				now = now->left;
				break;
			}
			else {
				now = now->left;
			}
		}
		else {
			if (now->right == NULL) {
				now->right = newnode;
				newnode->parent = now;
				now = now->right;
				break;
			}
			else {
				now = now->right;
			}
		}
	}
	while (now->value > now->parent->value) {
		if (now->id > now->parent->id) {
			now->parent->right = now->left;
			if(now->left !=NULL)now->left->parent = now->parent;
			now->left = now->parent;
			now->parent = now->parent->parent;
			if (now->parent->id > now->id) {
				now->parent->left = now;
			}
			else {
				now->parent->right = now;
			}
			now->left->parent = now;
		}
		else {
			now->parent->left = now->right;
			if(now->right!=NULL)now->right->parent = now->parent;
			now->right = now->parent;
			now->parent = now->parent->parent;
			if (now->parent->id > now->id) {
				now->parent->left = now;
			}
			else {
				now->parent->right = now;
			}
			now->right->parent = now;

		}
		
	}
}


string postorder(node* nod) {
	string msg="";
	if (nod->left->id != -1) {
		msg += postorder(nod->left);	
	}
	if (nod->right->id != -1) {
		msg += postorder(nod->right);	
	}
	msg += to_string(nod->id) + " ";
	return msg;
}

void preorder(node* root) {
	if (root == NULL)return;
	cout << " "<<root->id;
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root) {
	if (root == NULL)return;
	inorder(root->left);
	cout <<" "<< root->id;
	inorder(root->right);
}

bool find(node* root,int a) {
	if (root == NULL)return false;
	if (root->id == a)return true;
	if (root->id > a)return find(root->left, a);
	if (root->id < a)return find(root->right, a);
}

void del(node* root, int a) {
	root = root->left;
	while (1) {
		if (root == NULL)return;
		if (root->id == a) {
			break;
		}
		else if (root->id > a) {
			root = root->left;
		}
		else {
			root = root->right;
		}
	}
	while (root->left!=NULL || root->right!=NULL){
		if (root->left == NULL) {
			if (root->id < root->parent->id) {
				root->parent->left = root->right;
			}
			else {
				root->parent->right = root->right;
			}
			root->right->parent = root->parent;
			root->parent = root->right;
			root->right = root->parent->left;
			if(root->right!=NULL)root->right->parent = root;
			root->parent->left = root;
		}
		else if (root->right == NULL) {
			if (root->id < root->parent->id) {
				root->parent->left = root->left;
			}
			else {
				root->parent->right = root->left;
			}
			root->left->parent = root->parent;
			root->parent = root->left;
			root->left = root->parent->right;
			if(root->left!=NULL)root->left->parent = root;
			root->parent->right = root;
		}
		else {
			if (root->left->value > root->right->value) {
				if (root->id < root->parent->id) {
					root->parent->left = root->left;
				}
				else {
					root->parent->right = root->left;
				}
				root->left->parent = root->parent;
				root->parent = root->left;
				root->left = root->parent->right;
				if(root->left!=NULL)root->left->parent = root;
				root->parent->right = root;
			}
			else {
				if (root->id < root->parent->id) {
					root->parent->left = root->right;
				}
				else {
					root->parent->right = root->right;
				}
				root->right->parent = root->parent;
				root->parent = root->right;
				root->right = root->parent->left;
				if(root->right!=NULL)root->right->parent = root;
				root->parent->left = root;
			}
		}
	}
	if (root->id < root->parent->id) {
		root->parent->left = NULL;
	}
	else {
		root->parent->right = NULL;
	}
	free(root);
}



int main() {
	int n,tmp,tmp2;
	string msg;
	cin >> n;
	node* root = new node;
	root->left = root->right = NULL;
	root->id = INFI;
	root->value = INFI;
	for (int i = 0;i < n;i++) {
		cin >> msg;
		if (msg == "insert") {
			cin >> tmp>>tmp2;
			add(root, tmp,tmp2);
		}
		else if (msg == "print") {
			inorder(root->left);
			cout << endl;
			preorder(root->left);
			cout << endl;
		}
		else if(msg == "find"){
			cin >> tmp;
			if (find(root->left, tmp))cout << "yes\n";
			else cout << "no\n";
		}
		else {
			cin >> tmp;
			del(root, tmp);
		}
	}
}




