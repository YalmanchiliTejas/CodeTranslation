#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) ((x).begin(), (x).end())
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

template <typename Monoid, typename OperatorMonoid> struct LazySegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, OperatorMonoid)>;
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

    int sz, height;
    vector<Monoid> data;
    vector<OperatorMonoid> lazy;
    const F f;
    const G g;
    const H h;
    const Monoid M0;
    const OperatorMonoid O0;

    constexpr LazySegmentTree(const F &f, const G &g, const H &h,
                              const Monoid &M0, const OperatorMonoid &O0)
        : f(f), g(g), h(h), M0(M0), O0(O0) {}

    constexpr void init(const int &n) {
        sz = 1;
        height = 0;
        while(sz < n)
            sz <<= 1, height++;
        data.assign(sz << 1, M0);
        lazy.assign(sz << 1, O0);
    }

    constexpr void build(const vector<Monoid> &v) {
        int n = v.size();
        init(n);
        for(int i = 0; i < n; i++)
            data[sz + i] = v[i];
        for(int i = sz - 1; i; i--)
            data[i] = f(data[i << 1], data[i << 1 | 1]);
    }

    constexpr Monoid reflect(const int &k) const {
        return lazy[k] == O0 ? data[k] : g(data[k], lazy[k]);
    }

    constexpr void propagate(const int &k) {
        if(lazy[k] == O0) return;
        lazy[k << 1] = h(lazy[k << 1], lazy[k]);
        lazy[k << 1 | 1] = h(lazy[k << 1 | 1], lazy[k]);
        data[k] = reflect(k);
        lazy[k] = O0;
    }

    constexpr void thrust(const int &k) {
        for(int i = height; i; i--)
            propagate(k >> i);
    }

    constexpr void thrust(const int &l, const int &r) {
        if(l == r) {
            thrust(l);
            return;
        }
        int Xor = l ^ r, i = height;
        for(; !(Xor >> i); i--)
            propagate(l >> i);
        for(; i; i--) {
            propagate(l >> i);
            propagate(r >> i);
        }
    }

    constexpr void recalc(int k) {
        while(k >>= 1)
            data[k] = f(reflect(k << 1), reflect(k << 1 | 1));
    }

    constexpr void recalc(int l, int r) {
        int Xor = l ^ r;
        while(Xor >>= 1) {
            l >>= 1;
            r >>= 1;
            data[l] = f(reflect(l << 1), reflect(l << 1 | 1));
            data[r] = f(reflect(r << 1), reflect(r << 1 | 1));
        }
        while(l >>= 1)
            data[l] = f(reflect(l << 1), reflect(l << 1 | 1));
    }

    constexpr void update(int a, int b, const OperatorMonoid &x) {
        if(a >= b) return;
        thrust(a += sz, b += sz - 1);
        for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) lazy[l] = h(lazy[l], x), l++;
            if(r & 1) --r, lazy[r] = h(lazy[r], x);
        }
        recalc(a, b);
    }

    constexpr void set_val(int a, const Monoid &x) {
        thrust(a += sz);
        data[a] = x;
        lazy[a] = O0;
        recalc(a);
    }

    constexpr Monoid query(int a, int b) {
        if(a >= b) return M0;
        thrust(a += sz, b += sz - 1);
        Monoid vl = M0, vr = M0;
        for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) vl = f(vl, reflect(l++));
            if(r & 1) vr = f(reflect(--r), vr);
        }
        return f(vl, vr);
    }

    template <typename C>
    constexpr int find(const int &st, const C &check, Monoid &acc, const int &k,
                       const int &l, const int &r) {
        if(l + 1 == r) {
            acc = f(acc, reflect(k));
            return check(acc) ? k - sz : -1;
        }
        propagate(k);
        int m = (l + r) >> 1;
        if(m <= st) return find(st, check, acc, k << 1 | 1, m, r);
        if(st <= l && !check(f(acc, data[k]))) {
            acc = f(acc, data[k]);
            return -1;
        }
        int vl = find(st, check, acc, k << 1, l, m);
        if(~vl) return vl;
        return find(st, check, acc, k << 1 | 1, m, r);
    }

    template <typename C> constexpr int find(const int &st, const C &check) {
        Monoid acc = M0;
        return find(st, check, acc, 1, 0, sz);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    using P = pair<int, int>;
    V<P> kukan[n + 1];
    rep(i, m) {
        int l, r, a;
        cin >> l >> r >> a;
        kukan[r].push_back(P(l, a));
    }
    auto f = [](ll a, ll b) { return max(a, b); };
    auto g = [](ll a, ll b) { return a + b; };
    LazySegmentTree<ll, ll> seg(f, g, g, -inf, 0);
    seg.build(V<ll>(n + 1, 0));
    FOR(i, 1, n + 1) {
        seg.set_val(i, seg.query(0, i));
        for(auto p : kukan[i]) {
            int l = p.first;
            int a = p.second;
            seg.update(l, i + 1, a);
        }
    }

    cout << seg.query(0, n + 1) << endl;

    return 0;
}