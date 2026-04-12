#include<stdio.h>

int main(void){
  int a,b,c;

  scanf("%d %d %d",&a,&b,&c);

  c+=b*10;

  if(c%4==0)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
