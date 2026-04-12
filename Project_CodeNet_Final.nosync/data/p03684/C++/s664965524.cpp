#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define fst first
#define snd second

/* clang-format off */
template <class T, size_t D> struct _vec { using type = vector<typename _vec<T, D - 1>::type>; };
template <class T> struct _vec<T, 0> { using type = T; };
template <class T, size_t D> using vec = typename _vec<T, D>::type;
template <class T> vector<T> make_v(size_t size, const T& init) { return vector<T>(size, init); }
template <class... Ts> auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }
/* clang-format on */

using P = pair<ll, int>;

struct UnionFind {
  vector<int> parent;  // parent[root] is the negative of the size.
  UnionFind(int n)
      : parent(n, -1){};
  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (parent[u] > parent[v]) swap(u, v);
    parent[u] += parent[v];
    parent[v] = u;
    return true;
  }
  bool find(int u, int v) {
    return root(u) == root(v);
  }
  int root(int u) {
    return parent[u] < 0 ? u : parent[u] = root(parent[u]);
  }
  int size(int u) {
    return -parent[root(u)];
  }
};

template <class Compare>
void push(vector<P>& ps, P x, Compare cmp) {
  bool found = false;
  for (auto& y : ps) {
    if (y.snd == x.snd) {
      found = true;
      if (cmp(x, y))
        y = x;
    }
  }
  if (!found) ps.push_back(x);
  sort(ps.begin(), ps.end(), cmp);
  if (ps.size() > 2)
    ps.resize(2);
}

template <class T, class Compare>
void func(vector<P>& cheapest, UnionFind& uf, T bg, T ed, Compare cmp) {
  vector<P> ps;
  while (bg != ed) {
    auto now = *bg++;
    ll x = now.fst;
    int r = uf.root(now.snd);
    for (auto p : ps) {
      if (p.snd != r)
        cheapest[r] = min(cheapest[r], P(abs(x - p.fst), p.snd));
    }
    push(ps, P(x, r), cmp);
  }
}

const ll INF = 1ll << 60;

int main() {
  int N;
  while (cin >> N) {
    vector<P> xs, ys;
    for (int i = 0; i < N; i++) {
      ll x, y;
      cin >> x >> y;
      xs.emplace_back(x, i);
      ys.emplace_back(y, i);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    UnionFind uf(N);
    int components = N;
    ll res = 0;
    while (components >= 2) {
      vector<P> cheapest(N, P(INF, -1));
      func(cheapest, uf, xs.begin(), xs.end(), greater<P>());
      func(cheapest, uf, xs.rbegin(), xs.rend(), less<P>());
      func(cheapest, uf, ys.begin(), ys.end(), greater<P>());
      func(cheapest, uf, ys.rbegin(), ys.rend(), less<P>());
      for (int r = 0; r < N; r++) {
        if (cheapest[r].fst >= INF)
          continue;
        if (uf.unite(r, cheapest[r].snd)) {
          res += cheapest[r].fst;
          --components;
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}
