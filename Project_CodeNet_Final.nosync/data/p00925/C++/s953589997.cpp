///
// File:  1346.cpp
// Author: ymiyamoto
//
// Created on Sun Nov 26 02:53:16 2017
//

#include <cstdint>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int32_t main()
{
  string str;
  cin >> str;
  uint32_t n;
  cin >> n;

  stack<int32_t> stack;
  for (uint32_t i = 0; i < str.size(); i++) {
    if (i % 2 == 0) {
      uint32_t val = str[i] - '0';
      stack.push(val);
    } else {
      char op = str[i];
      if (op == '*') {
        i++;
        uint32_t val1 = stack.top();
        stack.pop();
        uint32_t val2 = str[i] - '0';
        stack.push(val1 * val2);
      }
    }
  }

  uint32_t result1 = 0;
  while (!stack.empty()) {
    result1 += stack.top();
    stack.pop();
  }

  uint32_t result2 = str[0] - '0';
  for (uint32_t i = 1; i < str.size(); i++) {
    if (str[i] == '+') {
      i++;
      result2 += str[i] - '0';
    } else {
      i++;
      result2 *= str[i] - '0';
    }
  }

  if (result1 == n && result2 == n) {
    cout << "U" << endl;
  } else if (result1 == n) {
    cout << "M" << endl;
  } else if (result2 == n) {
    cout << "L" << endl;
  } else {
    cout << "I" << endl;
  }

  return 0;
}