#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
  int a, b, c, x, y;
  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
  
  int price = 0;
  int mini = min(x, y);
  int sum1 = a*mini + b*mini;
  int sum2 = c*mini*2;
  if (sum1 > sum2) {
    price = min(sum2 + (x-mini)*a + (y-mini)*b, sum2 + (x-mini)*c*2 + (y-mini)*c*2);
  } else {
    price = min(sum1 + (x-mini)*a + (y-mini)*b, sum1 + (x-mini)*c*2 + (y-mini)*c*2);
  }
  
  printf("%d\n", price);
}