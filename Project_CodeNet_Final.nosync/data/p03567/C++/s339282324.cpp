#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool is_ac = false;
  for (int i=0; i<s.size()-1; i++)
    if (s.substr(i, 2) == "AC") {
      is_ac = true;
      break;
    }
  if (is_ac) cout << "Yes" << endl;
  else cout << "No" << endl;
}
