#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int without_ab(int a, int b, int x, int y)
{
  return a * x + b * y;
}

int all_ab(int c, int x, int y)
{
  return max(x, y) * 2 * c;
}

int partially_use_ab(int a, int b, int c, int x, int y)
{
  int total = 0;
  if(x < y) {
    total += x * 2 * c;
    total += (y-x) * b;
  } else {
    total += y * 2 * c;
    total += (x-y) * a;
  }
  return total;
}

int main()
{
  int a, b, c, x, y;
  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

  printf("%d\n", min(min(without_ab(a, b, x, y), all_ab(c, x, y)), partially_use_ab(a, b, c, x, y)));
  return 0;
}
