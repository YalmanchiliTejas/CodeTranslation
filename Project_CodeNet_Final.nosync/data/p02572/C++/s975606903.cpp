#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;
#define fst first
#define snd second

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  ll ans = 0, sum = 0, mod = 1e9 + 7;
  for (int i = 0; i < n; i++) {
    ll x; cin >> x;
    ans += sum * x % mod;
    sum = (sum + x) % mod;
  }
  cout << (ans % mod) << endl;

  return 0;
}
