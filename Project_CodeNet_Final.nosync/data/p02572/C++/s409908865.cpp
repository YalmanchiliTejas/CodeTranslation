#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;

	vector<ll> p(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;

		p[i + 1] = a + p[i];
	}

	ll s = 0;
	for (int i = 1; i < n; ++i) {
		ll a = (p[i] - p[i - 1]) % MOD;
		ll b = (p[n] - p[i]) % MOD;
		ll c = (a * b) % MOD;
		s = (s + c) % MOD;
	}

	cout << s;
	
	return 0;
}
