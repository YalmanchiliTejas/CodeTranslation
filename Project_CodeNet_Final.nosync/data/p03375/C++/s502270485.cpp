#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int ll

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)

int MOD = 1000000007;

//二分累乗法 xのe乗
ll binpow(ll x, ll e, ll mo=MOD) {
  ll a = 1, p = x;
  while(e > 0) {
    if(e%2 == 0) {p = (p*p) % mo; e /= 2;}
    else {a = (a*p) % mo; e--;}
  }
  return a;
}

ll combi(ll N_, ll C_, ll mo=MOD) {
  const int NUM_=1e5+10;
  static ll fact[NUM_+1]={},factr[NUM_+1]={},inv[NUM_+1]={};
  auto binpow = [&](ll x, ll e) -> ll{
    ll a = 1, p = x;
    while(e > 0) {
      if(e%2 == 0) {p = (p*p) % mo; e /= 2;}
      else {a = (a*p) % mo; e--;}
    }
    return a;
  };
  if (fact[0]==0) {
    fact[0] = factr[0] = inv[0] = 1;
    FOR(i, 1, NUM_+1) fact[i] = fact[i-1] * i % MOD;
    factr[NUM_] = binpow(fact[NUM_], mo-2);
    for(int i=NUM_-1; i>=0; --i) factr[i] = factr[i+1] * (i+1) % MOD;
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
      dp2[i][j] = (dp2[i-1][j]*(j+1) + dp2[i-1][j-1]) % MOD;
    }
  }

  REP(i, n+1) {
    REP(j, i+1) {
      (dp1[i] += dp2[i][j] * binpow(2, (n-i)*j)) %= MOD;
    }
    (dp1[i] *= binpow(2, binpow(2, n-i, MOD-1))) %= MOD;
  }

  int ans = 0;
  REP(i, n+1) {
    (ans += (i%2?-1:1) * combi(n, i) * dp1[i]) %= MOD;
  }
  cout << (ans%MOD+MOD)%MOD << endl;

  return 0;
}
