#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
const int MAXD = 105;
const int64_t MOD = 1000000007;
int64_t dp[MAXN][MAXD][2]; // Kより小さい

int main()
{
  string S;
  int D;
  cin >> S >> D;
  int N = S.size();
  dp[0][0][0] = 1;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < D; j++)
    {
      for (int k = 0; k < 2; k++)
      {
        int d = S[i] - '0';
        if (k == 0)
        {
          (dp[i + 1][(j + d) % D][0] = dp[i][j][k]) %= MOD;
          for (int l = 0; l < d; l++)
          {
            (dp[i + 1][(j + l) % D][1] += dp[i][j][k]) %= MOD;
          }
        }
        else
        {
          for (int l = 0; l <= 9; l++)
          {
            (dp[i + 1][(j + l) % D][k] += dp[i][j][k]) %= MOD;
          }
        }
      }
    }
  }
  cout << (dp[N][0][0] + dp[N][0][1] + MOD - 1) % MOD << endl;
}
