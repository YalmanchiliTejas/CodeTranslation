#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;

string dp[60];

int main()
{
  ll n, x;
  cin >> n >> x;

  ll p = 1, b = 1;
  ll pp[60] = {}, bb[60] = {};
  for (int i = 0; i <= n; ++i)
  {
    p *= 2, b *= 2;
    pp[i] = p - 1, bb[i] = b - 2;
  }
  p -= 1, b -= 2;

  ll ans = 0;
  ll i = n;

  while (x > 0)
  {
    if (x < pp[i] + bb[i])
    {
      i--, x--;
    }
    else if (x > pp[i] + bb[i])
    {
      ans += pp[i];
      x -= pp[i] + bb[i];
      if (x > 0)
      {
        x -= 1, ans++;
      }
    }
    else
    {
      ans += pp[i];
      x = 0;
    }
  }
  cout << ans << endl;

  return 0;
}
