#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

ll MOD = 1000000007;

int main()
{
  string s;
  int d;
  cin >> s >> d;
  int n = s.size();
  reverse(s.begin(), s.end());
  
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(d, vector<ll>(2, 0)));
  
  rep(i, 10) dp[0][i%d][i <= (s[0] - '0')]++;
  for(int i = 1; i < n; i++)
  {
    rep(j, d)
    {
      rep(k, 10)
      {
        int c = s[i] - '0';
        dp[i][(j+k)%d][k < c] = (dp[i][(j+k)%d][k < c] + dp[i - 1][j%d][0]) % MOD;
        dp[i][(j+k)%d][k <= c] = (dp[i][(j+k)%d][k <= c] + dp[i - 1][j%d][1]) % MOD;
      }
    }
  }
  
  cout << (MOD + dp[n-1][0][1] - 1) % MOD << endl;
  
  return 0;
}