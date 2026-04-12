#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n,a,b,c,d;
ll fac[1005];
ll dp[1005][1005];
const ll mod = 1e9 + 7;

ll f(ll a, ll x) {
  ll res = 1;
  while(x > 0) {
    if(x & 1) res = res * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return res;
}

ll rfac(ll x) {
  return f(x,mod - 2);
}

ll P(ll n, ll r) {
  return fac[n] * rfac(fac[n-r]) % mod;
}


int main() {
  cin >> n >> a >> b >> c >> d;
  fac[0] = 1;
  for(int i = 1; i <= n; i++) {
    fac[i] = i * fac[i-1] % mod;
  }

  dp[a-1][0] = 1;

  for(ll i = a; i <= b; i++) {
    for(ll j = 0; j <= n; j++) dp[i][j] = dp[i-1][j];
    for(ll j = 0; j <= n; j++) {
      for(ll k = c; k <= d; k++) {
	ll x = k * i;
	if(j - x < 0) continue;
	dp[i][j] = (dp[i][j] + (dp[i-1][j-x] * P(j,x) % mod) * rfac(f(fac[i],k) * fac[k] % mod) % mod) % mod; 
      }
    }
  }

  cout << dp[b][n] % mod << endl;
}




    
