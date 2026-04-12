#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t A, B, C, a, b, X, Y, cost, ans = 5000 * 100000 * 2;
  cin >> A >> B >> C >> X >> Y;
  int64_t maxc = max(X, Y) * 2;
  for (int64_t c = 0; c <= maxc; c += 2)
  {
    a = (X - c / 2) >= 0 ? (X - c / 2) : 0;
    b = (Y - c / 2) >= 0 ? (Y - c / 2) : 0;
    cost = A * a + B * b + C * c;
    ans = cost < ans ? cost : ans;
    cost = 0;
  }
  cout << ans << endl;
}