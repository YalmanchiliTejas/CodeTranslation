#include <iostream>

typedef long long ll;
const ll MOD = 1e9+7;

int N;
ll ar[200005];
ll sum[200005];

int main() {
  std::cin >> N;
  for (int i = 0; i < N; ++i)
    std::cin >> ar[i];

  sum[N-1] = ar[N-1] % MOD;
  for (int i = N-2; i >= 0; --i)
    sum[i] = (ar[i] + sum[i + 1]) % MOD;

  ll ans = 0;
  for (int i = 0; i < N-1; ++i)
    ans = (ans + (ar[i] * sum[i+1]) % MOD) % MOD;
  std::cout << ans << "\n";

  return 0;
}
