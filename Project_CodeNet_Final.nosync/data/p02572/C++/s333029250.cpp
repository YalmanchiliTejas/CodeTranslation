#include<iostream>
#include<vector>
#include<string>
#include <queue>
#include<map>
#include<set>
#include <cstring>
using namespace std;
#define ll long long int

#define mod 1000000007
int main()
{
   ll n ;
   cin>>n ;
   vector<ll> a(n) , pre(n , 0 );
   ll ans = 0 ;
   for(ll i = 0 ; i < n ; i++)
    cin>>a[i] ;

   pre[0] = a[0] ;
   for(ll i = 1 ; i < n ; i++)
   {
       pre[i] = pre[i - 1] + a[i];
   }

   for(ll i = 0 ; i < n - 1  ;i++)
   {
       ans += (((pre[n - 1] - pre[i])%mod)*a[i])%mod  ;
       ans = (ans + mod)%mod ;
   }

   ans = (ans + mod)%mod ;
   cout<<ans ;


}
