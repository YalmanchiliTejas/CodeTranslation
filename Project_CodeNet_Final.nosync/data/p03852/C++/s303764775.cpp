#include <iostream>

const bool is_vowel(const char& given)
{
  return given == 'a' ||
         given == 'e' ||
         given == 'i' ||
         given == 'o' ||
         given == 'u';
}

int main()
{
  char c;

  std::cin >> c;
  std::cout << (is_vowel(c) ? "vowel" : "consonant") << std::endl;

  return 0;
}
