#include <bits/stdc++.h>
using namespace std;

bool uku(string s) {
  if (s[0] == '0') return s.size() == 1;
  return stoi(s) <= 255;
}

int main() {
  string s;
  cin >> s;

  int ans = 0;
  for (int i = 1; i < s.size(); ++i) {
    for (int j = 1; i + j < s.size(); ++j) {
      for (int k = 1; i + j + k < s.size(); ++k) {
        string a = s.substr(0, i);
        string b = s.substr(i, j);
        string c = s.substr(i + j, k);
        string d = s.substr(i + j + k, (s.size() - (i + j + k)));

        ans += uku(a) && uku(b) && uku(c) && uku(d);
      }
    }
  }

  cout << ans << endl;
}

