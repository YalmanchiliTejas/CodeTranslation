#include <bits/stdc++.h>
using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  bool A = false;
  bool B = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') A = true;
    if (s[i] == 'B') B = true;
    if (A && B) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}