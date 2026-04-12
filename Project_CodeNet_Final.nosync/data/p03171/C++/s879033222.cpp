#include <bits/stdc++.h>

using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  vector < int > a(N);
  vector < vector < long long > > dp (N, vector < long long > (N, 0));
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    dp[i][i] = a[i];
  }
  for (int L = N - 2; L >= 0; --L)
    for (int R = L + 1; R < N; ++R)
      dp[L][R] = max (a[L] - dp[L + 1][R], a[R] - dp[L][R - 1]);
  cout << dp[0][N - 1];
}
