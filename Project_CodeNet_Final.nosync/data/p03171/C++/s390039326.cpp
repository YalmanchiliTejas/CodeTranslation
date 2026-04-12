#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

long long dp[3100][3100];

int main()
{
  int N;
  cin >> N;
  vector<long long> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int w = 1; w <= N; w++) {
    for (int i = 0; i + w <= N; i++) {
      int j = i + w;
      if ((N - w) % 2 == 0)
        dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
      else
        dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
    }
  }

  cout << dp[0][N] << endl;
  return 0;
}