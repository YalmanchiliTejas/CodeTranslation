#include <stdio.h>
#include <stdint.h>

uint32_t a[200000];
uint32_t e[200000];

int main(int argc, char **argv)
{
  int n;

  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d ", &a[i]);
  }

  const int c = 200000 / 2;
  int f;
  if (n % 2) { // odd
    for (int i = 0; i < n; i++) {
      int j = ((i + 1) % 2) ? -1 : 1;
      e[c + (i + 1) / 2 * j] = a[i];
    }
    f = c - n / 2;
  }
  else { // even
    for (int i = 0; i < n; i++) {
      int j = (i % 2) ? -1 : 1;
      e[c + (i + 1) / 2 * j] = a[i];
    }
    f = c - n / 2;
  }

  for (int i = 0; i < n - 1; i++) {
    printf("%d ", e[f + i]);
  }
  printf("%d\n", e[f + n - 1]);

  return 0;
}
