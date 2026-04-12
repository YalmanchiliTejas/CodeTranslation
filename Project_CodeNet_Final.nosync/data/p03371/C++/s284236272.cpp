#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
  int A, B, C, X, Y;
  int ans;
  scanf("%d%d%d%d%d", &A, &B, &C, &X, &Y);
  if (A+B < 2*C){
    ans = A * X + B * Y;
  }
  else{
    if (X > Y){
      int tmp = X;
      X = Y;
      Y = tmp;
      tmp = A;
      A = B;
      B = tmp;
    }
    ans = X * (2 * C);
    if (B <= 2*C){
      ans += (Y - X) * B;
    }
    else{
      ans += (Y - X) * 2 * C;
    }
  }
  printf("%d\n", ans);
  
  return 0;
}