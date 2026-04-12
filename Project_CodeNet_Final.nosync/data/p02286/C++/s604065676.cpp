#include <iostream>
using namespace std;

struct Node {
  int key;
  int pri;
  Node *r, *l;
};

Node *rrotate(Node *t) {
  Node *s = t->l;
  t->l = s->r;
  s->r = t;
  return s;
}
Node *lrotate(Node *t) {
  Node *s = t->r;
  t->r = s->l;
  s->l = t;
  return s;
}

Node *insert(Node *t, int k, int p) {
  if (t == NULL) {
    Node *n = new Node();
    n->key = k;
    n->pri = p;
    n->l = n->r = NULL;
    return n;
  }
  if (t->key == k) return t;

  if (k < t->key) {
    t->l = insert(t->l, k, p);
    if (t->pri < t->l->pri) t = rrotate(t);
  } else {
    t->r = insert(t->r, k, p);
    if (t->pri < t->r->pri) t = lrotate(t);
  }
  return t;
}
Node *find(Node *t, int k) {
  if (t == NULL) return NULL;
  if (t->key == k) return t;
  if (k < t->key)
    return find(t->l, k);
  else
    return find(t->r, k);
}
Node *dele(Node *t, int k) {
  if (t == NULL) return NULL;
  if (k == t->key) {
    if (t->l == NULL && t->r == NULL) {
      return NULL;
    } else if (t->l == NULL) {
      t = lrotate(t);
    } else if (t->r == NULL) {
      t = rrotate(t);

    } else {
      if (t->l->pri > t->r->pri)
        t = rrotate(t);
      else
        t = lrotate(t);
    }
    return dele(t, k);
  }
  if (k < t->key)
    t->l = dele(t->l, k);
  else
    t->r = dele(t->r, k);
  return t;
}
void printinorder(Node *t) {
  if (t == NULL) return;
  printinorder(t->l);
  cout << " " << t->key;
  printinorder(t->r);
}
void printpreorder(Node *t) {
  if (t == NULL) return;
  cout << " " << t->key;
  printpreorder(t->l);
  printpreorder(t->r);
}
int main() {
  int m, k, p;
  string cmd;
  Node *root=NULL;

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> cmd;
    if (cmd[0] == 'i') {
      cin >> k >> p;
      root = insert(root, k, p);
    } else if (cmd[0] == 'f') {
      cin >> k;
      if (find(root, k) != NULL)
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    } else if (cmd[0] == 'd') {
      cin >> k;
      root = dele(root, k);
    } else {
      printinorder(root);
      cout << endl;
      printpreorder(root);
      cout << endl;
    }
  }

  return 0;
}
