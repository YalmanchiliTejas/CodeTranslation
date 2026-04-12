#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(ll a[],ll n)
{
  ll dp[n+1][n+1];
  for(ll s = 0; s<n; s++)
  {
    for(ll i = 1,j = i+s; i<=n && j<=n; i++,j++)
    {
        if(i==j)
            dp[i][j] = a[i];
        else if(j==i+1)
            dp[i][j] = max(a[i],a[i+1]);
        else
        {
            ll t1=0,t2=0,t3=0;
            if(i+2<=j)
            {
                t1=dp[i+2][j];
                t2=dp[i+1][j-1];
                t3=dp[i][j-2];
            }
            dp[i][j] = max((a[i]+min(t1,t2)),(a[j]+min(t2,t3)));
        }
    }
  }
  return dp[1][n];
}

int main()
{
    ll n;
    ll sum = 0;
    cin>>n;
    ll a[n+1];
    for(ll i = 1 ;i<=n; i++)
    {
        cin>>a[i]; 
        sum+=a[i];
    }
    ll x = solve(a,n);
    ll y = sum-x;
    cout<<x-y;
    return 0;
}