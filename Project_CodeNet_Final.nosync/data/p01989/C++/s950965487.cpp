#include <bits/stdc++.h>
#define REP(i, a, n) for (ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

bool ok(string s) {
  if (s[0] == '0') {
    return s.length() == 1;
  }

  ll v = 0;
  REP(i, 0, s.length()) {
    v = v * 10 + (s[i] - '0');
  }
  return 1 <= v && v <= 255;
}

int main(void) {
  string S;
  cin >> S;

  ll ans = 0;
  REP(i, 1, S.length()) REP(j, i + 1, S.length()) REP(k, j + 1, S.length()) {
    if (ok(S.substr(0, i)) && ok(S.substr(i, j - i)) && ok(S.substr(j, k - j)) && ok(S.substr(k, S.length() - k))) {
      ans++;
    }
  }
  cout << ans << endl;
}
