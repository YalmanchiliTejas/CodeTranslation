#include <iostream>
#include <string>
 
int main(void){
  std::string input = "";
  std::cin >> input;
  if (input.find("A") != std::string::npos && input.find("B") != std::string::npos)
    std::cout << "Yes";
  else
    std::cout << "No";
  return 0;
}
