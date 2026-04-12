#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
 int n;
 cin >> n;

 vector<ll> v(n, 0);
 for(int i=0; i<n; i++)
  cin>> v[i];

  vector<ll> pre(n, 0);
  pre[0] = v[0];
  for(int i=1; i<n; i++)
    pre[i] += pre[i-1]+v[i];

  vector<vector<pair<ll,ll>>> dp(n, vector<pair<ll,ll>>(n, make_pair(0,0)));
  for(int i=0; i<n; i++)
    dp[i][i].first = v[i], dp[i][i].second = 0;

  for(int i=1; i<n; i++)
  {
    for(int j=0; j+i<n; j++)
    {
      dp[j][j+i].first = max(v[j+i]+dp[j][j+i-1].second, v[j]+dp[j+1][j+i].second);
      if(j == 0)
        dp[j][j+i].second = pre[j+i] - dp[j][j+i].first;
      else
        dp[j][j+i].second = (pre[j+i]-pre[j-1]) - dp[j][j+i].first; 
    }
  }
 
  cout<<dp[0][n-1].first - dp[0][n-1].second;
  return 0;
}
