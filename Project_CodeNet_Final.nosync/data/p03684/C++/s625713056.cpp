#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<bool> db;
template<class T> using vv=vector<vector< T > >;

struct UF {
  vector<int> par; // parent
  vector<int> sizes;
  UF(int n) : par(n), sizes(n, 1) {
    for (int i = 0; i < n; ++i) {
      par[i] = i;
    }
  }
  int root(int x) {
    if (x == par[x]) {
      return x;
    }
    return par[x] = root(par[x]);
  }
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) {
      return;
    }
    if (sizes[x] < sizes[y]) {
      swap(x, y);
    }
    par[y] = x;
    sizes[x] += sizes[y];
    sizes[y] = 0;
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  int size(int x) {
    return sizes[root(x)];
  }
};

vvi g;

int main() {
  int n;
  scanf("%d", &n);
  vector<pii> x(n), y(n);
  rep (i, n) {
    scanf("%d %d", &x[i].first, &y[i].first);
    x[i].second = y[i].second = i;
  }

  sort(all(x));
  sort(all(y));
  rep (i, n-1) {
    vi xedge = {x[i+1].first - x[i].first, x[i].second, x[i+1].second};
    g.push_back(xedge);
    vi yedge = {y[i+1].first - y[i].first, y[i].second, y[i+1].second};
    g.push_back(yedge);
  }

  sort(all(g));
  UF uf(n);
  ll cost = 0;
  rep (i, 2*n-2) {
    if (uf.same(g[i][1], g[i][2])) {
      continue;
    }
    cost += g[i][0];
    uf.unite(g[i][1], g[i][2]);
  }
  printf("%lld\n", cost);

  return 0;
}
