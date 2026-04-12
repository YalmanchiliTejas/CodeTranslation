#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

template <class S> struct M {
  using T = array<S, 3>; // min, max, sum
  using U = array<S, 2>; // linear function
  static T op(const T& a, const T& b) { return T{min(a[0], b[0]), max(a[1], b[1]), a[2] + b[2]}; }
  static constexpr T e() { return T{numeric_limits<S>::max(), numeric_limits<S>::min(), 0}; }
  static void ap(T& a, const U& g, int k) { for (int i = 0; i < 3; i++) a[i] = g[0] * a[i] + (i == 2 ? k : 1) * g[1]; if (g[0] < 0) swap(a[0], a[1]); }
  static void ap(U& f, const U& g) { f[0] *= g[0]; f[1] = g[0] * f[1] + g[1]; }
  static constexpr U id() { return U{1, 0}; }
};

template<class M> struct ST {
  using T = typename M::T;
  using U = typename M::U;
  int n;
  V<T> t;
  V<U> u;
  V<> k;

  ST(int n) : n(n) {
    t.assign(2 * n, M::e());
    u.assign(n, M::id());
    k.assign(2 * n, 1);
    for (int i = n - 1; i; i--) k[i] = k[2 * i] + k[2 * i + 1];
  }

  void _ap(int i, const U& f) {
    M::ap(t[i], f, k[i]);
    if (i < n) M::ap(u[i], f);
  }

  void build() {
    for (int i = n - 1; i; i--) t[i] = M::op(t[2 * i], t[2 * i + 1]);
  }

  T get(int l, int r) {
    _push(l, r);
    T resl = M::e(), resr = M::e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = M::op(resl, t[l++]);
      if (r & 1) resr = M::op(t[--r], resr);
    }
    return M::op(resl, resr);
  }

  void push() {
    for (int i = 1; i < n; i++) {
      _ap(2 * i, u[i]);
      _ap(2 * i + 1, u[i]);
      u[i] = M::id();
    }
  }

  void _push(int l, int r) {
    for (int hl = __lg(l + n), hr = __lg(r - 1 + n); hr > 0; hl--, hr--) {
      int i = r - 1 + n >> hr;
      _ap(2 * i, u[i]);
      _ap(2 * i + 1, u[i]);
      u[i] = M::id();
      i = l + n >> hl;
      if (i == r - 1 + n >> hr or i >= n) continue;
      _ap(2 * i, u[i]);
      _ap(2 * i + 1, u[i]);
      u[i] = M::id();
    }
  }

  void set(int l, int r, const U& f) {
    _push(l, r);
    for (int i = l + n, j = r + n; i < j; i >>= 1, j >>= 1) {
      if (i & 1) _ap(i++, f);
      if (j & 1) _ap(--j, f);
    }
    for (l += n; !(l & 1);) l >>= 1;
    while (l >>= 1) t[l] = M::op(t[2 * l], t[2 * l + 1]);
    for (r += n; !(r & 1);) r >>= 1;
    while (r >>= 1) t[r] = M::op(t[2 * r], t[2 * r + 1]);
  }
};

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  struct bag { int x, y; };
  V<bag> a(n);
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    if (x > y) swap(x, y);
    a[i] = bag{x, y};
  }
  sort(a.begin(), a.end(), [](bag a, bag b) { return a.x + a.y < b.x + b.y; });
  ST< M<int> > st1(n), st2(n);
  for (int i = 0; i < n; i++) st1.set(i, i + 1, {0, a[i].x}), st2.set(i, i + 1, {0, a[i].y});
  lint res = (lint) (st1.get(0, n)[1] - st1.get(0, n)[0]) * (st2.get(0, n)[1] - st2.get(0, n)[0]);
  for (int i = 0; i < n; i++) {
    st1.set(i, i + 1, {0, a[i].y}), st2.set(i, i + 1, {0, a[i].x});
    res = min(res, (lint) (st1.get(0, n)[1] - st1.get(0, n)[0]) * (st2.get(0, n)[1] - st2.get(0, n)[0]));
  }
  cout << res << '\n';
}