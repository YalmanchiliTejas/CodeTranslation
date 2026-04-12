/**
 *     author: qodjf
 *     created: 04.18.2020 02:04:55
 */
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  vector<ll> dp(N + 10, 0);

  ll sum = 0;
  for (int i = N - 1; i >= 1; i -= 2) {
    sum += a[i];
    dp[i - 1] = max(a[i - 1] + dp[i + 1], sum);
  }
  for (int i = N - 3; i >= 0; i -= 2) {
    dp[i] = max(dp[i + 2] + a[i], dp[i + 1]);
  }
  cout << dp[0] << endl;
}
