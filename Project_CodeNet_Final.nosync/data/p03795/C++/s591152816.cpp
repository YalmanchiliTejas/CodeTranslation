#include <cstdio>

int main(void){
  int N, discount;
  scanf("%d", &N);
  discount = N / 15;
  printf("%d\n", N * 800 - discount * 200);
  return 0;
}
