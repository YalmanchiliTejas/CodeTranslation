#include <bits/stdc++.h>
using namespace std;

// 0-indexed
template <class T, class E>
struct SegmentTreeLaze {
  // a,b:T c,d:E e:E(unit)
  // g(f(a,b),c) = f(g(a,c),g(b,c))
  // g(g(a,c),d) = g(a,h(c,d))
  // g(a,e) = a
  typedef function<T(T, T)> F;
  typedef function<T(T, E)> G;
  typedef function<E(E, E)> H;
  int n, height;
  F f;
  G g;
  H h;
  T tunit;
  E eunit;
  vector<T> dat;
  vector<E> laz;
  SegmentTreeLaze(){};
  SegmentTreeLaze(int newn, F f, G g, H h, T nt, E ne)
      : f(f), g(g), h(h), tunit(nt), eunit(ne) {
    init(newn);
  }
  SegmentTreeLaze(const vector<T>& v, F f, G g, H h, T nt, E ne)
      : f(f), g(g), h(h), tunit(nt), eunit(ne) {
    int _n = v.size();
    init(v.size());
    for (int i = 0; i < _n; ++i) dat[n + i] = v[i];
    for (int i = n - 1; i; --i) dat[i] = f(dat[i << 1], dat[(i << 1) | 1]);
  }
  void init(int newn) {
    n = 1, height = 0;
    while (n < newn) n <<= 1, ++height;
    dat.assign(n << 1, tunit);
    laz.assign(n << 1, eunit);
  }

  inline T reflect(int k) {
    return laz[k] == eunit ? dat[k] : g(dat[k], laz[k]);
    // reset query
    // dat[k] = reflect(k);
    // laz[k] = eunit;
  }

  inline void eval(int k) {
    if (laz[k] == eunit) return;
    laz[k << 1] = h(laz[k << 1], laz[k]);
    laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
    dat[k] = reflect(k);
    laz[k] = eunit;
  }

  inline void thrust(int k) {
    for (int i = height; i; --i) eval(k >> i);
  }

  void recalc(int k) {
    while (k >>= 1) dat[k] = f(reflect(k << 1), reflect((k << 1) | 1));
  }
  // [a,b)
  void update(int a, int b, E newdata) {
    thrust(a += n);
    thrust(b += n - 1);
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) laz[l] = h(laz[l], newdata), l++;
      if (r & 1) --r, laz[r] = h(laz[r], newdata);
    }
    recalc(a);
    recalc(b);
  }

  void set_val(int k, T newdata) {
    thrust(k += n);
    dat[k] = newdata;
    laz[k] = eunit;
    recalc(k);
  }

  // [a,b)
  T query(int a, int b) {
    thrust(a += n);
    thrust(b += n - 1);
    T vl = tunit, vr = tunit;
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = f(vl, reflect(l++));
      if (r & 1) vr = f(reflect(--r), vr);
    }
    return f(vl, vr);
  }
};

using P = pair<long long, int>;
long long n;
vector<P> a;
SegmentTreeLaze<P, long long> seg;

long long solve();

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  auto f = [](P l, P r) { return max(l, r); };
  auto g = [](P l, long long r) { return P(l.first + r, l.second); };
  auto h = [](long long l, long long r) { return l + r; };
  seg = SegmentTreeLaze<P, long long>(a, f, g, h, P(0, 0), 0);
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long res = 0;
  while (1) {
    auto [now, id] = seg.query(0, n);
    if (now < n) break;
    long long others = 0;
    while (now >= n) {
      long long x = now / n;
      now %= n;
      res += x;
      others += x;
      x = others / n;
      res += x * (n - 1);
      others %= n;
      now += (n - 1) * x;
      others += (n - 2) * x;
    }
    seg.set_val(id, P(now, id));
    seg.update(0, n, others);
    seg.update(id, id + 1, -others);
  }
  return res;
}