#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> s >> k;

  string ans = "";
  for (auto c : s) {
    if (c == s[k - 1])
      ans.push_back(c);
    else
      ans.push_back('*');
  }

  cout << ans << endl;
}