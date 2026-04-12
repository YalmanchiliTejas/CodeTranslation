#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
	int n; cin >> n;
	vector<long long> a(n);
	for (long long& e : a) cin >> e;
	vector<long long> t(n);
	t[n - 1] = a[n - 1];
	for (int i = n - 1; i > 0; --i)
		t[i - 1] = (t[i] + a[i - 1]) % MOD;
	long long ans = 0;
	for (int i = 1; i < n; ++i)
		(ans += a[i - 1] * t[i] % MOD) %= MOD;
	cout << ans << endl;

	return 0;
}