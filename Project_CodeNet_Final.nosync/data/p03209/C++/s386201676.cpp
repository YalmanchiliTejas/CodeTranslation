#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll num_layer(int lvl) {
  return (1LL<<(lvl+2)) - 3;
}

ll num_patty(int lvl) {
  return (1LL<<(lvl+1)) - 1;
}

ll num_patty_eaten(int lvl, ll eat) {
  if (eat == 0) return 0;
  ll nlay = num_layer(lvl);
  if (eat == nlay) return num_patty(lvl);
  ll mid = (nlay + 1) / 2;
  if (eat < mid) return num_patty_eaten(lvl-1, eat-1);
  return num_patty(lvl-1) + 1 + num_patty_eaten(lvl-1, eat-mid);
}

int main() {
  int n;
  ll x;
  cin >> n >> x;
  ll ans = num_patty_eaten(n, x);
  cout << ans << endl;
  return 0;
}