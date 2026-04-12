#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// c++11
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#define mp make_pair
#define mt make_tuple
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1 << 29;
const double EPS = 1e-9;
const ll MOD = 1000000007;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int N;
vector<pair<pii, int>> XY,YX;
priority_queue<pair<int, pii>> pque;
//UnionFind
class UnionFind {
public:
  UnionFind(int size_) : parent(size_, -1), __size(size_) {}
  void unite(int x, int y) {
    if ((x = find(x)) != (y = find(y))) {
      if (parent[y] < parent[x])
        std::swap(x, y);
      parent[x] += parent[y];
      parent[y] = x;
      __size--;
    }
  }
  bool is_parent(int x) { return find(x) == x; }
  bool is_same(int x, int y) { return find(x) == find(y); }
  int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
  int size(int x) { return -parent[find(x)]; }
  int size() const { return __size; }

private:
  std::vector<int> parent;
  int __size;
};
//UnionFind

int main() {

    cin >> N;
    UnionFind ut(N);
    for (int i = 0; i < N; i++){
        int x,y;
        cin >> x >> y;
        XY.emplace_back(mp(mp(x, y), i));
        YX.emplace_back(mp(mp(y, x), i));
    }
    sort(XY.begin(), XY.end());
    sort(YX.begin(), YX.end());
    for (int i = 0; i < N-1; i++){

        int px,py,pi;
        int qx,qy,qi;
        //XY
        px = XY[i].first.first;
        py = XY[i].first.second;
        pi = XY[i].second;

        qx = XY[i + 1].first.first;
        qy = XY[i + 1].first.second;
        qi = XY[i + 1].second;
        int cost = abs(px - qx);
        pque.emplace(mp(-cost, mp(pi, qi)));
    }
    for (int i = 0; i < N-1; i++){

        int px,py,pi;
        int qx,qy,qi;
        //XY
        px = YX[i].first.second;
        py = YX[i].first.first;
        pi = YX[i].second;

        qx = YX[i + 1].first.second;
        qy = YX[i + 1].first.first;
        qi = YX[i + 1].second;
        int cost = abs(py - qy);
        pque.emplace(mp(-cost, mp(pi, qi)));
    }
    ll res = 0;
    while (ut.size(0) != N){
        auto p = pque.top();
        pque.pop();
        int cost = p.first;
        cost *= -1;
        int pi,qi;
        pi = p.second.first;
        qi = p.second.second;
        if (not ut.is_same(pi, qi)){
            ut.unite(pi, qi);
            res += cost;
        }
    }
    cout << res << endl;
   return 0;
 }
