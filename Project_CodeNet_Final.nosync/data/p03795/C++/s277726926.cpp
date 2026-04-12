#include <cstdio>
int main(){
  int N, x, y;
  scanf("%d", &N);
  x=800*N;
  y=N/15*200;
  printf("%d", x-y);
  return 0;
}