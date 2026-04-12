#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cassert>

//std::cout << std::fixed << std::setprecision(10)
//std::ios::sync_with_stdio(false);
//constexpr long long MOD = 1000000007;

int dx[] = { 0, 1, 0, -1};
int dy[] = {-1, 0, 1,  0};

int main()
{
  std::string str;
  std::cin >> str;
  auto A = std::count(str.begin(), str.end(), 'A');
  auto B = std::count(str.begin(), str.end(), 'B');
  std::cout << (A == 3 || B == 3 ? "No" : "Yes") << std::endl;
  return 0;
}

