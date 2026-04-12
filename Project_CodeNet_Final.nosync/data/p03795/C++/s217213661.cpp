#include <stdio.h>
int main(void){
  int n;
  scanf("%d",&n);
  printf("%d\n",800*n-200*(n-n%15)/15);
  return 0;
}