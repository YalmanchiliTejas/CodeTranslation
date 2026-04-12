#include <stdio.h>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);
  char a[n + 1];
  scanf("%s", a);
  int m;
  scanf("%d", &m);
  char k = a[m - 1];
  for (int i = 0; i < n; i++) {
    printf("%c", (a[i] == k ? a[i] : '*'));
  }
  puts("");
  return 0;
}