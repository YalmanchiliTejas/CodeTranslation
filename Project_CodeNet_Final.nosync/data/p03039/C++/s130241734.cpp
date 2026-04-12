#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;


ll P(ll a, ll x) {
  ll res = 1;
  while(x > 0) {
    if(x & 1) res = res * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return res;
}

ll nCr(ll n, ll r) {
  ll tmp = n - r;
  if(tmp == 0 || r == 0) return 1;
  if(tmp > r) swap(tmp,r);

  ll sum = 1;
  for(ll i = n; i > n - tmp; i--) sum = sum * i % mod;
  ll sum2 = 1;
  for(ll i = tmp; i >= 1; i--) sum2 = sum2 * i % mod;

  return sum * P(sum2,mod-2) % mod;
}
  
int main() {
  ll n,m,k;
  cin >> n >> m >> k;

  ll ans = 0;
  for(ll i = 1; i < n; i++) {
    ans = (ans + i * (n - i)  * m * m ) % mod;
  }
  for(ll i = 1; i < m; i++) {
    ans = (ans + i * (m - i) * n * n ) % mod;
  }
  // cout << nCr(2,0) << endl;
  cout << ans * nCr(n * m - 2, k - 2) % mod << endl;
  
}

  
  
