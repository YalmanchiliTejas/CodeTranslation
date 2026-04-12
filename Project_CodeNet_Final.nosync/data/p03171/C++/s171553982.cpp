#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, 0));
  for (int d = 1; d <= N; d++){
    for (int i = 0; i <= N - d; i++){
      int j = i + d;
      if ((N - d) % 2 == 0){
        dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
      } else {
        dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
      }
    }
  }
  cout << dp[0][N] << endl;
}