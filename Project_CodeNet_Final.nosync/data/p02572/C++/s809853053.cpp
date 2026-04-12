#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
using ll = long long int;
ll a[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	ll totalsum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		totalsum += a[i];
	}

	ll sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum = (sum + a[i] * ((totalsum - a[i]) % MOD) % MOD) % MOD;
		totalsum -= a[i];
	}
	cout << sum << '\n';
	return 0;
}
