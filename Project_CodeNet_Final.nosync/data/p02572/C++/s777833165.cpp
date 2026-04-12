#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007

int main(){
  fast;
    ll n;
    cin>>n;
    ll arr[n],sum=0;
    for(int i=0;i<n;i++)
        cin>>arr[i],sum+=arr[i];
    ll val[n];
    for(int i=0;i<n;i++)
        val[i]=(sum-arr[i])%mod,sum-=arr[i];
    ll ans=0;
    for(int i=0;i<n;i++)
        ans=(ans+(val[i]*arr[i])%mod)%mod;
    cout<<ans;
  return 0;
}
