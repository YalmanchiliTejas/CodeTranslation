#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>

int main(){
  int A, B, C, X, Y;
  scanf("%d", &A);
  scanf("%d", &B);
  scanf("%d", &C);
  scanf("%d", &X);
  scanf("%d", &Y);
  int minXY = std::min(X, Y);
  long long ans = 0;
  if (A+B>2*C){
    ans += minXY*C*2;
  } else {
    ans += minXY*(A+B);
  }
  if (X>Y){
    if (A<2*C){
      ans += (long long)A*(X-minXY);
    } else {
      ans += (long long)2*C*(X-minXY);
    }
  } else {
    if (B<2*C){
      ans += (long long)B*(Y-minXY);
    } else {
      ans += (long long)2*C*(Y-minXY);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
