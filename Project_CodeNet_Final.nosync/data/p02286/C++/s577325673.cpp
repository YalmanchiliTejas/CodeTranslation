#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

/*treap*/

//二叉树结构体，
typedef struct node {
	long key;
	long pri;
	node * left = NULL;
	node * right = NULL;
	node * parent = NULL;
}node;

long m;
node * root = NULL;


/*left rotate*/
node * leftRotate(node * p) {
	node *p1 = p->right;
	node *p2 = p->parent;
	if (p1 != NULL) {
		p->right = p1->left;
		if (p1->left != NULL) {
			p1->left->parent = p;
		}
		p1->left = p;
		p->parent = p1;
	}
	if (p2 != NULL) {
		if (p2->left == p) {
			p2->left = p1;
		}
		else {
			p2->right = p1;
		}
	}
	else
		root = p1;
	p1->parent = p2;
	return p1;
}

/*right rotate*/
node * rightRotate(node * p) {
	node *p1 = p->left;
	node *p2 = p->parent;
	if (p1 != NULL) {
		p->left = p1->right;
		if (p1->right != NULL) {
			p1->right->parent = p;
		}
		p1->right = p;
		p->parent = p1;
	}
	if (p2 != NULL) {
		if (p2->left == p) {
			p2->left = p1;
		}
		else {
			p2->right = p1;
		}
	}
	else
		root = p1;
	p1->parent = p2;
	return p1;
}

/*插入函数*/
void insert(long key, long pri) {
	node *p1;
	p1 = (node *)malloc(sizeof(node));
	p1->key = key;
	p1->pri = pri;
	p1->left = p1->right = p1->parent = NULL;

	node *p2 = root;
	node *p3 = p2;
	if (p2 == NULL) {
		root = p1;
		return;
	}
	
	/*找到需要插入的位置*/
	while (p2 != NULL) {
		p3 = p2;
		if (p1->key < p2->key) {
			p2 = p2->left;
		}
		else if (p1->key > p2->key) {
			p2 = p2->right;
		}
	}

	if (p2 == NULL) {
		if (p3->key < p1->key) {
			p3->right = p1;
		}
		else
			p3->left = p1;
		p1->parent = p3;
	}

	/*对treap进行旋转处理*/
	while (1) {
		p3 = p1->parent;
		if (p3 != NULL&&p1->pri > p3->pri) {
			if (p1 == p3->left) {
				p1 = rightRotate(p3);
			}
			else if (p1 == p3->right) {
				p1 = leftRotate(p3);
			}
			else
				break;
		}
		else 
			break;
	}
	
	return;
}

void printinorder(node * p) {
	if (p == NULL) {
		return;
	}
	if (p->left != NULL) {
		printinorder(p->left);
	}
	cout << ' ' << p->key;
	if (p->right != NULL) {
		printinorder(p->right);
	}
}

void printpreorder(node * p) {
	if (p == NULL) {
		return;
	}
	cout << ' '<< p->key ;
	if (p->left != NULL) {
		printpreorder(p->left);
	}
	if (p->right != NULL) {
		printpreorder(p->right);
	}
}

node * findnext(node * p) {
	node * p1 = p->right;
	while (p1->left != NULL) {
		p1 = p1->left;
	}
	return p1;
}

void deletes(node * p) {
	node *p1; 
	if (p == NULL) {
		return;
	}
	while (p->left != NULL || p->right != NULL) {
		if (p->left == NULL) {
			p = leftRotate(p);
			p = p->left;
		}
		else if (p->right == NULL) {
			p = rightRotate(p);
			p = p->right;
		}
		else if (p->left->pri < p->right->pri) {
			p = leftRotate(p);
			p = p->left;
		}
		else if (p->left->pri > p->right->pri) {
			p = rightRotate(p);
			p = p->right;
		}
	}
	p1 = p->parent;
	if (p1 != NULL) {
		if (p1->left == p)
			p1->left = NULL;
		else
			p1->right = NULL;
		free(p);
		return;
	}
	else {
		root = NULL;
	}
	return;
}

node * finds(long k, int ss) {
	node * p = root;
	while (p != NULL && p->key != k) {
		if (p->key < k) {
			p = p->right;
		}
		else {
			p = p->left;
		}
	}
	if (p == NULL&&ss==1) {
		cout << "no" << endl;
	}
	else if(ss == 1){
		cout << "yes" << endl;
	}
	return p;
}

int main() {
	cin >> m;
	string com;
	long k, p;
	for (int i = 0; i < m; ++i) {
		cin >> com;
		switch (com[0]) {
		case 'f': cin >> k; finds(k, 1); break;
		case 'i': cin >> k >> p; insert(k, p); break;
		case 'd': cin >> k; deletes(finds(k, 0)); break;
		case 'p': printinorder(root); cout << endl; printpreorder(root); cout << endl; break;
		}
	}
	
	return 0;
}
