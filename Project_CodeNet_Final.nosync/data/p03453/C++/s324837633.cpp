#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[100005];
vector<pair<pair<int, int>, int>> edges;

int n, m;
int s, t;
long long dist1[100005];
long long cnt1[100005];
long long dist2[100005];
long long cnt2[100005];

const long long mod = 1000000007;

void fill(int from, long long* dist, long long* cnt) {
  priority_queue<pair<long long, int>> pq;
  pq.push({0, from});
  while (!pq.empty()) {
    auto top = pq.top();
    pq.pop();
    long long d = -top.first;
    int x = top.second;
    if (dist[x] == -1) {
      dist[x] = d;
    } else {
      continue;
    }
    for (auto nxt : graph[x]) {
      int y = nxt.first;
      int dd = nxt.second;
      if (dist[y] == -1) {
        pq.push({-d-dd, y});
      }
    }
  }
  cnt[from] = 1;
  for (int ni = 1; ni <= n; ni++) {
    pq.push({-dist[ni], ni});
  }
  while (!pq.empty()) {
    auto top = pq.top();
    pq.pop();
    long long d = -top.first;
    int x = top.second;
    for (auto nxt : graph[x]) {
      int y = nxt.first;
      int dd = nxt.second;
      if (dist[y] == dist[x] + dd) {
        cnt[y] += cnt[x];
        cnt[y] %= mod;
      }
    }
  }
}

int main() {
  cin >> n >> m;
  cin >> s >> t;
  for (int mi = 0; mi < m; mi++) {
    int u, v, d;
    cin >> u >> v >> d;
    graph[u].push_back({v, d});
    graph[v].push_back({u, d});
    edges.push_back({{u, v}, d});
  }
  memset(dist1, -1, sizeof(dist1));
  memset(dist2, -1, sizeof(dist2));
  fill(s, dist1, cnt1);
  fill(t, dist2, cnt2);
  long long sdist = dist1[t];
  long long ans = cnt1[t] * cnt1[t] % mod;
  for (int ni = 1; ni <= n; ni++) {
    if (dist1[ni] * 2 == sdist && dist2[ni] * 2 == sdist) {
      ans += mod - cnt1[ni] * cnt1[ni] % mod * cnt2[ni] % mod * cnt2[ni] % mod;
      ans %= mod;
    }
  }
  for (int mi = 0; mi < m; mi++) {
    int u = edges[mi].first.first;
    int v = edges[mi].first.second;
    int d = edges[mi].second;
    if (dist1[u] * 2 < sdist && dist2[v] * 2 < sdist && dist1[u] + dist2[v] + d == sdist) {
      ans += mod - cnt1[u] * cnt1[u] % mod * cnt2[v] % mod * cnt2[v] % mod;
      ans %= mod;
    } else if (dist1[v] * 2 < sdist && dist2[u] * 2 < sdist && dist1[v] + dist2[u] + d == sdist) {
      ans += mod - cnt1[v] * cnt1[v] % mod * cnt2[u] % mod * cnt2[u] % mod;
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}