typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;
const ll MOD = 1e9+7;
long long modpow(long long a, long long n) {
      long long res = 1;
      while (n > 0) {
          if (n & 1) res = res * a % MOD;
          a = a * a % MOD;
          n >>= 1;
      }
      return res;
  }
 ll inv_mul(ll x, ll y){
     return (x % MOD* modpow(y,MOD-2))%MOD;
 }
int main() {
    ll n;
    std::cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
        sum %= MOD;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += sum*a[i]%MOD;
        ans = ans - a[i]*a[i]%MOD + MOD;
        ans %= MOD;
    }
    std::cout << inv_mul(ans,2) << std::endl;
}
