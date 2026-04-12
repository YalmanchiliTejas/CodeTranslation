#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cstdint>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (size_t i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (size_t i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

struct UnionFind {
  vector<int> c, s;
  UnionFind(size_t n) : c(n), s(n, 1) { iota(begin(c), end(c), 0); }
  int root(int i) { return c[i] == i ? i : (c[i] = root(c[i])); }
  bool same(int i, int j) { return root(i) == root(j); }
  void unite(int i, int j) {
    i = root(i); j = root(j);
    if (i != j) {
      if (s[i] > s[j]) { c[j] = i; s[i] += s[j]; }
      else { c[i] = j; s[j] += s[i]; }
    }
  }
  int size(int i) { return s[root(i)]; }
};

i64 n, m;
using P = pair<i64, i64>;
vector<vector<P>> g;
vector<vector<i64>> mw;

void dfs(i64 r, i64 u, i64 b) {
  for (auto p : g[u]) {
    i64 v, c;
    tie(v, c) = p;
    if (v == b) continue;
    mw[r][v] = max(mw[r][u], c);
    dfs(r, v, u);
  }
}

int main() {
  cin >> n >> m;
  vector<tuple<i64, i64, i64>> es, tes;
  for (i64 i = 0; i < m; ++i) {
    i64 a, b, c;
    cin >> a >> b >> c;
    es.emplace_back(c, a, b);
  }
  sort(begin(es), end(es));
  UnionFind uf(n + 1);
  i64 csum = 0;
  for (i64 i = 0; tes.size() < n - 1; ++i) {
    auto t = es[i];
    i64 a, b, c;
    tie(c, a, b) = t;
    if (!uf.same(a, b)) {
      tes.emplace_back(c, a, b);
      csum += c;
      uf.unite(a, b);
    }
  }
  
  init_n(g, n + 1);
  for (auto e : tes) {
    i64 a, b, c;
    tie(c, a, b) = e;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }

  init_n(mw, n + 1, vector<i64>(n + 1));
  for (i64 r = 1; r <= n; ++r) {
    dfs(r, r, 0);
  }

  i64 q;
  cin >> q;
  while (q--) {
    i64 s, t;
    cin >> s >> t;
    cout << csum - mw[s][t] << '\n';
  }
  return 0;
}
