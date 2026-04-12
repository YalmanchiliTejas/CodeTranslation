#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  char c;
  int ca = 0, cb = 0;
  int t = 3;
  while (t--) {
    cin >> c;
    if (c == 'A') {
      ca++;
    } else {
      cb++;
    }
  }
  cout << ((ca == 0 || cb == 0) ? "No" : "Yes") << '\n';
  return 0;
}