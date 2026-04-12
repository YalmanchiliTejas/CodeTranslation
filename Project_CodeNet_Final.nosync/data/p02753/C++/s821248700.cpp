#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int cnt = 1;
  for (int i = 1; i < 3; i++) {
    cnt += (s[i] == s.front());
  }
  cout << (cnt == 3 ? "No" : "Yes") << '\n';
  return 0;
}
