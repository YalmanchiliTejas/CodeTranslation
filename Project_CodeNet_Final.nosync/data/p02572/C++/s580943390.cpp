#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	vector<ll> A(n);
	ll sum = 0, sum2 = 0;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
		sum = (sum + A[i]) % MOD;
		sum2 = (sum2 + A[i] * A[i]) % MOD;
	}
	ll res = (sum * sum % MOD + MOD - sum2) % MOD;
	if (res % 2 == 0)
		res /= 2;
	else
		res = (res + MOD) / 2;
	cout << res << '\n';
}
