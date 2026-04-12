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

//最大公約数
long long mygcd(long long a, long long b) {
  if (a < b) std::swap(a, b);
  long long r = a % b;
  while (r) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

//a^n mod p
//n > 0
//#include <cmath>
long long modpow(long long a, long long n, long long p) {
  a %= p;
  if (a == 0) return 0;
  if (a == 1) return 1;
  long long b = 1, cnt = 0;
  while (b < p && cnt < n) {
    b *= a;
    cnt++;
  }
  if (b < p) return b;
  b %= p;
  return modpow(b, n / cnt, p) * (long long)pow(a, n % cnt) % p;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);

	ll n;
	cin >> n;
	vll a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	vector<vll> dp(n, vll(2));
	//a[i]まで，j:切り捨て，切り上げ，k:値，自身を含むかどうか
	dp[0][0] = 0;
	dp[0][1] = a[0];
	dp[1][0] = max(a[0], a[1]);
	dp[1][1] = max(a[0], a[1]);

	vll v(n);
	v[0] = a[0];
	for (ll i = 2; i < n; i += 2) v[i] = v[i - 2] + a[i];

	for (ll i = 2; i < n; i++) {
		if (i % 2 == 0) {
			dp[i][0] = max(dp[i - 1][1], dp[i - 2][0] + a[i]);
			dp[i][1] = v[i];
		}
		else {
			dp[i][0] = max(dp[i - 1][1], dp[i - 2][0] + a[i]);
			dp[i][1] = dp[i][0];
		}
	}
	cout << dp[n - 1][0] << endl;
}
