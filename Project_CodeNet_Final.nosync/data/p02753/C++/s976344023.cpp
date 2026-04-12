#include<bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  map<char, int> m;
  for (int i = 0; i < 3; i++) {
    m[s[i]]++;
  }
  if (!m['A'] or !m['B']) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
 }