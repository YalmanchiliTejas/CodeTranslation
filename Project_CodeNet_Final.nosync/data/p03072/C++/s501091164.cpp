#include <cstdio>

int main(int argc, char const *argv[]) {
  int N, count = 1, max = 0;
  scanf("%d", &N);

  scanf("%d", &max);
  for (int i = 1; i < N; ++i) {
    int height = 0;
    scanf("%d", &height);
    if (height >= max) {
      ++count;
      max = height;
    }
  }

  printf("%d\n", count);

  return 0;
}
