#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
typedef long long ll;
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		sum %= MOD;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + MOD - a[i];
		sum %= MOD;
		ans += a[i] % MOD * sum % MOD;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}