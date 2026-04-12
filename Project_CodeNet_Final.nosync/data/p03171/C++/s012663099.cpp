#include <bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
template <class T1, class T2>void print(T1 a[], T2 n) { for (T2 i = 0; i < n; i++) { cout << a[i] << " ";} cout << endl;}
template <class T1, class T2>void print(vector<T1> a, T2 n) { for (T2 i = 0; i < n; i++) { cout << a[i] << " "; } cout << endl;}
ll modexpo(ll a, ll b, ll m) {if (b == 0) {return 1;} else if (a == 1) {return 1;} if (b % 2 == 0) {ll t = modexpo(a, b / 2, m); t = (t * t) % m; return t;} else {ll t = modexpo(a, b / 2, m); t = (t * t) % m; t = (t * a) % m; return t;}}

ll sum[3004][3004];
ll dp[3004][3004];


ll  fn(ll l, ll r, ll a[]) {
	if (l > r) {
		return 0;
	}
	if (l == r) {
		return a[l];
	}
	if (dp[l][r] != -1) {
		return dp[l][r];
	}
	ll op1 = sum[l ][r] - fn(l + 1, r, a);
	ll op2 = sum[l][r ] - fn(l, r - 1, a);
	ll ans = max(op1, op2);
	dp[l][r] = ans;
	return ans;
}

int main() {

	// taskkill /IM "cp.exe" /F
	fast
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
//#endif



	ll n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		ll s = 0;
		for (int j = i; j < n; j++) {
			s += a[j];
			sum[i][j] = s;
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	print(sum[i], n);
	// }
	ll t = sum[0][n - 1];
	ll f = fn(0, n - 1, a);
	ll s = t - f;
	ll ans = f - s;
	cout << ans;

}