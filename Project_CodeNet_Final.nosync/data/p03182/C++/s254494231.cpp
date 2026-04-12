#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
const int64 INF = 1LL << 58;

template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;
  using G = function< Monoid(Monoid, OperatorMonoid) >;
  using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;
  using P = function< OperatorMonoid(OperatorMonoid, int) >;

  int sz;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const P p;
  const Monoid M1;
  const OperatorMonoid OM0;


  LazySegmentTree(int n, const F f, const G g, const H h, const P p,
                  const Monoid &M1, const OperatorMonoid OM0)
      : f(f), g(g), h(h), p(p), M1(M1), OM0(OM0) {
    sz = 1;
    while(sz < n) sz <<= 1;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x) {
    data[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  void propagate(int k, int len) {
    if(lazy[k] != OM0) {
      if(k < sz) {
        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
        lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      }
      data[k] = g(data[k], p(lazy[k], len));
      lazy[k] = OM0;
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r) {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return data[k];
    } else if(a <= l && r <= b) {
      lazy[k] = h(lazy[k], x);
      propagate(k, r - l);
      return data[k];
    } else {
      return data[k] = f(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),
                         update(a, b, x, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x) {
    return update(a, b, x, 1, 0, sz);
  }


  Monoid query(int a, int b, int k, int l, int r) {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return M1;
    } else if(a <= l && r <= b) {
      return data[k];
    } else {
      return f(query(a, b, 2 * k + 0, l, (l + r) >> 1),
               query(a, b, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid query(int a, int b) {
    return query(a, b, 1, 0, sz);
  }

  Monoid operator[](const int &k) {
    return query(k, k + 1);
  }
};


int main() {
  int N, M;
  cin >> N >> M;
  vector< pair< int, int > > ev[200001];

  for(int i = 0; i < M; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    --l;
    --r;
    ev[r].emplace_back(l, x);
  }

  vector< int64 > dp(N);
  //1を使った最も右の位置

  using pi = pair< int64, int >;

  auto f = [](int64 a, int64 b) {
    return max(a, b);
  };
  auto g = [](int64 a, pi b) {
    if(b.second == 0) return a; // reset
    if(b.second == 1) return b.first; // set
    else if(b.second == 2) return a + b.first; // add
    return a;
  };
  auto h = [](pi a, pi b) {
    if(a.second == 0) return b;
    if(b.second == 0) return a;
    if(b.second == 1) return b;
    return pi(a.first + b.first, a.second);
  };


  auto p = [](pi a, int p) {
    return a;
  };

  LazySegmentTree< int64, pi > seg(N, f, g, h, p, 0, pi());

  for(int i = 0; i < N; i++) {
    // ここに1を書くと
    seg.update(i, i + 1, pi(seg.query(0, i), 1));
    for(auto &p : ev[i]) {
      seg.update(p.first, i + 1, pi(p.second, 2));
    }
  }

  cout << max(0LL, seg.query(0, N)) << endl;
}

