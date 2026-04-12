#include <bits/stdc++.h>
using namespace std;
#define rep(i, from, to) for (int i = from; i < to; i++)
int main()
{
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int AB = 2 * C;
  int ans = AB * (X + Y);
  rep(i, 0, X + Y)
      ans = min(ans, AB * i + A * max(0, X - i) + B * max(0, Y - i));
  cout << ans << endl;
  return 0;
}