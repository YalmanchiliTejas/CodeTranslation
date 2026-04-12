#include <cstdio>

using namespace std;

int h, w;
char s[11][11];

int main(void) {
  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; i++) scanf("%s", s[i]);

  int x, y; x=y=0;
  while (x!=w-1 || y!=h-1) {
    if (s[y][x] != '#') break;
    s[y][x] = '.';
    if (x+1 < w && s[y][x+1] == '#') x++;
    else if(y+1 < h && s[y+1][x] == '#') y++;
    else break;
  }
  s[y][x] = '.';
  bool ok = true;
  if (x == w-1 && y == h-1) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) ok &= s[i][j] == '.';
    }
  } else {
    ok = false;
  }
  puts(ok ? "Possible" : "Impossible");
  return 0;
}
