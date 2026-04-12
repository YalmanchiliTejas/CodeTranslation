#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct UnionFind {
  vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

  UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
    for(int i = 0; i < N; i++)
      par[i] = i;
  }

  int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if(par[x] == x)
      return x;
    return par[x] = root(par[x]); // 根の付替
  }

  void unite(int x, int y) { // xとyの木を併合
    if(same(x, y))
      return; // xとyの根が同じ(=同じ木にある)時はそのまま
    par[root(x)] = root(y); // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
  }

  bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};
struct Town {
  int x;
  int y;
  int idx;
};

struct Route {
  int a;
  int b;
  int cost;
};

int main() {
  int N;
  cin >> N;
  vector<Town> towns(N);
  for(int i = 0; i < N; ++i) {
    cin >> towns[i].x >> towns[i].y;
    towns[i].idx = i;
  }
  vector<Route> routes;
  sort(towns.begin(), towns.end(), [](const auto& a, const auto& b) { return a.x < b.x; });
  for(int i = 0; i < N - 1; ++i) {
    routes.push_back({towns[i].idx, towns[i + 1].idx, abs(towns[i].x - towns[i + 1].x)});
  }
  sort(towns.begin(), towns.end(), [](const auto& a, const auto& b) { return a.y < b.y; });
  for(int i = 0; i < N - 1; ++i) {
    routes.push_back({towns[i].idx, towns[i + 1].idx, abs(towns[i].y - towns[i + 1].y)});
  }

  sort(routes.begin(), routes.end(), [](const auto& a, const auto& b) { return a.cost < b.cost; });
  /*
  for(auto& r : routes) {
    cout << r.a << " - " << r.b << " : " << r.cost << endl;
  }
  */
  UnionFind uf(N);
  long long totalCost = 0;
  for(auto& r : routes) {
    if(!uf.same(r.a, r.b)) {
      totalCost += r.cost;
      uf.unite(r.a, r.b);
    }
  }
  cout << totalCost << endl;
  return 0;
}