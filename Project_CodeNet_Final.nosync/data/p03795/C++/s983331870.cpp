#include<stdio.h>
int main(void){
  int n;
  scanf("%d",&n);
  int ans=n*800-(n/15)*200;
  printf("%d",ans);
  return 0;
}