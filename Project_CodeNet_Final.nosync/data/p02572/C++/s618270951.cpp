#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  valarray<int64_t> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  const int64_t mod = 1000000007;
  int64_t sum = a.sum() % mod;
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    sum -= a[i];
    if (sum < 0) sum += mod;
    ans += a[i] * sum;
    ans %= mod;
  }
  cout << ans << endl;
}
