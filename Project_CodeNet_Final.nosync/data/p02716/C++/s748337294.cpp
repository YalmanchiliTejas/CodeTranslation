//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) cout << fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  //ios::sync_with_stdio(false);
  //cin.tie(nullptr);

  ll n;
  cin >> n;
  vll a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];

  vector<vll> dp(n, vll(2));
  //dp[i][0] : a[i] まで見て floor((i + 1) / 2) 個取る
  //dp[i][1] :               ceil((i + 1) / 2) 個取る
  dp[0][0] = 0;
  dp[0][1] = a[0];
  dp[1][0] = max(a[0], a[1]);
  dp[1][1] = max(a[0], a[1]);

  vll v(n, 0); //奇数項目まで見て切り上げ，のときの選び方は1通りなので先に求めておく --- (*)
  v[0] = a[0];
  for (ll i = 2; i < n; i += 2) v[i] = v[i - 2] + a[i];

  for (ll i = 2; i < n; i++) {
    dp[i][0] = max(dp[i - 1][1], dp[i - 2][0] + a[i]);
    if (i % 2 == 0) dp[i][1] = v[i]; // ------------------------------------ (*)
    else dp[i][1] = dp[i][0]; //偶数項目まで見たときは切り上げも切り捨ても変わらない
  }
  cout << dp[n - 1][0] << endl;
}
