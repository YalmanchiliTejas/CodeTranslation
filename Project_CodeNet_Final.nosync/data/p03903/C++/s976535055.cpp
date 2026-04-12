//#include <bits/stdc++.h>

#include <iostream>
#include <algorithm>

#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <string>
#include <utility>
#include <array>
#include <complex>
#include <valarray>

#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <chrono>
#include <random>
#include <numeric>


using namespace std;
#define int long long

typedef long long ll;
typedef unsigned long long ull;
//typedef unsigned __int128 HASH;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pullull;
typedef pair<ll,int> plli;
typedef pair<long double, int> pdbi;
typedef pair<int,pii> pipii;
typedef pair<ll,pll> plpll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
typedef vector<vector<int>> mat;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

const ll hmod1 = 999999937;
const ll hmod2 = 1000000000 + 9;
const int INF = 1<<30;
const ll INFLL = 1LL<<62;
const long double EPS = 1e-12;
const ll mod = 1000000000 + 7;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const long double pi = 3.141592653589793;

#define addm(X, Y) (X) = ((X) + ((Y) % mod) + mod) % mod
#define inside(y, x, h, w) (0 <= (y) && (y) < (h) && 0 <= (x) && (x) < (w)) ? true : false

//debug
#define DEBUG

#define DUMPOUT cout

#ifdef DEBUG
#define dump(...) DUMPOUT<<#__VA_ARGS__<<" :["<<__FUNCTION__<<":"<<__LINE__<<"]"<<endl; DUMPOUT<<"    "; dump_func(__VA_ARGS__)
#else
#define dump(...)
#endif

void dump_func() {DUMPOUT << endl;};

template <class Head, class... Tail> void dump_func(Head&& head, Tail&&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) == 0) DUMPOUT << " ";
    else DUMPOUT << ", ";
    dump_func(std::move(tail)...);
}

//ostream
template<typename T> ostream& operator << (ostream& os, vector<T>& vec) {
    os << "["; for (int i = 0; i<vec.size(); i++) os << vec[i] << (i + 1 == vec.size() ? "" : ", "); os << "]";
    return os;
}

template<typename T, typename U> ostream& operator << (ostream& os, pair<T, U>& pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}

template<typename T, typename U> ostream& operator << (ostream& os, map<T, U>& map_var) {
    os << "[";
    for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {
        os << "(" << itr->first << ", " << itr->second << ")"; itr++;  if(itr != map_var.end()) os << ", "; itr--;
    }
    os << "]";
    return os;
}

template<typename T> ostream& operator << (ostream& os, set<T>& set_var) {
    os << "[";
    for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
        os << *itr; ++itr; if(itr != set_var.end()) os << ", "; itr--;
    }
    os << "]";
    return os;
}

int n, m;
int q;

struct edge{int cost, u, v;};
vector<edge> edges;
bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

int ans[4000][4000];

struct UnionFind {
  vector<int> par, rank;
  vector<vector<int>> cmp;
  UnionFind(int size) : par(size), rank(size), cmp(size)
  {
    rep(i, size) {
      par[i] = i;
      cmp[i].push_back(i);
    }
  }

  int find_root(int x) {
    if (par[x] != x) return par[x] = find_root(par[x]);
    else return x;
  }

  bool same(int x, int y) {
    return find_root(x) == find_root(y);
  }

  void unite(int x, int y, int c) {
    int u = find_root(x);
    int v = find_root(y);
    for (auto uu : cmp[u]) {
      for (auto vv : cmp[v]) {
        ans[uu][vv] = c;
        ans[vv][uu] = c;
      }
    }
    if (rank[u] > rank[v]) swap(u, v);
    par[u] = v;
    for (auto uu : cmp[u]) cmp[v].push_back(uu);
    if (rank[u] == rank[v]) rank[v]++;
  }
};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    edges.push_back({c, a, b});
  }

  sort(all(edges), comp);
  UnionFind uf(n);
  int sum_cost = 0LL;
  rep(i, m) {
    edge e = edges[i];
    if (uf.same(e.u, e.v)) continue;
    uf.unite(e.u, e.v, e.cost);
    sum_cost += e.cost;
  }

  cin >> q;
  rep(i, q) {
    int s, t;
    cin >> s >> t;
    s--; t--;
    cout << sum_cost - ans[s][t] << endl;
  }
}
