#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int mod = 1e9 + 7;
const int MAX = 2e5 + 1;

ll a[MAX], sum[MAX];

void solve()
{
	int n;
	cin >> n;
	ll SUM = 0;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		SUM += a[i];
	}
	ll run = 0;
	for(int i = 1; i <= n; ++i)
	{
		run += a[i];
		sum[i] = (SUM - run) % mod;
	}
	ll ans = 0;
	for(int i = 1; i < n; ++i)
	{
		ans += (a[i] * sum[i]) % mod;
		ans %= mod;
	}
	cout << (ans % mod);
}

int main()
{
	IOS
	int t = 1;
	//cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}
