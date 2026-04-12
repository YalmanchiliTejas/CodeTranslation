#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  set<char> m;
  m.insert(s[0]);
  m.insert(s[1]);
  m.insert(s[2]);
  if (m.size() > 1) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }                   
  return 0;
}