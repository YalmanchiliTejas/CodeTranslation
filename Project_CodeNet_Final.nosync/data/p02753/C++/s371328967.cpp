#include<iostream>
#include<string>

int main() {
  std::string s;
  std::cin >> s;
  if(s[0] == s[1] && s[1] == s[2]) std::cout << "No";
  else std::cout << "Yes";
  std::cout << std::endl;
  return 0;
}
