#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include <tuple>
#include <queue>
#include <iostream>

using namespace std;

template <typename CapTp = int, typename CostTp = int>
struct Edge {
  int to, rev;
  CapTp cap; CostTp cost;
  bool is_rev;
  Edge(int t, bool f, int r, CapTp ca, CostTp co = 0):
    to(t), rev(r), cap(ca), cost(co), is_rev(f) {}
};

template <typename CapTp = int>
struct Dinic {
  using Graph = vector<vector<Edge<CapTp>>>;
  Graph G;
  vector<int> level, iter;
  const CapTp IA;
  vector<pair<int, int>> r_edges;
  Dinic(int N, CapTp IA_ = 1<<29): IA(IA_) {
    G.resize(N);
    level.resize(N);
    iter.resize(N);
  }
  void add_edge(int from, int to, CapTp cap) {
    G[from].emplace_back(to, false, G[to].size(), cap);
    G[to].emplace_back(from, true, G[from].size()-1, 0);
    r_edges.emplace_back(to, G[to].size()-1);
  }
  CapTp get_flowed_cap(size_t k) {
    if (r_edges.size() <= k) return -1;
    int v, i; tie(v, i) = r_edges[k];
    return G[v][i].cap;
  }
  void bfs(int s) {
    fill(level.begin(), level.end(), -1);
    queue<int> que; que.push(s);
    level[s] = 0;
    while (!que.empty()) {
      int temp = que.front(); que.pop();
      for (size_t i = 0; i < G[temp].size(); ++i) {
        auto &e = G[temp][i];
        if (e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[temp] + 1;
          que.push(e.to);
        }
      }
    }
  }

  CapTp dfs(int v, int t, CapTp f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < (int)G[v].size(); ++i) {
      auto &e = G[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) {
        CapTp d = dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  CapTp max_flow(int s, int t) {
    CapTp flow = 0, f;
    while (true) {
      bfs(s);
      if (level[t] < 0) return flow;
      fill(iter.begin(), iter.end(), 0);
      while ((f = dfs(s, t, IA)) > 0) flow += f;
    }
  }
};

void add_edge(Dinic<int> &fl, int u, int v, int c, vector< tuple<int, int, int> > &edges) {
  edges.emplace_back(u, v, c);
  fl.add_edge(u, v, c);
}

int testcase_ends() {
  const int INF = 1 << 20;
  int H, W, C, M, Nw, Nc, Nm;
  cin >> H >> W >> C >> M >> Nw >> Nc >> Nm;
  if(H < 0) return 1;

  vector< tuple<int, int, int> > edges;
  int N = H + 2*(W+1) + 2*(C+1) + 2*(M+1);
  Dinic<int> fl(N+2);
  int source = N, sink = source + 1;

  // source -- hero
  for(int i=0; i<H; i++) {
    add_edge(fl, source, i, 1, edges);

    // not use (hero -- warrior)
    add_edge(fl, i, H + W, INF, edges);
  }

  // hero -- warrior
  for(int i=0; i<W; i++) {
    int x; cin >> x;

    // friend (hero)
    for(int j=0; j<x; j++) {
      int y; cin >> y; y--;
      int u = y, v = H + i;
      add_edge(fl, u, v, INF, edges);
    }
  }

  // warrior -- warrior
  for(int i=0; i<W+1; i++) {
    int u = H + i, v = H + (W + 1) + i;
    int c = (i == W ? Nw : 1);
    add_edge(fl, u, v, c, edges);
  }

  for(int i=0; i<W; i++) {
    // not use (warrior -- cleric)
    add_edge(fl, H + (W + 1) + i, H + 2*(W + 1) + C, INF, edges);
  }

  // not use warror -- cleric
  for(int i=0; i<C; i++) {
    int u = H + (W+1) + W;
    int v = H + 2*(W+1) + i;
    add_edge(fl, u, v, INF, edges);
  }
  
  // warrior -- cleric
  for(int i=0; i<C; i++) {
    int x; cin >> x;

    // friend (warrior)
    for(int j=0; j<x; j++) {
      int y; cin >> y; y--;
      int u = H + (W + 1) + y;
      int v = H + 2*(W + 1) + i;
      add_edge(fl, u, v, INF, edges);
    }
  }

  // cleric -- cleric
  for(int i=0; i<C+1; i++) {
    int u = H + 2*(W+1) + i;
    int v = H + 2*(W+1) + (C+1) + i;
    int c = (i == C ? Nc : 1);
    add_edge(fl, u, v, c, edges);
  }

  // not use cleric -- mage
  for(int i=0; i<M; i++) {
    int u = H + 2*(W+1) + (C+1) + C;
    int v = H + 2*(W+1) + 2*(C+1) + i;
    add_edge(fl, u, v, INF, edges);
  }
  
  // cleric -- mage
  for(int i=0; i<M; i++) {
    int x; cin >> x;
    for(int j=0; j<x; j++) {
      int y; cin >> y; y--;
      int u = H + 2*(W+1) + (C+1) + y;
      int v = H + 2*(W+1) + 2*(C+1) + i;
      add_edge(fl, u, v, INF, edges);
    }
  }

  // not use (cleric -- mage)
  for(int i=0; i<C; i++) {
    add_edge(fl, H + 2*(W+1) + (C+1) + i, H + 2*(W+1) + 2*(C+1) + M, INF, edges);
  }

  // mage -- mage
  for(int i=0; i<M+1; i++) {
    int u = H + 2*(W+1) + 2*(C+1) + i;
    int v = H + 2*(W+1) + 2*(C+1) + (M+1) + i;
    int c = (i == M ? Nm : 1);
    add_edge(fl, u, v, c, edges);
  }

  // (not use) mage -- sink
  for(int i=0; i<M+1; i++) {
    int u = H + 2*(W+1) + 2*(C+1) + (M+1) + i;
    int v = sink;
    add_edge(fl, u, v, INF, edges);
  }

  cout << fl.max_flow(source, sink) << endl;
  for(int i=0; ; i++) {
    int cap = fl.get_flowed_cap(i);
    if(cap < 0) break;
    if(cap > 0) {
      int u, v, c; tie(u, v, c) = edges[i];
      // fprintf(stderr, "flowed cap %02d: %d (%d, %d, %d)\n", i, cap, u, v, c);
    }
  }
  // fprintf(stderr, "edge = %zu\n", edges.size());
  return 0;
}

int main() {
  while (!testcase_ends()) {}
}
