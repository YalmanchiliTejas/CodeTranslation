#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <limits>
#include <functional>

namespace structure {
  template<typename T, size_t dcap = 16ULL>
  class vec {
    size_t sz;
    size_t cap;
    T* a;
    void extend() {
      size_t ncap = cap << 1;
      T* b = new T[ncap];
      for (int i = 0; i < cap; i++) b[i] = a[i];
      delete[] a;
      a = b;
      cap = ncap;
    }
  public:
    vec() : sz(0), cap(dcap) {
      a = new T[cap];
    }
    vec(size_t n) : sz(n), cap(dcap) {
      while (cap < sz) cap <<= 1;
      a = new T[cap];
    }
    vec(size_t n, T v) : sz(n), cap(dcap) {
      while (cap < sz) cap <<= 1;
      a = new T[cap];
      for (size_t i = 0; i < sz; i++) {
        a[i] = v;
      }
    }
    vec(const vec<T>& v) {
      sz = v.sz;
      cap = v.cap;
      a = new T[cap];
      std::memcpy(a, v.a, sizeof(T) * sz);
    }
    vec<T>& operator=(const vec<T>& v) {
      sz = v.sz;
      cap = v.cap;
      delete[] a;
      a = new T[cap];
      std::memcpy(a, v.a, sizeof(T) * sz);
      return *this;
    }
    T& operator[](size_t i) {
      return a[i];
    }
    T front() const {
      return a[0];
    }
    T back() const {
      return a[sz - 1];
    }
    void push_back(const T& x) {
      if (sz == cap) extend();
      a[sz++] = x;
    }
    void pop_back() {
      sz--;
    }
    size_t size() const {
      return sz;
    }
    bool empty() const {
      return !sz;
    }
    void output(std::ostream& out, char delim = ' ') const {
      for (size_t i = 0; i < sz; i++) {
        if (i) out << delim;
        out << a[i];
      }
    }
    friend std::ostream& operator<<(std::ostream& out, const vec& v) {
      v.output(out);
      return out;
    }
    void input(std::istream& in) {
      for (size_t i = 0; i < sz; i++) {
        in >> a[i];
      }
    }
    friend std::istream& operator>>(std::istream& in, vec& v) {
      v.input(in);
      return in;
    }
    ~vec() {
      delete[] a;
    }
  };
  template<typename T, size_t dcap = 16ULL>
  class que {
    size_t begin, end;
    size_t sz;
    size_t cap;
    T* a;
    void extend() {
      size_t ncap = cap << 1;
      T* b = new T[ncap];
      for (int i = begin; i < begin + cap; i++) b[i] = a[i & (cap - 1)];
      end += cap;
      delete[] a;
      a = b;
      cap = ncap;
    }
  public:
    que() : begin(0), end(0), sz(0), cap(dcap) {
      a = new T[cap];
    }
    T front() const {
      return a[begin];
    }
    void push(const T& x) {
      if (sz == cap) extend();
      a[end++] = x;
      sz++;
      end &= cap - 1;
    }
    void pop() {
      begin = (begin + 1) & (cap - 1);
      sz--;
    }

    size_t size() const {
      return sz;
    }
    bool empty() const {
      return !sz;
    }
    void output(std::ostream& out, char delim = ' ') const {
      if (sz == cap) {
        for (size_t i = begin; i != (cap + end - 1) & (cap - 1); i = (i + 1) & (cap - 1)) {
          if (i != begin) out << delim;
          out << a[i];
        }
        out << delim << a[(cap + end - 1) & (cap - 1)];
      }
      else {
        for (size_t i = begin; i != end; i = (i + 1) & (cap - 1)) {
          if (i != begin) out << delim;
          out << a[i];
        }
      }
    }
    friend std::ostream& operator<<(std::ostream& out, const que& v) {
      v.output(out);
      return out;
    }
    ~que() {
      delete[] a;
    }
  };
  template<typename S, typename T>
  struct pair {
    S first;
    T second;
    pair() {}
    pair(S first, T second) : first(first), second(second) {}
    void output(std::ostream& out, char delim = ' ') const {
      out << first << delim << second;
    }
    friend std::ostream& operator<<(std::ostream& out, const pair& p) {
      p.output(out);
      return out;
    }
    void input(std::istream& in) {
      in >> first >> second;
    }
    friend std::istream& operator>>(std::istream& in, pair& p) {
      p.input(in);
      return in;
    }
  };
  template<typename T>
  class list {
    struct node {
      T val;
      node* prev;
      node* next;
      node() : prev(nullptr), next(nullptr) {}
      node(node* prev, node* next) : prev(prev), next(next) {}
      node(const T& val, node* prev, node* next) : val(val), prev(prev), next(next) {}
    };
    node* head;
    size_t sz;
  public:
    list() {
      head = new node;
      head->next = head->prev = head;
    }
    void push_front(const T& val) {
      node* n = new node(val, head, head->next);
      n->prev->next = n;
      n->next->prev = n;
      sz++;
    }
    void erase(node* n) {
      n->prev->next = n->next;
      n->next->prev = n->prev;
      delete n;
      sz--;
    }
    void pop_front() {
      erase(head->next);
    }
    void pop_back() {
      erase(head->prev);
    }
    bool erase(const T& val) {
      for (node* n = head->next; n != head; n = n->next) {
        if (n->val == val) {
          erase(n);
          return true;
        }
      }
      return false;
    }
    size_t size() const {
      return sz;
    }
    void output(std::ostream& out, char delim = ' ') const {
      for (node* n = head->next; n != head; n = n->next) {
        if (n != head->next) out << delim;
        out << n->val;
      }
    }
    friend std::ostream& operator<<(std::ostream& out, const list& l) {
      l.output(out);
      return out;
    }
  };
  // T have +-*/ and 0
  template<class T> class BIT {
  public:
    vec<T> dat;
    int N;
    BIT() {}
    BIT(int N) : N(N), dat(N, 0) {}
    // sum [0,c)
    T sum(int i) {
      T ret = 0;
      for (--i; i >= 0; i = (i & (i + 1)) - 1) ret += dat[i];
      return ret;
    }
    // sum [c,j1)
    T sum(int i1, int i2) { return sum(i2) - sum(i1); }
    T at(int i) { return sum(i, i + 1); }
    // add x to c
    void add(int i, T x) { for (; i < N; i |= i + 1) dat[i] += x; }
  };
}

namespace algorithm {
  template<typename T>
  void insertion_sort(structure::vec<T>& v, bool verbose = false) {
    for (int i = 0, n = v.size(); i < n; i++) {
      int x = v[i], j;
      for (j = i - 1; j >= 0 && v[j] > x; j--) {
        v[j + 1] = v[j];
      }
      v[j + 1] = x;
      if (verbose) std::cout << v << std::endl;
    }
  }
  template<typename T>
  size_t bubble_sort(structure::vec<T>& v) {
    size_t cnt = 0;
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
      for (int j = n - 1; j > i; j--) {
        if (v[j] < v[j - 1]) {
          T t = v[j - 1];
          v[j - 1] = v[j];
          v[j] = t;
          cnt++;
        }
      }
    }
    return cnt;
  }
  template<typename T>
  size_t selection_sort(structure::vec<T>& v) {
    size_t cnt = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
      int minj = i;
      for (int j = i; j < n; j++) {
        if (v[j] < v[minj]) minj = j;
      }
      T t = v[i];
      v[i] = v[minj];
      v[minj] = t;
      cnt += (v[i] != v[minj]);
    }
    return cnt;
  }
  template<typename T>
  size_t upper_bound(structure::vec<T>& v, const T& x) {
    // x より大きい最初の要素の添字を返す
    if (x < v[0]) return 0;
    if (v.back() <= x) return v.size();
    int ng = 0, ok = v.size() - 1;
    while (abs(ok - ng) > 1) {
      int mid = (ng + ok) / 2;
      (v[mid] > x ? ok : ng) = mid;
    }
    return ok;
  }
  template<typename T>
  size_t count(structure::vec<T>& v, const T& x) {
    return upper_bound(v, x) - upper_bound(v, x - 1);
  }
  namespace impl {}
  namespace {
    namespace impl {
      template<typename T>
      void merge(structure::vec<T>& v, int l, int m, int r) {
        T inf = std::numeric_limits<T>::max();
        int i = l, j = 0, k = 0, n1 = m - l, n2 = r - m;
        int* L = new int[n1 + 1];
        int* R = new int[n2 + 1];
        std::memcpy(L, &v[l], sizeof(T) * n1);
        std::memcpy(R, &v[m], sizeof(T) * n2);
        L[n1] = R[n2] = inf;
        while (i < r) {
          L[j] <= R[k] ? v[i] = L[j++] : v[i] = R[k++];
          i++;
        }
        delete[] L;
        delete[] R;
      }
      template<typename T>
      void align(structure::vec<T>& v, int l, int r) {
        if (l + 1 < r) {
          int m = (l + r) / 2;
          align(v, l, m);
          align(v, m, r);
          merge(v, l, m, r);
        }
      }
    }
    template<typename T>
    void merge_sort(structure::vec<T>& v) {
      impl::align(v, 0, v.size());
    }
  }
  template<typename T>
  struct MergeSorter {
    using F = std::function<bool(T, T)>;
    const F cmp;
    const T inf;
    structure::vec<T> v;
    MergeSorter(const structure::vec<T>& v, const T& inf, const F cmp) : v(v), inf(inf), cmp(cmp) {}
    void merge(int l, int m, int r) {
      int i = l, j = 0, k = 0, n1 = m - l, n2 = r - m;
      T* L = new T[n1 + 1];
      T* R = new T[n2 + 1];
      std::memcpy(L, &v[l], sizeof(T) * n1);
      std::memcpy(R, &v[m], sizeof(T) * n2);
      L[n1] = R[n2] = inf;
      while (i < r) {
        cmp(L[j], R[k]) ? v[i] = L[j++] : v[i] = R[k++];
        i++;
      }
      delete[] L;
      delete[] R;
    }
    void align(int l, int r) {
      if (l + 1 < r) {
        int m = (l + r) / 2;
        align(l, m);
        align(m, r);
        merge(l, m, r);
      }
    }
    void sort() {
      align(0, v.size());
    }
  };
  template<typename T>
  struct QuickSorter {
    using F = std::function<bool(T, T)>;
    const F cmp;
    structure::vec<T> v;
    QuickSorter(const structure::vec<T>& v, const F cmp) : v(v), cmp(cmp) {}
    int partition(int p, int r) {
      T x = v[r], tmp;
      int i = p - 1;
      for (int j = p; j < r; j++) {
        if (cmp(v[j], x)) {
          i++; tmp = v[i]; v[i] = v[j]; v[j] = tmp;
        }
      }
      i++; tmp = v[i]; v[i] = v[r]; v[r] = tmp;
      return i;
    }
    void align(int p, int r) {
      if (p < r) {
        int q = partition(p, r);
        align(p, q - 1);
        align(q + 1, r);
      }
    }
    void sort() {
      align(0, v.size() - 1);
    }
  };
}

namespace graph {

  template<typename T>
  class BinarySearchTree {
    uint64_t _r = 88172645463325252LL;
    unsigned rnd() {
      _r = _r ^ (_r << 7);
      return _r = _r ^ (_r >> 9);
    }
    struct Node {
      T key;
      unsigned priority;
      Node* parent;
      Node* left;
      Node* right;
      Node() {}
      Node(const T& key) : key(key), priority(rnd()), parent(nullptr), left(nullptr), right(nullptr) {}
      Node(const T& key, unsigned priority) : key(key), priority(priority), parent(nullptr), left(nullptr), right(nullptr) {}
    };
    Node* minimum(Node* x) {
      while (x->left) x = x->left;
      return x;
    }
    Node* successor(Node* x) {
      if (x->right) return minimum(x->right);
      Node* y = x->parent;
      while (y && x == y->right) {
        x = y;
        y = y->parent;
      }
      return y;
    }
    Node* right_rotate(Node* t) {
      Node* s = t->left;
      t->left = s->right;
      s->right = t;
      return s;
    }
    Node* left_rotate(Node* t) {
      Node* s = t->right;
      t->right = s->left;
      s->left = t;
      return s;
    }
    Node* insert(Node* t, const T& key, unsigned priority) {
      if (!t) return new Node(key, priority);
      if (key == t->key) return t;
      if (key < t->key) {
        t->left = insert(t->left, key, priority);
        if (t->priority < t->left->priority) t = right_rotate(t);
      }
      else {
        t->right = insert(t->right, key, priority);
        if (t->priority < t->right->priority) t = left_rotate(t);
      }
      return t;
    }
    Node* erase(Node* t, const T& key) {
      if (!t) return t;
      if (key < t->key) t->left = erase(t->left, key);
      else if (key > t->key) t->right = erase(t->right, key);
      else return _erase(t, key);
      return t;
    }
    Node* _erase(Node* t, const T& key) {
      if (!t->left && !t->right) {
        delete t;
        return nullptr;
      }
      else if (!t->left) t = left_rotate(t);
      else if (!t->right) t = right_rotate(t);
      else t = t->left->priority > t->right->priority ? right_rotate(t) : left_rotate(t);
      return erase(t, key);
    }
    Node* root;
  public:
    BinarySearchTree() : root(nullptr) {}
    void insert(const T& key) {
      insert(root, key, rnd());
    }
    void insert(const T& key, unsigned priority) {
      root = insert(root, key, priority);
    }
    Node* find(const T& key) const {
      Node* x = root;
      while (x && key != x->key) x = key < x->key ? x->left : x->right;
      return x;
    }
    void erase(const T& key) {
      root = erase(root, key);
    }
    void free(Node* x) {
      if (!x) return;
      if (x->left) free(x->left);
      if (x->right) free(x->right);
      delete x;
    }
    void print_preorder(const Node* n) const {
      if (!n) return;
      std::cout << ' ' << n->key;
      print_preorder(n->left);
      print_preorder(n->right);
    }
    void print_preorder() const {
      print_preorder(root);
    }
    void print_inorder(const Node* n) const {
      if (!n) return;
      print_inorder(n->left);
      std::cout << ' ' << n->key;
      print_inorder(n->right);
    }
    void print_inorder() const {
      print_inorder(root);
    }
    void print_postorder(const Node* n) const {
      if (!n) return;
      print_postorder(n->left);
      print_postorder(n->right);
      std::cout << ' ' << n->key;
    }
    void print_postorder() const {
      print_postorder(root);
    }
    ~BinarySearchTree() {
      free(root);
    }
  };
}

int main() {
  using namespace structure;
  using namespace algorithm;
  using namespace graph;
  using std::cin;
  using std::cout;
  using std::cerr;
  using std::endl;
  using std::string;

  std::ios::sync_with_stdio(false);
  cin.tie(0);

  BinarySearchTree<int> bst;

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    string op;
    int k, p;
    cin >> op;
    switch (op[0]) {
    case 'i':
      cin >> k >> p;
      bst.insert(k, p);
      break;
    case 'f':
      cin >> k;
      cout << (bst.find(k) ? "yes" : "no") << endl;
      break;
    case 'p':
      bst.print_inorder();
      cout << endl;
      bst.print_preorder();
      cout << endl;
      break;
    case 'd':
      cin >> k;
      bst.erase(k);
      break;
    default:
      exit(1);
    }
  }

  return 0;
}
