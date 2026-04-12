// https://atcoder.jp/contests/abc114/tasks/abc114_a

#include <iostream>
using namespace std;

int main()
{
  /* Magic word */
  cin.tie(0);
  ios::sync_with_stdio(false);
  /* ---------- */

  int x;
  string r;

  cin >> x;

  r = x == 3 || x == 5 || x == 7 ? "YES" : "NO";

  cout << r << '\n';

  return 0;
}
