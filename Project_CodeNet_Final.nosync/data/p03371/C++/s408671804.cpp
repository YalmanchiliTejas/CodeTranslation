#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int a, b, c, x, y;
  int ab, n, m, sum = 0;

  cin >> a >> b >> c >> x >> y;

  ab = min(a + b, c * 2);
  n = min(a, c * 2);
  m = min(b, c * 2);

  while(x > 0 && y > 0){
    x--; y--;
    sum += ab;
  }

  sum += x * n;
  sum += y * m;

  cout << sum << endl;

  return 0;
}