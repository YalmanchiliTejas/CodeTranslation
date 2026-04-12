#include <bits/stdc++.h>
using namespace std;
int dp[101][4][2];
int main()
  {string s; cin >> s;
  int n = s.size();
  int K; cin >> K;
  dp[0][0][0] = 1;
  for (int i = 0; i < n; ++i)
    {auto D = s[i] - '0';
    for (int j = 0; j <= K; ++j)
      {for (int k = 0; k < 2; ++k)
        {for (int d = 0; d <= 9; ++d)
          {auto j1 = j, k1 = k;
          if (d > 0) ++j1;
          if (j1 > K) continue;
          if (k == 0)
            {if (d > D) continue;
            if (d < D) k1 = 1;}
          dp[i + 1][j1][k1] += dp[i][j][k];}}}}
  cout << dp[n][K][0] + dp[n][K][1] << endl;}