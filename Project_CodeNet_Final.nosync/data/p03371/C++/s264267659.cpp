#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
  int A,B,C,X,Y,ans,tmp,x,y,z;
  scanf("%d%d%d%d%d",&A,&B,&C,&X,&Y);
  ans = A*X+B*Y;
  x=X;
  y=Y;
  z=0;
  if(2*C < A+B){
    while(x >= 0 || y >= 0){
      x--;
      y--;
      z++;
      tmp = A*max(0,x)+B*max(0,y)+2*C*z;
      if(tmp < ans){
        ans = tmp;
      }
    }
  }
  printf("%d\n",ans );
  return 0;

}
