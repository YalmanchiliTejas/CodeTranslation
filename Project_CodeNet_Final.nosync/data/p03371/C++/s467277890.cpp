#include <iostream>
using namespace std;
int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int a_b = a*x + b*y;
  int c_a_b = (y > x) ? (y-x)*b + x*c*2 : (x-y)*a + y*c*2;
  int c_o = (x > y) ? x*c*2 : y*c*2;
  cout << min(min(a_b, c_a_b), c_o) << endl;
}
    