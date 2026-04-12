#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int comb(int n, int k) {
  int res = 1;
  rep(i, k) res *= n - i;
  rep(i, k) res /= k - i;
  return res;
}

int main() {
  string n;
  int k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 0; i <= n.size(); i++) {
    int nz = 0;
    rep(j, i) if (n[j] != '0') nz++;
    if (nz > k) continue;
    if (n.size() - i < k - nz) continue;
    if (i == n.size()) {
      ans++;
      break;
    }
    if (n[i] == '0') continue;
    if (k > nz) ans += (n[i] - '0' - 1) * comb(n.size() - i - 1, k - nz - 1) * pow(9, k - nz - 1);
    if (n.size() - i > k - nz) ans += comb(n.size() - i - 1, k - nz) * pow(9, k - nz);
    // printf("ans = %d\n", ans);
  }
  cout << ans << endl;
  return 0;
}