#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define rrep(i, a, b) for (int i = int(a) - 1; i >= b; i--)
#define sz(x) (int)(x).size()

using namespace std;
using ll = long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  int a = 0, b = 0;
  for (int i = 0; i < sz(s); i++) {
    if (s[i] == 'A') {
      a++;
    } else {
      b++;
    }
  }
  if (a * b == 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}