#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);

  int res = 0;
  for (int i = 1; i <= N; ++i) {
    res += 800;
    if (i % 15 == 0) res -= 200;
  }
  printf("%d\n", res);
}