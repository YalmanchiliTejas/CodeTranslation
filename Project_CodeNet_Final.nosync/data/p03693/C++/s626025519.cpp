#include <cstdio>

int main()
{
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  puts((b * 10 + c) % 4 == 0 ? "YES" : "NO");
  return 0;
}