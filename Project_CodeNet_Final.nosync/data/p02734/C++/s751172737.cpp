#include "bits/stdc++.h"

using namespace std;

using u32 = uint32_t;
using u64 = uint64_t;
using i64 = int64_t;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = (b-1); i >= a; i--)
#define RF0(i,b) RFO(i,0,b)
#define F first
#define S second
#define ADD(a,b) (((u64)a + b)%MOD)
#define MUL(a,b) (((u64)a * b)%MOD)

constexpr int MOD = 998244353;

#if 1
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, S;
  cin >> N >> S;

  vector<int> A(N);
  F0R(i, N) {
    cin >> A[i];
  }

  // dp[N][S]<patternCount, patternCountIncrement>
  vector<vector<pair<u32, u32>>> dp(N, vector<pair<u32, u32>>(S + 1));

  F0R(i, N) {
    int num = A[i];
    F0R(j, S + 1) {
      if (i > 0) {
        dp[i][j].first = dp[i - 1][j].first + dp[i - 1][j].second;
        dp[i][j].second = dp[i - 1][j].second;

        if (j > num) {
          dp[i][j].first += dp[i - 1][j - num].second;
          dp[i][j].second += dp[i - 1][j - num].second;
        }
      }

      if (j == num) {
        dp[i][j].first += i + 1;
        dp[i][j].second += i + 1;
      }

      dp[i][j].first %= MOD;
      dp[i][j].second %= MOD;

      //cout << dp[i][j].first << "+" << dp[i][j].second << ' ';
    }
    //cout << '\n';
  }

  cout << dp[N - 1][S].first;
}

#else
// テストデータを生成する
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  constexpr int N = 100;
  constexpr int S = 100;

  cout << N << ' ' << S << '\n';

  // Generate Random
#if 0
  int rmin = (int)(S / N), rmax = (int)(S * 3 / N);

  random_device seedGen;
  mt19937 engine(seedGen());
  uniform_int_distribution<> dist(rmin, rmax);

  F0R(i, N) {
    cout << dist(engine) << ' ';
  }
#endif

  // Generate Shorter
#if 1
  int a = 1, ap = max(1, S / N);
  F0R(i, N) {
    cout << (a++) << ' ';
  }
#endif

  cout << '\n';
}
#endif