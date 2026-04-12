#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main () {
  string s;
  cin >> s;
  string ans = "Yes";
  if (s[0] == 'A' && s[1] == 'A' && s[2] == 'A') ans = "No";
  if (s[0] == 'B' && s[1] == 'B' && s[2] == 'B') ans = "No";
  cout << ans << endl;
}