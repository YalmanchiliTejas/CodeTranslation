#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
const ll mod = 1000000007;
ll n, m, k;
string s;
vector<int> road[2010], vec;
bool flag[2010], res;
map<P, int> mp;

ll pow(ll x, ll y)
{
	if (y == 0) return 1;
	if (y % 2)
	{
		return pow(x, y - 1) * x % mod;
	}
	else
	{
		ll yyy = pow(x, y / 2);
		return yyy * yyy % mod;
	}
}

ll div(ll x)
{
	return pow(x, mod - 2);
}

int main(void)
{
	cin >> n >> m >> k;
	ll ans = 1;
	for (ll i = 1; i <= k - 2; i++)
	{
		(ans *= (n * m - i - 1)) %= mod;
		(ans *= div(i)) %= mod;
	}
	ll res = 0;
	for (ll i = 1; i < n; i++)
	{
		for (ll j = 1; j < m; j++)
		{
			(res += 2 * (i + j) * (n - i) % mod * (m - j) % mod) %= mod;
		}
	}
	for (ll i = 1; i < n; i++)
	{
		(res += m * (n - i) % mod * i % mod) %= mod;
	}
	for (ll i = 1; i < m; i++)
	{
		(res += n * (m - i) % mod * i % mod) %= mod;
	}
	cout << ans * res % mod << endl;
	int www;
	cin >> www;
}
