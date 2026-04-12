#include <iostream>
using namespace std;
int a, b, c, x, y, r;
int main() {
  cin >> a >> b >> c >> x >> y;
  r = min(a*x+b*y, c*2*max(x,y));
  r = min(r, min(x,y)*2*c+abs(x-y)*(x>y?a:b));
  cout << r;
  return 0;
}