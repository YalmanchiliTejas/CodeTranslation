#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P=pair<int, int>;
typedef long long ll;

int const mod = 1e9 + 7;
signed main(void)
{
	int n;
	cin >> n;
	ll a[n];
	vector<ll> sum(n + 1, 0);
	ll ans;

	rep(i, n) cin >> a[i];
	for (int i = 1; i <= n; i++)
		sum[i] += sum[i - 1] + a[i - 1];
	ans = 0;
	rep(i, n - 1)
	{
		ans += ((sum[n] - sum[i + 1]) % mod * a[i]) % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
