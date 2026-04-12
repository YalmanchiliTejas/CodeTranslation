#include <bits/stdc++.h>
using namespace std;


int main() {
  string s;
  cin >> s;

  bool bus = false;
  if (s.at(0)!=s.at(1)) {
    bus = true;
  }
  if (s.at(0)!=s.at(2)) {
    bus = true;
  }
  if (s.at(2)!=s.at(1)) {
    bus = true;
  }

  if (bus) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}