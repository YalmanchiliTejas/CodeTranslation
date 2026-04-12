/*
 * atcoder/dp_2nd/l.cpp
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

// Nが奇数で最後1つ(j-i==1) dp[i][j] = +a_i
// Nが偶数で最後1つ(j-i==1) dp[i][j] = -a_i
// Nが奇数で最後2つ(j-i==2) dp[i][j] = - min(dp[i+1][j] - a_i, dp[i][j-1] - a_j)
// Nが偶数で最後2つ(j-i==2) dp[i][j] = + max(dp[i+1][j] + a_i, dp[i][j-1] + a_j)
// Nが奇数で最後3つ(j-i==3) dp[i][j] = + max(dp[i+1][j] + a_i, dp[i][j-1] + a_j)
// Nが偶数で最後3つ(j-i==3) dp[i][j] = - min(dp[i+1][j] - a_i, dp[i][j-1] - a_j)
// Nが奇数で最後Nつ(j-i==N) dp[0][N] = ...同上...
// Nが偶数で最後Nつ(j-i==N) dp[0][N] = ...同上...

const int MAX = 3100;
ll N;
vector<ll> A;
ll dp[MAX][MAX];

void input() {
  cin >> N;
  ll a;
  loop(n,0,N) {
    cin >> a;
    A.push_back(a);
  }
}

ll minmax(ll a, ll b, int sign) {
  if (sign > 0) return max(a, b);
  return min(a, b);
}

void solve() {
  for (int len=1; len <=N; len++) {
    for (int l=0; l+len <=N; l++) {
      int sign = ((N + len)%2 == 0) ? 1 : -1;
      if (len == 1) { dp[l][l+1] = sign * A[l]; continue; }
      int r = l + len;
      dp[l][r] = minmax(dp[l+1][r] + sign * A[l], dp[l][r-1] + sign * A[r-1], sign);
    }
  }
  cout << dp[0][N] << endl;
}

void dump() {
  for (int len=1; len <=N; len++) {
    for (int l=0; l+len <=N; l++) {
      int sign = ((N + len)%2 == 0) ? 1 : -1;
      cout << "[" << l << ": " << (l+len-1) << "] dp = " << dp[l][l+len] << " sign = " << sign << endl;
    }
  }
}

int main() {
  // cout.precision(15);
  input();
  solve();
  // dump();
  return 0;
}
