#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll A,B,C,D;
const ll mod = 1e9+7;
ll fac[1005];
ll dp[1005][1005];

ll getpow(ll a, ll x) {
  ll res = 1;

  while(x > 0) {
    if(x & 1) res = res * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return res;
}

ll get_rev(ll x) {
  return getpow(x,mod-2);
}

ll getP(ll n, ll r) {
  return fac[n] * get_rev(fac[n-r]) % mod;
}

int main() {
  cin >> N >> A >> B >> C >> D;
  fac[0] = 1;
  for(ll i = 1; i <= N; i++) {
    fac[i] = fac[i-1] * i % mod;
  }
  
  
  dp[A-1][0] = 1;

  for(ll i = A; i <= B; i++) {
    for(ll j = 0; j <= N; j++) dp[i][j] = dp[i-1][j];
    for(ll j = C; j <= D; j++) {
      for(ll k = i * j; k <= N; k++) {
	dp[i][k] = (dp[i][k] + (dp[i-1][k-i*j] * getP(k,i*j) % mod) * get_rev(getpow(fac[i],j) * fac[j] % mod) % mod) % mod;
      }
    }
  }

  cout << dp[B][N] << endl;
}
 
  
