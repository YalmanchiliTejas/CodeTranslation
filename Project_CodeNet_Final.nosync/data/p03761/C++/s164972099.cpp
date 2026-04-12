#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int n;
  cin >> n;
  vector<int> a(26, 2e9);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vector<int> b(26);
    for (auto &i : s) {
      b[i - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      a[i] = min(a[i], b[i]);
    }
  }
  for (int i = 0; i < 26; i++)
  for (int j = 0; j < a[i]; j++) {
    cout << (char)('a' + i);
  }
  cout << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
