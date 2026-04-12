#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;

struct V {
  int index;
  ll x, y;
};
struct E {
  int v, u;
  ll cost;
};
struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

int main() {
  int N;
  cin >> N;
  vector<V> vs;
  for (int i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    vs.push_back(V{ i, x, y });
  }
  vector<E> es;
  sort(vs.begin(), vs.end(), [](const V &a, const V &b) {
    return a.x < b.x;
  });
  for (int i = 1; i < N; i++) {
    es.push_back(E{ vs[i-1].index, vs[i].index, vs[i].x - vs[i-1].x });
  }
  sort(vs.begin(), vs.end(), [](const V &a, const V &b) {
    return a.y < b.y;
  });
  for (int i = 1; i < N; i++) {
    es.push_back(E{ vs[i-1].index, vs[i].index, vs[i].y - vs[i-1].y });
  }
  sort(es.begin(), es.end(), [](const E &a, const E &b) {
    return a.cost < b.cost;
  });
  UnionFind uf(N);
  ll res = 0;
  for (const auto &e: es) {
    if (!uf.findSet(e.v, e.u)) {
      res += e.cost;
      uf.unionSet(e.v, e.u);
    }
  }
  cout << res << endl;
  return 0;
}
