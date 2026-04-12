#include <bits/stdc++.h>
using namespace std;

template<class T> struct dinic {
  struct edge {
    int to, rev;
    T cap;
  };
  static constexpr T inf = numeric_limits<T>::max();
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
  int n, m;
  while (cin >> n >> m, n) {
    vector<int> u(m), v(m);
    for (int i = 0; i < m; ++i) {
      cin >> u[i] >> v[i];
      --u[i], --v[i];
    }
    auto chk = [&](int lower, int upper) {
      int s = n + m, t = s + 1, ss = t + 1, tt = ss + 1;
      dinic<int> g(tt + 1);
      vector<int> b(ss);
      auto add = [&](int from, int to, int lcap, int ucap) {
        g.add(from, to, ucap - lcap);
        b[to] += lcap;
        b[from] -= lcap;
      };
      for (int i = 0; i < m; ++i) {
        add(s, i, 1, 1);
        add(i, m + u[i], 0, 1);
        add(i, m + v[i], 0, 1);
      }
      for (int j = 0; j < n; ++j) {
        add(m + j, t, lower, upper);
      }
      add(t, s, m, m);
      for (int i = 0; i < ss; ++i) {
        g.add(ss, i, max(+b[i], 0));
        g.add(i, tt, max(-b[i], 0));
      }
      g.max_flow(ss, tt);
      for (auto&& e : g.g[ss]) {
        if (e.cap) {
          return false;
        }
      }
      return true;
    };
    [&] {
      for (int d = 0; ; ++d) {
        for (int l = m / n; l >= 0; --l) {
          if (chk(l, l + d)) {
            cout << l << ' ' << l + d << '\n';
            return;
          }
        }
      }
    }();
  }
}

