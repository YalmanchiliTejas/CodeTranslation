#include <stdio.h>

int main()
{
  int a,b,c;

  scanf("%d%d%d",&a,&b,&c);

  int ans = a * 100 + b * 10 + c;

  if (ans % 4 == 0) printf("YES\n");
  else printf("NO\n");
}
