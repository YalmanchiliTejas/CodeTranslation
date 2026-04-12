#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string make_nines(int d)
{
  std::ostringstream oss;
  for (int i = 0; i < d; ++i) {
    oss << '9';
  }
  return oss.str();
}

long solve1(const std::string& n)
{
  if (n.size() <= 0) return 0;
  int a = n[0] - 0x30;
  if (a == 0) return solve1(n.substr(1));
  return a + 9 * (n.size() - 1);
}

long solve2(const std::string& n)
{
  if (n.size() <= 1) return 0;
  int a = n[0] - 0x30;
  if (a == 0) return solve2(n.substr(1));
  return (a - 1) * solve1(make_nines(n.size() - 1))
      + solve1(n.substr(1))
      + solve2(make_nines(n.size() - 1));
}

long solve3(const std::string& n)
{
  if (n.size() <= 2) return 0;
  int a = n[0] - 0x30;
  if (a == 0) return solve3(n.substr(1));
  return (a - 1) * solve2(make_nines(n.size() - 1))
      + solve2(n.substr(1))
      + solve3(make_nines(n.size() - 1));
}

long solve(const std::string& n, int k)
{
  if (k == 1) return solve1(n);
  if (k == 2) return solve2(n);
  return solve3(n);
}

int main()
{
  std::string n;;
  int k;
  std::cin >> n >> k;

  std::cout << solve(n, k) << std::endl;
}
