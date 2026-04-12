#include <cassert>
#include <cstdio>

class Treap{
public:
  struct Node{
    int key;
    int priority;
    int size;
    Node *parent, *left, *right;

    void refresh(){
      size = 1;
      if(left != nullptr) size += left->size;
      if(right != nullptr) size += right->size;
    }
    
    Node():key(-1), priority(-1), parent(nullptr), left(nullptr), right(nullptr){refresh();};
    Node(int key,int priority,Node *parent):
      key(key), priority(priority), parent(parent), left(nullptr), right(nullptr){refresh();};

    Node(int key,int priority, Node *parent,Node *left,Node *right):
      key(key), priority(priority), parent(parent), left(left), right(right){refresh();};
  };
  
  int n;
  Node *root;
  Treap():n(0){}
  int size(){return n;}
  int size(Node *t){return t == nullptr? 0:t->size;}
  int empty(){return n == 0;}
  
  Node* rightRotate(Node *y){
    Node *x = y->left;
    y->left = x->right;
    x->right = y;

    x->parent = y->parent;
    y->parent = x;

    y->refresh(), x->refresh();
    return x;
  }

  Node* leftRotate(Node *x){
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    
    y->parent = x->parent;
    x->parent = y;

    x->refresh(), y->refresh();
    return y;
  }

  Node* insert(Node *t,int key,int priority, Node *parent = nullptr){
    if(t == nullptr){n++; return new Node(key, priority, parent);}
    
    if(key == t->key) return t;
    
    if(key < t->key){
      t->left = insert(t->left, key, priority,  t);
      if( t->priority < t->left->priority ) t = rightRotate(t);
    }
    else{
      t->right = insert(t->right, key, priority, t);
      if( t->priority < t->right->priority ) t = leftRotate(t);
    }
    return t;
  }

  Node* insert(int key,int priority){
    if(n == 0){n++; return root = new Node(key, priority, nullptr);}
    return root = insert(root, key, priority);
  }

  Node* erase(Node *t,int key){
    if( t == nullptr) return nullptr;
    if(key == t->key) return _erase(t, key);
    
    if(key < t->key ) t->left = erase(t->left, key);
    else if(key > t->key ) t->right = erase(t->right, key);
    return t;
  }
  
  Node* _erase(Node *t,int key){
    if(t->left == nullptr && t->right == nullptr) {
      n--;
      delete t;
      return nullptr;
    }
    
    if(t->left == nullptr) t = leftRotate(t);
    else if(t->right == nullptr) t = rightRotate(t);
    else {
      if( t->left->priority > t->right->priority ) t = rightRotate(t);
      else t = leftRotate(t);
    }
    
    return erase(t, key);
  }

  void erase(int key){root = erase(root, key);}

  Node* find(Node *t,int key){
    if( t == nullptr) return nullptr;
    if(key < t->key ) return find(t->left, key);
    if(key > t->key ) return find(t->right, key);
    return t;
  }

  Node* find(int key){return find(root, key);}

  Node* getKthNode(Node *t, int K){
    if(K == 0) return t;
    if(size(t->left) <= K) return getKthNode(t->left, K);
    return getKthNode(t->right, K - size(t->left)+1);
  }

  Node* getKthNode(int K){
    assert(K < n);
    return getKthNode(root, K);
  }
  
  void print(Node* t,int a=0,int b=0,int c=0){
    if(t == nullptr) return;
    if(a) printf(" %d", t->key);
    if(t->left != nullptr) print(t->left, a, b, c);
    if(b) printf(" %d", t->key);
    if(t->right != nullptr) print(t->right, a, b, c);
    if(c) printf(" %d", t->key);
  }
  
  void print(){
    print(root, 0, 1, 0);printf("\n");
    print(root, 1, 0, 0);printf("\n");
  }
    
};

signed main(){
  Treap T;
  
  int n;
  scanf("%d", &n);
  while(n--){
    char str[100];
    scanf("%s", str);
    
    if(str[0] == 'i'){
      int key, priority;
      scanf("%d%d", &key, &priority);
      T.insert(key, priority);
    }
    
    if(str[0] == 'f'){
      int key;
      scanf("%d", &key);
      int ans = T.find(key) != nullptr;
      printf("%s\n", (ans?"yes":"no"));
    }
    
    if(str[0] == 'd'){
      int key;
      scanf("%d", &key);
      T.erase(key);
    }
    if(str[0] == 'p'){
      T.print();
    }
  }
  
  return 0;
}


