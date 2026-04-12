#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll mod = 1'000'000'007;

auto main (void) -> int {
  int n;
  cin >> n;

  vector<int> a (n);
  for (auto i = 0; i < n; i++) cin >> a[i];

  ll tmp_0 = 0;
  ll tmp_1 = 0;

  for (auto i = 0; i < n; i++) {
    ll c  = static_cast<ll> (a[i]);
    tmp_0 = (tmp_0 + c) % mod;
    tmp_1 = (tmp_1 + c * c) % mod;
  }
  tmp_0 = (tmp_0 * tmp_0) % mod;

  ll b = tmp_0 < tmp_1 ? tmp_0 - tmp_1 + mod : tmp_0 - tmp_1;

  if (b % 2 != 0) {
    cout << (b + mod) / 2 << endl;
  }
  else {
    cout << b / 2 << endl;
  }

  return 0;
}
