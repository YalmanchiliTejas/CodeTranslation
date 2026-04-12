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

ll const mod = 1e9 + 7;

ll add(ll x, ll y)
{
	return (x + y) % mod;
}

ll sub(ll x, ll y)
{
	return (x - y + mod) % mod;
}

ll mul(ll x, ll y)
{
	return (x * y) % mod;
}

int const N = 2e5 + 7;
ll ar[N];
ll pfx[N] = {};

ll range(ll a, ll b)
{
	return sub(pfx[b], pfx[a-1]);
}

int main()
{
	fastio;

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> ar[i], pfx[i] = add(ar[i], pfx[i-1]);

	ll res = 0;
	for (int i = 1; i < n; ++i)
	{
		res = add(res, mul(ar[i], range(i+1, n)));
	}
	cout << res << '\n';

	return 0;
}
