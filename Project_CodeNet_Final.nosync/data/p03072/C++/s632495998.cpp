#include <cstdio>

int N;

int H[101];

int main()
{
  int max_height = 0;
  int counter = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &H[i]);
    if (H[i] >= max_height) {
      max_height = H[i];
      ++counter;
    }
  }
  printf("%d\n", counter);
  return 0;
}

