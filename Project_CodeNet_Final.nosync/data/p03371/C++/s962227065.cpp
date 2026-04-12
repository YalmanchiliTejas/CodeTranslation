#include <stdio.h>

int main(void)
{
  int num;
  int a,b,c,x,y;
  
  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
  
  if(a+b<=2*c){
    printf("%d", a*x+b*y);
    return 0;
  }
  else{
    if(x>y){
      num=x-y;
      if(a>=2*c){
        printf("%d", 2*x*c);
        return 0;
      }
      else{
        printf("%d", 2*y*c+(x-y)*a);
        return 0;
      }
    }
    else{
       num=y-x;
      if(b>=2*c){
        printf("%d", 2*y*c);
        return 0;
      }
      else{
        printf("%d", 2*x*c+(y-x)*b);
        return 0;
      }
    }
  }
}