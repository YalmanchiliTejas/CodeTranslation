#include <cstdio>

int main(void) {
  int N, S;

  scanf("%d", &N);
  S = 800 * N;
  
  while(N >= 15) {
    N -= 15;
    S -= 200;
  }
  printf("%d\n", S);
  return 0;
}
