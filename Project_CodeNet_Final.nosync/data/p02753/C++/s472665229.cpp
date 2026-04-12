#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  bool twoExists = true;
  if (s.find('A') == string::npos) {
    twoExists = false;
  }
  if (s.find('B') == string::npos) {
    twoExists = false;
  }
  cout << (twoExists ? "Yes" : "No") << endl;

  return 0;
}
