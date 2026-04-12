#include <iostream>
#include <cstdint>

int main() {
  char c;
  std::cin >> c;
  std::cout << (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ? "vowel" : "consonant") << std::endl;
  return 0;
}