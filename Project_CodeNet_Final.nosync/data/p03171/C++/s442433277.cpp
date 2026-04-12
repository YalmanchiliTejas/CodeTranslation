#include<bits/stdc++.h>
#define ll long long
#define iof ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi 3.1415926535897
#define mod 1000000007
#define inf (1ll<<60)
using namespace std;

int main()
{
    iof;
  ll n; cin>>n;
  ll arr[n];
  for(ll i=0;i<n;i++)
    cin>>arr[i];
  ll dp[n][n];
  for(ll i=0;i<n;i++)
    for(ll j=0;j<n;j++)
     dp[i][j]=0;
  for(ll i=0;i<n;i++)
    dp[i][i]=arr[i];
  ll k=1;
  while(k<n)
  {
      ll i=0,j=k;
      while(j<n)
      {
          dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
          j++;
          i++;
      }
      k++;
  }
  /*for(ll i=0;i<n;i++)
  {
      for(ll j=0;j<n;j++)
      {
          cout<<dp[i][j]<<" ";
      }
      cout<<endl;
  }*/
  cout<<dp[0][n-1]<<endl;

}
