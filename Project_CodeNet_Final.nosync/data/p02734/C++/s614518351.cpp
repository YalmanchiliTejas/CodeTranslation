#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

const int MAX = 3005;
const ll MOD = 998244353;

ll dp[MAX][MAX];

int main() {
  int n, s;
  cin >> n >> s;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  dp[1][0] = dp[1][A[0]] = 1;
  for (int i = 1; i < n; ++i) rep(j, MAX) {
    dp[i+1][j] += (dp[i][j] * 2 - dp[i-1][j]) % MOD;
    if (j == 0 || j == A[i]) dp[i+1][j] += 1;
    if (j+A[i] < MAX) {
      dp[i+1][j+A[i]] += (dp[i][j] - dp[i-1][j]) % MOD;
    }
  }
  ll ans = (dp[n][s] % MOD + MOD) % MOD;
  cout << ans << endl;
  return 0;
}