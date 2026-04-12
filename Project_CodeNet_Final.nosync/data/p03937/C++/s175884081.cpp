#include <stdio.h>

int main(void) {
  int i, j, h, w;
  scanf("%d%d", &h, &w);
  char a[h][w + 10];
  for(i = 0; i < h; ++i) scanf("%s", a[i]);
  for(i = 0; i < h; ++i) for(j = 0; j < w; ++j) {
    if(a[i][j] == '#' && ((i && j && a[i - 1][j] == '#' && a[i][j - 1] == '#') || (i != h - 1 && j != w - 1 && a[i + 1][j] == '#' && a[i][j + 1] == '#'))) {
      printf("Impossible");
      return 0;
    }
  }
  printf("Possible");
  return 0;
}