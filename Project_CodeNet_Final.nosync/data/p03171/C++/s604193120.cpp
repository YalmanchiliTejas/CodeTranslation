#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i8 = int8_t;
using i32 = int32_t;
using i64 = int64_t;
constexpr char newl = '\n';

template<typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = ((b)-1); i >=(a); i--)
#define RF0(i,b) RFO(i,0,b)
//#define F first
//#define S second
#define debug(x) cout << #x << ": " << x << '\n';

#if 1


// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  deque<int> a(N);
  F0R(i, N) {
    cin >> a[i];
  }

  // dp[i][j] ... 先頭からi個, 末尾からj個取り除いたときの最適行動時 X-Y
  vector<vector<i64>> dp(N, vector<i64>(N));

  F0R(i, N) {
    dp[i][N - i - 1] = a[i];
  }

  FOR(i, 1, N) {
    int jm = N - i - 1;
    F0R(j, N - i) {
      dp[j][jm - j] = max(
        a[N - jm + j - 1] - dp[j][jm - j + 1],
        a[j] - dp[j + 1][jm - j]
      );
    }
  }
  cout << dp[0][0];
}
#endif
