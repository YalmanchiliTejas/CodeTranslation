#include <stdio.h>

int main(){
  int X,Y,Z,hoge;
  
  scanf("%d %d %d",&X,&Y,&Z);
  
  hoge = (X-Z)/(Y+Z);
  
  printf("%d",hoge);
}