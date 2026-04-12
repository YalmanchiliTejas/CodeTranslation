#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> s >> k;

  for (auto& c : s) {
    if (c != s[k-1]) {
      cout << "*";
    } else {
      cout << c;
    }
  }
  cout << endl;

  return 0;
}
