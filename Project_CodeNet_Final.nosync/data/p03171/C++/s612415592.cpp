#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back
#define mod 1000000007
#define mk make_pair
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n+1]={0};
    ll dp[n+1][n+1][2];
    for(ll i=1;i<=n;i++)
    cin>>a[i];
    for(int i=0;i<=n;i++)
    {dp[i][i][0]=a[i];dp[i][i][1]=0;}
    for(int k=1;k<=n-1;k++)
    {   for(int i=1;i<n;i++)
        {
          int j=i+k;
          if(j>n)
          continue;
          else
          {
              ll t1=a[j]+dp[i][j-1][1];
              ll j1=dp[i][j-1][0];
              ll t2=a[i]+dp[i+1][j][1];
              ll j2=dp[i+1][j][0];
              if(t1-j1>t2-j2)
              {
                  dp[i][j][0]=t1;
                   dp[i][j][1]=j1;
              }
              else
              {
                   dp[i][j][0]=t2;
                  dp[i][j][1]=j2;
              }
          }
        }
    }
    
    ll ans=(dp[1][n][0]-dp[1][n][1]);
    cout<<ans;
    return 0;
}