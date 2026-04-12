#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  VV<> g(n);
  V<> d(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    ++d[u];
    ++d[v];
  }
  queue<int> que;
  for (int v = 0; v < n; ++v) if (d[v] == 1) {
    que.push(v);
  }
  V<bool> b(n);
  while (!que.empty()) {
    int v = que.front(); que.pop();
    if (b[v]) continue;
    b[v] = true;
    int p;
    for (int w : g[v]) if (!b[w]) {
      p = w;
      break;
    }
    b[p] = true;
    for (int w : g[p]) if (!b[w]) {
      if (--d[w] == 0) return cout << "First" << '\n', 0;
      if (d[w] == 1) que.push(w);
    }
  }
  cout << "Second" << '\n';
}