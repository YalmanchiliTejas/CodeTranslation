#include<bits/stdc++.h>
using namespace std;
#define M_PI  3.1415926535
#define ll long long
#define ld long double
#define all(a) a.begin(),a.end()
#define Summon_Tourist ios::sync_with_stdio(false);cin.tie(0);
ll gcd(ll a , ll b) { return b==0?a: gcd( b, a%b); }
ll lcm(ll a , ll b) { return a/gcd(a,b) * b ; }
ll inf = 1e9 + 7;
ll modexp( ll base ,ll power)
 {
     if( power == 0  ) return 1;
     if( power & 1) return base*modexp( base , power-1 )%inf;
     return modexp(base*base%inf,power/2);
 }
int main()
{
  Summon_Tourist
  //freopen("input.txt" , "r" , stdin ) ;
  ll t = 1;
  //cin>>t;
  while(t--)
  {
     ll n;
     cin>>n ;
     vector<ll> a(n) ;
     for( ll i = 0 ; i<n ; i++ ) cin>>a[i] ;

     vector<ll> pref_sum(n,0) ;
     pref_sum[0] = a[0]%inf ;
     for( ll i = 1 ; i<n ; i++ ) pref_sum[i] = (pref_sum[i-1]%inf + a[i]%inf)%inf ;
     ll ans = 0 ;
     for( ll i = n-1 ; i>=1 ; i-- ){
        ans = (ans%inf + (a[i]%inf*pref_sum[i-1]%inf)%inf)%inf ;
     }
     cout<<ans%inf;
  }
return 0;


}
