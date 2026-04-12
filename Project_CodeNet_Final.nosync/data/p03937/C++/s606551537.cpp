#include <cstdio>

int h, w;
int road;
char s[8][9];
char st[8][8];

void dfs(int x, int y, int count)
{
  st[y][x] = count;
  const int dir[] = {0, 1, 0};
  for (int i = 0; i < 2; ++i)
  {
    int X = x + dir[i + 1];
    int Y = y + dir[i];
    if (0 <= X && X < w && 0 <= Y && Y < h && st[Y][X] == 0 && s[Y][X] == '#')
    {
      dfs(X, Y, count + 1);
    }
  }
}

int main()
{
  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; ++i)
  {
    scanf("%s", s[i]);
    for (int j = 0; j < w; ++j)
    {
      if (s[i][j] == '#') ++road;
    }
  }
  dfs(0, 0, 1);
  puts(st[h - 1][w - 1] == road ? "Possible" : "Impossible");
  return 0;
}