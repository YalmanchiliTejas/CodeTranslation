#include <iostream>

int main(void){
  char c;
  std::cin >> c;
  switch(c){
    case 'a':case 'i':case 'u':case 'e': case 'o':
      std::cout << "vowel" << std::endl; break;
    default:
      std::cout << "consonant" << std::endl;
  }
  return 0;
}