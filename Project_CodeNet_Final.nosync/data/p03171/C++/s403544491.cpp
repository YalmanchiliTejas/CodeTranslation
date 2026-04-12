#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define speed                                                                  \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define oprecision                                                             \
  cout.precision(30);                                                          \
  cerr.precision(7);
#define bb bool
#define ii int
#define ll long long
#define ff float
#define dd double
#define cc char
#define ss string
#define forn(sz) for (int i = 1; i <= sz; i++)
#define forni(i, sz) for (int i = 1; i <= sz; i++)
#define fornid(i, m, sz) for (int i = m; i <= sz; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define vii vector<ii>
#define vii64 vector<ll>
#define vb vector<bb>
using namespace std;
ll sz, BIG = (1LL << 60), arr[3010], dp[3010][3010];
ll rec(ll l, ll r) {
  if (l > r) {
    return 0;
  }
  if (l == r) {
    return arr[l];
  }
  if (dp[l][r] != BIG) {
    return dp[l][r];
  }
  return dp[l][r] = max(arr[l] - rec(l + 1, r), arr[r] - rec(l, r - 1));
}
int main() {
  speed;
  oprecision;
  /*#ifndef ONLINE_JUDGE
freopen("outd.txt", "rt", stdin);
#endif*/
  // code
  for (int i = 0; i <= 3001; i++) {
    for (int j = 0; j <= 3001; j++) {
      dp[i][j] = BIG;
    }
  }
  cin >> sz;
  forn(sz) { cin >> arr[i]; }
  cout << rec(1, sz);
// endl
#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
