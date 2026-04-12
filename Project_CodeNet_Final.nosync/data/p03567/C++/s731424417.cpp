#include<iostream>
#include<string>

int main(){
  std::string s; std::cin >> s;
  if(s.find("AC") != std::string::npos)
    std::cout << "Yes\n";
  else
    std::cout << "No\n";
}
