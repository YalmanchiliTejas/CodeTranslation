#include <cstdio>
#include <algorithm>

int main()
{
  long a, b, c, x, y;
  scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &x, &y);
  printf("%lld\n", std::min(x, y) * std::min(a + b, 2 * c) + (x > y ? (x - std::min(x, y)) * std::min(a, 2 * c) : (y - std::min(x, y)) * std::min(b, 2 * c)));
  return 0;
}