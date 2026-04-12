#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
  int n, k, p, r;
  cin >> n >> k;
  ll ans = 0;
  for (int b = 1; b <= n; b++) {
    p = n / b; r = n % b;
    ans += p * max(0, b-k);
    ans += max(0,r-k+1);
  }
  if (k == 0) ans -= n;
  cout << ans << endl;
  return 0;
}