#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
class UnionFind {
private:
  int siz;
  vector<int> a;

public:
  UnionFind(int x) : a(x, -1) {}

  int root(int x) {
    return a[x] < 0 ? x : a[x] = root(a[x]);
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    siz--;
    if (a[x] > a[y]) swap(x, y);
    a[x] += a[y];
    a[y] =x;
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  int size(int x) {
    return -a[root(x)];
  }
};

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> in, x, y;
  for (int i = 0; i < n; i++) {
    int s, t;
    cin >> s >> t;
    in.emplace_back(s, t);
    x.emplace_back(s, i);
    y.emplace_back(t, i);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  vector<pair<int, pair<int, int>>> edge;
  for (int i = 0; i + 1 < n; i++) {
    int idx_x = x[i].second, idx_xx = x[i + 1].second;
    int idx_y = y[i].second, idx_yy = y[i + 1].second;
    edge.emplace_back(min(abs(in[idx_x].first - in[idx_xx].first), abs(in[idx_x].second - in[idx_xx].second)), make_pair(idx_x, idx_xx));
    edge.emplace_back(min(abs(in[idx_y].first - in[idx_yy].first), abs(in[idx_y].second - in[idx_yy].second)), make_pair(idx_y, idx_yy));
  }
  sort(edge.begin(), edge.end());
  long long ans = 0;
  UnionFind uf(n);
  for (int i = 0; i < (int) edge.size(); i++) {
    int u = edge[i].second.first, v = edge[i].second.second;
    if (uf.same(u, v)) continue;
    ans += edge[i].first;
    uf.unite(u, v);
  }
  cout << ans << endl;
  return 0;	
}