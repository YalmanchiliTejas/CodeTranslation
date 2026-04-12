#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

struct UnionFind {
  vector<ll> par; 
  vector<ll> siz; 

    
  UnionFind(ll sz_): par(sz_), siz(sz_, 1) {
    for (ll i = 0; i < sz_; ++i) par[i] = i; 
  }
  void init(ll sz_) {
    par.resize(sz_);
    siz.resize(sz_, 1);
    for (ll i = 0; i < sz_; ++i) par[i] = i;
  }

  ll root(ll x) { 
    while (par[x] != x) {
      x = par[x] = par[par[x]];
    }
    return x;
  }

  bool merge(ll x, ll y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    return true;
  }

  bool issame(ll x, ll y) {
    return root(x) == root(y);
  }

  ll size(ll x) {
    return siz[root(x)];
  }
};

ll n, m;

void solve() {
  UnionFind uf(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    uf.merge(a, b);
  }
  ll ans = 1, ok = 0;
  vector<bool> visited(n, false);
  rep(i, n) {
    int v = uf.root(i);
    if (visited[v]) continue;
    visited[v] = true;
    ans = (ans * 2) % mod;
    if (uf.size(v) > 1) ok = 1;
  }
  ans = (ans + ok) % mod;
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  while (cin >> n >> m, n || m) {
    solve();
  }

  




  
  return 0;
}
