#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const int MAX = 1e4;
const ll mod = 1e9+7;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i-1] * (ll)i % mod;
    inv[i] = mod - inv[mod%i] * (mod/(ll)i) % mod;
    finv[i] = finv[i-1] * inv[i] % mod;
  }
}

ll COM(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

void extgcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0) {
    x = 1;
    y = 0;
    return;
  }
  extgcd(b, a % b, y, x);
  y -= a/b*x;
  return; 
}

ll mod_inverse(ll a, ll m = mod) {
  ll x, y;
  extgcd(a,m,x,y);
  return (m + x % m) % m;
}

int main(){
  COMinit();
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  vector<vector<ll>> dp(b+1,vector<ll>(n+1,0));
  dp[a-1][0] = 1;
  for(int i = a; i <= b; i++) {
    for(int j = 0; j <= n; j++) {
      (dp[i][j] += dp[i-1][j]) %= mod;
      if(j + i*c <= n) {
        ll r = COM(n-j,i*c);
        for(int l = 1; l <= c; l++) {
          (r *= COM(i*l,i)) %= mod;
          (r *= mod_inverse(l)) %= mod;
        }
        for(int k = c; k <= min(d,(n-j)/i); k++) {
          (dp[i][j+k*i] += dp[i-1][j] * r % mod) %= mod;
          (r *= COM(n-j-i*k,i)) %= mod;
          (r *= mod_inverse(k+1)) %= mod;
        }
      }
    }
  }
  cout << dp[b][n] << endl;
  return 0;
}