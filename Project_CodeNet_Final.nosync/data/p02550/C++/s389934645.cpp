#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, x, m, ans = 0;
	cin >> n >> x >> m;
	vector <ll> rm (m, -1);
	for (i = 1; i < n && rm[x] == -1; ++i)
		ans += x,
		rm[x] = (x*x)%m,
		x = rm[x];
	if (i == n)
	{
		ans += x;
		cout << ans << '\n';
		return 0;
	}
	ll per = 1, qnt = x, ax = x;
	for (ax = rm[x]; ax != x; ax = rm[ax], ++per)
		qnt += ax;
	ans += qnt*((n-i)/per);
	for (j = 0; j < (n-i)%per; ++j)
		ans += x,
		x = rm[x];
	ans += x;
	cout << ans << '\n';
	//trav (a, rm) cout << a << ' ';
	//cout << '\n';

	return 0;
}

