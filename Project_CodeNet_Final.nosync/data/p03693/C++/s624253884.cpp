// https://atcoder.jp/contests/

#include <iostream>
using namespace std;

int main()
{
  /* Magic word */
  cin.tie(0);
  ios::sync_with_stdio(false);
  /* ---------- */

  int r, g, b;

  cin >> r >> g >> b;

  if ((10 * g + b) % 4 == 0)
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';

  return 0;
}
