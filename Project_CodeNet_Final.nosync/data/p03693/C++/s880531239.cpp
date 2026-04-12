#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int r, g, b;
  cin >> r >> g >> b;

  int d = r * 100 + g * 10 + b;
  if (d % 4) cout << "NO\n";
  else cout << "YES\n";

  return (0);
}
