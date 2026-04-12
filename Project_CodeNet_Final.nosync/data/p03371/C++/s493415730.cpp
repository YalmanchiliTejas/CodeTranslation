#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;
typedef long long ll;

int main()
{
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  ll ans = A * X + B * Y;
  ans = min(ans, 2 * C * max(X, Y));
  ll temp = 0;
  temp += 2 * C * min(X, Y);
  if (X > Y)
  {
    temp += A * (X - Y);
  }
  else
  {
    temp += B * (Y - X);
  }
  ans = min(ans, temp);

  cout << ans << endl;
}
