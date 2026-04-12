#include <iostream>
#include <string>

int main (void) {
  std::string str;
  std::cin >> str;
  
  bool a = false;
  bool b = false;
  
  for (int i = 0; i < str.size(); i++) {
    if (str.at(i) == 'A') a = true;
    if (str.at(i) == 'B') b = true;
  }
  
  std::cout << (a && b ? "Yes" : "No") << std::endl;
  
  return 0;
}

