#include <stdio.h>

long long as[200001];
int indices[200001];

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", as + i);
  }

  int isLeft = 1;
  int leftIdx = 0;
  int rightIdx = N - 1;
  for (int i = N - 1; i >= 0; i--) {
    if (isLeft == 1) {
      indices[leftIdx] = i;
      leftIdx++;
      isLeft = 0;
    } else {
      indices[rightIdx] = i;
      rightIdx--;
      isLeft = 1;
    }
  }

  for (int i = 0; i < N; i++) {
    if (i != 0) printf(" ");
    printf("%lld", as[indices[i]]);
  }
  printf("\n");

  return 0;
}
