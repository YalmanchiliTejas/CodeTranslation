#include <iostream>

using namespace std;

int A, B, C, X, Y;

int res = 0;

int main()
{
  cin >> A >> B >> C >> X >> Y;
  if (A + B < 2 * C)
  {
    res = A * X + B * Y;
  }
  else if (A + B >= 2 * C && X > Y && A > 2 * C)
  {
    res = Y * C * 2 + (X - Y) * 2 * C;
  }
  else if (A + B >= 2 * C && Y >= X && B > 2 * C)
  {
    res = X * C * 2 + (Y - X) * 2 * C;
  }
  else if (A + B >= 2 * C && X > Y && A <= 2 * C)
  {
    res = Y * C * 2 + (X - Y) * A;
  }
  else if (A + B >= 2 * C && Y >= X && B <= 2 * C)
  {
    res = X * C * 2 + (Y - X) * B;
  }
  cout << res << endl;
  return 0;
}