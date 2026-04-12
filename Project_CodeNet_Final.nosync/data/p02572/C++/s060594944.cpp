#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007


int main() 
{
   ll n;
   cin>>n;
   vector<ll> arr(n);
   for(ll i=0;i<n;i++)
   {
      cin>>arr[i];
   }
   vector<ll> csum(n+1,0);
   for(ll i=1;i<=n;i++)
   {
      csum[i]=(csum[i-1]%mod+arr[i-1]%mod)%mod;
   }
   ll ans=0;
   for(ll i=0;i<n-1;i++)
   {
      ans=(ans%mod+(arr[i]%mod*(csum[n]-csum[i+1]+mod)%mod)%mod)%mod;
   }
   cout<<ans<<endl;
   return 0;
}