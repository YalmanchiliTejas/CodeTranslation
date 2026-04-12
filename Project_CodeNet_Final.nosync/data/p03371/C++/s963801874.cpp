#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>

typedef long long ll;

int main(int argc, char* argv[])
{
  int a, b, c, x, y;
  std::vector< int > vi;
  int sum1 = 0;
  int sum2 = 0;
  std::cin >> a >> b >> c >> x >> y;
  int p1 = std::min(x, y);

  if (a+b < c*2) {
    sum1 += p1 * (a+b);
  } else {
    sum1 += p1 * c * 2;
  }

  if (x > y) {
    sum1 += (x-y) * a;
  } else {
    sum1 += (y-x) * b;
  }

  sum2 = c * 2 * std::max(x, y);

  std::cout << std::min(sum1, sum2) << std::endl;

  return 0;
}
