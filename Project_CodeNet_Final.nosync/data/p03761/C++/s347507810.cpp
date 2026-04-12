#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s.at(i);
  }
  
  string ans;
  for (char c = 'a'; c <= 'z'; c++) {
    int small = 100;

    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < s.at(i).length(); j++) {
        if (s.at(i).at(j) == c) cnt++;
      }
      small = min(small, cnt);
    }
    for (int i = 0; i < small; i++) {
      ans += c;
    }
  }
  cout << ans << endl;

  return 0;
}