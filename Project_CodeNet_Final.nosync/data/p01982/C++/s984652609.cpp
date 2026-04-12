#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define rep(i, j, k) for (auto i = j; i < k; i++)
#define rrep(i, j, k) for (auto i = j; i > k; i--)
using namespace std;

void solve(int &n, int &l, int &r) {
  int a[51];
  rep(i, 0, n) cin >> a[i];
  int ans = 0;
  rep(i, l, r + 1) {
    bool uruu = (n & 1 ? false : true);
    rep(j, 0, n) {
      if (i % a[j] == 0) {
        uruu = (j & 1 ? false : true);
        break;
      }
    }
    if(uruu) ans++;
  }
  cout << ans << endl;
}

int main() {
  int n, l, r;
  while (cin >> n >> l >> r, n) solve(n, l, r);
}

