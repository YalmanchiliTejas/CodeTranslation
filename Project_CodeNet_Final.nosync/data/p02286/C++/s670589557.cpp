#include <iostream>
#include <string>
using namespace std;

struct Node {
	int key;
	int priority;

	Node *left, *right;
	
	Node(int k, int p) : key(k), priority(p), left(nullptr), right(nullptr) { }

};

Node *insert(Node *node, int key, int priority);
void find(Node *node, int key);
Node *deleteNode(Node *node, int key);
Node *_deleteNode(Node *node, int key);
Node *head = nullptr;

Node *rightRotate(Node *node);
Node *leftRotate(Node *node);

void print();
void printFront(Node *node);
void printCenter(Node *node);

int main() {

	int m;
	int key, priority;
	string cmd;
	// 入力の数が入力される
	cin >> m;

	for (int i = 0; i < m; ++i) {

		cin >> cmd;
		if (cmd[0] == 'i') {   // insert

			cin >> key >> priority;
			head = insert(head, key, priority);

		}
		else if(cmd[0] == 'f') {   // find

			cin >> key;
			find(head, key);

		}
		else if (cmd[0] == 'd') {   // delete

			cin >> key;
			head = deleteNode(head, key);

		}
		else {
			
			print();

		}

		/*
		cout << endl;
		cout << "i = " << i << endl;
		print();
		cout << endl;
		*/
	}

	return 0;

}

Node *insert(Node *node, int key, int priority) {

	// cout << "insert" << endl;

	if (node == nullptr)
		return new Node(key, priority);
	if (key == node->key)
		return node;

	if (key < node->key) {
		node->left = insert(node->left, key, priority);
		if (node->priority < node->left->priority)
			node = rightRotate(node);
	}
	else {
		node->right = insert(node->right, key, priority);
		if (node->priority < node->right->priority)
			node = leftRotate(node);
	}

	return node;
}

void find(Node *node, int key) {

	if (node == nullptr) {
		cout << "no" << endl;
		return;
	}

	if (node->key == key) {
		cout << "yes" << endl;
		return;
	}
	else if (node->key > key) {
		find(node->left, key);
	}
	else
		find(node->right, key);

}

Node *rightRotate(Node *node) {

//	cout << "rightRotate" << endl;

	Node *s = node->left;
	node->left = s->right;
	s->right = node;
	return s;
}

Node *leftRotate(Node *node) {

//	cout << "leftRotate" << endl;

	Node *s = node->right;
	node->right = s->left;
	s->left = node;
	return s;
}

Node *deleteNode(Node *node, int key) {

	if (node == nullptr) {
		delete node;
		return nullptr;
	}

	if (key < node->key)
		node->left = deleteNode(node->left, key);
	else if (key > node->key)
		node->right = deleteNode(node->right, key);
	else
		return _deleteNode(node, key);

	return node;

}

Node *_deleteNode(Node *node, int key) {

	if (node->left == nullptr && node->right == nullptr)
		return nullptr;
	else if (node->left == nullptr)
		node = leftRotate(node);
	else if (node->right == nullptr)
		node = rightRotate(node);
	else {
		if (node->left->priority > node->right->priority)
			node = rightRotate(node);
		else
			node = leftRotate(node);
	}

	return deleteNode(node, key);

}

void printFront(Node *node) {

	if (node == nullptr)
		return;

	cout << " " << node->key;
	printFront(node->left);
	printFront(node->right);

}

void printCenter(Node *node) {

	if (node == nullptr)
		return;

	printCenter(node->left);
	cout << " " << node->key;
	printCenter(node->right);

}

void print() {

	printCenter(head);
	cout << endl;
	printFront(head);
	cout << endl;

}
