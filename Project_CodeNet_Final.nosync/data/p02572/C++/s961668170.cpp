#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define mod 1000000007

int main() {
	int n;
	int i, j;
	cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	ll ans=0;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	b[0] = a[n - 1];
	for (i = 1 ; i < n - 1; i++) {
		b[i] = (b[i - 1] + a[n - i - 1])%mod;
	}
	for (i = 0; i < n - 1; i++) {
		ans += (a[i] * b[n - i - 2]) % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}