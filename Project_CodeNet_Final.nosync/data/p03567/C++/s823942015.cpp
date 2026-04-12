#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;
  
  for (int i = 0; i < s.size() - 1; i++) {
    if (s.at(i) == 'A' && s.at(i + 1) == 'C') {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}