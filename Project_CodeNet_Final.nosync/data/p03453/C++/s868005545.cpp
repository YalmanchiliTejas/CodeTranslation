#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const int mod = 1e9 + 7;

inline void add(long long& x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}

vector<pair<long long, long long>> dijkstra(int S, vector<vector<pair<int, long long>>>& g) {
  vector<pair<long long, long long>> dis(g.size(), {inf, 0});
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
  q.push({0, S});
  dis[S] = {0, 1};
  vector<bool> vis(g.size());
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto& e : g[u]) {
      int v = e.first, w = e.second;
      if (dis[v].first > dis[u].first + w) {
        dis[v] = dis[u];
        dis[v].first += w;
        q.push({dis[v].first, v});
      } else if(dis[v].first == dis[u].first + w) {
        add(dis[v].second, dis[u].second);
      }
    }
  }
  return dis;
}

long long square(long long n) {
  n %= mod;
  return n * n % mod;
}

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  int n, m, S, T;
  cin >> n >> m >> S >> T;
  vector<vector<pair<int, long long>>> g(n + 1);
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
    edges.emplace_back(u, v, w);
    edges.emplace_back(v, u, w);
  }
  auto dis1 = dijkstra(S, g), dis2 = dijkstra(T, g);
  long long ans = dis1[T].second, L = dis1[T].first;
  ans = ans * ans % mod;
  for (int i = 1; i <= n; i++) {
    if (dis1[i].first + dis2[i].first == L && dis1[i].first * 2 == L) {
      ans = ((ans - square(dis1[i].second * dis2[i].second)) % mod + mod) % mod;
    }
  }
  for (auto e : edges) {
    int u, v, w;
    tie(u, v, w) = e;
    if (dis1[u].first + w + dis2[v].first == L) {
      if (dis1[u].first * 2 < L && dis2[v].first * 2 < L) {
        ans = ((ans - square(dis1[u].second * dis2[v].second)) % mod + mod) % mod;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
