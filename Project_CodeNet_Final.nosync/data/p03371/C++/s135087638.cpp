#include <bits/stdc++.h>
using namespace std;
int main() {
  long int a, b, c, x, y, result, result1, result2, result3;
  result = result1 = result2 = result3 = 0;
  cin >> a >> b >> c >> x >> y;
  result1 = (a * x) + (b * y);
  if (x < y) {
    result2 = (c * x * 2) + (b * (y - x));
    result3 = (c * y * 2);
  } else if (x > y) {
    result2 = (c * y * 2) + (a * (x - y));
    result3 = (c * x * 2);
  } else if (x == y) {
    result2 = (c * y * 2) + (a * (x - y));
    result3 = (c * x * 2);
  }
  if (result1 < result2 && result2 < result3) {
    result = result1;
  } else if (result1 > result2 && result2 < result3) {
    result = result2;
  } else if (result1 < result2 && result2 > result3) {
    if (result1 < result3) {
      result = result1;
    } else {
      result = result3;
    }
  } else {
    result = result3;
  }
  cout << result << endl;
}