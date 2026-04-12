#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define INF 10000000001
#define MOD 1000000007
using namespace std;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin>>n;
  ll sum=0;
  ll ar[n];
  for(ll i=0;i<n;i++)
  {
    cin>>ar[i];
    sum+=ar[i];
  }
  ll dp[n][n];
  for(int x=0;x<n;x++)
  {
    for(int i=0,j=x;j<n;j++,i++)
    {
      ll a,b,c;
      if(i+2>j)
        a=0;
      else
        a=dp[i+2][j];

      if(i+1>j-1)
        b=0;
      else
        b=dp[i+1][j-1];

      if(i>j-2)
        c=0;
      else
        c=dp[i][j-2];

      dp[i][j]=max(ar[i]+min(a,b),ar[j]+min(b,c));
    }
  }
  ll z=sum-dp[0][n-1];
  cout<<dp[0][n-1]-z;

}
