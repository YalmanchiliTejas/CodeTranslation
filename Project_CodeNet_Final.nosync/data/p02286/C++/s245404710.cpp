#include <iostream>
#include <vector>

using namespace std; 
struct node {
	long long key;
	long long pri;
	node* left;
	node* right;
};

node* root;
node* rightRotate(node* t);
node* leftRotate(node* t);
node* insert(node* t, long long k, long long p);
node* delete_node(node* t, long long k);
node* _delete(node* t, long long k);

node* rightRotate(node* t) {
	node* s = t->left;
	t->left = s->right;
	s->right = t;
	if (t == root) {
		root = s;
	}
	return s;
} 

node* leftRotate(node* t) {
	node* s = t->right;
	t->right = s->left;
	s->left = t;
	if (t == root) {
		root = s;
	}
	return s;
}

node* insert(node* t, long long k, long long p) {
	if (t == NULL) {
		if (root == NULL) {
			root = new node{k,p,NULL,NULL};
			return root;
		}
		return (new node{k,p});
	}
	if (k < t->key) {
		t->left = insert(t->left,k,p);
		if (t->pri < t->left->pri) {
			t = rightRotate(t);
		}
	}
	else {
		t->right = insert(t->right,k,p);
		if (t->pri < t->right->pri) {
			t = leftRotate(t);
		}
	}
	return t;
}

node* delete_node(node* t, long long k) {
	if (t == NULL) {
		return NULL;
	}
	if (k < t->key) {
		t->left = delete_node(t->left,k);
	}
	else if (k > t->key) {
		t->right = delete_node(t->right,k);
	}
	else {
		return _delete(t,k);
	}
	return t;
}

node* _delete(node* t, long long k) {
	if (t->left == NULL && t-> right == NULL) {
		if (t == root) {
			root = NULL;
		}
		return NULL;
	}
	else if (t->left == NULL) {
		t = leftRotate(t);
	}
	else if (t->right == NULL) {
		t = rightRotate(t);
	}
	else {
		if (t->left->pri > t->right->pri) {
			t = rightRotate(t);
		}
		else {
			t = leftRotate(t);
		}
	}
	return delete_node(t,k);
}

bool find_node(long long k) {
	node* now = root;
	while (now != NULL) {
		if (k == now->key) {
			return true;
		}
		else if (k > now->key) {
			now = now->right;
		}
		else {
			now = now->left;
		}
	}
	return false;
}

void inorder_walk(node* t) {
	if (t == NULL) {
		return;
	}
	inorder_walk(t->left);
	cout << " " << t->key;
	inorder_walk(t->right);
	return;
}

void preorder_walk(node* t) {
	if (t == NULL) {
		return;
	}
	cout << " " << t->key;
	preorder_walk(t->left);
	preorder_walk(t->right);
	return;
}

int main(void) {
	int nop;
	cin >> nop;

	root = NULL;
	string ope;
	long long k,p;
	for (int q = 0; q < nop; ++q) {
		cin >> ope;
		if (ope == "print") {
			inorder_walk(root);
			cout << endl;
			preorder_walk(root);
			cout << endl;
		}
		else {
			cin >> k;
			if (ope == "insert") {
				cin >> p;
				insert(root,k,p);
			}
			else {
				if (ope == "find") {
					if (find_node(k)) {
						cout << "yes" << endl;
					}
					else {
						cout << "no" << endl;
					}
				}
				else {
					delete_node(root,k);
				}
			}
		}
	}
	return 0;
}

