#include <iostream>
#include <string>
#include <algorithm>


int main(){
  std::string s;
  std::cin >> s;
  int numA = std::count(s.begin(), s.end(), 'A');

  if(numA == 0 || numA == 3){
    std::cout << "No";
  }
  else{
    std::cout << "Yes";
  }

  return 0;
}
