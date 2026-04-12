#include <iostream>

int main() {
  std::string s;
  std::cin >> s;
  for (unsigned i = 1; i < s.size(); ++i) {
    if (s[i-1] == 'A' && s[i] == 'C') {
      std::cout << "Yes" << std::endl;
      return 0;
    }
  }
  std::cout << "No" << std::endl;
  return 0;
}