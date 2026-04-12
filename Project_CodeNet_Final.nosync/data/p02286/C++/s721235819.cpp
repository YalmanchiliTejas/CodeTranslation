#include <iostream>
#include <string>

using namespace std;

struct node {
	node* right, * left;
	int key, priority;
};

node* root;

node* rightRotate(node* t) {
	node* s = t->left;
	t->left = s->right;
	s->right = t;
	return s;
}

node* leftRotate(node* t) {
	node* s = t->right;
	t->right = s->left;
	s->left = t;
	return s;
}

node* insert(node* t, int key, int priority) {
	if (t == NULL) {
		node* add;
		add = (node*)malloc(sizeof(node));
		add->key = key;
		add->priority = priority;
		add->left = NULL; add->right = NULL;
		return add;
	}
	if (key == t->key) return t;

	if (key < t->key) {
		t->left = insert(t->left, key, priority);
		if (t->priority < t->left->priority) t = rightRotate(t);
	} else {
		t->right = insert(t->right, key, priority);
		if (t->priority < t->right->priority) t = leftRotate(t);
	}
	return t;
}

node* find(int k) {
	node* x = root;
	while (x != NULL) {
		if (x->key == k) return x;
		else if (x->key > k) x = x->left;
		else x = x->right;
	}
	return NULL;
}

node* _delete(node*, int);
node* treeDelete(node* t, int key) {
	if (t == NULL) return NULL;
	if (key < t->key) t->left = treeDelete(t->left, key);
	else if (key > t->key) t->right = treeDelete(t->right, key);
	else return _delete(t, key);
	return t;
}

node* _delete(node* t, int key) {
	if (t->left == NULL && t->right == NULL) return NULL;
	if (t->left == NULL) t = leftRotate(t);
	else if (t->right == NULL) t = rightRotate(t);
	else {
		if (t->left->priority > t->right->priority) t = rightRotate(t);
		else t = leftRotate(t);
	}
	return treeDelete(t, key);
}

void preorder(node* u) {
	if (u == NULL) return;
	cout << " " << u->key;
	preorder(u->left);
	preorder(u->right);
}

void inorder(node* u) {
	if (u == NULL) return;
	inorder(u->left);
	cout << " " << u->key;
	inorder(u->right);
}

int main() {
	int n; cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == "insert") {
			int k, p; cin >> k >> p;;
			root = insert(root, k, p);
		} else if (s == "find") {
			int k; cin >> k;
			cout << (find(k) != NULL ? "yes" : "no") << endl;
		} else if (s == "delete") {
			int k; cin >> k;
			root = treeDelete(root, k);
		} else {
			inorder(root);
			cout << endl;
			preorder(root);
			cout << endl;
		}
	}

	return 0;
}
