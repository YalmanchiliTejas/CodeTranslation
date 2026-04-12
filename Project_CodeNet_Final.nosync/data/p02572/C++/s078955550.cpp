#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
  ll n ,i;
  cin>>n;
  ll a[n],sum=0,ans=0;  
  for(i=0;i<n;i++)
    cin>>a[i];
for(i=n-1;i>=0;i--)
{
  ans+=(sum*a[i]);
  sum+=a[i];
  ans%=mod;
  sum%=mod;
}
  
  cout<<ans<<endl;
  
  
  return 0;
}