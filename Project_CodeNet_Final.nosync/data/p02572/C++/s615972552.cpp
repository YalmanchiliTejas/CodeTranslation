#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

int main()
{
  ll n;
  cin>>n;
  ll a[n],suf[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  suf[n-1]=a[n-1];
  for(int i=n-2;i>=0;i--)
    suf[i]=(suf[i+1]+a[i])%mod;
  ll ans=0;
  for(int i=0;i<n-1;i++)
    ans=(ans+(a[i]*suf[i+1])%mod)%mod;
  cout<<ans;
  return 0;
}