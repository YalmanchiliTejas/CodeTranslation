#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

// mod int struct
// original : https://github.com/beet-aizu/library/blob/master/mod/mint.cpp

struct mint {
    ll v;
    ll mod;
    mint() : v(0) {}
    mint(signed v, ll mod = MOD) : v(v), mod(mod) {}
    mint(ll t, ll mod = MOD) : mod(mod) {
        v = t % mod;
        if (v < 0)
            v += mod;
    }

    mint pow(ll k) {
        mint res(1), tmp(v);
        while (k) {
            if (k & 1)
                res *= tmp;
            tmp *= tmp;
            k >>= 1;
        }
        return res;
    }

    static mint add_identity() { return mint(0); }
    static mint mul_identity() { return mint(1); }

    mint inv() { return pow(mod - 2); }

    mint &operator+=(mint a) {
        v += a.v;
        if (v >= mod)
            v -= mod;
        return *this;
    }
    mint &operator-=(mint a) {
        v += mod - a.v;
        if (v >= mod)
            v -= mod;
        return *this;
    }
    mint &operator*=(mint a) {
        v = 1LL * v * a.v % mod;
        return *this;
    }
    mint &operator/=(mint a) { return (*this) *= a.inv(); }

    mint operator+(mint a) const { return mint(v) += a; };
    mint operator-(mint a) const { return mint(v) -= a; };
    mint operator*(mint a) const { return mint(v) *= a; };
    mint operator/(mint a) const { return mint(v) /= a; };

    mint operator-() const { return v ? mint(mod - v) : mint(v); }

    bool operator==(const mint a) const { return v == a.v; }
    bool operator!=(const mint a) const { return v != a.v; }
    bool operator<(const mint a) const { return v < a.v; }

    // find x s.t. a^x = b
    static ll log(ll a, ll b) {
        const ll sq = 40000;
        unordered_map<ll, ll> dp;
        dp.reserve(sq);
        mint res(1);
        for (int r = 0; r < sq; r++) {
            if (!dp.count(res.v))
                dp[res.v] = r;
            res *= a;
        }
        mint p = mint(a).inv().pow(sq);
        res    = b;
        for (int q = 0; q <= MOD / sq + 1; q++) {
            if (dp.count(res.v)) {
                ll idx = q * sq + dp[res.v];
                if (idx > 0)
                    return idx;
            }
            res *= p;
        }
        assert(0);
        return ll(-1);
    }

    static mint comb(long long n, int k) {
        mint num(1), dom(1);
        for (int i = 0; i < k; i++) {
            num *= mint(n - i);
            dom *= mint(i + 1);
        }
        return num / dom;
    }
};
ostream &operator<<(ostream &os, mint m) {
    os << m.v;
    return os;
}

template <typename T>
vector<T> dijkstra(int s, vector<vector<pair<int, T>>> &G) {
    const T INF = numeric_limits<T>::max();
    using P     = pair<T, int>;
    int n       = G.size();
    vector<T> d(n, INF);
    vector<int> b(n, -1);
    priority_queue<P, vector<P>, greater<P>> q;
    d[s] = 0;
    q.emplace(d[s], s);
    while (!q.empty()) {
        P p = q.top();
        q.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        for (auto &e : G[v]) {
            int u = e.first;
            T c   = e.second;
            if (d[u] > d[v] + c) {
                d[u] = d[v] + c;
                b[u] = v;
                q.emplace(d[u], u);
            }
        }
    }
    return d;
}

int main() {
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    s--, t--;
    vector<vector<pair<int, ll>>> edges(n);
    for (int i = 0; i < m; ++i) {
        ll u, v, d;
        cin >> u >> v >> d;
        u--, v--;
        edges[u].emplace_back(v, d);
        edges[v].emplace_back(u, d);
    }
    auto distt = dijkstra(s, edges);
    auto dista = dijkstra(t, edges);
    vector<mint> dpt(n, 0);
    dpt[s] = 1;
    vector<bool> calcedt(n, false);
    calcedt[s]               = true;
    function<mint(int)> dfst = [&](int c) {
        if (calcedt[c])
            return dpt[c];
        mint ret = 0;
        for (auto &v : edges[c]) {
            if (distt[v.first] + v.second == distt[c]) {
                ret += dfst(v.first);
            }
        }
        calcedt[c]    = true;
        return dpt[c] = ret;
    };
    dfst(t);

    vector<mint> dpa(n, 0);
    dpa[t] = 1;
    vector<bool> calceda(n, false);
    calceda[t]               = true;
    function<mint(int)> dfsa = [&](int c) {
        if (calceda[c])
            return dpa[c];
        mint ret = 0;
        for (auto &v : edges[c]) {
            if (dista[v.first] + v.second == dista[c]) {
                ret += dfsa(v.first);
            }
        }
        calceda[c]    = true;
        return dpa[c] = ret;
    };
    dfsa(s);

    mint ret = dpt[t] * dpa[s];
    for (int i = 0; i < n; ++i) {
        if (distt[i] == dista[i]) {
            ret -= dpt[i].pow(2) * dpa[i].pow(2);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (auto &p : edges[i]) {
            if (distt[i] + p.second == distt[p.first]) {
                if (distt[i] * 2 < distt[t] && distt[p.first] * 2 > distt[t]) {
                    ret -= dpt[i].pow(2) * dpa[p.first].pow(2);
                }
            }
        }
    }
    cout << ret << "\n";
    return 0;
}