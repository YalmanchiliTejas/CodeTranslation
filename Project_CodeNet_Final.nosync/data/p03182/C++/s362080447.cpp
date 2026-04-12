#include <bits/stdc++.h>
using namespace std;

struct Benri { Benri() { std::cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(12);}} benri;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
//constexpr int INF = 1001001001;
constexpr ll INF = 1001001001001001001ll;
constexpr double EPS = 1e-10;
using number = long long;

template< typename Monoid, typename OperatorMonoid >
struct LazySegmentTree {
    using F = function< Monoid(Monoid, Monoid) >;
    using G = function< Monoid(Monoid, OperatorMonoid, int) >;
    using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;

    int sz;
    vector< Monoid > data;
    vector< OperatorMonoid > lazy;
    const F f;
    const G g;
    const H h;
    const Monoid M1;
    const OperatorMonoid OM0;

    LazySegmentTree(int n, const F f, const G g, const H h,
                    const Monoid &M1, const OperatorMonoid OM0)
        : f(f), g(g), h(h), M1(M1), OM0(OM0) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2 * sz, M1);
        lazy.assign(2 * sz, OM0);
    }

    void set(int k, const Monoid &x) {
        data[k + sz] = x;
    }
    void build() {
        for (int k = sz - 1; k > 0; k--) {
            data[k] = f(data[2 * k + 0], data[2 * k + 1]);
        }
    }

    void propagate(int k, int len) {
        if (lazy[k] != OM0) {
            if (k < sz) {
                lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
                lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
            }
            data[k] = g(data[k], lazy[k], len);
            lazy[k] = OM0;
        }
    }

    Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r) {
        propagate(k, r - l);
        if (r <= a || b <= l) {
            return data[k];
        } else if (a <= l && r <= b) {
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
        if (r <= a || b <= l) {
            return M1;
        } else if (a <= l && r <= b) {
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
    int N, M; cin >> N >> M;
    vll l(M), r(M), a(M);
    vvi indl(N + 1), indr(N + 1);
    rep(i, M) {
        cin >> l[i] >> r[i] >> a[i];
        indl[l[i]].pb(i);
        indr[r[i]].pb(i);
    }

    //区間加算・最大値クエリのセグ木
    LazySegmentTree<ll, ll> seg(
        N + 1,
    [](ll a, ll b) {return max(a, b);},
    [](ll a, ll b, int c) {return a + b;},
    plus<ll>(),
    -INF,
    0LL);

    ll ans = -INF;
    vll dp(N + 1, 0);
    
    chmax(ans, dp[0]);
    seg.update(0, 1, dp[0]+INF);

    for (int i = 1; i <= N ; i++) {
        for (auto k : indl[i]) {
            seg.update(0, l[k], a[k]);
        }
        dp[i] = seg.query(0, i);
        chmax(ans, dp[i]);
        seg.update(i, i + 1, dp[i]+INF);
        for (auto k : indr[i]) {
            seg.update(0, l[k], -a[k]);
        }
    }

    cout << ans << endl;

}
