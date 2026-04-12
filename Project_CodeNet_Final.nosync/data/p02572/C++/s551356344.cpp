#include <iostream>

using namespace std;

long long arr[200000];
long long sum[200001];

constexpr long long K = 1000000007;

int main(void) {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  for (auto i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (auto i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + arr[i];
  }

  auto result = 0LL;
  for (auto i = 0; i < n; i++) {
    result += arr[i] * ((sum[n] - sum[i + 1]) % K) % K;
    result %= K;
  }

  cout << result << '\n';

  return 0;
}
