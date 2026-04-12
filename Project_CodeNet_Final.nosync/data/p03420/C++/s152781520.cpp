#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  if (k == 0) {
    ans = (ll)n * n;
    cout << ans << endl;
    return 0;
  }
  for (int b = k+1; b <= n; ++b) {
    ans += max(n%b-k+1, 0) + (b-k) * (n/b);
    // printf("b = %d, ans = %lld\n", b, ans);
  }
  cout << ans << endl;
  return 0;
}