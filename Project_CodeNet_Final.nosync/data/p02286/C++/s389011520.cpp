#include<bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

#define MAX 100005
#define INF INT_MAX

typedef long long ll;
typedef pair<int, int> P;

#define NIL NULL
struct node{
    struct node *right;
    struct node *left;
    ll key;
    ll priority;
    node(ll key, ll priority) {
        this->key = key;
        this->priority = priority;
        this->right = NIL;
        this->left = NIL;
    }
};
typedef struct node * Node;

void preorder(Node u);
void inorder(Node u);

Node root;

Node treeMinimum(Node x)
{
    if (x == NIL) return NIL;

    Node current = x;
    while (current->left != NIL) current = current->left;

    return current;
}
Node treeMaximum(Node x)
{
    if (x == NIL) return NIL;

    Node current = x;
    while (current->right != NIL) current = current->right;

    return current;
}
Node treeSearch(Node u, int k)
{
    Node ret;
    if (u == NIL) return NIL;

    if (k < u->key) ret = treeSearch(u->left, k);
    else if (k > u->key) ret = treeSearch(u->right, k);
    else ret = u;

    return ret;
}
Node treeSuccessor(Node x)
{
    if (x == NIL) return NIL;

    return treeMinimum(x->right);
}

Node treeRotateRight(Node x)
{
    Node y = x->left;
    if (y == NIL) return NIL;

    x->left = y->right;
    y->right = x;

    return y;
}

Node treeRotateLeft(Node x)
{
    Node y = x->right;
    if (y == NIL) return NIL;

    x->right = y->left;
    y->left = x;

    return y;
}

Node treeDelete(Node x, ll k)
{
    if (x == NIL) return NIL;
    if (k < x->key) {
        x->left = treeDelete(x->left, k);
        return x;
    } else if (k > x->key) {
        x->right = treeDelete(x->right, k);
        return x;
    }

    // 削除対象の節点の場合
    if (x->left == NIL && x->right == NIL) return NIL;  // 葉の場合

    if (x->left == NIL) x = treeRotateLeft(x);
    else if (x->right == NIL) x = treeRotateRight(x);
    else {
        if (x->left->priority > x->right->priority) {
            x = treeRotateRight(x);
        } else {
            x = treeRotateLeft(x);
        }
    }
    return treeDelete(x, k);
}
void treeDelete(ll k) { root = treeDelete(root, k); }

Node insert(Node x, ll k, ll p)
{
    Node y = new node(k, p);

    if (x == NIL) return y;

    if (k < x->key) {
        x->left = insert(x->left, k, p);
        if (x->priority < x->left->priority) {
            x = treeRotateRight(x);
        }
    } else {
        x->right = insert(x->right, k, p);
        if (x->priority < x->right->priority) {
            x = treeRotateLeft(x);
        }
    }
    return x;
}
void insert(ll k, ll p) { root = insert(root, k, p); }

void inorder(Node u)
{
    if (u == NIL) return;
    
    inorder(u->left);
    cout << " " << u->key;
    inorder(u->right);    
}
void preorder(Node u)
{
    if (u == NIL) return;

    cout << " " << u->key;
    preorder(u->left);
    preorder(u->right);
}

int main(int, char**)
{
    ll n, k, p;
    string com;
    cin >> n;

    rep(i,n){
        cin >> com;
        if ( com[0] == 'f' ){
            cin >> k;
            Node t = treeSearch(root, k);
            if ( t != NIL ) cout << "yes" << endl;
            else cout << "no" << endl;
        } else if ( com[0] == 'i' ){
            cin >> k >> p;
            insert(k, p);
        } else if ( com[0] == 'p' ){
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        } else if ( com[0] == 'd' ){
            cin >> k;
            treeDelete(k);
        }
    }
    return 0;
}

