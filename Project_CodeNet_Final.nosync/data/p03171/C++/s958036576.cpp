#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define in(v) v; cin >> v;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)

const int MAX_N = 3001;
ll dp[MAX_N][MAX_N];
int A[MAX_N];
int N;
const ll INF = 1e13;
ll dfs(int a, int b) {
  if (a + b == N)
    return 0;
  if (dp[a][b] != INF)
    return dp[a][b];

  if ((a + b) % 2 == 0)
    return dp[a][b] = max(dfs(a+1, b) + A[a], dfs(a, b+1) + A[N-b-1]);
  return dp[a][b] = min(dfs(a+1, b) - A[a], dfs(a, b+1) - A[N-b-1]);
}
int main() {
  in(N);
  rep(i, MAX_N) rep(j, MAX_N) dp[i][j] = INF;
  rep(i, N)
    cin >> A[i];

  cout << dfs(0, 0) << endl;
  return 0;
}
