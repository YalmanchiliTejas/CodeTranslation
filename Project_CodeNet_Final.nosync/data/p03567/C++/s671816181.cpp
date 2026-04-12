#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, ans = "No";
  cin >> s;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i]=='A' && s[i+1]=='C') {
      ans = "Yes";
    }
  }
  
  cout << ans << endl;
}