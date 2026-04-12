#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main(void) {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;
  int anss = 2 * c * max(x, y);
  if(a + b > c * 2) {
    int m = min(x, y);
    ans += c * 2 * m;
    x -= m;
    y -= m;
  }
  ans += a * x;
  ans += b * y;
  cout << min(ans, anss) << endl;

  return 0;
}