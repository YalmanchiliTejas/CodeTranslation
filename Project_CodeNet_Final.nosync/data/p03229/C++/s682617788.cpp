#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &e : a)
    cin >> e;
  sort(a.begin(), a.end());
  ll sum = 0;
  vector<ll> small, big;
  for (int i = 0; i < n; ++i)
  {
    if (i < n / 2)
      small.push_back(a[i]);
    else
      big.push_back(a[i]);
  }
  reverse(big.begin(), big.end());
  for (int i = 0; i < n / 2; ++i)
  {
    if (i == 0)
      sum += abs(big[0] - small[0]);
    if (i < big.size() - 1)
      sum += abs(big[i + 1] - small[i]);
    if (i < small.size() - 1)
      sum += abs(big[i] - small[i + 1]);
  }
  ll ans = sum;
  small.clear();
  big.clear();
  sum = 0;
  for (int i = 0; i < n; ++i)
  {
    if (i < (n - 1) / 2 + 1)
      small.push_back(a[i]);
    else
      big.push_back(a[i]);
  }
  reverse(big.begin(), big.end());
  for (int i = 0; i < n / 2; ++i)
  {
    if (i == 0)
      sum += abs(big[0] - small[0]);
    if (i < big.size() - 1)
      sum += abs(big[i + 1] - small[i]);
    if (i < small.size() - 1)
      sum += abs(big[i] - small[i + 1]);
  }
  ans = max(ans, sum);
  cout << ans << endl;

  return 0;
}
