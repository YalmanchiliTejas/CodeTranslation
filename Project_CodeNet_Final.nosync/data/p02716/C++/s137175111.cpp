#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll dp[200005][2];

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  dp[0][1] = A[0];
  dp[1][1] = max(A[0], A[1]);
  for (int i = 2; i < N; i++) {
    if (i%2 == 0) {
      dp[i][0] = max(dp[i-1][1], dp[i-2][0] + A[i]);
      dp[i][1] = dp[i-2][1] + A[i];
    } else {
      dp[i][0] = max(dp[i-1][0], dp[i-2][0] + A[i]);
      dp[i][1] = max(dp[i-1][1], dp[i-2][1] + A[i]);
    }
  }
  if (N%2 == 0) {
    cout << dp[N-1][1] << '\n';
  } else {
    cout << dp[N-1][0] << '\n';
  }
  return 0;
}