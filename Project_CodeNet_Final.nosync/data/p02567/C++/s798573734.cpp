#include <bits/stdc++.h>
using namespace std;

template <typename T> class SegmentTree {
private:
  int n;
  function<T(T, T)> f;
  T t;
  vector<T> node;

public:
  SegmentTree() {}
  SegmentTree(function<T(T, T)> f, T t) : f(f), t(t) {}
  void init(int in) {
    n = 1;
    while (n < in) n <<= 1;
    node.assign(n << 1, t);
  }
  void build(const vector<T> &v) {
    int in = v.size();
    init(in);
    for (int i = 0; i < in; i++) node.at(n + i) = v.at(i);
    for (int i = n - 1; i; i--) {
      node.at(i) = f(node.at((i << 1) | 0), node.at((i << 1) | 1));
    }
  }
  void set(int k, T x) {
    node.at(k += n) = x;
    while (k >>= 1) {
      node.at(k) = f(node.at((k << 1) | 0), node.at((k << 1) | 1));
    }
  }
  T query(int a, int b) {
    if (a >= b) return t;
    T vl = t, vr = t;
    for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = f(vl, node.at(l++));
      if (r & 1) vr = f(node.at(--r), vr);
    }
    return f(vl, vr);
  }
  template <typename C> int find(int st, C &check, T &acc, int k, int l, int r) {
    if (l + 1 == r) {
      acc = f(acc, node.at(k));
      return check(acc) ? k - n : -1;
    }
    int m = (l + r) >> 1;
    if (m <= st) return find(st, check, acc, (k << 1) | 1, m, r);
    if (st <= l && !check(f(acc, node.at(k)))) {
      acc = f(acc, node.at(k));
      return -1;
    }
    int vl = find(st, check, acc, (k << 1) | 0, l, m);
    if (~vl) return vl;
    return find(st, check, acc, (k << 1) | 1, m, r);
  }
  template <typename C> int find(int st, C &check) {
    T acc = t;
    return find(st, check, acc, 1, 0, n);
  }
};

signed main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  long N, Q;
  cin >> N >> Q;
  using pii = pair<long, long>;
  vector<pii> A(N);
  for (long i = 0, a; i < N && cin >> a; i++) A.at(i) = {a, i};

  auto f = [&](pii x, pii y) { return max(x, y); };
  pii ng(-1, -1);
  SegmentTree<pii> ST(f, ng);
  ST.build(A);

  while (Q--) {
    long a, b, c;
    cin >> a >> b >> c, b--;
    if (a == 1) {
      ST.set(b, {c, b});
    } else if (a == 2) {
      cout << ST.query(b, c).first << "\n";
    } else {
      auto f2 = [&](pii p) { return c <= p.first; };
      long ans = ST.find(b, f2);
      if (ans == -1) ans = N; 
      cout << ans + 1 << "\n"; 
    }
  }
}