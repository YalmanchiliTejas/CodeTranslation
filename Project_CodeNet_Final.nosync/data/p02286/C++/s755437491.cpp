#include<stdio.h>
using namespace std;

struct Node {
	int key, priority;
	Node *left, *right;
};

class Treap {
private:
	Node *root = NULL;
	Node* rightRotate(Node*);
	Node* leftRotate(Node*);
	Node* insert_rec(Node*, int, int);
	Node* delete_rec(Node*, int);
	Node* _delete(Node*, int);
	void print_in(Node*);
	void print_pre(Node*);
	void postorder_delete(Node*);
public:
	~Treap();
	void Insert(int, int);
	void Delete(int);
	void Find(int);
	void Print();
};

Node* Treap::rightRotate(Node* t)
{
	Node *s;
	s = t->left;
	t->left = s->right;
	s->right = t;
	return s;
}

Node* Treap::leftRotate(Node* t)
{
	Node *s;
	s = t->right;
	t->right = s->left;
	s->left = t;
	return s;
}

void Treap::Insert(int key, int priority)
{
	this->root = this->insert_rec(this->root, key, priority);
}

Node* Treap::insert_rec(Node* t, int key, int priority)
{
	if (t == NULL)
		return new Node{ key, priority, NULL, NULL};
	if (key == t->key)
		return t;

	if (key < t->key)
	{
		t->left = this->insert_rec(t->left, key, priority);
		if (t->priority < t->left->priority)
			t = this->rightRotate(t);
	}
	else
	{
		t->right = this->insert_rec(t->right, key, priority);
		if (t->priority < t->right->priority)
			t = this->leftRotate(t);
	}

	return t;
}

void Treap::Delete(int key)
{
	this->root = this->delete_rec(this->root, key);
}

Node* Treap::delete_rec(Node* t, int key)
{
	if (t == NULL)
		return NULL;
	if (key < t->key)
		t->left = this->delete_rec(t->left, key);
	else if (key > t->key)
		t->right = this->delete_rec(t->right, key);
	else
		return this->_delete(t, key);
	return t;
}

Node* Treap::_delete(Node* t, int key)
{
	if (t->left == NULL && t->right == NULL)
	{
		delete t;
		return NULL;
	}
	else if (t->left == NULL)
		t = this->leftRotate(t);
	else if (t->right == NULL)
		t = this->rightRotate(t);
	else
	{
		if (t->left->priority > t->right->priority)
			t = this->rightRotate(t);
		else
			t = this->leftRotate(t);
	}
	return this->delete_rec(t, key);
}

void Treap::Find(int key)
{
	for (Node* finder = this->root; finder != NULL; 
		key < finder->key ? finder = finder->left : finder = finder->right)
		if (finder->key == key)
		{
			printf("yes\n");
			return;
		}
	printf("no\n");
	return;
}

void Treap::Print()
{
	this->print_in(this->root);
	printf("\n");
	this->print_pre(this->root);
	printf("\n");
}

void Treap::print_in(Node* subroot)
{
	if (subroot)
	{
		this->print_in(subroot->left);
		printf(" %d", subroot->key);
		this->print_in(subroot->right);
	}
}

void Treap::print_pre(Node* subroot)
{
	if (subroot)
	{
		printf(" %d", subroot->key);
		this->print_pre(subroot->left);
		this->print_pre(subroot->right);
	}
}

Treap::~Treap()
{
	this->postorder_delete(this->root);
}

void Treap::postorder_delete(Node* subroot)
{
	if (subroot)
	{
		this->postorder_delete(subroot->left);
		this->postorder_delete(subroot->right);
		delete subroot;
	}
}

int main()
{
	int m, key, priority;
	char command[16];
	Treap treap;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", command);
		if (command[0] == 'i')
		{
			scanf("%d%d", &key, &priority);
			treap.Insert(key, priority);
		}
		else if (command[0] == 'f')
		{
			scanf("%d", &key);
			treap.Find(key);
		}
		else if (command[0] == 'd')
		{
			scanf("%d", &key);
			treap.Delete(key);
		}
		else
			treap.Print();
	}
	return 0;
}
