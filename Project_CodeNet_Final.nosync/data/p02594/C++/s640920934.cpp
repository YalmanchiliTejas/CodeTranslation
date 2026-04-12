#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

std::string solve(int x)
{
  return x >= 30 ? "Yes" : "No";
}

int main()
{
  int x;
  std::cin >> x;

  std::cout << std::setprecision(20);
  std::cout << solve(x) << std::endl;
}
