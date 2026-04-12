#include <stdio.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main(int, char**) {
  string s;
  cin >> s;
  if (s[0] != s[1] || s[1] != s[2]) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
