#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  rep(i, s.length() - 1) {
    if (s[i] == 'A')
      if (s[i + 1] == 'C') {
        cout << "Yes" << endl;
        return 0;
      }
  }
  cout << "No" << endl;
  return 0;
}