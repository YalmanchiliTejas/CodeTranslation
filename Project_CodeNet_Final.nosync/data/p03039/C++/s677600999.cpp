typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

const int MAX = 510000;
 const int MOD = 1000000007;
 
 long long fac[MAX], finv[MAX], inv[MAX];
 
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
 // テーブルを作る前処理
 void COMinit() {
     fac[0] = fac[1] = 1;
     finv[0] = finv[1] = 1;
     inv[1] = 1;
     for (int i = 2; i < MAX; i++){
         fac[i] = fac[i - 1] * i % MOD;
         inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
         finv[i] = finv[i - 1] * inv[i] % MOD;
     }
 }
 
 // 二項係数計算
 long long COM(int n, int k){
     if (n < k) return 0;
     if (n < 0 || k < 0) return 0;
     return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
 }

int main() {
    ll n,m,k;
    // ll mod = 1000000007;
    std::cin >> n>>m>>k;
    COMinit();
    
    ll base = inv_mul(COM(n*m,k)*COM(k,2)%MOD,COM(n*m,2));
    // std::cout << base << std::endl;
    
    ll result = 0;
    for (ll i = 1; i <= n+m; i++) {
        // std::cout << i << std::endl;
        for (int l = max((ll)0,i-m); l <= min(i,n); l++) {
            ll r = i-l;
            // m-r>=0
            // std::cout <<result <<" "<<i<<" "<< l<<" "<<r <<" "<<(n-l)*(m-r) << std::endl;
            if(l == 0 || l == i){
                result += i*( max ((ll)0, (n-l)*(m-r) ) )%MOD;
                // result += ( max ((ll)0, (n-l)*(m-r) ) )%MOD;
            }else{
                result += i*2 *( max ((ll)0, (n-l)*(m-r) ) )%MOD;
                // result += 2 *( max ((ll)0, (n-l)*(m-r) ) )%MOD;
            }
            // std::cout << result << std::endl;
        }
        result%=MOD;
        // std::cout << i<<" "<<result << std::endl;
    }
    
    std::cout << base*result % MOD << std::endl;
    
}
