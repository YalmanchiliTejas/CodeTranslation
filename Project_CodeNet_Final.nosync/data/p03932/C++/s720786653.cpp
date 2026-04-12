#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
typedef long long int64;
 
 
struct Primal_Dual
{
  const int64 INF = 1LL << 59;
  typedef pair< int64, int > Pi;
 
  struct edge
  {
    int to, cap, cost, rev;
  };
  vector< vector< edge > > graph;
  vector< int64 > potential, min_cost, prevv, preve;
 
  Primal_Dual(int V) : graph(V) {}
 
  void add_edge(int from, int to, int cap, int cost)
  {
    graph[from].push_back((edge) {to, cap, cost, (int) graph[to].size()});
    graph[to].push_back((edge) {from, 0, -cost, (int) graph[from].size() - 1});
  }
 
  int64 min_cost_flow(int s, int t, int f)
  {
    int64 V = graph.size(), ret = 0;
    priority_queue< Pi, vector< Pi >, greater< Pi > > que;
    potential.assign(V, 0);
    preve.assign(V, -1);
    prevv.assign(V, -1);
 
    while(f > 0) {
      min_cost.assign(V, INF);
      que.push(Pi(0, s));
      min_cost[s] = 0;
 
      while(!que.empty()) {
        Pi p = que.top();
        que.pop();
        if(min_cost[p.second] < p.first) continue;
        for(int i = 0; i < graph[p.second].size(); i++) {
          edge &e = graph[p.second][i];
          int64 nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
          if(e.cap > 0 && min_cost[e.to] > nextCost) {
            min_cost[e.to] = nextCost;
            prevv[e.to] = p.second, preve[e.to] = i;
            que.push(Pi(min_cost[e.to], e.to));
          }
        }
      }
      if(min_cost[t] == INF) return (114514);
      for(int v = 0; v < V; v++) potential[v] += min_cost[v];
      int addflow = f;
      for(int v = t; v != s; v = prevv[v]) {
        addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
      }
      f -= addflow;
      ret += addflow * potential[t];
      for(int v = t; v != s; v = prevv[v]) {
        edge &e = graph[prevv[v]][preve[v]];
        e.cap -= addflow;
        graph[v][e.rev].cap += addflow;
      }
    }
    return ret;
  }
};
 
signed main()
{
  int H, W, A[200][200];
 
  cin >> H >> W;
  Primal_Dual flow(H * W * 2);
 
  auto cell = [&](int i, int j, bool in)
  {
    if(in) return (H * W + i * W + j);
    return (i * W + j);
  };
 
  const int mx = 1e6;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cin >> A[i][j];
      flow.add_edge(cell(i, j, false), cell(i, j, true), 1, mx - A[i][j]);
      flow.add_edge(cell(i, j, false), cell(i, j, true), 1, mx);
      if(i > 0) flow.add_edge(cell(i - 1, j, true), cell(i, j, false), 2, 0);
      if(j > 0) flow.add_edge(cell(i, j - 1, true), cell(i, j, false), 2, 0);
    }
  }
  cout << -(flow.min_cost_flow(cell(0, 0, false), cell(H - 1, W - 1, true), 2) - mx * (H + W - 1) * 2) << endl;
}