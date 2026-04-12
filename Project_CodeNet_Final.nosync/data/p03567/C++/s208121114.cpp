#include <bits/stdc++.h>

using namespace std;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15);
  }
} initializer;

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < int(s.size()) - 1; ++i) {
    if (s.substr(i, 2) == "AC") {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}

