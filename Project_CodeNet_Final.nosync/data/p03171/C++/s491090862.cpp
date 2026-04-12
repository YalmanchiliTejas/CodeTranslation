#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  long long a[N], dp[N][N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  dp[0][0] = a[0];
  for (int j = 1; j < N; j++) {
    dp[j][j] = a[j];
    for (int i = j-1; i+1; i--) {
      dp[i][j] = max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
    }
  }
  cout << dp[0][N-1];
}