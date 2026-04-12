#include <iostream>

int main() {
  char c;
  std::cin >> c;
  if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
    std::cout << "vowel" << "\n";
  } else {
    std::cout << "consonant" << "\n";
  }
}