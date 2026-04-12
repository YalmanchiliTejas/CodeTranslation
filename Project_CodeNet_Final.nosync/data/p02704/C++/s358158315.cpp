#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> struct dinic {
  struct edge {
    int to, rev;
    T cap;
  };
  const T inf = numeric_limits<T>::max();
  vector<vector<edge>> g;
  vector<int> dist, i;
  dinic(int n) : g(n), dist(n), i(n) {}
  void add(int from, int to, T cap, bool directed = true) {
    assert(cap >= 0);
    if (from == to or cap == 0) return;
    g[from].push_back({to, (int)g[to].size(), cap});
    g[to].push_back({from, (int)g[from].size() - 1, directed ? 0 : cap});
  }
  void bfs(int s) {
    fill(begin(dist), end(dist), -1);
    queue<int> que;
    dist[s] = 0, que.push(s);
    while (not que.empty()) {
      int v = que.front();
      que.pop();
      for (auto&& e : g[v])
        if (e.cap and dist[e.to] == -1)
          dist[e.to] = dist[v] + 1, que.push(e.to);
    }
  }
  T dfs(int v, int s, T f) {
    if (v == s) return f;
    for (; i[v] < (int)g[v].size(); ++i[v]) {
      edge &e = g[v][i[v]];
      if (g[e.to][e.rev].cap and dist[e.to] < dist[v])
        if (T d = dfs(e.to, s, min(f, g[e.to][e.rev].cap)))
          return g[e.to][e.rev].cap -= d, e.cap += d, d;
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
      while (T f = dfs(t, s, inf)) res += f;
    }
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector or_row(n, 0), or_col(n, 0);
  for (auto&& e : or_row) cin >> e;
  for (auto&& e : or_col) cin >> e;
  vector row(n, 0uLL), col(n, 0uLL);
  for (auto&& e : row) cin >> e;
  for (auto&& e : col) cin >> e;
  vector res(n, vector(n, 0uLL));
  for (int k = 0; k < 64; ++k) {
    int s = 2 * n, t = s + 1, ss = t + 1, tt = ss + 1;
    dinic<int> g(tt + 1);
    vector b(ss, 0);
    auto add = [&](int from, int to, int lcap, int ucap) {
      g.add(from, to, ucap - lcap);
      b[from] -= lcap;
      b[to] += lcap;
    };
    for (int i = 0; i < n; ++i) {
      if (or_row[i]) {
        if (row[i] >> k & 1) {
          add(s, i, 1, n);
        } else {
          add(s, i, 0, 0);
        }
      } else {
        if (row[i] >> k & 1) {
          add(s, i, n, n);
        } else {
          add(s, i, 0, n - 1);
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      if (or_col[j]) {
        if (col[j] >> k & 1) {
          add(n + j, t, 1, n);
        } else {
          add(n + j, t, 0, 0);
        }
      } else {
        if (col[j] >> k & 1) {
          add(n + j, t, n, n);
        } else {
          add(n + j, t, 0, n - 1);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        add(i, n + j, 0, 1);
      }
    }
    add(t, s, 0, n * n);
    for (int v = 0; v < ss; ++v) {
      g.add(ss, v, max(+b[v], 0));
      g.add(v, tt, max(-b[v], 0));
    }
    g.max_flow(ss, tt);
    for (auto&& e : g.g[ss]) {
      if (e.cap) {
        cout << "-1\n";
        exit(0);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (auto&& e : g.g[i]) {
        int j = e.to - n;
        if (j < 0 or j >= n) {
          continue;
        }
        if (e.cap == 0) {
          res[i][j] |= 1uLL << k;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << res[i][j] << " \n"[j == n - 1];
    }
  }
}
