#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  int ans = 0;
  int maxh = 0;
  rep(i, n) {
    cin >> h[i];
    if (h[i] >= maxh) ans++;
    maxh = max(maxh, h[i]);
  }

  cout << ans << endl;
  return 0;
}
