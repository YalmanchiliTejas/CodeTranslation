#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <list>
#include <stack>
#include <cctype>
#include <cmath>

using namespace std;

/* typedef */

typedef long long ll;

/* constant */
const int INF = 1 << 30;
const int MAX = 500000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
struct Node {
    Node *left, 
         *right;
    int key,
        priority;
};

Node *root, *NIL;

/* function */

Node* rightRotate(Node* t);
Node* leftRotate(Node* t);
Node* insert(Node* t, int key, int priority);
Node* Delete(Node* t, int key);
Node* _delete(Node* t, int key);
Node* findNode(int key);
void preorder(Node* v);
void inorder(Node* v);

/* main */
int main(){

    // main
    int n, val, pri;
    cin >> n;
    string man;
    for (int i = 0; i < n; i++) {
        cin >> man;
        if (man == "print") {
            inorder(root); cout << '\n';
            preorder(root); cout << '\n';
        }
        else {
            cin >> val;
            if (man == "insert") {
                cin >> pri;
                root = insert(root, val, pri);
            }
            else if (man == "delete" ) {
                Node* target = findNode(val);
                root = Delete(root, val);
            }
            else {
                Node* ret_node = findNode(val);
                if (ret_node != NIL)
                    cout << "yes" << '\n';
                else
                    cout << "no" << '\n';
            }
        }
    }

}

Node* rightRotate(Node* t) {
    Node* s = t->left;
    t->left = s->right;
    s->right = t;
    return s;  // root of the subtree
}

Node* leftRotate(Node* t) {
    Node* s = t->right;
    t->right = s->left;
    s->left = t;
    return s;  // root of the subtree
}

Node* insert(Node* t, int key, int priority) {          // 再帰的に探索
    if (t == NIL){
        Node* N = new Node();              // 葉に到達したら新しい節点を生成して返す
        N->left = NIL;
        N->right = NIL;
        N->key = key;
        N->priority = priority;
        return N;
    }

    if (key == t->key)
        return t;                                 // 重複したkeyは無視

    if (key < t->key) {                          // 左の子へ移動
        t->left = insert(t->left, key, priority);  // 左の子へのポインタを更新
        if (t->priority < t->left->priority)          // 左の子の方が優先度が高い場合右回転
            t = rightRotate(t);
    }
    else {                                       // 右の子へ移動
        t->right = insert(t->right, key, priority);  // 右の子へのポインタを更新
        if (t->priority < t->right->priority)         // 右の子の方が優先度が高い場合左回転
            t = leftRotate(t);
    }

  return t;
}

Node* Delete(Node* t, int key) {
    if (t == NIL)
        return NIL;
    if (key < t->key)                               // 削除対象を検索
        t->left = Delete(t->left, key);
    else if (key > t->key)
        t->right = Delete(t->right, key);
    else
        return _delete(t, key);
    return t;
}

Node* _delete(Node* t, int key) { // 削除対象の節点の場合
    if (t->left == NIL && t->right == NIL)          // 葉の場合
        return NIL;
    else if (t->left == NIL)                       // 右の子のみを持つ場合左回転
        t = leftRotate(t);
    else if (t->right == NIL)                      // 左の子のみを持つ場合右回転
        t = rightRotate(t);
    else {                                        // 左の子と右の子を両方持つ場合
        if (t->left->priority > t->right->priority)    // 優先度が高い方を持ち上げる
            t = rightRotate(t);
        else
            t = leftRotate(t);
    }
    return Delete(t, key);
}

Node* findNode(int key) {
    Node* x = root;
    while (x != NIL) {
        if (key == x->key) 
            return x;
        else if (key < x->key)                               // 削除対象を検索
            x = x->left;
        else if (key > x->key)
            x = x->right;
        }
    return x;
}
 
void preorder(Node* v) {
    if (v != NIL) {
        cout << ' ' << v->key;
        preorder(v->left);
        preorder(v->right);
    }

}

void inorder(Node* v) {
    if (v != NIL) {
        inorder(v->left);
        cout << ' ' << v->key;
        inorder(v->right);
    }
}

