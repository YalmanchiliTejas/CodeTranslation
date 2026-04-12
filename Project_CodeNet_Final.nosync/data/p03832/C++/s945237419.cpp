#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll n,a,b,c,d;
ll pa[1005];
ll dp[1005][1005];
ll p(ll a, ll x) {
  ll res = 1;
  while(x > 0) {
  if(x & 1) res = (res * a) % mod;
  a = a * a % mod;
  x >>= 1;
  }
  return res;
}


ll r(ll x) {
  return p(x,mod - 2);
}

ll P(ll a, ll b) {
  return pa[a] * r(pa[a-b]) % mod;
}

int main() {
  cin >> n >> a >> b >> c >> d;
  pa[0] = 1;
  for(int i = 1; i <= n; i++) pa[i] = pa[i-1] * i % mod;
  dp[a-1][0] = 1;

  for(ll k = a; k <= b; k++) {
    for(ll i = 0; i <= n; i++) dp[k][i] = dp[k-1][i];
    for(ll i = c; i <= d; i++) {
      for(ll j = k * i; j <= n; j++) {
	dp[k][j] = (dp[k][j] + (dp[k-1][j-k*i] * P(j,k*i) % mod) * r(p(pa[k],i) * pa[i] % mod) % mod) % mod;
      }
    }
  }

  cout << dp[b][n] << endl;
}
	

  
