#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int M = 100000;

ll n, x, m, a[M + 1];
int used[M];

int main() {
  cin >> n >> x >> m;
  a[0] = x;
  int l = 0;
  rep(i, m) used[i] = -1;
  while (1) {
    // printf("l = %d\n", l);
    if (used[a[l]] != -1) break;
    used[a[l]] = l;
    a[l + 1] = a[l] * a[l] % m;
    l++;
  }
  int si = used[a[l]];
  ll ans = 0;
  rep(i, si) ans += a[i];
  n -= si;

  // cout << ans << endl;

  ll sm = 0;
  for (int i = si; i < l; i++) sm += a[i];
  ll ln = l - si;
  ans += n / ln * sm;
  n %= ln;

  // cout << ans << endl;

  int i = si;
  rep(j, n) {
    ans += a[i++];
    if (i >= l) i = si;
  }
  cout << ans << endl;
  return 0;
}