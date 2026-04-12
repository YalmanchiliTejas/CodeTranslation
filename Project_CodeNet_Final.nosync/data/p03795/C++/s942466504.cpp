#include<stdio.h>
int main(){
  int N;
  scanf("%d", &N);
  int x = N * 800;
  int y = N/15 * 200;
  printf("%d", x - y);
  return 0;
}