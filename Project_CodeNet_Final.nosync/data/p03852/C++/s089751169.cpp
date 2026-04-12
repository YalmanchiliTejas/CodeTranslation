#include <iostream>

int main() {
  char c;
  std::cin >> c;

  const char s[] = "aeiou";
  for (auto e : s) {
    if (c == e) {
      std::cout << "vowel" << std::endl;
      return 0;
    }
  }
  std::cout << "consonant" << std::endl;
}