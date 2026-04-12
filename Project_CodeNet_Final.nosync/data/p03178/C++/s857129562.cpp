/*
 * atcoder/dp_2nd/s.cpp
 */

// C++ 14
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <cassert>

using namespace std;

#define ll long long
#define MOD 1000000007

#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
template <class T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template <class T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }

const int MAX_K = 10100;
const int MAX_D = 120;
int D, N;
string K;

ll dp[2][MAX_K][MAX_D];

void input() {
  cin >> K >> D;
  N = K.size();
}

/*
 * n: 今何桁目
 * d: 今までの合計 (MOD D)
 * l: 次の桁の数字を制限するか
 */
ll rec(int n = 0, int d = 0, bool l = true) {
  ll &cache = dp[l][n][d];
  if (~cache) return cache;
  if (n == N) return cache = d == 0;
  int u = l ? K[n] - '0' : 9;
  ll ways = 0;
  for (int i=0; i<=u; i++) {
    ways += rec(n + 1, (d + i) % D, l && i == u);  // 一度でも制限解除されると最後の桁まで制限なし.
    ways %= MOD;
  }
  return cache = ways;
}

void memoRec() {
  memset(dp, -1, sizeof(dp));
  ll ways = (rec() - 1 + MOD) % MOD; // 1<= なので0の分を引く
  cout << ways << endl;
}

void give() {
  memset(dp, 0, sizeof(dp));
  dp[1][0][0] = 1;
  for (int n=0; n<N; n++) {
    for (int d=0; d<D; d++) {
      for (int l=0; l<=1; l++) {
        for (int i=0; i<=9; i++) {
          if (l && i > K[n] - '0') continue;
          int nl = (l && i == K[n] - '0') ? 1 : 0;
          dp[nl][n+1][(d+i)%D] += dp[l][n][d];
          dp[nl][n+1][(d+i)%D] %= MOD;
        }
      }
    }
  }

  ll ans = dp[0][N][0];
  ans += dp[1][N][0];
  ans--;
  ans = (ans + MOD) % MOD;
  cout << ans << endl;
}

void solve() {
  give();
}

int main() {
  // cout.precision(15);
  input();
  solve();
  return 0;
}
