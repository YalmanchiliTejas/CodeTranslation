#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  string s;
  cin >> s;

  int len = s.length();
  bool ans = false;
  for (int i = 0; i < len-2; i++) {
    if (s.substr(i, 2) == "AC") {
      ans = true;
    }
  }

  if(s == "AC"){
    ans = true;
  }

  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
