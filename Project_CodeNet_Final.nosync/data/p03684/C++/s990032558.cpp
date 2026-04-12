#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
  
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
  
using namespace std;
  
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
  
const int INF=1<<29;
const double EPS=1e-9;
  
const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

const int mod = 1e9 + 7;

struct Point {
  int x, y;
  int ind;
};

struct Edge {
  int a, b;
  int cost;
  bool operator>(const Edge &rhs) const {
    return cost > rhs.cost;
  }
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
  vector<Point> P(N), PX, PY;
  for (int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    P[i] = (Point){x, y, i};
  }
  PX = PY = P;
  sort(PX.begin(), PX.end(), [](Point a, Point b){return a.x < b.x;});
  sort(PY.begin(), PY.end(), [](Point a, Point b){return a.y < b.y;});

  priority_queue<Edge, vector<Edge>, greater<Edge>> Q;
  for (int i = 0; i < N - 1; i++) {
    Q.push((Edge){PX[i].ind, PX[i + 1].ind, PX[i + 1].x - PX[i].x});
    Q.push((Edge){PY[i].ind, PY[i + 1].ind, PY[i + 1].y - PY[i].y});
  }

  UnionFind uf(N);
  ll ans = 0;
  while(!Q.empty()) {
    Edge e = Q.top(); Q.pop();
    if (uf.findSet(e.a, e.b)) continue;
    uf.unionSet(e.a, e.b);
    ans += e.cost;
  }

  cout << ans << endl;

  return 0;
}