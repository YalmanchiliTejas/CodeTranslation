#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
ll a[200100];
ll sum = 0; 
int main() {
	int n;
	cin >> n;
	rep(i,n) cin >> a[i];
	rep(i,n) {
		sum += a[i];
		sum %= MOD;
	}
	ll ans = 0;
	rep(i,n) {
		sum -= a[i];
		if (sum < 0) sum += MOD;
		ans += a[i] * sum % MOD;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}