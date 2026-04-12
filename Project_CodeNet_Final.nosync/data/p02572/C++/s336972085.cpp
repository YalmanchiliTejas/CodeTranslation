#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll mod=1000000007;
ll a[200005],b[200005];
int main()
{
  ll n;
  cin>>n;
  for(ll i=0;i<n;i++)
  cin>>a[i];
  b[0]=a[0];
  ll ans=0;
  ll i,j;
  for(i=1;i<n;i++)
  {
      b[i]=(b[i-1]+a[i])%mod;
  }
  for(i=1;i<n;i++)
  {
      ans=(ans+(a[i]*b[i-1])%mod)%mod;
  }
  cout<<ans<<endl;
}