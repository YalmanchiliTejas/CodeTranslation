#include "bits/stdc++.h"
using namespace std;

bool solve(string &s) {
  for(int i = 0; i + 1 < s.size(); ++i)
    if(s[i] == 'A' && s[i + 1] == 'C')
      return true;
  return false;
}

int main() {
  string s;
  cin >> s;
  if(solve(s)) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}
