#include<bits/stdc++.h>
#define GO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
const int N = 3e5 + 5;
const int M = 1e6 + 5;
const int Mod = 1e9 + 7;

int n, a[N];
ll prefO[N], sufO[N], prefE[N], sufE[N];

int main()
{
	GO;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		(i & 1 ? prefO : prefE)[i] = a[i];
		prefO[i] += prefO[i - 1];
		prefE[i] += prefE[i - 1];
	}
	for (int i = n; i >= 1; i--)
	{
		(i & 1 ? sufO : sufE)[i] += a[i];
		sufO[i] += sufO[i + 1];
		sufE[i] += sufE[i + 1];
	}
	ll ans = -1e18;
	if (n % 2)
	{
		vec pref(n + 2);
		ll mx = -1e18;
		for (int i = 0; i <= n+1; i += 2)
		{
			mx = max(mx, prefO[i] - prefE[i]);
			pref[i] = prefE[i] + mx;
		}
		mx = -1e18;
		for (int i = n+1; i >= 2; i-=2)
		{
			mx = max(mx, sufO[i] - sufE[i]);
			ans = max(ans, pref[i - 2] + sufE[i] + mx);
		}
	}
	else
		for (int i = 1; i <= n + 1; i+=2)
			ans = max(ans, prefO[i - 1] + sufE[i]);
	cout << ans << endl;
	return 0;
}