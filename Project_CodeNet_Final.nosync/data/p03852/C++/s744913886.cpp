#include <iostream>
#include <string>

int main() {
  char c;
  std::string s = "aiueo";

  std::cin >> c;
  
  std::size_t x = s.find(c);

  if(x != std::string::npos) {
    std::cout << "vowel\n";
    return 0;
  }

  std::cout << "consonant\n";
  return 0;
}
