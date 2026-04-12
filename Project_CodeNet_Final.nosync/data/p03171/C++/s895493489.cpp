#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <sstream>
#include <string.h>

using namespace std;
typedef long long ll;

/* https://qiita.com/drken/items/4e1bcf8413af16cb62da#%E4%BE%8B%E9%A1%8C-3-edpc-l-%E5%95%8F%E9%A1%8C---deque-%E5%BE%97%E7%82%B9%E5%B7%AE%E3%82%82%E6%9C%80%E5%A4%A7%E5%8C%96%E3%81%97%E3%81%9F%E3%81%84-
*/

// DP テーブル
long long dp[3100][3100];

int main() {
  // 入力受け取り
  int N; cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];
  
  // 初期条件
  for (int i = 0; i < N; ++i) dp[i][i] = 0;
  
  
  // DP
  for (int len = 1; len <= N; ++len) {
    for (int i = 0; i + len <= N; ++i) {
      int j = i + len;
//      cout << endl;
//      cout << "len:" << len << " i:" << i << " j:" << j << endl;
      // 先手番
      if ((N - len) % 2 == 0) {
//        cout << "先攻　" << endl;
//        cout << dp[i + 1][j] << " + " << a[i] << " " << dp[i][j - 1] << " + " << a[j - 1] << endl;
        dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
      }
      // 後手番
      else {
//        cout << "後攻" << endl;
//        cout << dp[i + 1][j] << " - " << a[i] << " " << dp[i][j - 1] << " - " << a[j - 1] << endl;
        dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
      }
//      cout << "dp:" << dp[i][j] << endl;
    }
//    cout << endl;
  }
  
//  for (int i = 0; i <= N; i++) {
//    for (int j = 0; j <= N; j++) {
//      cout << dp[i][j] << " ";
//    }
//    cout << endl;
//  }
  
  // 答え
  cout << dp[0][N] << endl;
}
