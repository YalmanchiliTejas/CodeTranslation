#include <bits/stdc++.h>
using namespace std ;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll ;
typedef unsigned long long ull ;
typedef long double ld ;

const ll MOD = 1E9 + 7, INF = 2E18 + 5 ;
const double PI = 2 * acos(0.0) ;
const long double EPS = 1.0E-14 ;

ll arr[200005] ;

ll big_mod(ll base, ll power, ll mod)
{
    if(power == 0)  return 1;
    else if(power % 2 == 1) {
      ll p1 = base % mod;
      ll p2 = (big_mod(base, power-1, mod) ) % mod;
      return (p1 * p2) % mod;
    }
    else if(power % 2 == 0) {
      ll p1 = (big_mod(base, power/2, mod) ) % mod;
      return (p1 * p1) % mod;
    }
}

int main()
{
    ll n, sum1 = 0, sum2 = 0, ans ,val ;
    cin >> n ;

    for (int i = 0; i < n; i++) {
        cin >> arr[i] ;
        sum1 += arr[i] ;
        sum1 %= MOD ;
        sum2 = ((sum2 % MOD) + (arr[i] * arr[i]) % MOD) % MOD ;
    }
    sum1 = (sum1 * sum1) % MOD ;
    val = (sum1 - sum2 + MOD) % MOD ;
    ans = (val * big_mod(2, MOD - 2, MOD)) % MOD ;
    cout << ans ;

    return 0 ;
}
