#include <iostream>
#include <string>

std::string solve(std::string s, int k)
{
  const char k_char = s[k - 1];
  for (auto& c : s) {
    if (c != k_char) c = '*';
  }
  return s;
}

int main()
{
  int n, k;
  std::string s;
  std::cin >> n >> s >> k;

  std::cout << solve(s, k) << std::endl;
}
