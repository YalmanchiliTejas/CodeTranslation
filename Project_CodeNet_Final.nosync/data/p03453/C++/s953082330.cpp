#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
const long long INF = 1LL << 60;    // 1.15x10^18
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//-----------------------
const int MOD = (int)1e9 + 7;
struct mint { int n; mint(int n_ = 0) : n(n_ % MOD) { if (n < 0) n += MOD; } };
mint operator+(mint a, mint b) { return (a.n += b.n) >= MOD ? a.n - MOD : a.n; }
mint operator-(mint a, mint b) { return (a.n -= b.n) < 0 ? a.n + MOD : a.n; }
mint operator*(mint a, mint b) { return 1LL * a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }
ostream &operator<<(ostream &os, mint a) { return os << a.n; }
istream &operator>>(istream &is, mint& a) { return is >> a.n; }
mint inv(mint x) { long long a = x.n, b = MOD, u = 1, v = 0;
    while (b) { long long t = a/b; swap((a -= t*b), b); swap((u -= t*v), v); }
    return mint(u); }
mint operator^(mint a, long long n) { mint r = 1;
    while (n) { if (n & 1) r *= a; a *= a; n >>= 1; } return r; }
bool operator<(const mint &a, const mint &b) { return a.n < b.n; }
//-----------------------

using edge = pair<int, long long>;
using Graph = vector<vector<edge>>;

vector<long long> dijkstra(const Graph &g, int s, vector<mint> &pat) {
    vector<long long> dist(g.size(), INF);
    using Pi = pair<long long, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> que;
    dist[s] = 0; pat[s] = 1; que.emplace(dist[s], s);
    while (!que.empty()) {
        long long cost; int u; tie(cost, u) = que.top(); que.pop();
        if (dist[u] < cost) continue;
        for (auto &e: g[u]) {
            int v; long long nc; tie(v, nc) = e;
            if (chmin(dist[v], dist[u] + nc)) {
                que.emplace(dist[v], v), pat[v] = pat[u];
            } else if (dist[v] == dist[u] + nc) {
                pat[v] += pat[u];
            }
        }
    }
    return dist;
}

int main() {
    int n, m; cin >> n >> m;
    int s, t; cin >> s >> t; s--, t--;
    Graph g(n);
    while (m--) {
        int u, v, d; cin >> u >> v >> d; u--, v--;
        g[u].emplace_back(v, d);
        g[v].emplace_back(u, d);
    }
    vector<mint> patS(n);
    auto distS = dijkstra(g, s, patS);
    vector<mint> patT(n);
    auto distT = dijkstra(g, t, patT);
    mint ans = patS[t] * patT[s];
    long long d = distS[t];
    for (int u = 0; u < n; u++) {
        if (distS[u] + distT[u] == d && distS[u] == distT[u]) {
            ans -= (patS[u] * patT[u]) * (patT[u] * patS[u]);
        }
    }
    for (int u = 0; u < n; u++) for (auto &e: g[u]) {
        int v = e.first;
        long long c = e.second;
        if (distS[u] + c + distT[v] != d) continue;
        if (distS[u] * 2 < d && distT[v] * 2 < d) {
            ans -= (patS[u] * patT[v]) * (patT[v] * patS[u]);
        }
    }
    cout << ans << endl;
    return 0;
}