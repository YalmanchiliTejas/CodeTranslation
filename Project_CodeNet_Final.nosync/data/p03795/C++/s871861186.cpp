#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int ans = 800 * n;
  ans -= 200 * (n / 15);

  cout << ans << '\n';

  return (0);
}
