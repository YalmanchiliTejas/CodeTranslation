#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define pb push_back
#define eb emplace_back
#define rep(a, b, i) for(int i = a; i < b; i++)
#define repi(a, b, i) for(int i = a; i > b; i--)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define __ ios_base::sync_with_stdio(cin.tie(0) && 0);

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef double ld;

const ld pi = 3.141592653589793;
const ll inf = 1e18 + 5;
const int MOD = 1e9 + 7;
const int maxn = 2e5 + 5;
const int mxn = 1e5 + 5;
const int mx = 1000;

int main() {
  __;

  int n; cin >> n;
  int a[n];
  rep(0, n, i) cin >> a[i];

  ll ans = 0;
  ll sum = 0;
  rep(0, n, i) {
    (ans += (sum * a[i]) % MOD) %= MOD;
    (sum += a[i]) %= MOD;
  }

  cout << ans << '\n';

  return 0;
}
