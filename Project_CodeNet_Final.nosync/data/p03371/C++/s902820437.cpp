#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  if (2 * c < a && 2 * c < b) {
    cout << 2 * c * max(x, y) << endl;
    return 0;
  }
  int pay = 0;
  if (2 * c < a + b) {
    int m = min(x, y);
    pay += 2 * c * m;
    x -= m;
    y -= m;
  }
  if (x) {
    pay += x * min(2 * c, a);
  }
  if (y) {
    pay += y * min(2 * c, b);
  }

  cout << pay << endl;
  return 0;
}

