#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct Node {
  ll value;
  ll priority;
  Node *left = nullptr,
       *right = nullptr,
       *parent = nullptr;

  Node(ll value = 0, ll priority = 0): value(value), priority(priority) {}
};

class BST {
  Node *root = nullptr;

  string tos_pre(Node *nd) {
    string s = "";

    s += " " + to_string(nd->value);
    if (nd->left) s += tos_pre(nd->left);
    if (nd->right) s += tos_pre(nd->right);

    return s;
  }

  string tos_in(Node *nd) {
    string s = "";

    if (nd->left) s += tos_in(nd->left);
    s += " " + to_string(nd->value);
    if (nd->right) s += tos_in(nd->right);

    return s;
  }
  
  Node *find_partial(ll value, Node *nd) {
    if (!nd) return nullptr;
    if (nd->value == value) return nd;
    
    return nd->value > value
      ? find_partial(value, nd->left)
      : find_partial(value, nd->right);
  }
  
  Node *get_min(Node *x) {
    while (x->left) x = x->left;
    return x;
  }

  Node *get_successor(Node *x) {
    if (x->right) return get_min(x->right);

    auto y = x->parent;
    while (y && x == y->right) {
      x = y;
      y = y->parent;
    }

    return y;
  }

  Node *rotate_right(Node *t) {
    auto s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
  }

  Node *rotate_left(Node *t) {
    auto s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
  }
  
  Node *del_inner(Node *t, ll value) {
    if (!t->left && !t->right) return nullptr;
    else if (!t->left) t = rotate_left(t);
    else if (!t->right) t = rotate_right(t);
    else {
      if (t->left->priority > t->right->priority) t = rotate_right(t);
      else t = rotate_left(t);
    }

    return del(t, value);
  }

public:
  void insert(ll value, ll priority) {
    auto t = insert(root, value, priority);
    if (!root || root->priority < priority) root = t; 
  }

  Node *insert(Node *t, ll value, ll priority) {
    if (!t) return new Node(value, priority);
    if (t->value == value) return t;
    
    if (t->value > value) {
      t->left = insert(t->left, value, priority);
      if (t->priority < t->left->priority) t = rotate_right(t);
    } else {
      t->right = insert(t->right, value, priority);
      if (t->priority < t->right->priority) t = rotate_left(t);
    }
      
    return t;
  }

  Node *find(ll value) {
    return find_partial(value, root); 
  }
  
  void del(ll value) {
    root = del(root, value);
  }

  Node *del(Node *t, ll value) {
    if (!t) return nullptr; 
    if (t->value > value) t->left = del(t->left, value);
    else if (t->value < value) t->right = del(t->right, value);
    else return del_inner(t, value);
    return t;
  }
  
  string print_pre() {
    return tos_pre(root);
  }

  string print_in() {
    return tos_in(root);
  }
};

int main() {
  int n;
  cin >> n;
  
  auto bst = BST();
  rep(i, n) {
    string cmd;
    cin >> cmd;
    
    if (cmd == "print") {
      cout << bst.print_in() << endl;
      cout << bst.print_pre() << endl;
    } else {
      ll value;
      cin >> value;
      
      if (cmd == "find" || cmd == "delete") {
        if (cmd == "find")
          cout << (bst.find(value) ? "yes" : "no") << endl;
        else bst.del(value);
      } else {
        ll priority;
        cin >> priority;

        bst.insert(value, priority);
      }
    }
  }
}

