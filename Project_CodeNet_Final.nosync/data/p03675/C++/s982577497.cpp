#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 1000000002486618624LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cout << std::fixed << std::setprecision(6);

  int n;

  std::cin >> n;

  std::vector<int> a(n), x, y;

  for (int i = 0; i < n; i ++)
    std::cin >> a[i];

  for (int i = 0; i < n; i ++)
    if (i % 2 == 0) {
      x.push_back(a.back());

      a.pop_back();
    }
    else {
      y.push_back(a.back());

      a.pop_back();
    }

  std::reverse(ALL(y));

  std::copy(ALL(y), std::back_inserter(x));

  for (const auto& i : x)
    std::cout << i << ' ';
  std::cout << std::endl;
  
  return 0;
}
