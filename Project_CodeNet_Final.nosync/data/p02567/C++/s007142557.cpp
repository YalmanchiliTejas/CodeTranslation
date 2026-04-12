#include <bits/extc++.h>

char readchar() {
  static char buf[1 << 18], *ptr = buf, *end = buf;
  if (ptr == end) ptr = buf, end = buf + fread(buf, 1, 1 << 18, stdin);
  return *ptr++;
}
void writechar(char c) {
  static char buf[1 << 18], *ptr = buf;
  if (ptr == std::end(buf) or c == '\0')
    fwrite(buf, 1, ptr - buf, stdout), ptr = buf;
  *ptr++ = c;
}
__attribute__((destructor)) void destructor() { writechar('\0'); }
template <class T = int>
T getint() {
  char c{};
  while (c < '-') c = readchar();
  bool neg = c == '-';
  T res = neg ? 0 : c - '0';
  while ((c = readchar()) >= '0') res = res * 10 + (c - '0');
  return neg ? -res : res;
}
template <class T>
void putint(T a, char delim = '\n') {
  if (a < 0) writechar('-'), a = -a;
  char buf[sizeof(T) * 3], *ptr = buf;
  do
    *ptr++ = '0' + a % 10;
  while (a /= 10);
  while (ptr-- > buf) writechar(*ptr);
  writechar(delim);
}
#define cin void(0)
#define cout void(0)

struct segment_tree_base {
  virtual int size() const = 0;

 protected:
  template <class F>
  void forward(int l, int r, F f) const {
    int h = h1(l += size() - 1, r += size());
    for (int s = 0; s < h; ++s)
      if (int i = l >> s; ~i & 1) f(i + 1);
    for (int s = h; s--;)
      if (int i = r >> s; i & 1) f(i - 1);
  }
  template <class F>
  void forward(int l, int r, F f) {
    const_cast<const segment_tree_base*>(this)->forward(l, r, f);
  }
  template <class F>
  void backward(int l, int r, F f) const {
    int h = h1(l += size() - 1, r += size());
    for (int s = 0; s < h; ++s)
      if (int i = r >> s; i & 1) f(i - 1);
    for (int s = h; s--;)
      if (int i = l >> s; ~i & 1) f(i + 1);
  }
  template <class F>
  void backward(int l, int r, F f) {
    const_cast<const segment_tree_base*>(this)->backward(l, r, f);
  }
  template <class F>
  void downward(int l, int r, F f) const {
    if (l == r or (l == 0 and r == size())) return;
    int h = h2(l += size(), r += size());
    for (int s = std::__lg(l); s > h; --s) f(l >> s);
    for (int s = h; s > __builtin_ctz(l); --s) f(l >> s);
    for (int s = h; s > __builtin_ctz(r); --s) f(r >> s);
  }
  template <class F>
  void downward(int l, int r, F f) {
    const_cast<const segment_tree_base*>(this)->downward(l, r, f);
  }
  template <class F>
  void upward(int l, int r, F f) const {
    if (l == r or (l == 0 and r == size())) return;
    int h = h2(l += size(), r += size());
    for (int s = __builtin_ctz(r); s++ < h;) f(r >> s);
    for (int s = __builtin_ctz(l); s++ < h;) f(l >> s);
    for (int s = h; s++ < std::__lg(l);) f(l >> s);
  }
  template <class F>
  void upward(int l, int r, F f) {
    const_cast<const segment_tree_base*>(this)->upward(l, r, f);
  }

 private:
  static int h1(int l, int r) {
    for (int h = 0;; ++h)
      if ((r >> h) - (l >> h) == 1) return h;
  }
  static int h2(int l, int r) {
    l <<= std::__lg(l) < std::__lg(r);
    return std::__lg(l ^ r);
  }
};

template <class T>
struct segment_tree : segment_tree_base {
  segment_tree() {}
  template <class Generator>
  segment_tree(int n, Generator gen) : tree(2 * n) {
    for (int i = 0; i < n; ++i) tree[n + i] = gen(i);
    for (int i = n; i-- > 1;) pull(i);
  }

  int size() const override { return std::size(tree) / 2; }
  const T& operator[](int i) const {
    assert(0 <= i), assert(i < size());
    return tree[size() + i];
  }
  T fold(int l, int r) const {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    T res{};
    forward(l, r, [&](int i) { res = res * tree[i]; });
    return res;
  }
  T fold_all_rotated() const { return size() ? tree[1] : T{}; }
  template <class Function>
  void update(int i, Function func) {
    assert(0 <= i), assert(i < size());
    tree[size() + i] = func(tree[size() + i]);
    upward(i, i + 1, [&](int j) { pull(j); });
  }
  template <class Predicate>
  int forward_search(int l, int r, Predicate pred) const {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    T a{};
    assert(pred(a));
    int res = r;
    forward(l, r, [&](int i) {
      if (res < r) return;
      if (T na = a * tree[i]; pred(na)) {
        a = na;
        return;
      }
      while (i < size())
        if (T na = a * tree[2 * i]; pred(na))
          a = na, i = 2 * i + 1;
        else
          i = 2 * i;
      res = i - size();
    });
    return res;
  }
  template <class Predicate>
  int backward_search(int l, int r, Predicate pred) const {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    T a{};
    assert(pred(a));
    int res = l - 1;
    backward(l, r, [&](int i) {
      if (res >= l) return;
      if (T na = a * tree[i]; pred(na)) {
        a = na;
        return;
      }
      while (i < size())
        if (T na = a * tree[2 * i + 1]; pred(na))
          a = na, i = 2 * i;
        else
          i = 2 * i + 1;
      res = i - size();
    });
    return res;
  }

 private:
  std::vector<T> tree;

  void pull(int i) { tree[i] = tree[2 * i] * tree[2 * i + 1]; }
};

struct node {
  int mx = -1;
  friend node operator*(const node& a, const node& b) {
    return a.mx < b.mx ? b : a;
  }
};

int main() {
  using namespace std;
  int n = getint();
  int q = getint();
  vector<int> a(n);
  generate(begin(a), end(a), getint<>);
  reverse(begin(a), end(a));
  segment_tree<node> seg(n, [&](int i) -> node { return {a[i]}; });

  while (q--) {
    if (int t = getint(); t == 1) {
      int i = getint() - 1;
      i = n - i - 1;
      seg.update(i, [](node) -> node { return {getint()}; });
    } else if (t == 2) {
      int l = getint() - 1;
      int r = getint();
      tie(l, r) = pair{n - r, n - l};
      putint(seg.fold(l, r).mx);
    } else if (t == 3) {
      int l = getint() - 1;
      int v = getint();
      int r = n - l;
      int i =
          seg.backward_search(0, r, [&](node x) -> bool { return x.mx < v; });
      i = n - i - 1;
      putint(i + 1);
    } else
      assert(false);
  }
}
