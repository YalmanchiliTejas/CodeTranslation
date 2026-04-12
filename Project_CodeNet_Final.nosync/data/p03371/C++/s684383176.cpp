#include <iostream>
using namespace std;

int a, b , c , x ,y;

int main() {
  cin >> a >> b >> c >> x >> y;
  int total = 0;
  if (a + b > c * 2) {
    if (x > y) {
      if (a > c * 2) {
        total = c * x * 2;
      }
      else {
      	total = c * y * 2+ a * (x - y);
      }
    } else {
      if ( b > c * 2) {
        total = c * y * 2;
      } else {
        total = c * x * 2+ b * (y - x);
      }
    }
  } else {
   total = a * x + b * y; 
  }
  cout << total;
}
