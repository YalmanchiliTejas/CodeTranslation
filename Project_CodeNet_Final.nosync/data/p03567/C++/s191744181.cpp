///
// File:  a.cpp
// Author: ymiyamoto
//
// Created on Sun Oct 22 21:02:34 2017
//

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

int32_t main()
{
  string str;
  cin >> str;

  for(uint32_t i =0; i < str.size() -1;i++){
    if(str[i] == 'A' && str[i+1] == 'C'){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}