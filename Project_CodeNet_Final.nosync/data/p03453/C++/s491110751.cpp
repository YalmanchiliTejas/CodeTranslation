#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
// https://beta.atcoder.jp/contests/arc090/tasks/arc090_c
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
struct edge { int v, w; };
const ll INF = LLONG_MAX / 2;
const int MOD = 1e9 + 7;
const ll e18 = 1e18;

pair<vector<ll>, vector<ll>> dijkstra(int N, vector<vector<edge> >& G, int s) {
  vector<ll> d(N, INF); d[s] = 0;
  vector<ll> way(N, s); way[s] = 1;
  priority_queue<ll_i, vector<ll_i>, greater<ll_i> > pq;
  pq.push(ll_i(0, s));
  while (pq.size()) {
    ll_i p = pq.top(); pq.pop();
    int u = p.second;
    if (p.first > d[u]) continue;
    for (edge e: G[u]) {
      if (d[e.v] > d[u] + e.w) {
        d[e.v] = d[u] + e.w;
        way[e.v] = 0;
        pq.push(ll_i(d[e.v], e.v));
      }
      if (d[e.v] == d[u] + e.w)
        way[e.v] = (way[e.v] + way[u]) % MOD;
    }
  }
  return {d, way};
}

int main() {
  int N, M; cin >> N >> M;
  int s, t; cin >> s >> t, s--, t--;
  vector<vector<edge>> G(N);
  while (M--) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    u--, v--;
    G[u].pb({v, w}), G[v].pb({u, w});
  }
  vector<ll> ds = dijkstra(N, G, s).first;
  vector<ll> ws = dijkstra(N, G, s).second;
  vector<ll> dt = dijkstra(N, G, t).first;
  vector<ll> wt = dijkstra(N, G, t).second;
  ll D = ds[t];
  ll tot = 0;
  rep(u, N) if (ds[u] + dt[u] == D && ds[u] == dt[u]) {
    ll z = ws[u] * wt[u] % MOD;
    tot = (tot + z * z) % MOD;
  }
  rep(u, N) for (edge e: G[u]) {
    int v = e.v;
    if (ds[u] + e.w + dt[v] == D && ds[u] * 2 < D && dt[v] * 2 < D) {
      ll z = ws[u] * wt[v] % MOD;
      tot = (tot + z * z) % MOD;
    }
  }
  ll ans = (ws[t] * ws[t] - tot) % MOD;
  cout << (ans + MOD) % MOD << endl;
}
