#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;
const ll MOD = ll(1e9) + 7;

int main() {
  ll n;
  ll a;
  ll wa = 0;
  ll seki = 0;
  cin >> n;
  rep(i, n) {
    cin >> a;
    wa = (wa + a) % MOD;
    seki = (seki + a * a) % MOD;
  }
  ll ans = (wa * wa - seki + MOD) % MOD;
  if (ans % 2 == 0) {
    ans /= 2;
  } else {
    ans = (ans + MOD) / 2;
  }
  cout << ans << endl;

  return 0;
}