//in the name of Allah
#include <bits/stdc++.h>
using namespace std ;
#define F first
#define S second
typedef long long ll ;
const ll INF = 1e9 ;
const ll N = 1000002 ;
ll n , a[N] , dp[N] , last[N] , ans = 0  ;
// you can prove that last[i]s are all increasing :)
// Lets go for LIS
int main()
{
std::ios::sync_with_stdio(0) ;
cin.tie(0) ;
cout.tie(0);
cin >> n  ;
for(int i = 0 ; i < n ; i ++ )cin >> a[n-1-i] ;
for(int i = 0 ; i < n ; i ++)last[i]=INF ;
last[0]=0;
for(int i = 0 ; i< n ; i ++){
 ll x =upper_bound(last , last+n , a[i]) -last ;
 dp[i] = x ;
 last[x] = min(last[x] , a[i]) ;
 ans = max(ans , dp[i]) ;
}
cout << ans ;
return 0 ;
}
