#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool can = false;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < s.size(); j++) {
      if (s.at(i) == 'A' && s.at(j) == 'C' && j == i + 1) {
        can = true;
      }
    }
  }
  if (can) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
