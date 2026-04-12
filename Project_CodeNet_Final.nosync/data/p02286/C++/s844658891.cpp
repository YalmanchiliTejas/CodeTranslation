#include <iostream>
#include <string>

using namespace std;

struct node_t{
	int key;
	int priority;
	node_t *left;
	node_t *right;
	node_t(int key, int priority): key(key), priority(priority), left(NULL), right(NULL) {}
};

node_t* left_rotate(node_t *t){
	node_t *right_child = t->right;
	t->right = right_child->left;
	right_child->left = t;
	return right_child;
}

node_t* right_rotate(node_t *t){
	node_t *left_child = t->left;
	t->left = left_child->right;
	left_child->right = t;
	return left_child;
}

node_t* insert(node_t *t, int key, int priority){
	if(t == NULL) return new node_t(key, priority);
	if(key == t->key) return t;
	if(key < t->key){
		t->left = insert(t->left, key, priority);
		if(t->priority < t->left->priority) t = right_rotate(t);
	}else{
		t->right = insert(t->right, key, priority);
		if(t->priority < t->right->priority) t = left_rotate(t);
	}
	return t;
}

node_t* delete_node(node_t *t, int key){
	if(t == NULL) return NULL;
	if(key == t->key){
		// move the node to the leaf
		if(t->left == NULL && t->right == NULL) {
			delete t;
			return NULL;
		}else if(t->left == NULL){
			t = left_rotate(t);
		}else if(t->right == NULL){
			t = right_rotate(t);
		}else{
			if(t->left->priority > t->right->priority){
				t = right_rotate(t);
			}else{
				t = left_rotate(t);
			}
		}
		return delete_node(t, key); // do this again until we move t into the leaf
	}

	// search the node to delete
	if(key < t->key){
		t->left = delete_node(t->left, key);
	}else{
		t->right = delete_node(t->right, key);
	}
	return t;
}

void find_node(node_t *t, int key){
	if(t == NULL) {
		cout << "no" << endl;
		return;
	}
	if(key == t->key){
		cout << "yes" << endl;
	}else if(key < t->key){
		find_node(t->left, key);
	}else{
		find_node(t->right, key);
	}
}

void inorder(node_t *t){
	if(t == NULL){
		return;
	}
	inorder(t->left);
	cout << " " << t->key;
	inorder(t->right);
}

void preorder(node_t *t){
	if(t == NULL) {
		return;
	}
	cout << " " << t->key;
	preorder(t->left);
	preorder(t->right);
}

void print_tree(node_t *t){
	inorder(t);
	cout << endl;
	preorder(t);
	cout << endl;
}

int main(){
	int q;
	cin >> q;
	node_t *t = NULL;
	for(auto i = 0; i < q; ++i){
		string cmd;
		cin >> cmd;
		if(cmd == "insert"){
			int k, p;
			cin >> k >> p;
			t = insert(t, k, p);
		}else if(cmd == "find"){
			int k;
			cin >> k;
			find_node(t, k);
		}else if(cmd == "delete"){
			int k;
			cin >> k;
			t = delete_node(t, k);
		}else if(cmd == "print"){
			print_tree(t);
		}
	}
}
