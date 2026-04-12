#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(20);

  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) { cin >> h[i]; }
  
  int ans = 0;
  int max_h = h[0];
  rep(i, n) {
    if (max_h <= h[i]) ans++;
    max_h = max(max_h, h[i]);
  }
  cout << ans << endl;
  return 0;
}
