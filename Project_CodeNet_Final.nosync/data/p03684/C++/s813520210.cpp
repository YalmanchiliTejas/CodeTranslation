#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define rep(X, S, E) for (int(X) = (S); (X) < (E); ++(X))
#define rrep(X, S, E) for (int(X) = (E)-1; (X) >= (S); --(X))
#define itrep(X, Y) for (auto(X) = (Y).begin(); (X) != (Y).end(); (X)++)
#define all(X) (X).begin(), (X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define print(x) cout << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef priority_queue<ll, vl> decendingQueue;              //降順
typedef priority_queue<ll, vl, greater<ll>> ascendingQueue; //昇順
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll INF = 9 * 1e18;
const ll MOD = 1e9 + 7;

class UnionFindTree {
private:
  vector<int> par;
  vector<int> rnk;
  vector<int> siz;

public:
  UnionFindTree(int n) {
    par.assign(n, -1);
    rnk.assign(n, -1);
    siz.assign(n, -1);

    for (int i = 0; i < n; ++i) {
      par[i] = i;
      rnk[i] = 0;
      siz[i] = 1;
    }
  }

  int find(int x) {
    if (par[x] == x)
      return x;
    else
      return par[x] = find(par[x]);
  }

  bool same(int x, int y) { return find(x) == find(y); }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    if (rnk[x] < rnk[y]) {
      par[x] = y;
      siz[y] += siz[x];
    } else {
      par[y] = x;
      siz[x] += siz[y];
      if (rnk[x] == rnk[y])
        ++rnk[x];
    }
  }

  int size(int x) {
    x = find(x);
    return siz[x];
  }
};

class T {
public:
  ll from;
  ll to;
  ll cost;

  T(ll from, ll to, ll cost) {
    this->from = from;
    this->to = to;
    this->cost = cost;
  }
};

// 昇順ソート
bool cmp(const T &a, const T &b) { return a.cost < b.cost; }

void solve(long long N, std::vector<long long> x, std::vector<long long> y) {
  vector<pll> xi;
  vector<pll> yi;
  rep(i, 0, N) {
    xi.push_back(mp(x[i], i));
    yi.push_back(mp(y[i], i));
  }

  sort(all(xi));
  sort(all(yi));

  vector<T> edges;
  rep(i, 0, N - 1) {
    ll xi1 = xi[i].sc;
    ll xi2 = xi[i + 1].sc;
    ll cost = min(abs(x[xi1] - x[xi2]), abs(y[xi1] - y[xi2]));
    edges.push_back(T(xi1, xi2, cost));

    ll yi1 = yi[i].sc;
    ll yi2 = yi[i + 1].sc;
    cost = min(abs(x[yi1] - x[yi2]), abs(y[yi1] - y[yi2]));
    edges.push_back(T(yi1, yi2, cost));
  }

  // 最小全域木(クラスカル法)
  UnionFindTree uf(N);
  ll ans = 0;
  sort(all(edges), cmp);
  rep(i, 0, edges.size()) {
    ll from = edges[i].from;
    ll to = edges[i].to;
    ll cost = edges[i].cost;

    if (!uf.same(from, to)) {
      uf.unite(from, to);
      ans += cost;
    }
  }

  print(ans);
}

int main() {
  long long N;
  scanf("%lld", &N);
  std::vector<long long> x(N);
  std::vector<long long> y(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &x[i]);
    scanf("%lld", &y[i]);
  }
  solve(N, std::move(x), std::move(y));
  return 0;
}
