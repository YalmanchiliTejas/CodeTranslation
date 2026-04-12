#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  if (s.at(0) == 'A') {
    if (s.at(1) == 'B' || s.at(2) == 'B') {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    if (s.at(1) == 'A' || s.at(2) == 'A') {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}