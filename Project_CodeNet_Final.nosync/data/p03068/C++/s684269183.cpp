#include <cstdio>

int main()
{
  int n, k;
  char s[11];
  scanf("%d%s%d", &n, s, &k);
  for (int i = 0; i < n; ++i)
  {
    putchar(s[i] == s[k - 1] ? s[k - 1] : '*');
  }
  putchar('\n');
  return 0;
}