#include <bits/stdc++.h>
using namespace std;

template<class T, class E> struct LazySegmentTree {
    using F = function<T(T, T)>;
    using G = function<T(T, E)>;
    using H = function<E(E, E)>;
private : 
    int n, dep;
    const F f;
    const G g;
    const H h;
    T id1;
    E id0;
    vector<T> node;
    vector<E> lazy;

public : 
    LazySegmentTree (const F &f, const G &g, const H &h, const T &id1, const E &id0) :
        f(f), g(g), h(h), id1(id1), id0(id0) { }

    void init (int sz) {
        n = 1; dep = 0;
        while (n < sz) { n <<= 1; dep++; }
        node.resize(2*n, id1);
        lazy.resize(2*n, id0);
    }

    void build (vector<T> v) {
        const int sz = v.size();
        init(sz);
        for (int i = 0; i < sz; i++) node[i+n] = v[i];
        for (int i = n-1; i > 0; i--) node[i] = f(node[i<<1|0], node[i<<1|1]);
    }

    inline T reflect (int k) {
        return (lazy[k] == id0 ? node[k] : g(node[k], lazy[k]));
    }

    inline void eval (int k) {
        if (lazy[k] == id0) return;
        lazy[k<<1|0] = h(lazy[k<<1|0], lazy[k]);
        lazy[k<<1|1] = h(lazy[k<<1|1], lazy[k]);
        node[k] = reflect(k);
        lazy[k] = id0;
    }

    inline void thrust (int k) {
        for (int i = dep; i; i--) eval(k>>i);
    }

    inline void recalc (int k) {
        while (k >>= 1) node[k] = f(reflect(k<<1|0), reflect(k<<1|1));
    }

    void update (int a, int b, T x) {
        thrust(a += n);
        thrust(b += n-1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l&1) { lazy[l] = h(lazy[l], x); l++; }
            if (r&1) { --r; lazy[r] = h(lazy[r], x); }
        }
        recalc(a);
        recalc(b);
    }

    T query (int a, int b) {
        thrust(a += n);
        thrust(b += n-1);
        T vl = id1, vr = id1;
        for (int l = a, r = b+1; l < r; l >>= 1, r >>= 1) {
            if (l&1) vl = f(vl, reflect(l++));
            if (r&1) vr = f(reflect(--r), vr);
        }
        return f(vl, vr);
    }

};

int main() {
   int n, m;
   cin >> n >> m;
   vector<pair<int, long long>> dat[n];
   for (int i = 0; i < m; i++) {
       int l, r; long long a;
       cin >> l >> r >> a;
       --l; --r;
       dat[r].emplace_back(l, a);
   }
   
   auto f = [](long long a, long long b) { return max(a, b); };
   auto g = [](long long a, long long b) { return a + b; };
   LazySegmentTree<long long, long long> dp(f, g, g, 0LL, 0LL);
   dp.init(n+10);
   
   for (int r = 0; r < n; r++) {
       dp.update(r, r+1, dp.query(0, r));
       for (const auto &e : dat[r]) {
           dp.update(e.first, r+1, e.second);
       }
   }
   
   cout << dp.query(0, n) << endl;
   return 0;
}