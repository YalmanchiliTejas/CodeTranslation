#include <bits/stdc++.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <ctype.h>
#include <unordered_map>
#include <set>
#include <iterator>
#include <deque>
using namespace std;

typedef long long int lli;


#define MOD (lli)(1e9+7)
#define endl "\n"
#define pb push_back
#define TEST_CASES  lli t;cin >> t;while(t--)

lli mod = 998244353;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,s;
  cin>>n>>s;
  vector<lli> a(n+1);
  vector< vector<lli> > f(n+1,vector<lli> (s+1,0));
  vector< vector<vector<lli>> > dp(n+1,vector<vector<lli>> (s+1,vector<lli>(3,0)));
  for (int i = 1; i <= n; ++i)
  {
    cin>>a[i];
    //f[i][a[i]] = 1;
    if(a[i] <= s)
      dp[i][a[i]][1] = 1;
  }
 
 /* for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= s; ++j)
    {
      f[i][j] += (f[i-1][j]);
      if(j>a[i])
        f[i][j] += f[i-1][j-a[i]];
      f[i][j] %=mod;
    }
  }*/
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 0; j <= s; ++j)
    {
        if(j == 0){
          dp[i][j][1] = i;
        }
        else{
          dp[i][j][1] += dp[i-1][j][1];
          if(j>=a[i])
            dp[i][j][1] += dp[i-1][j-a[i]][1];
          dp[i][j][2] += dp[i-1][j][2] + dp[i][j][1];
          dp[i][j][2] %=mod;
          dp[i][j][1] %=mod; 
        }
    }
  }
  /*for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= s; ++j)
    {
      cout<<dp[i][j][2]<<" "; 
    }
    cout<<endl;
  }*/
  cout<<dp[n][s][2]<<endl;  
}




