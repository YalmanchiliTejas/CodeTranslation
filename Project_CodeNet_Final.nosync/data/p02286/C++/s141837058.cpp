#include <iostream>
#include <cstdio>

struct node{
	struct node *right;
	struct node *left;
	struct node *parent;
	int key;
	int priority;
};
typedef struct node * Node;
#define NIL NULL

Node root;

Node rightRotate(Node t){
	Node s = t->left;
	if (t == root) root = s;
	if (t->parent != NIL){
		if (t->parent->right == t){
			t->parent->right = s;
		}
		else{
			t->parent->left = s;
		}
	}
	s->parent = t->parent;
	t->parent = s;
	if (s->right != NIL) s->right->parent = t;
	t->left = s->right;
	s->right = t;
	return s; // root of the subtree
}

Node leftRotate(Node t){
	Node s = t->right;
	if (t == root) root = s;
	if (t->parent != NIL){
		if (t->parent->right == t){
			t->parent->right = s;
		}
		else{
			t->parent->left = s;
		}
	}
	s->parent = t->parent;
	t->parent = s;
	if (s->left != NIL) s->left->parent = t;
	t->right = s->left;
	s->left = t;
	return s; // root of the subtree
}

Node treeMinimum(Node x){
	Node c = x;
	while (c->left != NIL){
		c = c->left;
	}
	return c;
}

Node treeMaximum(Node x){
	Node c = x;
	while (c->right != NIL){
		c = c->right;
	}
	return c;
}

Node treeSearch(Node u, int k){
	if (u == NIL) return NIL;
	if (u->key == k){
		return u;
	}
	else if (u->key > k){
		Node n = treeSearch(u->left, k);
		if (n != NIL) return n;
	}
	else{
		Node m = treeSearch(u->right, k);
		if (m != NIL) return m;
	}
	return NIL;
}


Node Rec_delete(Node t, int key);
Node treapDelete(Node t, int key);
void treeDelete(Node t);
void preorder(Node t);

Node Rec_delete(Node t, int key){ // 削除対象の節点の場合
	if (t->left == NIL && t->right == NIL){           // 葉の場合
		//treeDelete(t);
		return NIL;
	}
	else if (t->left == NIL){                        // 右の子のみを持つ場合左回転
		t = leftRotate(t);
	}
	else if (t->right == NIL){                       // 左の子のみを持つ場合右回転
		t = rightRotate(t);
	}
	else{                                         // 左の子と右の子を両方持つ場合
		if (t->left->priority > t->right->priority){    // 優先度が高い方を持ち上げる
			t = rightRotate(t);
		}
		else{
			t = leftRotate(t);
		}
	}
	return treapDelete(t, key);
}

Node treapDelete(Node t, int key){
	if (t == NIL){
		return NIL;
	}
	if (key < t->key){                                // 削除対象を検索
		t->left = treapDelete(t->left, key);
	}
	else if (key > t->key){
		t->right = treapDelete(t->right, key);
	}
	else{
		return Rec_delete(t, key);
	}
	return t;
}

Node treeSuccessor(Node x){
	if (x->right != NIL){
		return treeMinimum(x->right);
	}
	else{
		Node c = x;
		while (c != root){
			if (c->parent->left == c){
				return c->parent;
				break;
			}
		}
		return NIL;
	}
}

void treeDelete(Node z){
	if (z->left == NIL && z->right == NIL){
		if (z->parent->left == z){
			z->parent->left = NIL;
		}
		else{
			z->parent->right = NIL;
		}
		delete z;
	}
	else if (z->left == NIL){
		if (z->parent->left == z){
			z->parent->left = z->right;
		}
		else{
			z->parent->right = z->right;
		}
		z->right->parent = z->parent;
		delete z;
	}
	else if (z->right == NIL){
		if (z->parent->left == z){
			z->parent->left = z->left;
		}
		else{
			z->parent->right = z->left;
		}
		z->left->parent = z->parent;
		delete z;
	}
	else{
		Node y = treeSuccessor(z);
		z->key = y->key;
		treeDelete(y);
	}
}

Node insert(Node t, int key, int priority){ // 再帰的に探索
	if (t == NIL){
		Node y = NIL;
		Node x = root;
		Node z = new node;

		z->key = key;
		z->priority = priority;
		z->left = NIL;
		z->right = NIL;

		while (x != NIL){
			y = x;
			if (z->key < x->key){
				x = x->left;
			}
			else{
				x = x->right;
			}
		}
		z->parent = y;
		if (y == NIL) {
			root = z;
		}
		else if (z->key < y->key){
			y->left = z;
		}
		else{
			y->right = z;
		}
		return z;               // 葉に到達したら新しい節点を生成して返す
	}
	if (key == t->key){
		return t;                             // 重複したkeyは無視
	}

	if (key < t->key){                             // 左の子へ移動
		t->left = insert(t->left, key, priority);   // 左の子へのポインタを更新
		if (t->priority < t->left->priority){     // 左の子の方が優先度が高い場合右回転
			t = rightRotate(t);
		}
	}
	else{                  // 右の子へ移動
		t->right = insert(t->right, key, priority);// 右の子へのポインタを更新
		if (t->priority < t->right->priority){    // 右の子の方が優先度が高い場合左回転
			t = leftRotate(t);
		}
	}

	return t;


}

void inorder(Node u){
	if (u->left != NIL) inorder(u->left);
	printf(" %d", u->key);
	if (u->right != NIL) inorder(u->right);
	return;
}
void preorder(Node u){
	printf(" %d", u->key);
	if (u->left != NIL) preorder(u->left);
	if (u->right != NIL) preorder(u->right);
	return;
}


int main(){
	int n, i, x, y;
	char com[20];
	scanf("%d", &n);

	for (i = 0; i < n; i++){
		scanf("%s", com);
		if (com[0] == 'f'){
			scanf("%d", &x);
			Node t = treeSearch(root, x);
			if (t != NIL) printf("yes\n");
			else printf("no\n");
		}
		else if (com[0] == 'i'){
			scanf("%d%d", &x, &y);
			insert(root, x, y);
		}
		else if (com[0] == 'p'){
			inorder(root);
			printf("\n");
			preorder(root);
			printf("\n");
		}
		else if (com[0] == 'd'){
			scanf("%d", &x);
			treapDelete(root, x);
		}
	}

	return 0;
}
