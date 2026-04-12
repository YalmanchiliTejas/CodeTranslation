#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;

ld const PI = 4*atan((ld)1);

int const N = 1e5 + 7;
ll ar[N];
ll pos[N] = {};

int main()
{
	fastio;

	ll n, x, m;
	cin >> n >> x >> m;

	if (n <= 100000)
	{
		ll res = x;
		for (ll i = 2; i <= n; ++i)
		{
			x = (x * x) % m;
			res += x;
		}
		cout << res << '\n';
		return 0;
	}

	ar[1] = x;
	pos[x] = 1;

	int len = 2;
	ll res = 0;
	for (; len <= n; ++len)
	{
		ar[len] = (ar[len-1] * ar[len-1]) % m;

		if (len == n || ar[len] == 0)
		{
			for (int i = 1; i <= len; ++i)
				res += ar[i];
			break;
		}
		else if (pos[ar[len]] == 0)
		{
			pos[ar[len]] = len;
		}
		else
		{
			ll lt = pos[ar[len]], rt = len-1;
			ll sum = 0;

			for (int i = lt; i <= rt; ++i)
				sum += ar[i];

			n -= (lt - 1);
			for (int i = 1; i < lt; ++i)
				res += ar[i];

			ll segment_len = (rt - lt + 1);
			res += (n / segment_len) * sum;
			for (int i = lt; i < lt + (n % segment_len); ++i)
				res += ar[i];

			break;
		}
	}
	cout << res << '\n';

	return 0;
}
