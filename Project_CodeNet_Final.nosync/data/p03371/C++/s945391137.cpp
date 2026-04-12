#include <stdio.h>
#include <iostream>
int main(void){
  int a,b,c,x,y;
  int min,cost;
  std::cin >> a >> b >> c >> x >> y;
  if(a+b <= c*2){
    printf("%d",a*x+b*y);
    return 0;
  }
  if(x < y){
    min = x;
  }else{
    min = y;
  }
  cost = 2*min*c;
  if(a < 2*c && min == y){
    cost += (x-y)*a;
  }else if(b < 2*c && min == x){
    cost += (y-x)*b;
  }else if(min == x){
    cost += 2*c*(y-x);
  }else if(min == y){
    cost += 2*c*(x-y);
  }
  printf("%d",cost);
  return 0;
}