#include<stdio.h>

int main(void){
  int A,B,C,X,Y;
  scanf("%d",&A);
  scanf("%d",&B);
  scanf("%d",&C);
  scanf("%d",&X);
  scanf("%d",&Y);
  int a=0;
  int b=0;
  int c=0;
  int min = A*X + B*Y;
  a = X;
  b = Y;
  while(c<2*X || c<2*Y){
    if(a>0){
    a--;
    }
    if(b>0){
    b--;
    }
    c += 2;
    
    
    int x = a*A + b*B + c*C;
    if(x<min){
      min = x;
    }
  }
  printf("%d",min);
  return 0;
}
