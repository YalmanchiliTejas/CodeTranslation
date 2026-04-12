#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  int n = s[0] + s[1] + s[2];
  if (n != 195) {
    if (n != 198)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  } else
    cout << "No" << endl;
  return 0;
}