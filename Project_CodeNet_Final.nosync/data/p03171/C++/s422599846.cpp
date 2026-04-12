#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
#define REP(i,n) for (int i = 0; i < n; ++i)

const int MAX = 3019;
const ll INF = 1e15;
int N, K;
ll dp[MAX][MAX];
int A[MAX];

ll solve(int l, int r) {
  if (l+r == N) return 0;
  if (dp[l][r] > -INF) return dp[l][r];
  if ((l+r)%2 == 0)
    dp[l][r] = max(solve(l+1, r) + A[l], solve(l, r+1) + A[N-1-r]);
  else
    dp[l][r] = min(solve(l+1, r) - A[l], solve(l, r+1) - A[N-1-r]);
  return dp[l][r];
}

int main () {
  cin >> N;
  REP (i, N) cin >> A[i];
  REP (i, MAX) REP (j, MAX) dp[i][j] = -INF;
  ll ans = solve(0, 0);
  cout << ans << endl;
}