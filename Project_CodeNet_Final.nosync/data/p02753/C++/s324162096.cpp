#include <bits/stdc++.h>
using namespace std;

int main() {
  bool a = false;
  bool b = false;
  
  string s; cin >> s;
  for (char c : s) {
    if (c == 'A') a = true;
    if (c == 'B') b = true;
  }
  
  if (a and b) cout << "Yes" << endl;
  else cout << "No" << endl;
}