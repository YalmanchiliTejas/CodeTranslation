#include <bits/stdc++.h>

int main() {
  std::string s;
  std::cin >> s;
  if (std::count(s.begin(), s.end(), 'A') == 3 || std::count(s.begin(), s.end(), 'B') == 3)
    std::cout << "No" << std::endl;
  else
    std::cout << "Yes" << std::endl;
}
