#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 4000000000000000000LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cout << std::fixed << std::setprecision(6);
  std::cerr << std::fixed << std::setprecision(6);

  int n, a;

  std::cin >> n;

  std::deque<int> deque;

  for (int i = 0; i < n; i ++) {
    std::cin >> a;

    if (i % 2 == 0) {
      deque.push_back(a);
    }
    else {
      deque.push_front(a);
    }
  }

  if (n % 2 == 0)  {
    for (int i = 0; i < n; i ++)
      std::cout << deque[i] << ' ';
  }
  else {
    for (int i = n - 1; i >= 0; i --)
      std::cout << deque[i] << ' ';
  }
  std::cout << std::endl;
  
  return 0;
}
