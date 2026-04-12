#include <cstdio>

bool skipr[100];
bool skipc[100];

int main()
{
  char s[100][101];
  int h, w;
  scanf("%d %d", &h, &w);
  for (int i = 0; i < h; ++i)
  {
    scanf("%s", s[i]);
    int j = 0;
    for (; j < w; ++j)
    {
      if (s[i][j] != '.')
      {
        break;
      }
    }
    if (j == w)
    {
      skipr[i] = true;
    }
  }
  
  for (int i = 0; i < w; ++i)
  {
    int j = 0;
    for (; j < h; ++j)
    {
      if (s[j][i] != '.')
      {
        break;
      }
    }
    if (j == h)
    {
      skipc[i] = true;
    }
  }
  
  for (int i = 0; i < h; ++i)
  {
    if (skipr[i]) continue;
    for (int j = 0; j < w; ++j)
    {
      if (skipc[j]) continue;
      printf("%c", s[i][j]);
    }
    puts("");
  }
  return 0;
}