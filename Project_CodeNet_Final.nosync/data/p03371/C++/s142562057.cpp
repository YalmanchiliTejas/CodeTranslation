#include <stdio.h>

int main(void){
  int A,B,C,X,Y,ans;
  scanf("%d%d%d%d%d",&A,&B,&C,&X,&Y);

  if(A+B < 2*C){
    ans = A*X+B*Y;
  }
  else{
    int temp=Y;
    if(X < Y)temp = X;
    ans = temp*2*C;
    if(X < Y){
      if(B < 2*C)
        ans += (Y-temp)*B;
      else
        ans += (Y-temp)*2*C;
    }
    else{
      if(A < 2*C)
        ans += (X-temp)*A;
      else
        ans += (X-temp)*2*C;
    }
  }
  printf("%d\n",ans);

  return 0;
}