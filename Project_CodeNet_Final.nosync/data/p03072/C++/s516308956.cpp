#include <cstdio>

int main()
{
  int n, hmax, h;
  scanf("%d %d", &n, &hmax);
  int ans = 1;
  for (int i = 1; i < n; ++i)
  {
    scanf("%d", &h);
    if (hmax <= h)
    {
      hmax = h;
      ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}