//
//  station_bus.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <math.h>
typedef long long ll;
int main(int argc, const char* argv[]) {
  std::string s;
  std::cin >> s;

  if (s[0]!=s[1] || s[0]!=s[2]) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }


}