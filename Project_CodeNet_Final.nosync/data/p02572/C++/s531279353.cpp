#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
using ll = long long;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> a(n);
	ll sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		sum -= a[i];
		ans += (sum % MOD) * (a[i] % MOD);
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}