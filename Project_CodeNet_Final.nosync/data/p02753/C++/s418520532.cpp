#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  std::string s;
  std::cin >> s;

  if (s == "AAA" || s == "BBB")
    std::cout << "No" << '\n';
  else
    std::cout << "Yes" << '\n';

  return 0;
}
