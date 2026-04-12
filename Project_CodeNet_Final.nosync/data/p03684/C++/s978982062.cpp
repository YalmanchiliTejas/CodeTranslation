#include <bits/stdc++.h>
using namespace std;

struct Kruskal {
  Kruskal() {}
  Kruskal(int n) {
    init(n);
  }

  struct UnionFind {
    vector<int> p, r;

    UnionFind() {}
    UnionFind(int size) {
      init(size);
    }

    void init(int size) {
      p.resize(size);
      r.resize(size);
      for (int i = 0; i < size; ++i) {
        p[i] = i;
        r[i] = 1;
      }
    }

    int root(int x) {
      if (p[x] == x)
        return x;
      else
        return p[x] = root(p[x]);
    }

    void unite(int x, int y) {
      x = root(x);
      y = root(y);

      if (x == y) return;

      if (r[x] > r[y]) swap(x, y);
      r[x] += r[y];
      p[y] = x;
    }

    bool same(int x, int y) {
      return root(x) == root(y);
    }
  };

  struct edges {
    edges() {}
    edges(int u, int v, int64_t cost) : u(u), v(v), cost(cost) {}
    bool operator<(const edges &e) const {
      return cost < e.cost;
    }

    int u, v;
    int64_t cost;
  };

  struct edge {
    edge() {}
    edge(int to, int64_t cost) : to(to), cost(cost) {}

    int to;
    int64_t cost;
  };

  vector<edges> E;
  vector<vector<edge>> G;

  void init(int n) {
    G.resize(n + 1);
  }

  void add(int u, int v, int64_t cost) {
    // cerr << u << " <-" << cost << "-> " << v << endl;
    E.push_back(edges(u, v, cost));
  }

  void make_graph(edges e) {
    G[e.u].push_back(edge(e.v, e.cost));
    G[e.v].push_back(edge(e.u, e.cost));
  }

  int64_t kruskal(int n) {
    int64_t res = 0;
    UnionFind uf(n + 1);

    sort(E.begin(), E.end());
    for (auto &e : E) {
      if (!uf.same(e.u, e.v)) {
        res += e.cost;
        uf.unite(e.u, e.v);
        make_graph(e);
      }
    }

    return res;
  }

  int64_t kruskal() {
    return kruskal(G.size());
  }
};

int main() {
  int n;
  cin >> n;

  vector<pair<pair<int, int>, int>> a, b;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;

    a.push_back(make_pair(make_pair(x, y), i));
    b.push_back(make_pair(make_pair(y, x), i));
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  Kruskal G(n);
  for (int i = 1; i < n; ++i) {
    G.add(a[i - 1].second, a[i].second, abs(a[i].first.first - a[i - 1].first.first));
    G.add(b[i - 1].second, b[i].second, abs(b[i].first.first - b[i - 1].first.first));
  }

  cout << G.kruskal() << endl;
}
