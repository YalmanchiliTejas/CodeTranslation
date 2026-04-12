#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

// ====================================================================

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;

  ll dp[s.size() + 1][2][5] = {};  // 既に未満が確定か？のフラグ
  dp[0][false][0] = 1;             // 1文字目、1桁のやつと合わす

  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j <= k; j++) {
      dp[i + 1][true][j + 1] += dp[i][true][j] * 9;  // 以下+1~9
      dp[i + 1][true][j] += dp[i][true][j];          // 以下+0

      dp[i + 1][true][j + 1] += dp[i][false][j] * (max(0, s[i] - '0' - 1));  // 0以外を追加して剥がれる                            // ぴったり張り付いたまま

      if (s[i] - '0') dp[i + 1][false][j + 1] += dp[i][false][j];  // くっついたまま
      dp[i + 1][s[i] - '0' != 0][j] += dp[i][false][j];            // くっついてる所に0を追加
    }
  }

  cout << dp[s.size()][false][k] + dp[s.size()][true][k] << endl;
}
