#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
  ll dp0[101][4]; // i桁目までみてnより小さいことが確定していない
  ll dp1[101][4]; // i桁目までみてnより小さいことが確定している

  for (auto i = 0; i <= 100; i++)
  {
    for (auto j = 0; j <= 3; j++)
    {
      dp0[i][j] = 0;
      dp1[i][j] = 0;
    }
  }

  string N;
  ll K;

  cin >> N;
  cin >> K;

  int digit = N.at(0) - '0';

  // i桁目までNと一致
  dp0[0][0] = 0; // 1桁目は0以上なので.
  dp0[0][1] = 1;
  // i桁目まででNより小さい
  dp1[0][0] = 1;
  dp1[0][1] = digit - 1; // digit, 0を除く (digit + 1) - 2;

  for (auto i = 1; i < N.size(); i++)
  {
    int digit = N.at(i) - '0';
    // cout << "i: " << i << endl;
    for (auto k = 0; k <= K; k++)
    {
      // cout << "k: " << k << endl;
      if (k == 0)
      {
        // i桁目までNと一致
        dp0[i][0] = digit == 0 ? dp0[i - 1][0] : 0;
        // i桁目まででNより小さい
        dp1[i][0] = 1; // '000000...'のとき, 1になる。

        // cout << "dp0[i][k]: " << dp0[i][0] << endl;
        // cout << "dp1[i][k]: " << dp1[i][0] << endl;

        continue;
      }

      if (digit == 0)
      {
        // i桁目までNと一致
        dp0[i][k] = dp0[i - 1][k];
        // i桁目まででNより小さい
        dp1[i][k] = dp1[i - 1][k - 1] * 9 + dp1[i - 1][k];
      }
      else
      {
        // i桁目までNと一致
        dp0[i][k] = dp0[i - 1][k - 1];
        // i桁目まででNより小さい
        dp1[i][k] = dp1[i - 1][k - 1] * 9 + dp1[i - 1][k] + dp0[i - 1][k] + dp0[i - 1][k - 1] * (digit - 1);
      }

      // cout << "dp0[i][k]: " << dp0[i][k] << endl;
      // cout << "dp1[i][k]: " << dp1[i][k] << endl;
    }
  }

  cout << dp0[N.size() - 1][K] + dp1[N.size() - 1][K] << endl;

  return 0;
}
