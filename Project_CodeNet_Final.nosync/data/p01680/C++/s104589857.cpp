#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RREP(i, n) for(int i=(int)(n);i>=0;--i)
#define RFOR(i, a, b) for(int i=(int)(a);i>=(int)(b);--i)
#define ALL(a) (a).begin(),(a).end()
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;

const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;

template<typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  REP(i, SZ(v)) {
    if (i) os << " ";
    os << v[i];
  }
  return os;
}

ll modpow(ll x, ll y) {
  ll res = 1;
  while (y > 0) {
    if (y & 1) {
      (res *= x) %= MOD;
    }
    (x *= x) %= MOD;
    y /= 2;
  }
  return res;
}

struct UnionFind {
  vi par;

  UnionFind(int n) {
    par.resize(n, -1);
  }

  int root(int x) {
    return par[x] < 0 ? x : par[x] = root(par[x]);
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);

    if(x == y) return;
    if(par[x] < par[y]) {
      swap(x, y);
    }

    par[y] += par[x];
    par[x] = y;
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  int size(int x) {
    return -par[root(x)];
  }
};

bool solve() {
  int n, m;
  cin >> n >> m;
  if(n == 0) return false;
  UnionFind uf(n);
  REP(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    uf.unite(a, b);
  }


  map<int, int> mp;
  REP(i, n) {
    mp[uf.root(i)] = uf.size(i);
  }

  int cnt = 0;
  for(auto &e: mp) {
    if(e.second > 1) cnt++;
  }

  ll ans = 1;
  for(auto &e: mp) {
    ans *= 2;
    ans %= MOD;
  }

  if(cnt == 1) cout << (ans + 1) % MOD << endl;
  else if(cnt >= 2) cout << (ans + 1) % MOD << endl;
  else cout << ans << endl;
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  while(solve()) {}


}

