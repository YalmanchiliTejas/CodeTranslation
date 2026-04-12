#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n; cin>>n;
  ll a[n];
  for(ll i=0;i<n;i++) cin>>a[i];
  ll pre[n];
  pre[n-1] = a[n-1];
  for(ll i=n-2;i>=1;i--)
    pre[i] = a[i] + pre[i+1];
  ll ans = 0, mod = 1e9+7;
  for(ll i=0;i<n-1;i++)
    ans = (ans + a[i]*(pre[i+1]%mod))%mod;
  cout<<ans;
  return 0;
}
    