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
      for (auto&& e : g[v]) if (e.cap and dist[e.to] == -1)
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
  vector<int> x(n);
  for (auto&& e : x) {
    cin >> e;
  }
  vector<int> y(n);
  for (auto&& e : y) {
    cin >> e;
  }
  vector<uint64_t> u(n);
  for (auto&& e : u) {
    cin >> e;
  }
  vector<uint64_t> v(n);
  for (auto&& e : v) {
    cin >> e;
  }
  vector res(n, vector(n, 0uLL));
  for (int k = 0; k < 64; ++k) {
    int s = 2 * n, t = s + 1, ss = t + 1, tt = ss + 1;
    dinic<int> g(tt + 1);
    vector<int> b(t + 1);
    auto add = [&](int from, int to, int lb, int ub) {
      g.add(from, to, ub - lb);
      b[from] -= lb;
      b[to] += lb;
    };
    for (int i = 0; i < n; ++i) {
      if (x[i] == 0) {
        if (u[i] >> k & 1) {
          add(s, i, n, n);
        } else {
          add(s, i, 0, n - 1);
        }
      } else {
        if (u[i] >> k & 1) {
          add(s, i, 1, n);
        } else {
          add(s, i, 0, 0);
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      if (y[j] == 0) {
        if (v[j] >> k & 1) {
          add(n + j, t, n, n);
        } else {
          add(n + j, t, 0, n - 1);
        }
      } else {
        if (v[j] >> k & 1) {
          add(n + j, t, 1, n);
        } else {
          add(n + j, t, 0, 0);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        add(i, n + j, 0, 1);
      }
    }
    b[s] += n * n + 1;
    b[t] -= n * n + 1;
    int sum = 0;
    for (int i = 0; i < 2 * n + 2; ++i) {
      if (i < 2 * n) {
        sum += max(b[i], 0);
      }
      g.add(ss, i, max(b[i], 0));
      g.add(i, tt, max(-b[i], 0));
    }
    auto f = g.max_flow(ss, tt);
    for (int i = 0; i < n; ++i) {
      for (auto&& e : g.g[i]) {
        if (e.cap) {
          continue;
        }
        int j = e.to - n;
        if (0 <= j and j < n) {
          res[i][j] |= 1uLL << k;
        }
      }
    }
  }
  vector r0(n, -1uLL), r1(n, 0uLL), c0(n, -1uLL), c1(n, 0uLL);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      r0[i] &= res[i][j];
      r1[i] |= res[i][j];
      c0[j] &= res[i][j];
      c1[j] |= res[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (x[i] == 0 and r0[i] != u[i]) {
      cout << "-1\n";
      exit(0);
    }
    if (x[i] == 1 and r1[i] != u[i]) {
      cout << "-1\n";
      exit(0);
    }
  }
  for (int j = 0; j < n; ++j) {
    if (y[j] == 0 and c0[j] != v[j]) {
      cout << "-1\n";
      exit(0);
    }
    if (y[j] == 1 and c1[j] != v[j]) {
      cout << "-1\n";
      exit(0);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << res[i][j] << " \n"[j == n - 1];
    }
  }
}
