#include <stdio.h>
#include <string.h>

int main(void) {
  int h, w, i, j, k;
  scanf("%d%d", &h, &w);
  char s[h][w + 10];
  for(i = 0; i < h; ++i) scanf("%s", s[i]);
  for(i = 0; i < h; ++i) {
    bool b = true;
    for(j = 0; j < w; ++j) if(s[i][j] == '#') b = false;
    if(b) {
      h--;
      for(j = i; j < h; ++j) for(k = 0; k < w; ++k) s[j][k] = s[j + 1][k];
      i--;
    }
  }
  for(i = 0; i < w; ++i) {
    bool b = true;
    for(j = 0; j < h; ++j) if(s[j][i] == '#') b = false;
    if(b) {
      w--;
      for(j = i; j < w; ++j) for(k = 0; k < h; ++k) s[k][j] = s[k][j + 1];
      i--;
    }
  }
  for(i = 0; i < h; ++i) {
    for(j = 0; j < w; ++j) printf("%c", s[i][j]);
    printf("\n");
  }
  return 0;
}