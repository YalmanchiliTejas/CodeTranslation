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
const ll LLINF = 1LL<<40;
const ll MOD = 1000000007;

ll dp[10010][105][2];
signed main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll m;
  string s;
  cin >> s >> m;
  const int n = s.size();

  dp[0][0][0] = 1;
  REP(i, n) REP(j, m) REP(k, 2) {
    int lim = k?9:s[i]-'0';
    REP(d, lim+1) {
      (dp[i+1][(j+d)%m][k || d<lim] += dp[i][j][k]) %= MOD;
    }
  }

  ll ans = 0;
  REP(i, 2) (ans += dp[n][0][i]) %= MOD;
  cout << (ans+MOD-1) % MOD << endl;

  return 0;
}
