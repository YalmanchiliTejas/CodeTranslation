#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int a, b, ab; cin >> a >> b >> ab;
  int x, y;     cin >> x >> y;
  int cost = 0;
  int nab = min(x, y);
  if (a + b < 2 * ab)
    cost += nab * (a + b);
  else
    cost += nab * (2 * ab);
  x -= nab; y -= nab;
  if (x != 0)
  {
    if (a < 2*ab)
      cost += a * x;
    else
      cost += 2 * ab * x;
  }
  else
  {
    if (b < 2*ab)
      cost += b * y;
    else
      cost += 2 * ab * y;
  }
  cout << cost << endl;
}