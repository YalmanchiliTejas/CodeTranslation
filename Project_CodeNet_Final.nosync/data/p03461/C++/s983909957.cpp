#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
// #define int ll
using PII = pair<int, int>;
 
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
const ll LLINF = 1LL<<40;
const ll MOD = 1000000007;

signed main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll a, b;
  cin >> a >> b;
  vector<vector<ll>> v(a, vector<ll>(b));
  REP(i, a) REP(j, b) cin >> v[i][j];

  vector<vector<ll>> g(300, vector<ll>(300, -1));
  // 0~100
  FOR(i, 1, 101) {
    g[i-1][i] = -2;
  }
  // 101~201
  FOR(i, 102, 202) {
    g[i-1][i] = -3;
  }

  // 頂点[0,100]から頂点[101,201]への辺
  REP(x, 101) REP(y, 101) {
    ll ret = 0;
    REP(i, a) REP(j, b) {
      chmax(ret, v[i][j]-(i+1)*x-(j+1)*y);
    }
    g[x][201-y] = ret;
  }

  // 確かめる
  FOR(i, 1, a+1) FOR(j, 1, b+1) {
    ll mi = INF;
    REP(x, 101) REP(y, 101) {
      chmin(mi, i*x+j*y+g[x][201-y]);
    }
    if(v[i-1][j-1] != mi) {
      cout << "Impossible" << endl;
      return 0;
    }
  }

  ll m = 0;
  REP(i, 300) REP(j, 300) {
    if(g[i][j] != -1) m++;
  }
  cout << "Possible" << endl;
  cout << 300 << " " << m << endl;
  REP(i, 300) REP(j, 300) {
    if(g[i][j] == -1) continue;
    if(g[i][j] == -2) cout << i+1 << " " << j+1 << " X" << endl;
    else if(g[i][j] == -3) cout << i+1 << " " << j+1 << " Y" << endl;
    else cout << i+1 << " " << j+1 << " " << g[i][j] << endl; 
  }
  cout << 1 << " " << 202 << endl;

  return 0;
}
