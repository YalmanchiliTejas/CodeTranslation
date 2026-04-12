#include <cstdio>

char p[10][10];

int main(){
  int H, W; scanf("%d%d", &H, &W);

  int cnt = 0;

  for(int i = 0; i < H; i++){
    scanf("%s", p[i]);
    for(int j = 0; j < W; j++) if(p[i][j] == '#') cnt++;
  }

  int x = 0, y = 0; bool v = true;
  for(;;){
    if(p[x][y] != '#'){ v = false; break; }
    if(x == H - 1 && y == W - 1) break;

    bool d = false, r = false;
    if(x + 1 < H && p[x + 1][y] == '#') d = true;
    if(y + 1 < W && p[x][y + 1] == '#') r = true;

    if((d && r) || (!d && !r)){ v = false; break; }
    if(d) x++; else y++;
  }

  if(cnt != H + W - 1) v = false;

  puts(v ? "Possible" : "Impossible");
  return 0;
}