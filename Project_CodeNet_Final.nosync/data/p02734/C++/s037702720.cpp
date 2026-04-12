#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll mod = 998244353 ;
ll dp[4000] ;
int main()
{
  ll n , s ;
  cin >> n >> s ;
  ll ans = 0 ;
  for(int i = 1; i <= n ;i ++)
   {
     dp[0] += 1 ;
     int a ;
     cin >> a ;
     for(int j = s ;j >= a; j --)
      dp[j] = (dp[j] + dp[j - a]) % mod ;
     (ans += dp[s]) % mod ;
   }
   cout << ans % mod << endl ;
  return 0 ;
}
