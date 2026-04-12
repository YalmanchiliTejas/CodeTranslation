#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

int a, b, c, x, y;
int ans;

int main() {
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &x);
  scanf("%d", &y);
  if(c * 2 >= a + b) {
    ans += a * x;
    ans += b * y;
    printf("%d\n", ans);
    return 0;
  } else {
    if(x < y) {
      ans += c  * 2 * x;
      if(c * 2 >= b) {
        ans += b * (y - x);
      } else {
        ans += c * 2 * (y - x);
      }
    } else {
      ans += c * 2 * y;
      if(c * 2 >= a) {
        ans += a * (x - y);
      } else {
        ans += c * 2 * (y - x);
      }
    }
    printf("%d\n", ans);
    return 0;
  }
}
