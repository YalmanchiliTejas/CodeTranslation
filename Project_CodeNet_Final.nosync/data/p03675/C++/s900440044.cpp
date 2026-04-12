#include <stdio.h>
#include <stdint.h>

uint32_t a[200000];

int main(int argc, char **argv)
{
  int n;

  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d ", &a[i]);
  }

  if (n == 1) {
    printf("%d", a[0]);
  }
  else if (n % 2) {
    for (int i = n - 1; i >= 0; i -= 2)
      printf("%d ", a[i]);
    for (int i = 1; i < n; i += 2)
      printf("%d ", a[i]);
  }
  else {
    for (int i = n - 1; i >= 0; i -= 2)
      printf("%d ", a[i]);
    for (int i = 0; i < n; i += 2)
      printf("%d ", a[i]);
  }
  printf("\n");
}