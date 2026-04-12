#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll mod=1000000007;
int main()
{
  ll a,b,c,d,i,j,k,l,m,n;
  ll sum=0,ans=0;
  cin>>n;
  ll arr[n];
  for(i=0;i<n;i++)cin>>arr[i];
  for(i=0;i<n;i++)sum+=arr[i],sum%=mod;
  for(i=0;i<n-1;i++)
  {
    sum-=arr[i];
    sum+=mod;
    sum%=mod;
    ans+=(arr[i]*sum);
    ans+=mod;
    ans%=mod;
  }
  cout<<ans<<endl;


}