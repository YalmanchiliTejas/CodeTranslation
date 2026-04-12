#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0;i < n;i++)
#define FOR(i, m, n) for(ll i = m;i < n;i++)

int n;
string s;
string ans;

char swap(char c) {
  return (c == 'S' ? 'W' : 'S');
}

bool search(int c0, int c1) {
  if (c0) ans = (c1 ? "SS" : "SW");
  else ans = (c1 ? "WS" : "WW");

  rep(i, n-2) {
    if (s[i+1] == 'o') {
      ans += (ans[i+1] == 'S' ? ans[i] : swap(ans[i]));
    } else {
      ans += (ans[i+1] == 'S' ? swap(ans[i]) : ans[i]);
    }
  }

  bool ok = true;
  rep(i, 2) {
    if (s[(n+i-1)%n] == 'o') {
      ok &= ans[i] == (ans[(n+i-1)%n] == 'S' ? ans[(n+i-2)%n] : swap(ans[(n+i-2)%n]));
    } else {
      ok &= ans[i] == (ans[(n+i-1)%n] == 'S' ? swap(ans[(n+i-2)%n]) : ans[(n+i-2)%n]);
    }
  }
  return ok;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  cin >> n;
  cin >> s;

  cerr << search(0, 0) << endl;
  cerr << ans << endl;
  cerr << endl;
  cerr << search(0, 1) << endl;
  cerr << ans << endl;
  cerr << endl;
  cerr << search(1, 0) << endl;
  cerr << ans << endl;
  cerr << endl;
  cerr << search(1, 1) << endl;
  cerr << ans << endl;
  cerr << endl;

  rep(i, 2) {
    rep(j, 2) {
      if (search(i, j)) {
        cout << ans << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}