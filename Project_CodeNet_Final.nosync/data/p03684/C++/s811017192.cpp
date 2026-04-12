#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

using int64 = long long;

class UnionFind {
 public:
  UnionFind(int64 n) : par_(n), sizes_(n, 1) {
    for (int64 i = 0; i < n; ++i) {
      par_[i] = i;
    }
  }

  int64 find(int64 x) {
    if (x == par_[x])
      return x;
    return par_[x] = find(par_[x]);
  }

  void unite(int64 x, int64 y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;

    if (sizes_[x] < sizes_[y])
      swap(x, y);

    par_[y] = x;
    sizes_[x] += sizes_[y];
  }

  int64 size(int64 x) {
    x = find(x);
    return sizes_[x];
  }

 private:
  vector<int64> par_;
  vector<int64> sizes_;
};

struct Town {
  int64 x, y, i;
};
struct Route {
  int64 i, j, dist;
};

int main() {
  int64 n;
  cin >> n;
  vector<Town> towns(n);
  for (int64 i = 0; i < n; ++i) {
    cin >> towns[i].x >> towns[i].y;
    towns[i].i = i;
  }

  vector<Route> routes;
  sort(towns.begin(), towns.end(), [](const Town& a, const Town& b) {
      if (a.x == b.x) return a.y < b.y;
      return a.x < b.x;
    });
  for (int i = 1; i < n; ++i) {
    int64 d = towns[i].x - towns[i - 1].x;
    Route r {towns[i].i, towns[i-1].i, d};
    routes.push_back(r);
  }
  sort(towns.begin(), towns.end(), [](const Town& a, const Town& b) {
      if (a.y == b.y) return a.x < b.x;
      return a.y < b.y;
    });
  for (int i = 1; i < n; ++i) {
    int64 d = towns[i].y - towns[i - 1].y;
    Route r {towns[i].i, towns[i-1].i, d};
    routes.push_back(r);
  }
  sort(routes.begin(), routes.end(), [](const Route& a, const Route& b) {
      return a.dist < b.dist;
    });

  UnionFind uf(n);
  int64 ret = 0;
  for (auto& r : routes) {
    if (uf.find(r.i) == uf.find(r.j))
      continue;
    uf.unite(r.i, r.j);
    ret += r.dist;
  }
  cout << ret << "\n";

  return 0;
}
