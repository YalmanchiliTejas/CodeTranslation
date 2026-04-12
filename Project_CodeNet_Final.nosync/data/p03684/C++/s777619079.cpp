#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

class UnionFind {
    vector<int> par, Size;

  public:
    UnionFind(int n) : par(n), Size(n) {
        rep(i, n) {
            par[i] = i;
            Size[i] = 1;
        }
    }

    int root(int x) {
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    bool same(int x, int y) { return root(x) == root(y); }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(Size[x] > Size[y]) {
            Size[x] += Size[y];
            par[y] = x;
        } else {
            Size[y] += Size[x];
            par[x] = y;
        }
    }

    int size(int x) { return Size[root(x)]; }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    vector<ll> px(n), py(n);
    rep(i, n) px[i] = py[i] = i;
    sort(ALL(px), [&](int a, int b) { return x[a] < x[b]; });
    sort(ALL(py), [&](int a, int b) { return y[a] < y[b]; });
    struct edge {
        int a, b;
        ll cost;
        edge(int a, int b, ll c) : a(a), b(b), cost(c) {}
    };
    vector<edge> e;
    rep(i, n - 1) {
        e.push_back(edge(px[i], px[i + 1], x[px[i + 1]] - x[px[i]]));
        e.push_back(edge(py[i], py[i + 1], y[py[i + 1]] - y[py[i]]));
    }
    sort(ALL(e), [&](edge a, edge b) { return a.cost < b.cost; });
    UnionFind UF(n);
    ll ans = 0;
    for(edge i : e) {
        if(!UF.same(i.a, i.b)) {
            UF.unite(i.a, i.b);
            ans += i.cost;
        }
    }
    cout << ans << endl;

    return 0;
}