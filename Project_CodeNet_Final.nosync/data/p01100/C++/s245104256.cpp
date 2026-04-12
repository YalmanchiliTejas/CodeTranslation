#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

struct Dinic
{
  struct edge
  {
    int to, cap, rev;
  };

  vector< vector< edge > > graph;
  vector< int > min_cost, iter;

  Dinic(int n)
  {
    graph.resize(n);
  }

  void add_edge(int from, int to, int cap)
  {
    graph[from].push_back((edge) {to, cap, (int) graph[to].size()});
    graph[to].push_back((edge) {from, 0, (int) graph[from].size() - 1});
  }

  bool bfs(int s, int t)
  {
    min_cost.assign(graph.size(), -1);
    queue< int > que;
    min_cost[s] = 0;
    que.push(s);
    while(!que.empty()) {
      int p = que.front();
      que.pop();
      for(int i = 0; i < graph[p].size(); i++) {
        const edge &e = graph[p][i];
        if(e.cap > 0 && min_cost[e.to] == -1) {
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return (min_cost[t] != -1);
  }

  int dfs(int idx, const int t, int flow)
  {
    if(idx == t) return (flow);
    for(int &i = iter[idx]; i < graph[idx].size(); i++) {
      edge &e = graph[idx][i];
      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
        int d = dfs(e.to, t, min(flow, e.cap));
        if(d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return (d);
        }
      }
    }
    return (0);
  }

  int max_flow(int s, int t)
  {
    int flow = 0;
    while(bfs(s, t)) {
      iter.assign(graph.size(), 0);
      int f = 0;
      while((f = dfs(s, t, INF)) > 0) {
        flow += f;
      }
    }
    return (flow);
  }
};

int N, M, U[10000], V[10000];

bool check(int low, int high)
{
  Dinic flow(M + N + 4);
  const int S = M + N, T = M + N + 1;
  const int X = M + N + 2, Y = M + N + 3;
  auto add_edge = [&](int x, int y, int l, int h)
  {
    flow.add_edge(x, Y, l);
    flow.add_edge(X, y, l);
    flow.add_edge(x, y, h - l);
  };
  for(int i = 0; i < M; i++) {
    add_edge(S, i, 1, 1);
    add_edge(i, M + U[i], 0, 1);
    add_edge(i, M + V[i], 0, 1);
  }
  for(int i = 0; i < N; i++) {
    add_edge(M + i, T, low, high);
  }
  flow.max_flow(X, Y);
  flow.max_flow(X, T);
  flow.max_flow(S, Y);
  flow.max_flow(S, T);
  for(auto &p : flow.graph[X]) if(p.cap > 0) return (false);
  for(auto &p : flow.graph[Y]) if(flow.graph[p.to][p.rev].cap > 0) return (false);
  return (true);
}

int main()
{
  while(cin >> N >> M, N) {
    for(int i = 0; i < M; i++) {
      cin >> U[i] >> V[i];
      --U[i], --V[i];
    }
    int ret = 114514, high = 0;
    int val = 114514;
    for(int low = 0; low < N; low++) {
      while(high < N && !check(low, high)) ++high;
      if(high == N) break;
      if(high - low < ret) {
        ret = high - low;
        val = low;
      }
    }
    cout << val << " " << val + ret << endl;
  }
}