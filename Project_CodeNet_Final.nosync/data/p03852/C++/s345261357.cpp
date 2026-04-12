#include <iostream>

int main() {
  char character;
  std::cin >> character;
  if (
    character == 'a' ||
    character == 'e' ||
    character == 'i' ||
    character == 'o' ||
    character == 'u'
  ) {
    std::cout << "vowel" << std::endl;
  } else {
    std::cout << "consonant" << std::endl;
  }

  return 0;
}
