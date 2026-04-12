#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T, bool Scaling = false> struct dinic {
  struct edge {
    int to;
    T cap;
  };
  static constexpr inline T inf = numeric_limits<T>::max(), eps = 1e-10;
  int n, s, t;
  vector<edge> es;
  vector<vector<int>> g;
  T scale;
  vector<int> h, ptr;
  dinic(int _n, int _s, int _t) : n(_n), s(_s), t(_t), g(n), h(n), ptr(n) {}
  void add(int from, int to, T cap, T rev_cap = 0) {
    g[from].push_back(size(es)), es.push_back({to, cap});
    g[to].push_back(size(es)), es.push_back({from, rev_cap});
  }
  bool bfs() {
    static vector<int> que(n);
    fill(begin(h), end(h), -1);
    h[t] = 0, que[0] = t;
    for (int bg = 0, ed = 1; bg < ed; ) {
      int v = que[bg++];
      for (int id : g[v])
        if (es[id ^ 1].cap > scale and h[es[id].to] == -1) {
          h[es[id].to] = h[v] + 1, que[ed++] = es[id].to;
          if (es[id].to == s) return true;
        }
    }
    return false;
  }
  T dfs(int v, T f) {
    if (v == t) return f;
    for (int& i = ptr[v]; i >= 0; --i) {
      int id = g[v][i];
      if (es[id].cap > scale and h[v] > h[es[id].to])
        if (T df = dfs(es[id].to, min(f, es[id].cap)); df > eps)
          return es[id].cap -= df, es[id ^ 1].cap += df, df;
    }
    return 0;
  }
  T max_flow() {
    T flow = 0, max_cap = 0;
    for (auto&& e : es) max_cap = max(max_cap, e.cap);
    for (scale = Scaling ? max_cap / 2 : eps; ; scale /= 2) {
      while (bfs()) {
        for (int v = 0; v < n; ++v) ptr[v] = (int)size(g[v]) - 1;
        for (T df; (df = dfs(s, inf)) > eps; ) flow += df;
      }
      if (scale <= eps) break;
    }
    return flow;
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
    int s = 2 * n, t = 2 * n + 1;
    dinic<int, true> g(2 * n + 4, 2 * n + 2, 2 * n + 3);
    vector b(2 * n + 2, 0);
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
    for (int v = 0; v < 2 * n + 2; ++v) {
      g.add(g.s, v, max(+b[v], 0));
      g.add(v, g.t, max(-b[v], 0));
    }
    g.max_flow();
    for (int id : g.g[g.s]) {
      if (g.es[id].cap) {
        cout << "-1\n";
        exit(0);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int id : g.g[i]) {
        int j = g.es[id].to - n;
        if (j < 0 or j >= n) {
          continue;
        }
        if (g.es[id].cap == 0) {
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
