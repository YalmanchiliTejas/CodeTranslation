#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
const ll mod = 1e9+7;
ll N,A,B,C,D;
ll fac[1005];
ll rfac[1005];
ll dp[1005][1005];
ll pow (ll x, ll a) {
  ll res = 1;
  while(a > 0) {
    if(a & 1) res = res * x % mod;
    x = x * x % mod;
    a >>= 1;
  }
  return res % mod;
}



ll rpow(ll x) {
  return pow(x,mod-2);
}

ll P(ll n, ll r) {
  return fac[n] * rpow(fac[n-r]) % mod;
}

int main() {
  cin >> N >> A >> B >> C >> D;
  fac[0] = 1;
  for(ll i = 1; i <= N; i++) {
    fac[i] = fac[i-1] * i % mod;
  }

  dp[A-1][0] = 1;
  for(ll i = A; i <= B; i++) {
    for(ll j = 0; j <= N; j++) dp[i][j] = dp[i-1][j]; //i人のグループを一つも作らない場合の操作
    for(ll k = C; k <= D; k++) {
      for(ll j = i * k; j <= N; j++) {
	dp[i][j] = (dp[i][j] + (dp[i-1][j-i*k] * (P(j,i*k) * rpow(pow(fac[i],k) * fac[k] % mod) % mod) % mod)) % mod;

      }
    }
  }
  cout << dp[B][N] << endl;
		       
  
}
  
  
