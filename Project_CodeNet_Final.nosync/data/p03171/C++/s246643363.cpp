#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll,ll>
#define vi vector<ll>
#define vii vector<pii>
#define f(i,a,b) for(ll i=a;i<b;i++)

int main()
{  
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   ll n=0,j=0;
   cin>>n;

   ll a[n];
   vector<vii> dp(n);

   f(i,0,n)
    cin>>a[i];

   f(i,0,n)
    {
      f(j,0,n)
       {
        dp[i].push_back(make_pair(0,0));
       }
    }

    f(k,0,n)
    {
      f(i,0,n)
       {
          j = i + k;

          if(j>=n)
            continue;

          if(i==j)
          {
            dp[i][j].first = a[i];
            dp[i][j].second = 0;
          }

          else if((a[i] + dp[i+1][j].second) > (a[j] + dp[i][j-1].second))
          {
            dp[i][j].first = a[i] + dp[i+1][j].second;
            dp[i][j].second = dp[i+1][j].first;
          }

          else{
            dp[i][j].first = a[j] + dp[i][j-1].second;
            dp[i][j].second = dp[i][j-1].first;
          }
       }
    }

   cout<<dp[0][n-1].first - dp[0][n-1].second;
  return 0;
}
