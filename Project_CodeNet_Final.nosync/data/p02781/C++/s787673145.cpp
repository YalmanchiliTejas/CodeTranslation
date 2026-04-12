#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
#define chmax(x, v)                                                            \
  do {                                                                         \
    x = max(x, v);                                                             \
  } while (0)
#define chmin(x, v)                                                            \
  do {                                                                         \
    x = min(x, v);                                                             \
  } while (0)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

ll K,N;
string s;

// i桁目から見て、そこまででj個の非zeroを使った時のパターン数
// ただし、k=0ならそこまでの桁が一致している
ll dp[110][10][2];

// i=0123456..
// s=314159

signed main() {
  cin >> s >> K;
  N = s.size();
  dp[0][0][1]=0;
  dp[0][0][0]=1;
  rep(i, N) rep(j, 10) rep(k,2) {
    // if (dp[i][j][k] == 0)
    //  continue;
    rep(d, 10) { // 次の桁を0~9のどれにするか
      ll nd = s[i]-'0'; // 次の桁にある数
      ll ni = i+1, nj = j, nk = k;
      if (d > 0) nj++;
      if (nj >= 10) continue; // 非ゼロが発生しすぎている
      if (k == 0) {
        if (d > nd) continue;
        if (d < nd) nk = 1; // 未満が確定
        if (d == nd) nk = 0; // 一致している
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  cout << dp[N][K][0] + dp[N][K][1] << endl;
  return 0;
}
