#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){

  int a, b, c, x, y;

  cin >> a >> b >> c >> x >> y;
  int sum;


  int min1 = a * x + b * y;
  if (x > y){
    min1 = min(min1, y * c * 2+ (x - y) * a);
  }else{
    min1 = min(min1, x * c * 2 + (y - x) * b);
  }
  min1 = min(min1, max(x, y) * c * 2);

  cout << min1 << endl;

  return 0;
}
