#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

// ====================================================================

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int h = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    if (h <= v[i]) {
      h = v[i];
      ans++;
    }
  }
  cout << ans << endl;
}
