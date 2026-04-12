#include <iostream>

int main() {
  char c;
  std::cin >> c;

  char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };
  bool is_vowel = false;
  for (int i = 0; i < 5; ++i) {
    if ( c == vowel[i] ) {
      is_vowel = true;
      break;
    }
  }
  if ( is_vowel ) {
    std::cout << "vowel" << std::endl;
  } else {
    std::cout << "consonant" << std::endl;
  }

  return 0;
}
