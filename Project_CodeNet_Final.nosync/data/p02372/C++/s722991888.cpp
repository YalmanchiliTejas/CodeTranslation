#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  struct Edge { int to, w; };
  VV<Edge> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int s, t, w; cin >> s >> t >> w;
    g[s].push_back({t, w});
    g[t].push_back({s, w});
  }
  V<> d(n, -1);
  d[0] = 0;
  auto dfs = [&](auto dfs, int v, V<>& d) -> void {
    for (const auto& e : g[v]) if (d[e.to] == -1) {
      d[e.to] = d[v] + e.w;
      dfs(dfs, e.to, d);
    }
  };
  dfs(dfs, 0, d);
  int v0 = distance(begin(d), max_element(begin(d), end(d)));
  V<> d0(n, -1);
  d0[v0] = 0;
  dfs(dfs, v0, d0);
  int v1 = distance(begin(d0), max_element(begin(d0), end(d0)));
  V<> d1(n, -1);
  d1[v1] = 0;
  dfs(dfs, v1, d1);
  for (int i = 0; i < n; ++i) cout << max(d0[i], d1[i]) << '\n';
}
