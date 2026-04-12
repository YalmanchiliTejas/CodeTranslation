#include <bits/stdc++.h>
#define pb push_back

using namespace std;
using ll = long long int;
const int MOD = 998244353;

ll dp[3005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, s; cin >> n >> s;
	int a[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	ll ans = 0;
	dp[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > s) continue;
		if (a[i] < s) ans += 1LL * (n-i) * dp[s-a[i]];
		else ans += 1LL * (n-i) * (i+1);
		ans %= MOD;
		for (int x = s; x > a[i]; --x)
		{
			dp[x] += dp[x-a[i]];
			dp[x] %= MOD;
		}
		dp[a[i]] += i+1; dp[a[i]] %= MOD;
	}
	cout << ans;
}