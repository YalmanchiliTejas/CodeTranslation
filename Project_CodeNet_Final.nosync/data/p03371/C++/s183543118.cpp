#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int cost1, cost2, cost3, cost4, cost5;
  cost1 = A * X + B * Y;
  cost2 = A * max(X - Y, 0) + 2 * C * Y;
  cost3 = 2 * C * X + B * max(Y - X, 0);
  cost4 = 2 * C * max(X, Y);

  int ans = min({cost1, cost2, cost3, cost4});
  cout << ans << endl;
  return 0;
}