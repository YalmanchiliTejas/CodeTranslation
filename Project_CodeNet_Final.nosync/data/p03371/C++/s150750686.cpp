#include <iostream>

using namespace std;
int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  if(a+b <= 2*c) {
    cout << a*x + b*y << endl;
  } else {
    if(x == y) {
      cout << c*(x+y) << endl;
    } else if(x > y) {
      cout << min(2*c*y + a*(x-y), 2*c*x) << endl;
    } else {
      cout << min(2*c*x + b*(y-x), 2*c*y) << endl;
    }
  }
  return 0;
}
