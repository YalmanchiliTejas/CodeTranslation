#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;

  int a = 0;
  int b = 0;
  rep(i, s.length()) {
    if (s[i] == 'A') {
      a++;
    } else {
      b++;
    }
  }

  if (a > 0 && b > 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
