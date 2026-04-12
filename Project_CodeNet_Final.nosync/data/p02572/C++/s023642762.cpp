/*Author:Copyrights: S7a2a7d 
 Hardwork can always beat talent */

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define pb push_back
#define ll long long
#define rep(i,n)  for(ll i=0;i<n;i++)
#define repi(i,n)  for(ll i=1;i<=n;i++)
#define mem(arr,x) memset(arr,x,sizeof(arr))
     
#define mp make_pair
#define ff first
#define ss second
     
 const double PI = 3.1415926535897932;
 const int mod = 1e9 + 7;  
 const int inf = 1e9 + 5;
ll lcm(ll a,ll b)
{
        return (a*b)/__gcd(a,b);
}
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
int max(int a,int b)
{
        if(a<b)
        return b;
        return a;
}

int main()
{
    fast_io;
    int T=1;
    //cin>>T;
    while(T--)
    {    
       ll n;
       cin>>n;
       int a[n];
       rep(i,n)
       cin>>a[i];
       vector<ll int>sums(n+1,0);
       for(int i=0;i<n;i++)
       {
          sums[i+1]=(sums[i]+a[i]);
       }
       ll ans=0;
       for(int i=0;i<n;i++)
       {
          ll req=(sums[n]-sums[i+1])%mod;
          ans=ans+(ll)(a[i]*req);
          ans=ans%mod;
       }
        cout<<ans<<'\n';
    }
            
   
 }