#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  long long int a, b, c, x, y;
  long long int sum = 0;
  cin >> a >> b >> c >> x >> y;
  if (x > y) {
    if (a*x + b*y > 2*c*y + a*(x-y)) sum = 2*c*y + a*(x-y);
    else sum = a*x + b*y;
    if (2*c*x < sum) sum = 2*c*x;
  }
  else {
    if (a*x + b*y > 2*c*x + b*(y-x)) sum = 2*c*x + b*(y-x);
    else sum = a*x + b*y;
    if (2*c*y < sum) sum = 2*c*y;
  }
  cout << sum  << endl;
  return 0;
}
