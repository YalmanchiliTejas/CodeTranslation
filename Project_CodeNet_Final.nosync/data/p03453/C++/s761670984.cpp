#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
const lint mod = 1000000007;

struct mint {
    lint v;
    lint _mod;
    mint() : v(0) {}
    mint(signed v, lint _mod = mod) : v(v), _mod(_mod) {}
    mint(lint t, lint _mod = mod) : _mod(_mod) {
        v = t % _mod;
        if (v < 0)
            v += _mod;
    }

    mint pow(lint k) {
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
    mint inv() { return pow(_mod - 2); }

    mint &operator+=(mint a) {
        v += a.v;
        if (v >= _mod)
            v -= _mod;
        return *this;
    }
    mint &operator-=(mint a) {
        v += _mod - a.v;
        if (v >= _mod)
            v -= _mod;
        return *this;
    }
    mint &operator*=(mint a) {
        v = v * a.v % _mod;
        return *this;
    }
    mint &operator/=(mint a) { return (*this) *= a.inv(); }

    mint operator+(mint a) const { return mint(v) += a; };
    mint operator-(mint a) const { return mint(v) -= a; };
    mint operator*(mint a) const { return mint(v) *= a; };
    mint operator/(mint a) const { return mint(v) /= a; };

    mint operator-() const { return v ? mint(_mod - v) : mint(v); }

    bool operator==(const mint a) const { return v == a.v; }
    bool operator!=(const mint a) const { return v != a.v; }
    bool operator<(const mint a) const { return v < a.v; }
};
ostream &operator<<(ostream &os, mint m) { return os << m.v; }

template <typename T>
vector<T> dijkstra(int s, vector<vector<pair<int, T>>> &G, vector<mint> &dp) {
    const T inf = numeric_limits<T>::max();
    using P     = pair<T, int>;
    int n       = G.size();
    vector<T> d(n, inf);
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
                q.emplace(d[u], u);
                dp[u] = dp[v];
            } else if (d[u] == d[v] + c) {
                dp[u] += dp[v];
            }
        }
    }
    return d;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    lint n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    s--, t--;
    vector<vector<pair<int, lint>>> edges(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        lint w;
        cin >> u >> v >> w;
        u--, v--;
        edges[u].emplace_back(v, w);
        edges[v].emplace_back(u, w);
    }
    vector<mint> dpt(n, 0);
    vector<mint> dps(n, 0);
    dpt[t]     = 1;
    dps[s]     = 1;
    auto distt = dijkstra(t, edges, dpt);
    auto dists = dijkstra(s, edges, dps);

    lint distst = distt[s];
    mint ret    = dpt[s] * dps[t];
    for (int i = 0; i < n; ++i) {
        if (distt[i] == dists[i]) {
            if (distt[i] * 2 == distst)
                ret -= (dpt[i] * dps[i]).pow(2);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (auto &w : edges[i]) {
            if (distt[i] * 2 < distst && distt[w.first] * 2 > distst) {
                if (dists[w.first] * 2 < distst && dists[i] * 2 > distst)
                    if (distt[i] + w.second == distt[w.first])
                        if (dists[w.first] + w.second == dists[i])
                            if (distt[i] + dists[i] == distst && distt[w.first] + dists[w.first] == distst)
                                ret -= (dpt[i] * dps[w.first]).pow(2);
            }
        }
    }
    cout << ret << "\n";
    return 0;
}