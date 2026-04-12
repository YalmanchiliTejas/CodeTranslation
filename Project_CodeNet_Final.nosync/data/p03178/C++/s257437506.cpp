#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  ll MOD = 1000000007;
  string K;
  int D;
  cin >> K >> D;
  vector<vector<vector<ll>>> dp(K.length() + 1, vector<vector<ll>>(2, vector<ll>(D)));
  dp[0][1][0] = 1;
  rep(i, K.length())
  {
    int d = K[i] - '0';
    rep(j, D)
      rep(k, 10)
        dp[i+1][0][(j+k)%D] = (dp[i+1][0][(j+k)%D] + dp[i][0][j]) % MOD;
    rep(j, D)
    {
      dp[i+1][1][(j+d)%D] = (dp[i+1][1][(j+d)%D] + dp[i][1][j]) % MOD;
      rep(k, d)
        dp[i+1][0][(j+k)%D] = (dp[i+1][0][(j+k)%D] + dp[i][1][j]) % MOD;
    }
  }
  ll ans = (dp[K.length()][1][0] + dp[K.length()][0][0] - 1) % MOD;
  if (ans < 0)
    ans += MOD;
  cout << ans << endl;
  return 0;
}