#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  cout << (s[0] == s[2] ? "No" : "Yes") << '\n';
  return 0;
}