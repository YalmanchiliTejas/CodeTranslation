#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
const long long INFLL = 1LL << 60;
const int INFINT = 1 << 30;
const long long MOD = 1e9 + 7;

template <class T> void vecout(T V) {
    auto t = V.begin();
    while(t != V.end()) {
        cout << *t++;
        if(t != V.end()) cout << " ";
    }
    cout << endl;
};

class node {
  public:
    int key;
    int pri;
    node *p;
    node *l;
    node *r;
};
node *NIL, *root;

node *rightRotate(node *t) {
    node *s;
    s = t->l;
    t->l = s->r;
    s->r = t;
    return s;
}

node *leftRotate(node *t) {
    node *s;
    s = t->r;
    t->r = s->l;
    s->l = t;
    return s;
}

node *insert(node *t, int k, int p) {
    if(t == NIL) {
        node *z = new node;
        z->key = k;
        z->pri = p;
        z->l = NIL;
        z->r = NIL;
        return z;
    }
    if(k == t->key) {
        return t;
    }
    if(k < t->key) {
        t->l = insert(t->l, k, p);
        if(t->pri < t->l->pri) t = rightRotate(t);
    } else {
        t->r = insert(t->r, k, p);
        if(t->pri < t->r->pri) t = leftRotate(t);
    }
    return t;
}

void traverse(node *now, int order) {
    if(order == 0) cout << " " << now->key; // preorder
    if(now->l != NIL) traverse(now->l, order);
    if(order == 1) cout << " " << now->key; // inorder
    if(now->r != NIL) traverse(now->r, order);
    if(order == 2) cout << " " << now->key; // postorder
}

node *find(int k) {
    node *x = root;
    while(x != NIL && x->key != k) {
        x = x->key > k ? x->l : x->r;
    }
    return x;
}

void print() {
    traverse(root, 1);
    cout << endl;
    traverse(root, 0);
    cout << endl;
}

node *next(node *k) {
    node *x;
    if(k->r != NIL) {
        x = k->r;
        while(x->l != NIL)
            x = x->l;
        return x;
    } else {
        cout << "error";
        return NIL; // error..
    }
}

node *dele(node *t, int key);
node *_dele(node *t, int key) {
    if(t->l == NIL && t->r == NIL)
        return NIL;
    else if(t->l == NIL)
        t = leftRotate(t);
    else if(t->r == NIL)
        t = rightRotate(t);
    else {
        if(t->l->pri > t->r->pri)
            t = rightRotate(t);
        else
            t = leftRotate(t);
    }
    return dele(t, key);
}

node *dele(node *t, int key) {
    if(t == NIL) return NIL;

    if(key < t->key)
        t->l = dele(t->l, key);
    else if(key > t->key)
        t->r = dele(t->r, key);
    else
        return _dele(t, key);
    return t;
}

int main() {
    int n, k, p;
    string o;
    cin >> n;
    node *a;

    rep(i, n) {
        cin >> o;
        if(o == "insert") {
            cin >> k >> p;
            root = insert(root, k, p);
        } else if(o == "find") {
            cin >> k;
            a = find(k);
            cout << (a != NIL ? "yes\n" : "no\n");
        } else if(o == "print") {
            print();
        } else if(o == "delete") {
            cin >> k;
            root = dele(root, k);
        }
    }
}

