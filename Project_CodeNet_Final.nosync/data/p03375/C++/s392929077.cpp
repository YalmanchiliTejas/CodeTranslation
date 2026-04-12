#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int ll
using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define PB push_back

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
int MOD = 1000000007;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template <typename T> bool IN(T a, T b, T x) { return a<=x&&x<b; }
template<typename T> T ceil(T a, T b) { return a/b + !!(a%b); }
template<class S,class T>
ostream &operator <<(ostream& out,const pair<S,T>& a){
  out<<'('<<a.first<<','<<a.second<<')';
  return out;
}
template<class T>
ostream &operator <<(ostream& out,const vector<T>& a){
  out<<'[';
  REP(i, a.size()) {out<<a[i];if(i!=a.size()-1)out<<',';}
  out<<']';
  return out;
}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

//二分累乗法 xのe乗
ll binpow(ll x, ll e, ll mo=MOD) {
  ll a = 1, p = x;
  while(e > 0) {
    if(e%2 == 0) {p = (p*p) % mo; e /= 2;}
    else {a = (a*p) % mo; e--;}
  }
  return a % mo;
}

ll combi(ll N_, ll C_) {
  const int NUM_=1e5+10;
  static ll fact[NUM_+1]={},factr[NUM_+1]={},inv[NUM_+1]={};
  auto binpow = [&](ll x, ll e, ll mo=MOD) -> ll{
    ll a = 1, p = x;
    while(e > 0) {
      if(e%2 == 0) {p = (p*p) % mo; e /= 2;}
      else {a = (a*p) % mo; e--;}
    }
    return a % mo;
  };
  if (fact[0]==0) {
    fact[0] = factr[0] = inv[0] = 1;
    FOR(i, 1, NUM_+1) {
      fact[i] = fact[i-1] * i % MOD;
      inv[i] = binpow(i, MOD-2) % MOD;
      factr[i] = factr[i-1] * inv[i] % MOD;
    }
  }
  if(C_<0 || C_>N_) return 0;
  // 前計算 O(max(N,K)log(mod)) クエリ O(1)
  return factr[C_]*fact[N_]%MOD*factr[N_-C_]%MOD;
}

int dp1[3010], dp2[3010][3010];
signed main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n >> MOD;

  REP(i, n+1) {
    dp2[i][0] = 1;
    FOR(j, 1, i+1) {
      dp2[i][j] = (dp2[i-1][j]*(j+1)%MOD + dp2[i-1][j-1]) % MOD;
    }
  }
  // REP(i, n+1) {
  //   REP(j, i+1) cout << dp2[i][j] << " ";
  //   cout << endl;
  // }

  REP(i, n+1) {
    REP(j, i+1) {
      (dp1[i] += dp2[i][j] * binpow(2, (n-i)*j) % MOD) %= MOD;
    }
    (dp1[i] *= binpow(2, binpow(2, n-i, MOD-1))) %= MOD;
  }
  // REP(i, n+1) cout << dp1[i] << " ";
  // cout << endl;

  int ans = 0;
  REP(i, n+1) {
    (ans += (i%2?-1:1) * combi(n, i) * dp1[i] % MOD) %= MOD;
    // cout << combi(n, i) << " " << ans << endl;
  }
  cout << (ans%MOD+MOD)%MOD << endl;

  return 0;
}
