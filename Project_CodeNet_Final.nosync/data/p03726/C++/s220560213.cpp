#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct UnionFind {
  const int n;
  V<> t; // root ? -sz : par
  UnionFind(int n) : n(n), t(n, -1) {}
  int find(int v) { return t[v] < 0 ? v : t[v] = find(t[v]); }
  void unite(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return;
    if (-t[u] < -t[v]) swap(u, v);
    t[u] += t[v];
    t[v] = u;
  }
  bool same(int u, int v) { return find(u) == find(v); }
  int size(int v) { return -t[find(v)]; }
};

template<class T> struct Dinic {
  struct Edge { int to, rev; T cap; };
  const T inf = numeric_limits<T>::max();
  const int n;
  VV<Edge> g;
  V<> dist, i;
  Dinic(int n) : n(n), g(n), dist(n), i(n) {}
  void add_edge(int from, int to, T cap) {
    assert(from != to);
    assert(cap >= 0);
    if (!cap) return;
    g[from].emplace_back(Edge{to, (int) g[to].size(), cap});
    g[to].emplace_back(Edge{from, (int) g[from].size() - 1, 0});
  }
  void bfs(int s) {
    fill(begin(dist), end(dist), -1);
    queue<int> que;
    dist[s] = 0;
    que.push(s);
    while (!que.empty()) {
      int v = que.front(); que.pop();
      for (const auto& e : g[v]) {
        if (dist[e.to] != -1 or !e.cap) continue;
        dist[e.to] = dist[v] + 1;
        que.push(e.to);
      }
    }
  }
  T dfs(int v, int s, T f) {
    if (v == s) return f;
    for (; i[v] < (int) g[v].size(); ++i[v]) {
      Edge& e = g[v][i[v]];
      if (dist[e.to] >= dist[v] or !g[e.to][e.rev].cap) continue;
      T d = dfs(e.to, s, min(f, g[e.to][e.rev].cap));
      if (d > 0) {
        g[e.to][e.rev].cap -= d;
        e.cap += d;
        return d;
      }
    }
    return 0;
  }
  T max_flow(int s, int t) {
    assert(s != t);
    T res = 0;
    while (true) {
      bfs(s);
      if (dist[t] == -1) return res;
      fill(begin(i), end(i), 0);
      while (true) {
        T f = dfs(t, s, inf);
        if (!f) break;
        res += f;
      }
    }
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  VV<> g(n);
  UnionFind uf(2 * n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    uf.unite(u, n + v);
    uf.unite(v, n + u);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  Dinic<int> d(n + 2);
  int S = n, T = S + 1;
  for (int v = 0; v < n; ++v) {
    if (uf.same(0, v)) {
      d.add_edge(S, v, 1);
      for (int w : g[v]) {
        d.add_edge(v, w, 1);
      }
    } else {
      d.add_edge(v, T, 1);
    }
  }
  cout << (2 * d.max_flow(S, T) == n ? "Second" : "First") << '\n';
}