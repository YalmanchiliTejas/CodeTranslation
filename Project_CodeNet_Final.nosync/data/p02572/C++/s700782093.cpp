#include<bits/stdc++.h>
#define ll long long 
#define OJ \
        freopen("input.txt","r",stdin); \
        freopen("output.txt","w",stdout);
using namespace std;
int mod=1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
  cin.tie(NULL);
//  OJ;
  int n;
  cin>>n;
  int a[n];
  ll int sum=0;
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
      sum+=a[i];
      sum%=mod;
  }
  ll int ans=0;
  for(int i=0;i<n;i++)
  {
      sum-=a[i];
      if(sum<0)
      {
          sum+=mod;
      }
      ans+=sum*a[i];
      ans%=mod;

  }
  cout<<ans;
  
}