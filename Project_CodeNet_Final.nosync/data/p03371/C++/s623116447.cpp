#include <cstdio>
#include <algorithm>

using namespace std;

int A, B, C, X, Y;

int div_up(int a, int b){
  if(a%b == 0){
    return a/b;
  }else{
    return a/b + 1;
  }
}

int calc(int a, int b, int ab){
  return a*A + b*B + ab*C;
}

int main(){
  scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);

  int res = X*max(A, 2*C) + Y*max(B, 2*C);
  for(int n_ab=0; n_ab <= 2*max(X, Y); n_ab++){
    int n_a = max(0, div_up(2*X - n_ab, 2));
    int n_b = max(0, div_up(2*Y - n_ab, 2));
    res = min(res, calc(n_a, n_b, n_ab));
  }
  printf("%d\n", res);

  
  return 0;
}
