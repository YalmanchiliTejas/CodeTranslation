// https://atcoder.jp/contests/abc055/tasks/abc055_a

#include <iostream>
using namespace std;

int main()
{
  /* Magic word */
  cin.tie(0);
  ios::sync_with_stdio(false);
  /* ---------- */

  int n, r;

  cin >> n;

  r = n * 800 - (int)(n / 15) * 200;

  cout << r << "\n";

  return 0;
}
