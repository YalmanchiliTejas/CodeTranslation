#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define rep(i,n) for(int i = 0; i != n; ++i)

const double EPS = 1e-10;
const int INF = 1e7;

int main(){
  int a, b, c, x, y;
  scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
  int min_xy = min(x, y);
  int sum_val = 0;
  if ((a + b) > c*2) {
    x -= min_xy;
    y -= min_xy;
    sum_val += 2 * c * min_xy;
  }
  if (a > c*2 && x > 0) {
    sum_val += 2 * c * x;
    y -= x;
    x = 0;
  }
  if (b > c*2 && y > 0) {
    sum_val += 2 * c * y;
    x -= y;
    y = 0;
  }

  if (x > 0) {
    sum_val += x * a;
  }
  if (y > 0) {
    sum_val += y * b;
  }
  

  std::cout << sum_val << '\n';
  return 0;
}
