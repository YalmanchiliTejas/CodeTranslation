#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  if (a + b >= 2 * c)
  {
    long long ans = min(x, y) * 2 * c;
    if (x < y)
    {
      ans += min((y - x) * b, 2 * (y - x) * c);
    }
    else if (x > y)
    {
      ans += min((x - y) * a, 2 * (x - y) * c);
    }
    cout << ans << endl;
  }
  else
  {
    long long ans = x * a + y * b;
    cout << ans << endl;
  }
}