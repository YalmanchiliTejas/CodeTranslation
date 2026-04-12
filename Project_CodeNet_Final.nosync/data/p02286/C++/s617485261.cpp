#include <iostream>
#include <cassert>
using std::cout;
using std::cin;
using std::endl;
using ll = long long;

template <typename T, typename S> struct Node {
  T key;
  S pri;
  Node *p;
  Node *left;
  Node *right;
  Node(): p(nullptr), left(nullptr), right(nullptr) {}
  Node(T key) : key(key), p(nullptr), left(nullptr), right(nullptr) {}
  Node(T key, S pri): key(key), pri(pri), p(nullptr), left(nullptr), right(nullptr) {}
  Node(T key, S pri, Node* p): key(key), pri(pri), p(p), left(nullptr), right(nullptr) {}
};

template <typename T, typename S> struct Treap {
  Node<T, S> *root;
  Treap() : root(nullptr) {}

  void inorder(){
    inorder(root);
  }
  void inorder(Node<T, S> *n) {
    if (n == nullptr) {
      return;
    }
    inorder(n->left);
    cout << " " << n->key;
    inorder(n->right);
    return;
  }

  void preorder(){
    preorder(root);
  }
  void preorder(Node<T, S> *n) {
    if (n == nullptr) {
      return;
    }
    cout << " " << n->key;
    preorder(n->left);
    preorder(n->right);
    return;
  }

  Node<T, S>*  insert(T key, T pri){
    return root = insert(root, nullptr, key, pri);
  }
  Node<T, S> *insert(Node<T, S> *t, Node<T, S> *par, T key, S pri){
    if(t == nullptr){
      return new Node<T, S>(key, pri, par);
    }
    if(key == t->key){
      return t;
    }

    if(key < t->key){
      t->left = insert(t->left, t, key, pri);
      if(t->pri < t->left->pri){
        t = rightRotate(t);
      }
    }else{
      t->right = insert(t->right, t, key, pri);
      if(t->pri < t->right->pri){
        t = leftRotate(t);
      }
    }
    return t;
  }

  Node<T, S>* erase(T key){
    return root = erase(root, key);
  }
  Node<T, S> *erase(Node<T, S> *t, T key){
    if(t == nullptr){
      return nullptr;
    }

    if(key == t->key){
      if(t->left == nullptr && t->right == nullptr){
        return nullptr;
      }
      else if(t->left == nullptr){
        t = leftRotate(t);
      }else if(t->right == nullptr){
        t = rightRotate(t);
      }else{
        if(t->left->pri > t->right->pri){
          t = rightRotate(t);
        }else{
          t = leftRotate(t);
        }
      }
    }
    if(key < t->key){
      t->left = erase(t->left, key);
    }else{
      t->right = erase(t->right, key);
    }
    return t;
  }

  Node<T, S>* find(T key){
    return find(root, key);
  }
  Node<T, S>* find(Node<T, S> *t, T key){
    if(t == nullptr){
      return nullptr;
    }
    if(t->key == key){
      return t;
    }
    if(key < t->key){
      return find(t->left, key);
    }else{
      return find(t->right, key);
    }
  }

  Node<T, S> *rightRotate(Node<T, S> *t) {
    Node<T, S> *s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
  }

  Node<T, S> *leftRotate(Node<T, S> *t) {
    Node<T, S> *s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  Treap<ll, ll> treap;
  for(int loop = 0; loop < N; loop++){
    char op[16];
    cin >> op;
    if(op[0] == 'i'){
      int key, pri;
      cin >> key >> pri;
      treap.insert(key, pri);
    }else if(op[0] == 'p'){
      treap.inorder();
      cout << '\n';
      treap.preorder();
      cout << '\n';
    }else if(op[0] == 'f'){
      int key; cin >> key;
      if(treap.find(key) == nullptr){
        cout << "no" << '\n';
      }else{
        cout << "yes" << '\n';
      }
    }else if(op[0] == 'd'){
      int key; cin >> key;
      treap.erase(key);
    }else{
      cout << "Invalid Operation" << endl;
      assert(false);
    }
  }
}

