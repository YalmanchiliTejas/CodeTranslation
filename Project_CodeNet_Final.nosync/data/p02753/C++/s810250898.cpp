#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool is = true;
  if (s[0]=='A' && s[1]=='A' && s[2]=='A')
    is = false;
  if (s[0]=='B' && s[1]=='B' && s[2]=='B')
    is = false;
  if (is)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
