#include <stdio.h>

int num[8], n, ans = 0;
bool r[8][8], flg[8];

void saiki(int a) {
  int i;
  if(a == n) {
    bool b = true;
    for(i = 1; i < n; ++i) if(!r[num[i - 1]][num[i]]) b = false;
    if(b) ++ans;
    return;
  }
  for(i = 1; i < n; ++i) if(flg[i]) {
    num[a] = i, flg[i] = false;
    saiki(a + 1);
    flg[i] = true;
  }
}

int main(void) {
  int i, m, j, x, y;
  scanf("%d%d", &n, &m);
  for(i = 0; i < n; ++i) for(j = 0; j < n; ++j) r[i][j] = false;
  for(i = 0; i < n; ++i) flg[i] = true;
  for(i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y);
    x--, y--;
    r[x][y] = r[y][x] = true;
  }
  num[0] = 0;
  saiki(1);
  printf("%d", ans);
  return 0;
}