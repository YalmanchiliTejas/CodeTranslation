#include <bits/stdc++.h>
using namespace std;


void solver() {
  string s;
  cin >> s;

  bool a = false;
  bool b = false;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'A') {
      a = true;
    } else {
      b = true;
    }
  }

  if (a && b){
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return;
}

int main() {
  solver();
  return 0;
}
