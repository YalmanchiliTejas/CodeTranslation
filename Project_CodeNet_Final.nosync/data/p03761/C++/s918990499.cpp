#include<bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  map<char, int> m;
  bool f = true;
  while (n--) {
    string s; cin >> s;
    map<char, int> t;
    for (char c : s) {
      if (f) m[c]++;
      t[c]++;
    }
    f = false;
    for (char c = 'a'; c <= 'z'; c++) {
      m[c] = min(m[c], t[c]);
    }
  }
  for (char c = 'a'; c <= 'z'; c++) {
    while (m[c]--) cout << c;
  }
  cout << endl;
}

