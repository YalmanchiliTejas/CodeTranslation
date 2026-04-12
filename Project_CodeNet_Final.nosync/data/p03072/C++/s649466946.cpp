#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)  //  repマクロ
#define leng(n) (int)(log10(n)+1)  //  桁数
using namespace std;

signed main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) {
    cin >> h[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    bool ok = true;
    for (int j = 0; j < i; j++) {
      if (h[i] < h[j]) {
      ok = false;
      break;
      }
    }
    if (ok) ans++;
  }
  cout << ans << endl;
}
