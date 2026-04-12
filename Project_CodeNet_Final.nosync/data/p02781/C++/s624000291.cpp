#include <bits/stdc++.h>
using namespace std;
string S;
int64_t K;
int64_t DP[105][4][2]; // i桁目まで決めて、j個の非0を使って、N以下であることが確定している個数

int main()
{
  cin >> S >> K;
  int N = S.size();
  DP[0][0][0] = 1;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < 2; k++)
      {
        int si = S[i] - '0'; // 今の桁
        for (int d = 0; d < 10; d++)
        {
          int ni = i + 1, nj = j, nk = k;
          if (d != 0)
            nj++;
          if (nj > K)
            continue;
          if (k == 0)
          {
            if (d > si)
              continue;
            else if (d < si)
              nk = 1;
          }
          DP[ni][nj][nk] += DP[i][j][k];
        }
      }
    }
  }
  int64_t ans = DP[N][K][0] + DP[N][K][1];
  cout << ans << endl;
}
