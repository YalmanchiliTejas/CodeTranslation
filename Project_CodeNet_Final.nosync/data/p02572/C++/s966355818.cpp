#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
int main()
{
  int n,i,j;
  cin>>n;
  ll arr[n];
  for(i=0;i<n;i++)
    cin>>arr[i];
  ll csum[n];
  csum[n-1]=arr[n-1];
  for(i=n-2;i>=0;i--)
    csum[i]=arr[i]+csum[i+1];
  ll ans=0,t;
  for(i=0;i<n-1;i++)
  {
      t=(arr[i]*(csum[i+1]%mod))%mod;
      ans+=t;
      ans=ans%mod;
  }
  cout<<ans;
  return 0;
}
