#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  bool flag = false;
  if(a + b <= 2 * c) flag = true;
  long long ans = 0;
  if(flag){
    ans += a * x + b * y;
  }else{
    if(x < y){
      ans += x * c * 2;
      long long temp = b * (y - x);
      ans += min(temp, (long long) c * 2 * (y - x));
    }else if(x > y){
      ans += y * c * 2;
      long long temp = a * (x - y);
      ans += min(temp, (long long) c * 2 * (x - y));
    }else{
      ans += x * c * 2;
    }
  }
  cout << ans << endl;
  return 0;
}
