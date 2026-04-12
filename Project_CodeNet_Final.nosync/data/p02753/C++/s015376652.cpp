#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)
int main() {
  string s;
  cin >> s;
  unordered_map<char, int> m;
  for (char& c : s) {
    m[c]++;
  }
  if (m['A'] == 3 or m['B'] == 3)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}
