/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
const int MOD = 1000000007;
const int MOD1 = 998244353;
const int maxn = 100010;
const int lim = (int)1e9;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n = 0ll, x = 0ll, m = 0ll, sum = 0ll;
	cin >> n >> x >> m;
	map<lli, pair<lli, lli> > mp;
	lli res = 0ll;
	for (lli i = 1ll; i <= n; ++i)
	{
		if (mp.count(x) == 1)
		{
			lli d = i - mp[x].fi;
			lli y = max(0ll, (n - i - 1ll) / d);
			i += (1ll * y * d); res += (1ll * y * (res + x - mp[x].se));
		}
		res += x;
		mp[x] = {i, res};
		x = (x * x) % m;
	}
	cout << res << endl;
}