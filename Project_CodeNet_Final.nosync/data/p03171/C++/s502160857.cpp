#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  function<int64_t(int, int)> dfs = [&](int lb, int rb) {
    static int64_t dp[3001][3001];
    static bool   vis[3001][3001];
    if (vis[lb][rb]) return dp[lb][rb];
    if (lb == rb) return (int64_t) 0;
    vis[lb][rb] = 1;
    return dp[lb][rb] = max(A[lb] - dfs(lb + 1, rb), A[rb - 1] - dfs(lb, rb - 1));
  };

  cout << dfs(0, N) << endl;

  return 0;
}
