#include <cstdio>

int main()
{
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%.12f\n", a * b / double(a + b));
  return 0;
}