#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
// #define int ll
using PII = pair<ll, ll>;
 
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
 
template<typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template<typename T> bool IN(T a, T b, T x) { return a<=x&&x<b; }
template<typename T> T ceil(T a, T b) { return a/b + !!(a%b); }

template<typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts) { 
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type
fill_v(T &t, const V &v) { t=v; }
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t, const V &v ) { for(auto &e:t) fill_v(e,v); }

template<class S,class T>
ostream &operator <<(ostream& out,const pair<S,T>& a){
  out<<'('<<a.first<<','<<a.second<<')'; return out;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& vec){
  for(T& x: vec) {is >> x;} return is;
}
template<class T>
ostream &operator <<(ostream& out,const vector<T>& a){
  out<<'['; for(T i: a) {out<<i<<',';} out<<']'; return out;
}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}; // DRUL
const int INF = 1<<30;
const ll LLINF = 1LL<<60;
const int MOD = 1000000007;

struct UnionFind {
  vector<int> par, s;
  UnionFind(int n=2e5) { init(n); }
  void init(int n) { 
    s.assign(n, 1); par.resize(n); 
    iota(par.begin(), par.end(), 0);
  }
  int find(int x) {
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(s[x] < s[y]) par[x] = y, s[y] = s[x] + s[y];
    else par[y] = x, s[x] = s[x] + s[y];
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return s[find(x)]; }
};

signed main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  auto e = make_v<ll>(m, 3);
  REP(i, m) {
    cin >> e[i][1] >> e[i][2] >> e[i][0];
    e[i][1]--, e[i][2]--;
  }

  ll sum = 0;
  UnionFind uf(n);
  vector<vector<PII>> g(n);
  sort(ALL(e));
  REP(i, m) {
    if(uf.same(e[i][1], e[i][2])) continue;
    uf.unite(e[i][1], e[i][2]);
    g[e[i][1]].push_back({e[i][2], e[i][0]});
    g[e[i][2]].push_back({e[i][1], e[i][0]});
    sum += e[i][0];
  }

  auto d = make_v<ll>(n, n);
  fill_v(d, 0);
  function<void(ll,ll,ll,ll)> dfs = [&](ll v, ll p, ll s, ll dist) {
    d[s][v] = dist;
    ll ret = 0;
    for(auto to: g[v]) {
      if(to.first == p) continue;
      dfs(to.first, v, s, max(dist,to.second));
    }
  };
  REP(i, n) dfs(i, -1, i, 0);

  // REP(i, n) cout << d[i] << endl;

  ll q;
  cin >> q;
  REP(i, q) {
    ll s, t;
    cin >> s >> t;
    s--, t--;
    cout << sum - d[s][t] << endl;
  }

  return 0;
}
