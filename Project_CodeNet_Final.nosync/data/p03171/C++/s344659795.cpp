/*
 * atcoder/dp_3rd/l.cpp
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

#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
template <class T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template <class T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }

const int MAX = 3100;
ll N;
vector<ll> A;

/*
 * dp[l][r] := [l:r) まで取った時のX-Y
 * dp[l][r] = A[l] if r-l==1 and First
 * dp[l][r] = -A[l] if r-l==1 and not First
 * dp[l][r] = max(dp[l+1][r] + A[l], dp[l][r-1] + A[r-1]) if First
 * dp[l][r] = min(dp[l+1][r] - A[l], dp[l][r-1] - A[r-1]) if not First
 * First = (N-(r-l))%2==0
 */
ll dp[MAX][MAX] = {0};

void input() {
  cin >> N;
  ll a;
  loop(n,0,N) {
    cin >> a;
    A.push_back(a);
  }
}

ll minmax(ll a, ll b, int sign) {
  if (sign < 0) return min(a, b);
  else return max(a, b);
}

void solve() {
  for (int len=1; len<=N; len++) {
    int sign = ((N-len)%2==0) ? 1 : -1;
    for (int l=0; l+len<=N; l++) {
      if (len==1) { dp[l][l+len] = sign * A[l]; continue; }
      int r = l+len;
      dp[l][r] = minmax(dp[l+1][r] + sign * A[l], dp[l][r-1] + sign * A[r-1], sign);
    }
  }
  cout << dp[0][N] << endl;
}

int main() {
  // cout.precision(15);
  input();
  solve();
  return 0;
}
