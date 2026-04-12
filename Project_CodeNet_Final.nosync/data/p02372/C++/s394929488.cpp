#include <bits/stdc++.h>
using namespace std;

template<typename T> struct Graph {
  struct Edge { int to; T cost; };
  vector<int> prev;
  vector<vector<Edge>> g;
  Graph(int n) : prev(n, -1), g(n) {}

  void addEdge(int u, int v, T w) {
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  vector<T> dijkstra(int s) {
    vector<T> dist(g.size(), -1);
    using Node = pair<T, int>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({dist[s] = 0, s});

    while (!pq.empty()) {
      auto d = pq.top().first;
      auto u = pq.top().second;
      pq.pop();
      if (dist[u] < d) continue;
      for (auto&& v : g[u]) {
        if (dist[v.to] < 0 || dist[v.to] > dist[u] + v.cost) {
          dist[v.to] = dist[u] + v.cost;
          prev[v.to] = u;
          pq.push({dist[v.to], v.to});
        }
      }
    }
    return dist;
  }
  vector<int> getPath(int t) {
    vector<int> path;
    for (; t != -1; t = prev[t]) path.push_back(t);
    reverse(begin(path), end(path));
    return path;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  Graph<int> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int s, t, w; cin >> s >> t >> w;
    g.addEdge(s, t, w);
  }
  vector<int> d0 = g.dijkstra(0);
  int maxId0 = distance(begin(d0), max_element(begin(d0), end(d0)));
  vector<int> d1 = g.dijkstra(maxId0);
  int maxId1 = distance(begin(d1), max_element(begin(d1), end(d1)));
  vector<int> d2 = g.dijkstra(maxId1);
  for (int i = 0; i < n; ++i) {
    cout << max(d1[i], d2[i]) << endl;
  }
  return 0;
}

