#include<stdio.h>
 int main(void){
 int r;
 int g;
 int b;
 scanf("%d",&r);
 scanf("%d",&g);
 scanf("%d",&b);
   int sum;
   sum=100*r+10*g+b;
  if (sum%4==0){
    printf("YES\n");
  }else{
    printf("NO\n");
  } 
 
 return 0;
 }