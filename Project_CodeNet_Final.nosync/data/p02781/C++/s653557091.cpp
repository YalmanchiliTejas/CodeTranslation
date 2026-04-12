#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
constexpr int INF = 1001001001;
constexpr int MOD = 1000000007;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int k;
  cin >> k;

  int keta_total = s.size();

  // dp[i][non_zero][enough] :=
  // 左からi桁目まで決まっていて、非ゼロがnon_zero個使われているときのパターン数
  // enoughが1な場合はなんでも、0な場合は既にギリギリ
  int dp[110][4][2];
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;

  for (int cur_keta = 0; cur_keta < keta_total; cur_keta++) {
    for (int nzero = 0; nzero < 4; nzero++) {
      int cur_num = s[cur_keta] - '0';  // nの現在の桁の数
      for (int enough = 0; enough < 2; enough++) {
        for (int num = 0; num < 10; num++) {
          int next_keta = cur_keta + 1;
          int next_nzero = nzero;
          int next_enough = enough;

          if (num != 0) next_nzero++;
          if (next_nzero > k) continue;
          if (!enough) {
            if (num > cur_num) continue;
            if (num < cur_num) {
              next_enough = 1;
            }
          }

          dp[next_keta][next_nzero][next_enough] += dp[cur_keta][nzero][enough];
        }
      }
    }
  }

  ll ans = dp[keta_total][k][0] + dp[keta_total][k][1];

  cout << ans << endl;

  return 0;
}