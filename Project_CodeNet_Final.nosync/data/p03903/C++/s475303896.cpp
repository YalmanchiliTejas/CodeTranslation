#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef vector<char> vc;
typedef vector<vector<char> > vvc;
typedef vector<double> vd;
typedef vector<vector<double> > vvd;
template<class T> using vv=vector<vector< T > >;
typedef deque<int> di;
typedef deque<deque<int> > ddi;
typedef deque<bool> db;
typedef deque<deque<bool> > ddb;

// cout pair
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {
  s << p.first << " " << p.second << "\n"; return s;
}

// cout vector<pair>
template<typename T1, typename T2> ostream& operator<<(ostream& s, const vector<pair<T1, T2> >& vp) {
  int len = vp.size(); s << "\n";
  for (int i = 0; i < len; ++i) { s << vp[i]; }
    s << "\n"; return s;
}

// cout vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size(); s << "\n";
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  s << "\n"; return s;
}

// cout deque
template<typename T> ostream& operator<<(ostream& s, const deque<T>& v) {
  int len = v.size(); s << "\n";
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  s << "\n"; return s;
}

// cout 2-dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) { s << vv[i]; }
  return s;
}

// cout 2-dimentional deque
template<typename T> ostream& operator<<(ostream& s, const deque< deque<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) { s << vv[i]; }
  return s;
}

struct UF {
  vector<int> par; // parent
  vector<int> sizes;
  vector<int> next;
  vector<int> last;
  UF(int n) : par(n), sizes(n, 1), next(n, -1), last(n) {
    for (int i = 0; i < n; ++i) {
      par[i] = i;
      last[i] = i;
    }
  }
  int root(int x) {
    if (x == par[x]) return x;
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
    next[last[x]] = y;
    last[x] = last[y];
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  int size(int x) {
    return sizes[root(x)];
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vvi edge(m, vi(3));
  rep (i, m) {
    cin >> edge[i][1] >> edge[i][2] >> edge[i][0];
    edge[i][1] -= 1; edge[i][2] -= 1;
  }
  sort(all(edge));
  UF uf(n);
  vvi maxcost(n, vi(n));
  ll cost = 0;
  cost += edge[0][0];
  uf.unite(edge[0][1], edge[0][2]);
  maxcost[edge[0][1]][edge[0][2]] = maxcost[edge[0][2]][edge[0][1]] = edge[0][0];
  FOR (i, 1, m) {
    int x = edge[i][1];
    int y = edge[i][2];
    if (!(uf.same(x, y))) {
      cost += edge[i][0];
      for (int j = uf.root(x); j != -1; j = uf.next[j]) {
        for (int k = uf.root(y); k != -1; k = uf.next[k]) {
          maxcost[j][k] = maxcost[k][j] = edge[i][0];
        }
      }
      uf.unite(x, y);
    }
  }

  int q;
  cin >> q;
  vll ans(q, 0);
  rep (j, q) {
    int s, t;
    cin >> s >> t;
    s -= 1; t -= 1;
    ans[j] = cost - maxcost[s][t];
  }
  rep (i, q) {
    printf("%lld\n", ans[i]);
  }

  return 0;
}
