/**
 *  author: ivanzuki   
 *  created: Sun Sep 13 2020
**/
#include <bits/stdc++.h>

using namespace std;

class DSU {
 public:
  int n;
  vector<int> parent;

  DSU(int _n) : n(_n) {
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (x == parent[x]) {
      return x;
    }
    return parent[x] = find(parent[x]);
  }

  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) {
      return false;
    }
    parent[x] = y;
    return true;
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n), order(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    order[i] = i;
  }
  sort(order.begin(), order.end(), [&](int i, int j) {
    return x[i] < x[j];
  });
  int j = -1;
  vector<pair<int, pair<int, int>>> edges; 
  for (int i : order) {
    if (j > -1) {
      if (x[i] - x[j] <= abs(y[i] - y[j])) {
        edges.push_back(make_pair(x[i] - x[j], make_pair(i, j)));
      }
    }
    j = i;
  }
  sort(order.begin(), order.end(), [&](int i, int j) {
    return y[i] < y[j];
  });
  j = -1;
  for (int i : order) {
    if (j > -1) {
      if (y[i] - y[j] <= abs(x[i] - x[j])) {
        edges.push_back(make_pair(y[i] - y[j], make_pair(i, j)));
      }
    }
    j = i;
  }
  sort(edges.begin(), edges.end());
  long long ans = 0;
  DSU dsu(n);
  for (auto& e : edges) {
    int w = e.first, i = e.second.first, j = e.second.second;
    if (dsu.merge(i, j)) {
      ans += w;
    }
  }
  cout << ans << '\n';
  return 0;
}