#include <iostream>
#include <string>
 
int main()
{
  std::string s {};
  std::cin >> s;
  if(s == "AAA" or s == "BBB")
    std::cout << "No";
  else std::cout << "Yes";
}