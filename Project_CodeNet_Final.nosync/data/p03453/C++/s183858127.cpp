#include<bits/stdc++.h>
using namespace std;

using I = long long;
struct Edge {int from, to; I weight;};
using Graph = vector<vector<Edge>>;
using P = pair<I, int>;

const I M = 1e9 + 7;

vector<I> Dijkstra(auto& G, auto S) {
  vector<I> d(G.size(), -1);
  priority_queue<P, vector<P>, greater<P>> q;
  q.emplace(0, S);
  while(!q.empty()) {
    auto w = q.top().first;
    auto v = q.top().second;
    q.pop();
    if(d[v] != -1) continue;
    d[v] = w;
    for(auto e: G[v]) if(d[e.to] == -1) q.emplace(w + e.weight, e.to);
  }
  return d;
}

vector<I> path(auto& G, auto& d, auto& S, auto q, auto shortest) {
  vector<I> dp(G.size());
  for(auto v=0; v<G.size(); ++v) q.emplace(d[v], v);
  dp[S] = 1;
  while(!q.empty()) {
    auto w = q.top().first;
    auto v = q.top().second;
    q.pop();
    for(auto e: G[v]) if(shortest(d[e.from], e.weight, d[e.to])) (dp[e.to] += dp[e.from]) %= M;
  }
  return dp;
}

int main() {
  int N, m;
  int S, T;
  cin >> N >> m >> S >> T;
  --S; --T;
  Graph G(N);
  for(auto i=0; i<m; ++i) {
    int u, v, d;
    cin >> u >> v >> d;
    --u; --v;
    G[u].push_back({u, v, d});
    G[v].push_back({v, u, d});
  }

  auto d = Dijkstra(G, S);
  auto dp1 = path(G, d, S, priority_queue<P, vector<P>, greater<P>>(), [](auto u, auto w, auto v) {return u+w==v;});
  auto dp2 = path(G, d, T, priority_queue<P>(), [](auto v, auto w, auto u) {return v==w+u;});

  auto ans = dp1[T] * dp1[T] % M;
  for(auto v=0; v<N; ++v) if(2*d[v] == d[T]) (ans -= (dp1[v]*dp1[v]%M)*(dp2[v]*dp2[v]%M)) %= M;
  for(auto E: G) for(auto e: E) if(d[e.from]+e.weight == d[e.to]) {
    if(2*d[e.from]<d[T] && d[T]<2*d[e.to]) (ans -= (dp1[e.from]*dp1[e.from]%M)*(dp2[e.to]*dp2[e.to]%M)) %= M;
  }
  cout << (ans + M) % M << endl;
}
