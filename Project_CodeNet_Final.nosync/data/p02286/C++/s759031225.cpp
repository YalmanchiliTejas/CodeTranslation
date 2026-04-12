#include <iostream>

class Node {
public:
	int key;
	Node* left;
	Node* right;
	int priority;
	Node(int key, int priority) { this->key = key; left = right = NULL; this->priority = priority; }
	~Node(){}
};

Node* deleteKey(Node* t, int key);

Node* rightRotate(Node* t)
{
	Node* s = t->left;
	t->left = s->right;
	s->right = t;
	return s;
}

Node* leftRotate(Node* t)
{
	Node* s = t->right;
	t->right = s->left;
	s->left = t;
	return s;
}

Node* insert(Node* t, int key, int priority)
{	
	if (t == NULL) return new Node(key, priority);
	if (key == t->key) return t;
	
	if (key < t->key) {
		t->left = insert(t->left, key, priority);
		if (t->priority < t->left->priority) t = rightRotate(t);
	}
	else {
		t->right = insert(t->right, key, priority);
		if (t->priority < t->right->priority) t = leftRotate(t);
	}
	return t;
}

Node* _deleteKey(Node* t, int key)
{
	if (t->left == NULL && t->right == NULL) {
		delete t;
		return NULL;
	}
	else if (t->left == NULL) t = leftRotate(t);
	else if (t->right == NULL) t = rightRotate(t);
	else {
		if (t->left->priority > t->right->priority) t = rightRotate(t);
		else t = leftRotate(t);
	}
	return deleteKey(t, key);
}

Node* deleteKey(Node* t, int key)
{
	if (t == NULL) return NULL;
	if (key < t->key) t->left = deleteKey(t->left, key);
	else if (key > t->key) t->right = deleteKey(t->right, key);
	else return _deleteKey(t, key);
	return t;
}

bool find(Node* z, int key)
{
	if (z == NULL) return false;
	
	if (key == z->key) return true;
	if (key < z->key) return find(z->left, key);
	else return find(z->right, key);
}

void walk_preorder(Node* x)
{
	std::cout << " " << x->key;
	if (x->left != NULL) walk_preorder(x->left);
	if (x->right != NULL) walk_preorder(x->right);
}

void walk_inorder(Node* x)
{
	if (x->left != NULL) walk_inorder(x->left);
	std::cout << " " << x->key;
	if (x->right != NULL) walk_inorder(x->right);
}

void deleteTree(Node* x)
{
	if (x->left != NULL) deleteTree(x->left);
	if (x->right != NULL) deleteTree(x->right);
	delete x;
}
	
int main()
{
	std::string strn;
	getline(std::cin, strn);
	
	int n = std::stoi(strn);
	
	Node* Treap = NULL;
	
	for (int i=0; i<n; i++) {
		std::string buf;
		getline(std::cin, buf);
		int sp_pos1 = buf.find(' ', 0);
		if (sp_pos1 == std::string::npos) {
			// print
			walk_inorder(Treap); std::cout << std::endl;
			walk_preorder(Treap); std::cout << std::endl;
		}
		else {
			int sp_pos2 = buf.find(' ', sp_pos1+1);
			if (sp_pos2 == std::string::npos) { // find or delete
				std::string op = buf.substr(0, sp_pos1);
				int key = std::stoi(buf.substr(sp_pos1+1));
				if (op == "find") {
					if (find(Treap, key)) std::cout << "yes" << std::endl;
					else std::cout << "no" << std::endl;
				}
				else { // delete
					Treap = deleteKey(Treap, key);
				}
			}
			else {
				int key = std::stoi(buf.substr(sp_pos1 + 1, sp_pos2 - sp_pos1 - 1));
				int priority = std::stoi(buf.substr(sp_pos2+1)); 
				Treap = insert(Treap, key, priority);
			}
		}
	}
	
	deleteTree(Treap);
	
	return 0;
}

