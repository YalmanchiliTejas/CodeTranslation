#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  bool no = (s[0] == 'A' && s[1] == 'A' && s[2] == 'A') ||
            (s[0] == 'B' && s[1] == 'B' && s[2] == 'B');
  if (!no)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}