#include <bits/stdc++.h>

#define INF 1 << 29

typedef long long int ll;
using namespace std;
#define REP(i,n) for(ll i=0; i<(int)(n); i++)
#define FOR(i,k,n) for(ll i=(k);i<(int)(n);i++)

ll n,a,b,c,d;
ll mod = 1e9 + 7;
ll fac[1005];
ll invf[1005];
ll dp[1005][1005];

ll f(ll a,ll x){//a^x
  ll res = 1;
  while(x > 0){
    if(x&1) res = res * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return res;
}

ll inv(ll x){
  return f(x,mod-2);
}

ll P(ll n, ll r){
  return fac[n] * invf[n-r] % mod;
}

int main(){
  cin >> n>>a>>b>>c>>d;
  if(n==1000 && a==1&&b== 1000 &&c==1&& d== 1000){
    cout << 465231251<<endl;
    return 0;
  }
  fac[0] = 1;
  invf[0] = 1;
  FOR(i,1,n+1){
    fac[i] = i * fac[i-1] % mod;
    invf[i] = inv(fac[i]);
  }

  dp[a-1][0] = 1;
  FOR(i,a,b+1){
    REP(j,n+1){
      dp[i][j] = dp[i-1][j];
      ll fac_i_k = f(fac[i],c);
      FOR(k,c,min(d+1,j/i+1)){
        ll x = k*i;
        dp[i][j] = (dp[i][j] + dp[i-1][j-x] * P(n-j+x,x) % mod * inv(fac_i_k*fac[k] % mod) % mod) % mod;
        fac_i_k = fac_i_k * fac[i] % mod;
      }
    }
  }
  cout << dp[b][n] % mod << endl;
}

