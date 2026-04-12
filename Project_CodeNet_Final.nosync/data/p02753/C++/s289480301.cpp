#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cstdint>
#include <unordered_set>
#include <ctime>
#include <numeric>
typedef long long int llint;

int main(void){

  std::string s;
  std::cin >> s;

  bool a = false, b = false;

  for(int i=0; i<s.size(); i++){
    if(s[i]=='A') a=true;
    else          b = true;
  }

  if(a && b) std::cout << "Yes" << std::endl;
  else      std::cout << "No" << std::endl;
  
  return 0;
}
