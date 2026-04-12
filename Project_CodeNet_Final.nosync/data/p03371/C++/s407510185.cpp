#include <bits/stdc++.h>
int main(void){
  int a, b, c, x, y, ans;
  std::cin >> a >> b >> c >> x >> y;
  if(x < y){
    int tmp;
    tmp = x; x = y; y = tmp;
    tmp = a; a = b; b = tmp;
  }
  ans = std::min(2 * x * c, 2 * y * c + (x - y) * a);
  ans = std::min(ans, x * a + y * b);
  std::cout << ans << std::endl;
  return 0;
}
