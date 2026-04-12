#include <algorithm>
#include <iostream>
#include <vector>

using Heights = std::vector<int>;

int solve(const Heights& heights)
{
  int result = 0;
  for (auto i = 0u; i < heights.size(); ++i) {
    const auto it = std::max_element(heights.begin(), heights.begin() + i);
    if (*it <= heights[i]) ++result;
  }
  return result;
}

int main()
{
  int n;
  std::cin >> n;

  Heights heights(n);
  for (auto& h : heights) {
    std::cin >> h;
  }

  std::cout << solve(heights) << std::endl;
}
