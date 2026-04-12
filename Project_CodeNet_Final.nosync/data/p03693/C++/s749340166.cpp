#include<stdio.h>

signed main()
{
  int r, g, b;
  scanf("%d %d %d", &r, &g, &b);

  int num = (100 * r) + (10 * g) + b;
  if( num % 4 == 0 ) puts("YES");
  else puts("NO");

  return 0;
}