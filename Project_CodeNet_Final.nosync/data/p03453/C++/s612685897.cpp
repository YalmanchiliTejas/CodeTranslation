#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Edge {
  int to;
  LL diff;

  Edge(int to, LL diff) : to(to), diff(diff) {}
};
struct Dist {
  LL dist;
  int pos;
  Dist() : dist(0), pos(0){};
  Dist(LL dist, int pos) : dist(dist), pos(pos) {}
};
bool operator<(const Dist &a, const Dist &other) {
  if (other.dist != a.dist) return a.dist > other.dist;
  return true;
}
const LL MOD = 1000000007;
void dijkstra(vector<LL> &dist, vector<LL> &ans, int s,
              vector<vector<Edge>> edges) {
  int N = edges.size();

  ans.resize(N);
  priority_queue<Dist> pq;
  pq.push(Dist(0, s));
  vector<int> used(N, 0);
  // vector<LL> dist(N, 0);
  LL INF = 100000000;
  INF *= INF;
  dist = vector<LL>(N, INF);
  dist[s] = 0;
  while (!pq.empty()) {
    Dist d = pq.top();
    pq.pop();
    int v = d.pos;
    if (used[v] == 1) continue;
    if (dist[v] != d.dist) continue;
    used[v] = 1;
    for (auto e : edges[v]) {
      int u = e.to;
      LL update = e.diff + d.dist;
      if (dist[u] > update) {
        dist[u] = update;
        pq.push(Dist(dist[u], u));
      }
    }
  }

  vector<Dist> result(N);
  for (int i = 0; i < N; i++) result[i] = Dist(dist[i], i);
  sort(result.begin(), result.end());
  reverse(result.begin(), result.end());

  ans = vector<LL>(N, 0);
  ans[s] = 1;
  for (auto res : result) {
    int v = res.pos;
    for (auto e : edges[v]) {
      if (dist[e.to] + e.diff != dist[v]) continue;
      ans[v] += ans[e.to];
      ans[v] %= MOD;
    }
  }
}

int main() {
  int N, M, s, t;
  cin >> N >> M >> s >> t;
  s--;
  t--;
  vector<vector<Edge>> edges(N);
  for (int i = 0; i < M; i++) {
    int v, u, dist;
    cin >> v >> u >> dist;
    v--;
    u--;
    dist *= 2;
    edges[v].push_back(Edge(u, dist));
    edges[u].push_back(Edge(v, dist));
  }
  vector<LL> res1, res2, dist, distA;
  dijkstra(distA, res1, s, edges);
  dijkstra(dist, res2, t, edges);

  for (int i = 0; i < N; i++) {
    // cout << i << "  " << dist[i] << " " << res1[i] << " " << res2[i] << endl;
  }

  LL med = -1;
  LL maxdist = dist[s];

  if (maxdist % 2 == 0) med = maxdist / 2;

  LL ans = 0;
  ans = res2[s] * res2[s] % MOD;
  assert(res2[s] == res1[t]);
  // cout << ans << endl;
  LL sum = 0;
  for (int v = 0; v < N; v++) {
    if (dist[v] + distA[v] > maxdist) continue;
    if (dist[v] == med && distA[v] == med) {
      LL tmp = res1[v] * res1[v] % MOD;
      tmp = tmp * res2[v] % MOD;
      tmp = tmp * res2[v] % MOD;
      ans -= tmp;
      ans %= MOD;
      sum += res2[v] * res1[v];
    }
    if (dist[v] >= med) continue;
    for (auto e : edges[v]) {
      if (maxdist < distA[e.to] + dist[v] + e.diff) continue;
      if (dist[e.to] != dist[v] + e.diff) continue;
      if (dist[e.to] > med) {
        sum += res2[v] * res1[e.to] % MOD;
        LL tmp = res1[e.to] * res2[v] % MOD;
        tmp *= tmp;
        tmp %= MOD;
        ans -= tmp;
        ans %= MOD;
      }
    }
  }
  assert(sum % MOD == res2[s]);
  ans += MOD;
  ans %= MOD;
  assert(ans >= 0);
  cout << ans << endl;

  return 0;
}