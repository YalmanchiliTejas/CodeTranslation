#include <iostream>
using namespace std;

class Treap {
public:
  Treap *left = nullptr;
  Treap *right = nullptr;
  int key;
  int pri;
  Treap(int k, int p) : key(k), pri(p) {}
  Treap *Insert(int k, int p) {
    if (k < key) {
      if (!left) {
        left = new Treap(k, p);
      } else {
        left = left->Insert(k, p);
      }
      if (left->pri > pri) {
        //        cout << "Debug: At " << key << ", left node " << left->key
        //             << " has lower priority " << left->pri << " (vs. " << pri
        //             << "); rotating right\n";
        return RotateRight();
      }
    } else if (k > key) {
      if (!right) {
        right = new Treap(k, p);
      } else {
        right = right->Insert(k, p);
      }
      if (right->pri > pri) {
        //        cout << "Debug: At " << key << ", right node " << right->key
        //             << " has lower priority " << right->pri << " (vs. " <<
        //             pri
        //             << "); rotating left\n";
        return RotateLeft();
      }
    }
    return this;
  }
  // pre: right != null
  Treap *RotateLeft() {
    Treap *s = right;
    right = s->left;
    s->left = this;
    return s;
  }
  // pre: left != null
  Treap *RotateRight() {
    Treap *s = left;
    left = s->right;
    s->right = this;
    return s;
  }
  bool Find(int k) {
    if (k == key) {
      return true;
    } else if (k > key) {
      return (right and right->Find(k));
    } else if (k < key) {
      return (left and left->Find(k));
    }
  }
  // pre: k is in the treap
  Treap *Remove(int k) {
    if (k == key) {
      if (not left and not right) {
        delete this;
        return nullptr;
      } else if (left and not right) {
        return RotateRight()->Remove(k);
      } else if (right and not left) {
        return RotateLeft()->Remove(k);
      } else {
        if (right->pri > left->pri) {
          return RotateLeft()->Remove(k);
        } else {
          return RotateRight()->Remove(k);
        }
      }
    } else {
      if (k > key and right) {
        right = right->Remove(k);
      } else if (k < key and left) {
        left = left->Remove(k);
      }
      return this;
    }
  }
};

void PrintInorder(Treap *t) {
  if (!t)
    return;
  PrintInorder(t->left);
  cout << ' ' << t->key;
  PrintInorder(t->right);
}

void PrintPreorder(Treap *t) {
  if (!t)
    return;
  cout << ' ' << t->key;
  PrintPreorder(t->left);
  PrintPreorder(t->right);
}

int main() {
  int n;
  cin >> n;
  string cmd;
  Treap *root = nullptr;
  int k, p;
  while (cin >> cmd) {
    if (cmd == "insert") {
      cin >> k >> p;
      if (!root) {
        root = new Treap(k, p);
      } else {
        root = root->Insert(k, p);
      }
    } else if (cmd == "find") {
      cin >> k;
      if (root and root->Find(k)) {
        cout << "yes\n";
      } else {
        cout << "no\n";
      }
    } else if (cmd == "print") {
      PrintInorder(root);
      cout << endl;
      PrintPreorder(root);
      cout << endl;
    } else if (cmd == "delete") {
      cin >> k;
      // root will always be non-null when deleting
      root = root->Remove(k);
    }
  }
}
