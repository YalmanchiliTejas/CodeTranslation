#include <iostream>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
#define rrep(i,n) for(long long i=(n);i>=0;--i)

int A[3000];
ll dp[3001][3001]; // dp[l][r] = 左からl個、右からr個とった状態からスタートしたときのX-Y
const ll INF = 1e15;
int main() {
  int N; cin >> N;
  rep(i, N) cin >> A[i];
  rep(i, N+1) rep(j, N+1) dp[i][j] = 0;

  rrep(l, N) rrep(r, N) {
    if (l + r >= N)
      continue;
    dp[l][r] = ((l+r) % 2 == 0)
      ? max(dp[l+1][r] + A[l], dp[l][r+1] + A[N-1-r])
      : min(dp[l+1][r] - A[l], dp[l][r+1] - A[N-1-r]);
  }

  cout << dp[0][0] << endl;
  return 0;
}
