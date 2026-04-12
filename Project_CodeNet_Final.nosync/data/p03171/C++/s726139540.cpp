#include <bits/stdc++.h>
using namespace std;

template <typename T = int64_t>
static constexpr auto inf = static_cast <T> (0x0de0b6b43b9aca00);

auto main () -> int
{
  cin.tie (nullptr);
  ios::sync_with_stdio (false);

  size_t n;
  cin >> n;

  vector <int64_t> a (n);
  for (auto && elem : a) cin >> elem;

  vector <vector <int64_t>> dp (n + 1, vector <int64_t> (n + 1, - inf <>));

  auto f = [&] (auto self, auto i, auto j) {
    if (dp[i][j] > - inf <>) return dp[i][j];
    if (i + 1 == j) return dp[i][j] = a[i];
    return dp[i][j] = max (a[i] - self (self, i + 1, j), a[j - 1] - self (self, i, j - 1));
  };

  cout << f (f, size_t {0}, n) << endl;
}
