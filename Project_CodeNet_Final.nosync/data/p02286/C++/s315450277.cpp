#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>

typedef struct _node {
	int key;
	int priority;
	struct _node * left;
	struct _node * right;
	struct _node * parent;
} node;

node * left_rotate(node * t) {
	node * new_t = t->right;
	t->right = new_t->left;
	if (t->right != NULL) {
		t->right->parent = t;
	}
	new_t->left = t;
	new_t->parent = t->parent;
	t->parent = new_t;

	if (new_t->parent == NULL) {
		return new_t;
	}

	node * parent = new_t->parent;
	if (parent->left == t) {
		parent->left = new_t;
	}
	else {
		parent->right = new_t;
	}
	return new_t;
}

node * right_rotate(node * t) {
	node * new_t = t->left;
	t->left = new_t->right;
	if (t->left != NULL) {
		t->left->parent = t;
	}
	new_t->right = t;
	new_t->parent = t->parent;
	t->parent = new_t;

	if (new_t->parent == NULL) {
		return new_t;
	}

	node * parent = new_t->parent;
	if (parent->left == t) {
		parent->left = new_t;
	}
	else {
		parent->right = new_t;
	}
	return new_t;
}

node * create_node(int key, int priority) {
	node * p;
	p = (node *)malloc(sizeof(node));
	p->key = key;
	p->priority = priority;
	p->left = NULL;
	p->right = NULL;
	p->parent = NULL;
	return p;
}

node * insert(node * t, int key, int priority) {
	if (t == NULL) {
		node * p = create_node(key, priority);
		return p;
	}

	if (key < t->key) {
		if (t->left == NULL) {
			node * p = create_node(key, priority);
			t->left = p;
			p->parent = t;
		}
		else {
			insert(t->left, key, priority);
		}
				
		if (t->priority < t->left->priority) {
			t = right_rotate(t);
		}
		return t;
	}
	else if (key > t->key) {
		if (t->right == NULL) {
			node * p = create_node(key, priority);
			t->right = p;
			p->parent = t;
		}
		else {
			insert(t->right, key, priority);
		}

		if (t->priority < t->right->priority) {
			t = left_rotate(t);
		}
		return t;
	}
	
	return t;
}

node * delete_node(node * t, int key) {
	if (key == t->key) {
		if (t->left == NULL && t->right == NULL) {
			if (t->parent->left == t) {
				t->parent->left = NULL;
			}
			else {
				t->parent->right = NULL;
			}
			free(t);
			return NULL;
		}

		if (t->left == NULL) {
			t = left_rotate(t);	
		}
		else if (t->right == NULL) {
			t = right_rotate(t);
		}
		else if (t->left->priority > t->right->priority) {
			t = right_rotate(t);
		}
		else {
			t = left_rotate(t);
		}
		t = delete_node(t, key);
		return t;
	}

	if (key < t->key) {
		if (t->left == NULL) {
			return NULL;
		}
		delete_node(t->left, key);
		return t;
	}
	else {
		if (t->right == NULL) {
			return NULL;
		}
		delete_node(t->right, key);
		return t;
	}
}

int find(node * t, int key) {
	if (key == t->key) {
		return 1;
	}
	if (key < t->key) {
		if (t->left == NULL) {
			return 0;
		}
		return find(t->left, key);
	}
	else {
		if (t->right == NULL) {
			return 0;
		}
		return find(t->right, key);
	}
}

void print_preorder(node * t) {
	if (t == NULL) {
		return;
	}
	printf(" %d", t->key);
	if (t->left != NULL) {
		print_preorder(t->left);
	}
	if (t->right != NULL) {
		print_preorder(t->right);
	}
}

void print_inorder(node * t) {
	if (t == NULL) {
		return;
	}
	if (t->left != NULL) {
		print_inorder(t->left);
	}
	printf(" %d", t->key);
	if (t->right != NULL) {
		print_inorder(t->right);
	}
}

int main() {
	int m;
	std::string buf;
	std::string str;
	int k, p;
	node * root = NULL;

	std::getline(std::cin, buf);
	std::stringstream ss0(buf);
	ss0 >> m;

	for (int i = 0; i < m; i++) {
		std::getline(std::cin, buf);
		std::stringstream ss(buf);
		std::getline(ss, str, ' ');
		if (str == "insert") {
			ss >> k >> p;
			//printf("--insert %d %d\n", k, p);
			root = insert(root, k, p);
		}
		else if (str == "find") {
			ss >> k;
			//printf("--find %d\n", k);
			int result = find(root, k);
			if (result == 1) {
				printf("yes\n");
			}
			else {
				printf("no\n");
			}
		}
		else if (str =="delete") {
			ss >> k;
			//printf("--delete %d\n", k);
			root = delete_node(root, k);
		}
		else if (str == "print") {
			//printf("--print\n");
			print_inorder(root);
			printf("\n");
			print_preorder(root);
			printf("\n");
		}
		else {
			printf("error\n");
		}
	}
	
	return 0;
}

