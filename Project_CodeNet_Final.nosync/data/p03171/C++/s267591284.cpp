#include <iostream>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
int N;
int A[3000];
ll dp[3001][3001]; // dp[l][r] = 左からl個、右からr個とった状態からスタートしたときのX-Y
const ll INF = 1e15;

ll dfs(int l, int r) {
  if (l + r == N) return 0;
  if (dp[l][r] != INF) return dp[l][r];

  if ((l+r) % 2 == 0)
    return dp[l][r] = max(dfs(l+1, r) + A[l], dfs(l, r+1) + A[N-1-r]);
  return dp[l][r] = min(dfs(l+1, r) - A[l], dfs(l, r+1) - A[N-1-r]);
}
int main() {
  cin >> N;

  rep(i, N)
    cin >> A[i];

  rep(i, N+1) rep(j, N+1) dp[i][j] = INF;

  cout << dfs(0, 0) << endl;
  return 0;
}
