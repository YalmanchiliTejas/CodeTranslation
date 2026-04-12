#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Node {
	Node *parent, *right, *left;
	int key;
	int priority;
};

Node *root, *NIL;

Node * deleteN(Node *, int);
Node * _delete(Node *, int);


Node * createNode(int key,int priority){
	Node *n = new Node;
	n->key = key;
	n->priority = priority;
	n->left = NIL;
	n->right = NIL;
	return n;
}

Node * rightRotate(Node *t){
	Node *s = t->left;
	t->left = s->right;
	s->right = t;
	return s;
}

/*
rightRotate(Node t)
    Node s = t.left
    t.left = s.right
    s.right = t
    return s // root of the subtree
*/

Node * leftRotate(Node *t){
	Node *s = t->right;
	t->right = s->left;
	s->left = t;
	return s;
}

/*
leftRotate(Node t)
    Node s = t.right
    t.right = s.left
    s.left = t
    return s // root of the subtree
*/

Node * insert(Node *t, int key, int priority){
	//cout << "insertはいってる" << endl;
	if(t == NIL){
		return createNode(key, priority);
	}
	if(key < t->key){
		t->left = insert(t->left, key, priority);
		if(t->priority < t->left->priority){
			t = rightRotate(t);
		}
	}
	else{
		t->right = insert(t->right, key, priority);
		if(t->priority < t->right->priority){
			t = leftRotate(t);
		}
	}
	return t;
}

/*
insert(Node t, int key, int priority){}           // 再帰的に探索
    if t == NIL
        return Node(key, priority)               // 葉に到達したら新しい節点を生成して返す
    if key == t.key
        return t;                               // 重複したkeyは無視

    if key < t.key                               // 左の子へ移動
        t.left = insert(t.left, key, priority)   // 左の子へのポインタを更新
        if t.priority < t.left.priority          // 左の子の方が優先度が高い場合右回転
            t = rightRotate(t)
    else                                         // 右の子へ移動
        t.right = insert(t.right, key, priority) // 右の子へのポインタを更新
        if t.priority < t.right.priority         // 右の子の方が優先度が高い場合左回転
            t = leftRotate(t)

  return t;
*/

Node * deleteN(Node *t, int key){
	if(t == NIL){
		return NIL;
	}
	if(key < t->key){
		t->left = deleteN(t->left, key);
	}
	else if(key > t->key){
		t->right = deleteN(t->right, key);
	}
	else{
		return _delete(t, key);
	}
	return t;
}

/*
delete(Node t, int key)
    if t == NIL
        return NIL
    if key < t.key                                // 削除対象を検索
        t.left = delete(t.left, key)
    else if key > t.key
        t.right = delete(t.right, key)
    else
        return _delete(t, key)
    return t
*/

Node * _delete(Node *t, int key){
	if(t->left == NIL && t->right == NIL){
		return NIL;
	}
	else if(t->left == NIL){
		t = leftRotate(t);
	}
	else if(t->right == NIL){
		t = rightRotate(t);
	}
	else{
		if(t->left->priority > t->right->priority){
			t = rightRotate(t);
		}
		else{
			t = leftRotate(t);
		}
	}
	return deleteN(t,key);
}

/*
_delete(Node t, key) // 削除対象の節点の場合
    if t.left == NIL && t.right == NIL           // 葉の場合
        return NIL
    else if t.left == NIL                        // 右の子のみを持つ場合左回転
        t = leftRotate(t)
    else if t.right == NIL                       // 左の子のみを持つ場合右回転
        t = rightRotate(t)
    else                                         // 左の子と右の子を両方持つ場合
        if t.left.priority > t.right.priority    // 優先度が高い方を持ち上げる
            t = rightRotate(t)
        else
            t = leftRotate(t)
    return delete(t, key)
*/


Node * find(Node *t,int key){
	while(t != NIL && key != t->key){
		if(key < t->key){
			t = t->left;
		}
		else{
			t = t->right;
		}
	}

	return t;
}

/*
int maxValue(Node *t){
	if(t->right != NIL) maxValue(t->right);
	else{
		return t->key;
	}
}
*/

void inorder(Node *t){
	if(t == NIL)return;
	inorder(t->left);
	cout << " " << t->key;
	inorder(t->right);
}

void preorder(Node *t){
	if(t == NIL)return;
	cout << " " << t->key;
	preorder(t->left);
	preorder(t->right);
}

int main(){
	root = NIL;
	int n,x,y;
	string s;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> s;

		if(s == "insert"){
			cin >> x >> y;
			root = insert(root, x, y);
		}

		if(s == "delete"){
			cin >> x;
			root = deleteN(root, x);
		}

		if(s == "find"){
			cin >> x;
			Node *t = find(root, x);
			if(t != NIL){
				cout << "yes" << endl;
			}
			else{
				cout << "no" << endl;
			}
		}

		if(s == "print"){
			inorder(root);
			cout << endl;
			preorder(root);
			cout << endl;
		}
	}

	return 0;
}
