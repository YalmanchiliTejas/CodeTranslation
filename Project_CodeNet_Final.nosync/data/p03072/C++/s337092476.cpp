#include <stdio.h>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int ans = 1;
  for (int i = 1; i < n; i++) {
    int cur = 1;
    for (int j = 0; j < i; j++) {
      cur &= (a[j] <= a[i]);
    }
    ans += cur;
  }
  printf("%d\n", ans);
  return 0;
}