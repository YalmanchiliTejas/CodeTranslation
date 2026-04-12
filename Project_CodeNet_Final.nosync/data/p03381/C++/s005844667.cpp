#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long long unsigned llu;
typedef pair<ll, ll> P;//change when necessary
typedef long double ld;
#define mp make_pair
#define N ll(200005)//change it
#define M ll(1)
const ll OO = 1e18;
const ll md = 1e9 + 7;
ll X[] = { 0,0,1,-1 }, Y[] = { 1,-1,0,0 };
ll gcd(ll xx, ll yy)
{
	ll x = min(xx, yy), y = max(xx, yy);
	if (x == 0)
		return y;
	return gcd(x, y%x);
}
ll vivo(ll x, ll y)
{
	if (y == 0)
		return 1LL;
	if (y == 1)
		return x;
	ll t = vivo(x, y / 2), r = vivo(x, y % 2);
	t *= t;
	t *= r;
	return t;
}
ll vivo_mod(ll x, ll y, ll m)
{
	if (y == 0)
		return 1LL;
	if (y == 1)
		return x%m;
	ll t = vivo(x, y / 2), r = vivo(x, y % 2);
	t *= t; t %= m;
	t *= r; t %= m;
	return t;
}
ll mo(ll x, ll y)
{
	return max(x, y) - min(x, y);
}
void fast()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

P p[N];
ll n, ans[N];
int main()
{
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &p[i].first);
		p[i].second = i;
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)
			ans[p[i].second] = p[n / 2].first;
		else
			ans[p[i].second] = p[n / 2 - 1].first;
	}
	for (int i = 0; i < n; i++)
		printf("%lld\n", ans[i]);
	return 0;
}