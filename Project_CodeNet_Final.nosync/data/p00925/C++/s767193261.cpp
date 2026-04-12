#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {

  string exp; cin >> exp;
  int ans; cin >> ans;

  stack<int> nums;
  for (unsigned int i = 0; i < exp.size(); i++) {
    if (exp[i] == '*') {
      int v1 = nums.top(); nums.pop();
      int v2 = exp[++i] - '0';
      nums.push(v1*v2);
    } else if (exp[i] == '+') {
      continue;
    } else {
      nums.push(exp[i] - '0');
    }
  }
  int a1 = 0;
  while (!nums.empty()) {
    a1 += nums.top(); nums.pop();
  }

  int a2 = exp[0] - '0';
  for (unsigned int i = 1; i < exp.size(); i++) {
    if (exp[i] == '+') {
      a2 += exp[i+1] - '0';
    } else if (exp[i] == '*') {
      a2 *= exp[i+1] - '0';
    }
  }

  if (a1 == ans) {
    if (a2 == ans) {
      cout << "U" << endl;
    } else {
      cout << "M" << endl;
    }
  } else if (a2 == ans) {
    cout << "L" << endl;
  } else {
    cout << "I" << endl;
  }

  return 0;
}