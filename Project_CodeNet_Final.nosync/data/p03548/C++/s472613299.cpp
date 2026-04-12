#include<stdio.h>

int main(void){
  int a,b,c,s=0;

  scanf("%d %d %d",&a,&b,&c);

  a-=c;

  while(a>=0){
    a-=b;
    a-=c;
    s++;
  }

  if(a<0) s--;

  printf("%d\n",s);

  return 0;
}