#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
const int64_t INF = 1LL << 62;
int64_t dp[MAXN][2][3];

void init()
{
  for (int i = 0; i < MAXN; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        dp[i][j][k] = -INF;
      }
    }
  }
  dp[0][0][0] = 0;
}

int main()
{
  int64_t N;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  init();
  if (N % 2)
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        for (int k = 0; k < 3; k++)
        {
          if (dp[i][j][k] == -INF)
          {
            continue;
          }
          if (j == 0)
          {
            dp[i + 1][1][k] = max(dp[i + 1][1][k], dp[i][j][k] + A[i]);
            if (k <= 1)
            {
              dp[i + 1][0][k + 1] = max(dp[i + 1][0][k + 1], dp[i][j][k]);
            }
          }
          else
          {
            dp[i + 1][0][k] = max(dp[i + 1][0][k], dp[i][j][k]);
          }
        }
      }
    }
    cout << max<int64_t>({dp[N][0][1], dp[N][1][2]}) << endl;
  }
  else
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        for (int k = 0; k < 3; k++)
        {
          if (dp[i][j][k] == -INF)
          {
            continue;
          }
          if (j == 0)
          {
            dp[i + 1][1][k] = max(dp[i + 1][1][k], dp[i][j][k] + A[i]);
            if (k == 0)
            {
              dp[i + 1][0][k + 1] = max(dp[i + 1][0][k + 1], dp[i][j][k]);
            }
          }
          else
          {
            dp[i + 1][0][k] = max(dp[i + 1][0][k], dp[i][j][k]);
          }
        }
      }
    }
    cout << max<int64_t>({dp[N][0][0], dp[N][1][1]}) << endl;
  }
}
