#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll long long

const int MOD = 1000000007;

int main() {
	//入力
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	//処理
	ll mx = 0;
	for (int i = 1;i < n;++i) {
		mx += a[i];
	}
	int ans = 0;
	rep(i, n-1) {
		ans += ((a[i] % MOD) * (mx % MOD)) % MOD;
		ans = ans % MOD;
		mx -= a[i + 1];
	}

	//出力
	cout << ans << endl;
} 