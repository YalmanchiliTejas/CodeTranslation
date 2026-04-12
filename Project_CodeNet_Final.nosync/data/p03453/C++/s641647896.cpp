#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 2, mod = 1e9 + 7;

#define temptts template <class T, class... Ts>
temptts int add(T f) { return f; } temptts int add(T f, Ts... ts) { return (f + add(ts...)) % mod; }
temptts int sub(T f) { return f; } temptts int sub(T f, Ts... ts) { return (f - sub(ts...) + 1ll * mod * mod) % mod; }
temptts int mul(T f) { return f; } temptts int mul(T f, Ts... ts) { return (1ll * f * mul(ts...)) % mod; }
int binpow(ll n, ll k) { int ans = 1; while (k) { if (k & 1) ans = mul(ans, n); n = mul(n, n), k >>= 1; } return ans; }
ll powr(ll x, int k) { ll res = 1; while (k) { if (k & 1) { if (x && mod / x < res) return 0; res = res * x; } if (x && mod / x < x) x = 0; x = x * x; k >>= 1; } return res; }
int inv(int n) { return binpow(n, mod - 2); }
struct precompute { int f[N]; precompute() { f[0] = 1; for (int i = 1; i < N; i++) f[i] = mul(f[i - 1], i); } int operator() (int n) { return f[n]; } } fact;
int C(int n, int k) { return mul(fact(n), inv(mul(fact(k), fact(n - k)))); }

struct edge {
  int u, v;
  ll w;
  bool operator < (const edge &o) const {
    return w > o.w;
  }
} e[N];

int n, m, s, t;
bool vis[N];
ll ds[N], dt[N];
int cs[N], ct[N];
vector<int> adj[N];

void dijkstra(int s, ll* d, int* c) {
  priority_queue<edge> pq;
  for (int i = 1; i <= n; i++) {
    d[i] = 1e18;
    vis[i] = 0;
  }
  pq.push({s, s, d[s] = 0});
  c[s] = 1;
  while (!pq.empty()) {
    int v = pq.top().v;
    pq.pop();
    if (vis[v]) continue;
    vis[v] = 1;
    for (auto& i : adj[v]) {
      int u = v ^ e[i].u ^ e[i].v;
      ll w = e[i].w;
      if (d[v] < 1e18 && d[u] > d[v] + w) {
        c[u] = c[v];
        pq.push({v, u, d[u] = d[v] + w});
      } else if (d[u] == d[v] + w) {
        c[u] = add(c[u], c[v]);
      }
    }
  }
}

int32_t main() { cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> s >> t;
  for (int i = 1, u, v, w; i <= m; i++) {
    cin >> u >> v >> w;
    e[i] = {u, v, w};
    adj[u].push_back(i);
    adj[v].push_back(i);
  }
  dijkstra(s, ds, cs);
  dijkstra(t, dt, ct);
  ll ans = 0;
  for (int v = 1; v <= n; v++) {
    if (ds[v] + dt[v] == ds[t] 
    && 2 * ds[v] == ds[t] 
    && 2 * dt[v] == dt[s]) {
      ll cc = mul(cs[v], ct[v]);
      ans = add(ans, mul(cc, cc));
    }
  }
  for (int i = 1; i <= m; i++) {
    int u = e[i].u, v = e[i].v;
    ll w = e[i].w;
    if (ds[u] + dt[v] + w == ds[t] 
    && 2 * ds[u] < ds[t] 
    && 2 * dt[v] < dt[s]) {
      ll cc = mul(cs[u], ct[v]);
      ans = add(ans, mul(cc, cc));
    }
    if (ds[v] + dt[u] + w == ds[t] 
    && 2 * ds[v] < ds[t] 
    && 2 * dt[u] < dt[s]) {
      ll cc = mul(cs[v], ct[u]);
      ans = add(ans, mul(cc, cc));
    }
  }
  cout << sub(mul(cs[t], ct[s]), ans);
}