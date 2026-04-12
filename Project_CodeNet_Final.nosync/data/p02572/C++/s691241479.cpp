#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define deb(x) cout<<#x<<"="<<x<<endl;
#define endl '\n'
#define M 1000000007
#define int long long
#define INF 1e18
#define N 1000005

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	ll pre[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (ll i = n - 1; i >= 0; --i)
	{
		if (i == n - 1)pre[i] = a[i];
		else pre[i] = (a[i] + pre[i + 1]) % M;
	}
	ll ans = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		ans = (ans + (a[i] * pre[i + 1]) % M) % M;
	}
	cout << ans << endl;
}

int32_t main()
{
	IOS
	ll T = 1;
	// cin >> T;
	for (ll i = 1; i <= T; ++i)
	{
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}