#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1ll << 56;
const ll MOD = 1e9 + 7;

pair<vector<ll>, vector<ll>> calc(const vector<vector<pair<int, ll>>> &G, int S) {
  vector<ll> dist(G.size(), INF);
  priority_queue<pair<ll, int>> q;
  q.emplace(0, S);
  dist[S] = 0;
  while (!q.empty()) {
    auto p = q.top(); q.pop();
    int v = p.second;
    for (auto e: G[v]) {
      int u = e.first;
      ll c = e.second;
      if (dist[v] + c < dist[u]) {
        dist[u] = dist[v] + c;
        q.emplace(-dist[u], u);
      }
    }
  }
  vector<bool> used(G.size(), false);
  vector<ll> dp(G.size(), 0);
  q.emplace(0, S);
  used[S] = true;
  dp[S] = 1;
  while (!q.empty()) {
    auto p = q.top(); q.pop();
    int v = p.second;
    for (auto e: G[v]) {
      int u = e.first;
      ll c = e.second;
      if (dist[v] + c == dist[u]) {
        dp[u] += dp[v];
        dp[u] %= MOD;
        if (!used[u]) {
          used[u] = true;
          q.emplace(-dist[u], u);
        }
      }
    }
  }
  return make_pair(dist, dp);
}

int main() {
  int N, M;
  cin >> N >> M;
  int S, T;
  cin >> S >> T;
  --S;
  --T;
  vector<vector<pair<int, ll>>> G(N);
  for (int i = 0; i < M; i++) {
    int U, V;
    ll D;
    cin >> U >> V >> D;
    --U;
    --V;
    G[U].emplace_back(V, D);
    G[V].emplace_back(U, D);
  }
  auto ps = calc(G, S);
  auto pt = calc(G, T);
  vector<ll> distS = ps.first, dpS = ps.second;
  vector<ll> distT = pt.first, dpT = pt.second;
  ll res = dpS[T] * dpT[S] % MOD;
  ll dame = 0;
  for (int v = 0; v < N; v++) {
    for (auto e: G[v]) {
      int u = e.first;
      ll c = e.second;
      if (distS[v] + c + distT[u] == distS[T] &&
          distT[u] + c + distS[v] == distT[S]) {
        if (distS[v] + c > distT[u] && distT[u] + c > distS[v]) {
          ll tmp = dpS[v] * dpT[u] % MOD;
          dame = (dame + tmp * tmp % MOD) % MOD;
        }
      }
    }
  }
  for (int v = 0; v < N; v++) {
    if (distS[v] + distT[v] == distT[S] && distS[v] == distT[v]) {
      ll tmp = dpS[v] * dpT[v] % MOD;
      dame = (dame + tmp * tmp % MOD) % MOD;
    }
  }
  res = (res - dame + MOD) % MOD;
  cout << res << endl;
  return 0;
}
