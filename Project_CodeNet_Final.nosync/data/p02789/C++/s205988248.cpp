//
//  abc152_AC_WA.cpp
//  learningCplusplus
//
//  Created by Tran Duc Chinh on 2020/04/04.
//  Copyright © 2020 Tran Duc Chinh. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define PI 3.14159265


int main() {
  int n, m;
  std::cin >> n >> m;

  if (m>=n) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }
  return 0;
}