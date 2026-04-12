
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX_N = 100000;
int N;
int x[MAX_N], y[MAX_N];

struct edge {
  int cost, u, v;
  edge(int c, int a, int b) {
    cost = c; u = a; v = b;
  }
};

bool comp(edge& e1, edge& e2) {
  return e1.cost < e2.cost;
}

static const int MAX_UF = MAX_N;

template <class T> class UnionFind {
private:
  T par[MAX_UF];
  T rank[MAX_UF];
  
public:
  T find(T x);
  void init(T n);
  void unite(T x, T y);
  bool same (T x, T y);
};

template <class T> void UnionFind<T>::init(T n) {
  for (T i = 0; i < n; ++i) {
    par[i] = i;
    rank[i] = 0;
  }
}

template <class T> T UnionFind<T>::find(T x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

template <class T> void UnionFind<T>::unite(T x, T y) {
  x = find(x); y = find(y);
  if (x == y) {
    return;
  } else {
    if (rank[x] > rank[y]) {
      par[y] = x;
    } else {
      par[x] = y;
      if (rank[x] == rank[y]) ++rank[y];
    }
  }
}

template <class T> bool UnionFind<T>::same(T x, T y) {
  return find(x) == find(y);
}

int main() {
  cin >> N;
  rep(i,N) cin >> x[i] >> y[i];
  vector<pii> vx, vy;
  rep(i,N) {
    vx.push_back(pii(x[i], i));
    vy.push_back(pii(y[i], i));
  }

  sort(all(vx)); sort(all(vy));

  vector<edge> evx, evy;
  for (int i = 0; i < N-1; ++i) {
    evx.push_back(edge(vx[i+1].fi-vx[i].fi, vx[i+1].sc, vx[i].sc));
    evy.push_back(edge(vy[i+1].fi-vy[i].fi, vy[i+1].sc, vy[i].sc));
  }

  sort(all(evx), comp); sort(all(evy), comp);
  

  ll ans = 0;
  UnionFind<int> uf;
  uf.init(N);
  int indx = 0, indy = 0;
  while (indx < N || indy < N) {
    if (indx == N) {
      if (uf.same(evy[indy].u, evy[indy].v)) {
        ++indy;
      } else {
        ans += evy[indy].cost;
        uf.unite(evy[indy].u, evy[indy].v);
        ++indy;
      }
      continue;
    }

    if (indy == N) {
      if (uf.same(evx[indx].u, evx[indx].v)) {
        ++indx;
      } else {
        ans += evx[indx].cost;
        uf.unite(evx[indx].u, evx[indx].v);
        ++indx;
      }
      continue;
    }

    if (comp(evx[indx], evy[indy])) {
      if (uf.same(evx[indx].u, evx[indx].v)) {
        ++indx;
      } else {
        ans += evx[indx].cost;
        uf.unite(evx[indx].u, evx[indx].v);
        ++indx;
      }
      continue;
    } else {
      if (uf.same(evy[indy].u, evy[indy].v)) {
        ++indy;
      } else {
        ans += evy[indy].cost;
        uf.unite(evy[indy].u, evy[indy].v);
        ++indy;
      }
      continue;
    }
  }

  cout << ans << endl;

  return 0;
}
