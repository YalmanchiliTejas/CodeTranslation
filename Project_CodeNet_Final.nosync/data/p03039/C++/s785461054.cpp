#include <iostream>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
ll fact[200010];
 
// a^b % MOD を計算して返す
ll power(ll a, ll b) {
  if (b == 0) {
    return 1;
  } else {
    ll ans = power(a, b / 2); ans = ans * ans; ans = ans % MOD;
    if (b % 2 == 1) ans = ans * a;
    ans = ans % MOD;
    return ans;
  }
}
 
 // nCr % MOD を計算して返す
ll choose(ll n, ll r) {
  ll ans = fact[n];
  ans = fact[n] * power(fact[r], MOD-2); ans = ans % MOD;
  ans = ans * power((fact[n-r] + MOD) % MOD, MOD-2); ans = ans % MOD;
  return ans;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  fact[0] = 1;
  for (int i = 0; i <= n*m; ++i) {
    fact[i+1] = fact[i]*(i+1)%MOD;
  }
  ll ans = 0;
  for (ll i = 1; i < n; ++i) {
    ans += i * (n-i) * m * m % MOD;
    ans %= MOD;
  }
  for (ll i = 1; i < m; ++i) {
    ans += i * (m-i) * n * n % MOD;
    ans %= MOD;
  }
  ans = ans * choose(n*m-2, k-2) % MOD;
  cout << ans << endl;
}
