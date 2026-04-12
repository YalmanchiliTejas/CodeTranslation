#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

const lint inf = 1e18;
struct edge { int to; lint cost; edge(int to, lint cost) : to(to), cost(cost) {} };

template<class T> V<T> dijkstra(int s, const VV<edge>& g) {
  V<T> d(g.size(), inf);
  using P = pair<T, int>;
  priority_queue<P, V<P>, greater<P> > pq;
  pq.emplace(d[s] = 0, s);
  while (!pq.empty()) {
    T dv; int v; tie(dv, v) = pq.top(); pq.pop();
    if (dv > d[v]) continue;
    for (auto&& e : g[v]) {
      if (d[e.to] <= d[v] + e.cost) continue;
      pq.emplace(d[e.to] = d[v] + e.cost, e.to);
    } 
  }
  return d;
}

const lint mod = 1e9 + 7;
inline lint emod(lint a, lint p = mod) { return (a % p + p) % p; }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, m, s, t; cin >> n >> m >> s >> t, s--, t--;
  VV<edge> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, d; cin >> u >> v >> d, u--, v--;
    g[u].emplace_back(v, d);
    g[v].emplace_back(u, d);
  }
  V<lint> ds = dijkstra<lint>(s, g), dt = dijkstra<lint>(t, g);
  V<> vs;
  for (int i = 0; i < n; i++) if (ds[i] + dt[i] == ds[t] and ds[i] == dt[i]) vs.push_back(i);
  V< pair<int, int> > ps;
  for (int i = 0; i < n; i++) for (auto&& e : g[i]) if (ds[i] < ds[e.to] and 2 * ds[i] < ds[t] and 2 * dt[e.to] < ds[t] and ds[i] + e.cost + dt[e.to] == ds[t]) ps.emplace_back(i, e.to);
  auto f = [&](int s, const V<lint>& d) {
    V<lint> dp(n);
    V< pair<lint, int> > a(n);
    for (int i = 0; i < n; i++) a[i] = {d[i], i};
    sort(a.begin(), a.end());
    dp[s] = 1;
    for (int i = 0; i < n; i++) for (auto&& e : g[a[i].second]) if (d[a[i].second] + e.cost == d[e.to]) (dp[e.to] += dp[a[i].second]) %= mod;
    return dp;
  };
  auto dps = f(s, ds), dpt = f(t, dt);
  lint res = dps[t] * dpt[s] % mod;
  for (int v : vs) (res -= dps[v] * dps[v] % mod * dpt[v] % mod * dpt[v]) %= mod;
  for (auto&& p : ps) (res -= dps[p.first] * dps[p.first] % mod * dpt[p.second] % mod * dpt[p.second]) %= mod;
  cout << emod(res) << '\n';
}