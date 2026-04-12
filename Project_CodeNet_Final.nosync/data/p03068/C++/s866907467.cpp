#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> s >> k;

  for (auto &c : s) {
    if (c != s[k - 1]) {
      c = '*';
    }
  }
  cout << s << '\n';
  return 0;
}
