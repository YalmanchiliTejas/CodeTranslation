#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return b/gcd(a,b)*b;}

int main() {
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll ans = LONG_LONG_MAX;
  // 制約条件に目をつける
  // 全探索で終わるなら全探索する
  for (ll i = 0; i <= 100000; i++) {
    ans = min(2 * c * i + a * max(ll(0), x-i) + b * max(ll(0), y-i), ans);
  }
  cout << ans << endl;
  return 0;
}