#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vi h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  int ans = 0;
  int prev = 0;
  for (int i = 0; i < n; i++) {
    if (prev <= h[i]) {
      ans++;
      prev = h[i];
    }
  }
  cout << ans << endl;
  return 0;
}
