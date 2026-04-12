#include <bits/stdc++.h>

using namespace std;

int main(void) {
  string s;
  cin >> s;

  bool yes = false;
  for (int i = 0; i < s.size(); i++) {
    yes |= s.substr(i, 2) == "AC";
  }

  cout << (yes ? "Yes" : "No") << endl;

  return 0;
}