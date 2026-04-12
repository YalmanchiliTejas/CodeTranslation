#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
ll dx[4] = { 0, 1, 0, -1 };
ll dy[4] = { 1, 0, -1, 0 };
const ll INF = LLONG_MAX;
const ll MOD = 1e9 + 7;

struct Node {
    int key;
    int priority;
    Node *left, *right;
};

Node *root, *NIL;

Node* _delete(Node* t, int key);

Node* rightRorate(Node* t)
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

Node* insert(Node* t, int key, int priority) // 再帰的に検索
{
    if (t == NIL) { // 葉に到達したら新しい節点を生成して返す
        Node* ret = (Node*)malloc(sizeof(Node));
        ret->key = key;
        ret->priority = priority;
        ret->left = NIL;
        ret->right = NIL;
        return ret;
    }
    if (key == t->key) { // 重複したkeyは無視
        return t;
    }
    if (key < t->key) { // 左の子へ移動
        t->left = insert(t->left, key, priority); // 左の子のポインタを更新
        if (t->priority < t->left->priority) { // 左の子の優先度が高い場合右回転
            t = rightRorate(t);
        }
    } else { // 右の子へ移動
        t->right = insert(t->right, key, priority); // 右の子へのポインタを更新
        if (t->priority < t->right->priority) { // 右の子の方が優先度が高い場合左回転
            t = leftRotate(t);
        }
    }
    return t;
}

Node* treeDelete(Node* t, int key)
{
    if (t == NIL) {
        return NIL;
    }
    if (key < t->key) { // 削除対象を検索
        t->left = treeDelete(t->left, key);
    } else if (key > t->key) {
        t->right = treeDelete(t->right, key);
    } else {
        return _delete(t, key);
    }
    return t;
}

Node* _delete(Node* t, int key)
{
    if (t->left == NIL && t->right == NIL) { // 葉の場合
        return NIL;
    } else if (t->left == NIL) { // 右の子のみを持つ場合左回転
        t = leftRotate(t);
    } else if (t->right == NIL) { // 左の子のみを持つ場合右回転
        t = rightRorate(t);
    } else { // 左の子と右の子を両方持つ場合
        if (t->left->priority > t->right->priority) { // 優先度が高い方を持ち上げる
            t = rightRorate(t);
        } else {
            t = leftRotate(t);
        }
    }
    return treeDelete(t, key);
}

Node* find(Node* u, int x)
{
    while (!(u == NIL || u->key == x)) {
        if (u->key < x) {
            u = u->right;
        } else {
            u = u->left;
        }
    }
    return u;
}

void inorder(Node* u)
{
    if (u == NIL) {
        return;
    }
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void preorder(Node* u)
{
    if (u == NIL) {
        return;
    }
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

void print()
{
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    rep(i, m)
    {
        int k, p;
        string com;
        cin >> com;
        if (com == "insert") {
            cin >> k >> p;
            root = insert(root, k, p);
        } else if (com == "print") {
            print();
        } else if (com == "find") {
            cin >> k;
            Node* t = find(root, k);
            if (t != NIL) {
                puts("yes");
            } else {
                puts("no");
            }
        } else if (com == "delete") {
            cin >> k;
            root = treeDelete(root, k);
        }
    }
    return 0;
}
