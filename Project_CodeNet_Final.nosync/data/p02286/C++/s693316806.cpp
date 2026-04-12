#include <bits/stdc++.h>

#ifdef _DEBUG
#define ASSERT(x) assert(x)
#define DLOG(x) cout << "L" << __LINE__ << ": " << x << endl;
#else
#define ASSERT(x)
#define DLOG(x)
#endif
#define DLOG_V(x) DLOG(#x << ": " << x)

using namespace std;

struct Node;
using NodePtr = unique_ptr<Node>;

struct Node {
  explicit Node(int value, int prio, NodePtr* parent)
      : value{value}, prio{prio}, parent{parent} {}
  int value;
  int prio;
  NodePtr left;
  NodePtr right;
  NodePtr* parent;

  bool isLeaf() const { return !left && !right; }

  bool isLeft() const { return parent && (*parent)->left.get() == this; }

  void dump(ostream& s) {
    s << "value: " << value << " prio: " << prio;
    if (parent && *parent) {
      s << " p.value: " << (*parent)->value;
    }
  }
};

struct Tree {
  void print(ostream& os) const {
    doInOrder(root, 0,
              [&os](auto&& node, auto&&) { os << " " << node->value; });
    os << endl;
    doPreOrder(root, [&os](auto&& i) { os << " " << i; });
    os << endl;
  }
  void insert(int val, int prio) {
    DLOG("insert " << val << " " << prio);
    auto current = &root;
    decltype(current) parent{nullptr};
    while (*current) {
      parent = current;
      current =
          val < (*current)->value ? &(*current)->left : &(*current)->right;
    }
    *current = make_unique<Node>(val, prio, parent);
    promote(*current);
    debugPrint(cerr);
  }

  bool find(int val) { return static_cast<bool>(*findNode(val)); }

  void delete_(int val) {
    DLOG("delete " << val);
    deleteNode(*findNode(val));
    debugPrint(cerr);
  }

 private:
  void debugPrint(ostream& os) const {
#ifdef _DEBUG
    doInOrder(root, 0, [&os](auto&& node, auto&& depth) {
      for (int i = 0; i < depth; ++i) {
        os << "  ";
      }
      // os << setw(2) << setfill('0') << node->value << " " << node->prio <<
      // endl;
      os << setw(2) << setfill('0');
      node->dump(os);
      os << endl;
    });
    os << endl;
#else
    (void)os;
#endif
  }

  NodePtr* findNode(int val) {
    auto current = &root;
    while (*current && (*current)->value != val) {
      current =
          val < (*current)->value ? &(*current)->left : &(*current)->right;
    }
    return current;
  }

  void deleteNode(NodePtr& node) {
    if (node) {
      auto p = &node;
      while ((*p)->left || (*p)->right) {
        p = &promoteChild(*p);
      }
      p->reset();
    }
  }

  NodePtr& promoteChild(NodePtr& node) {
    if (!node->left || (node->right && node->left->prio < node->right->prio)) {
      return promoteRight(node);
    } else {
      return promoteLeft(node);
    }
  }

  void promote(NodePtr& node) {
    auto c = &node;
    while (true) {
      if (!c || !*c || !(*c)->parent) {
        DLOG_V((bool)c);
        DLOG_V((bool)*c);
        DLOG_V((*c)->parent);
        return;
      }
      auto& p = (*c)->parent;
      if (!*p || (*c)->prio < (*p)->prio) {
        DLOG("(*c)->prio < p->prio");
        return;
      }
      if ((*c)->isLeft()) {
        debugPrint(cout);
        c = promoteLeft(*p)->parent;
        debugPrint(cout);
      } else {
        debugPrint(cout);
        c = promoteRight(*p)->parent;
        debugPrint(cout);
      }
    }
  }

  void fixChildren(NodePtr& node) {
    if (node) {
      if (node->left) node->left->parent = &node;
      if (node->right) node->right->parent = &node;
    }
  }

  void ptrSwap(NodePtr& lhs, NodePtr& rhs) {
    lhs.swap(rhs);
    fixChildren(lhs);
    fixChildren(rhs);
  }

  NodePtr& promoteLeft(NodePtr& node) {
    ASSERT(node);
    DLOG("promoteLeft " << node->value);
    auto& src = node->left;
    ASSERT(src);
    auto& srcRight = src->right;
    auto parent = node->parent;
    swap(node, src);
    swap(src, srcRight);
    node->parent = parent;
    fixChildren(node);
    fixChildren(src);
    fixChildren(srcRight);
    return node->right;
  }

  NodePtr& promoteRight(NodePtr& node) {
    ASSERT(node);
    DLOG("promoteRight " << node->value);
    auto& src = node->right;
    ASSERT(src);
    auto& srcLeft = src->left;
    auto parent = node->parent;
    swap(node, src);
    swap(src, srcLeft);
    node->parent = parent;
    fixChildren(node);
    fixChildren(src);
    fixChildren(srcLeft);
    return node->left;
  }

  void doInOrder(const NodePtr& node, int depth,
                 const function<void(Node*, int)>& f) const {
    if (!node) {
      return;
    }
    doInOrder(node->left, depth + 1, f);
    f(node.get(), depth);
    doInOrder(node->right, depth + 1, f);
  }

  void doPreOrder(const NodePtr& node, const function<void(int)>& f) const {
    if (!node) {
      return;
    }
    f(node->value);
    doPreOrder(node->left, f);
    doPreOrder(node->right, f);
  }

  NodePtr root;
};

int main() {
  int num;
  cin >> num;
  Tree tree;
  ostringstream ss;
  for (int i = 0; i < num; ++i) {
    string cmd;
    cin >> cmd;
    if (cmd == "insert") {
      int val, prio;
      cin >> val >> prio;
      tree.insert(val, prio);
    } else if (cmd == "find") {
      int val;
      cin >> val;
      ss << (tree.find(val) ? "yes" : "no") << endl;
    } else if (cmd == "delete") {
      int val;
      cin >> val;
      tree.delete_(val);
    } else if (cmd == "print") {
      tree.print(ss);
    }
  }
  cout << ss.str();
}

