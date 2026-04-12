#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree
{
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
      : f(f), g(g), h(h), p(p), M1(M1), OM0(OM0)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x)
  {
    data[k + sz] = x;
  }

  void build()
  {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  void propagate(int k, int len)
  {
    if(lazy[k] != OM0) {
      if(k < sz) {
        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
        lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      }
      data[k] = g(data[k], p(lazy[k], len));
      lazy[k] = OM0;
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r)
  {
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

  Monoid update(int a, int b, const OperatorMonoid &x)
  {
    return update(a, b, x, 1, 0, sz);
  }


  Monoid query(int a, int b, int k, int l, int r)
  {
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

  Monoid query(int a, int b)
  {
    return query(a, b, 1, 0, sz);
  }

  Monoid operator[](const int &k)
  {
    return query(k, k + 1);
  }
};

int main() {
    int n, m;
    cin >> n >> m;

    using ll = long long;

    vector<vector<pair<int, ll>>> rs(n);

    for (int i = 0; i < m; i++) {
        int l, r;
        ll a;

        cin >> l >> r >> a;
        
        l--;
        r--;

        rs[r].emplace_back(l, a);
    }

    auto f = [](ll a, ll b) { return max(a, b); };
    auto g = [](ll a, ll b) { return a + b; };
    auto h = [](ll a, ll b) { return a + b; };
    auto p = [](ll a, ll b) { return a; };
    LazySegmentTree<ll> seg(n, f, g, h, p, INT_MIN, 0);

    for (int i = 0; i < n; i++) {
        seg.set(i, 0);
    }

    seg.build();

    for (int i = 0; i < n; i++) {
        if (i != 0) {
            seg.update(i, i + 1, max<ll>(0, seg.query(0, i)));
        }

        for (auto& p : rs[i]) {
            seg.update(p.first, i + 1, p.second);
        }

    }

    cout << max<ll>(0, seg.query(0, n)) << endl;
}