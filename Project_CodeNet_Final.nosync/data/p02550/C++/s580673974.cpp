#include<iostream>
#include<vector>
#include<assert.h>
#define ll long long
using namespace std;

int main() {
	long long n;
	ll X, MOD;
	cin >> n >> X >> MOD;
	vector<ll> v(MOD + 1);
	vector<int> seen(MOD + 1);
	v[1] = X;
	seen[X] = 1;
	long long ans = v[1];
	for (ll i = 2; i <= n; i++) {
		ll x = ((1LL * v[i - 1] % MOD) * (v[i - 1] % MOD)) % MOD;
		if (x == 0)
			break;
		if (x == 1) {
			ans += (n - i + 1);
			break;
		}
		if (seen[x]) {
			ll sz = i - seen[x];
			ll t = 0;
			for (int j = seen[x]; j < i; j++) {
				t += v[j];
			}
			ans += ((n - i + 1) / sz) * t;
			ll rem = (n - i + 1) % sz;
			assert(rem < MOD);
			for (int j = seen[x]; j < seen[x] + rem; j++) {
				ans += v[j];
			}
			break;
		}
		else {
			v[i] = x;
			seen[x] = i;
			ans += v[i];
		}
	}
	cout << ans;
}