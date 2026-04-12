#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int X, Y, Z;
  cin >> X >> Y >> Z;
  X -= Y + 2 * Z;
  int ans = 1 + X / (Y + Z);
  cout << ans << endl;
  return 0;
}