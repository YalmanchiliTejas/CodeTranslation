#include<stdio.h>
int main(void){
  int r;
  int g;
  int b;
  1<=r,g,b;
  r,g,b<=9;
  scanf("%d",&r);
  scanf("%d",&g);
  scanf("%d",&b);
  if((r*100+g*10+b)%4==0){
    printf("YES");
  }else{
    printf("NO");
  }
}
  