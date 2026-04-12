#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <map>


int main(){
  std::string str;
  std::cin >> str;
  char prev=str[0];
  for(auto &&c : str)
  {
    if(c != prev){
      std::cout << "Yes" << std::endl;
      return 0;
    }
  }
  std::cout << "No" << std::endl;
  return 0;
}