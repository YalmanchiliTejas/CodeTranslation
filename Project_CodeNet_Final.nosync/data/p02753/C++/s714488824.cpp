#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  bool a = false, b = false;
  for (int i = 0; i < 3; i++) {
    if (s[i] == 'A') a = true;
    if (s[i] == 'B') b = true;
  }
  if (a && b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}