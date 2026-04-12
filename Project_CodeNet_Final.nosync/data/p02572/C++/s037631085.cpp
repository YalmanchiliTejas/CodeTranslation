// J'aime
// Chemise Blanche

#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << __LINE__ << " > " << #x << " = " << (x) << endl

const int MOD = 1e9 + 7;

void MAIN() {
  int n; cin >> n;
  vector<int> a(n + 1), d(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    d[i] = a[i] + d[i - 1];
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans += (a[i] * ((d[n] - d[i]) % MOD)) % MOD;
    ans %= MOD;
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
