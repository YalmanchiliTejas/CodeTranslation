#include <iostream>
#include <string>

int main() {
  std::string str;
  std::cin >> str;
  int ca = 0;
  int cb = 0;
  for (int i = 0; i < 3; ++i)
    if (str[i] == 'A') ca += 1;
  	else cb += 1;
  if (ca == 3 || cb == 3) std::cout << "No" << std::endl;
  else std::cout << "Yes" << std::endl;
  
}