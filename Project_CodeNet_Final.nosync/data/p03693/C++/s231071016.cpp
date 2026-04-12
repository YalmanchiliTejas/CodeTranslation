#include <stdio.h>
int main(void){
  int r,g,b;
  scanf("%d%d%d",&r,&g,&b);
  printf("%s\n",((g*10+b)%4)? "NO":"YES");
  return 0;
}