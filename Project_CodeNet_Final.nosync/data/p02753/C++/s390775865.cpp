#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

std::string solve(const std::string& s)
{
  if (std::all_of(s.begin(), s.end(), [](char c) { return c == 'A'; })) return "No";
  if (std::all_of(s.begin(), s.end(), [](char c) { return c == 'B'; })) return "No";
  return "Yes";
}

int main()
{
  std::string s;
  std::cin >> s;

  std::cout << std::setprecision(20);
  std::cout << solve(s) << std::endl;
}
