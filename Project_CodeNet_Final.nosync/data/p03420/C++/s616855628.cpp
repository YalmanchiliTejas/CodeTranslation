#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int infint = 1e9;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)2e3 + 7;
ll n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	ll ans = 0;
	for (int i = m + 1; i <= n; i++)
	{
		//[m, i - 1], [m + i, 2 * i - 1], [m + 2 * i, 3 * i - 1], ...
		ll T = (n + 1) / i, D = 0;
		D += T * (i - m);
		if((n + 1) % i)
			D += max(0LL, n - (m + T * i) + 1);
		ans += D;
	}
	if(m == 0)
		ans -= n;
	cout << ans;
}