#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m;

ll f(ll x) { return x*x%m; }

int main()
{
	ll n, x;
	scanf("%lld%lld%lld", &n, &x, &m);
	ll t = f(x), h = f(f(x));
	while (t != h) t = f(t), h = f(f(h));
	ll m = 0, l = 1;
	for (h = x; h != t; h = f(h), t = f(t), ++m);
	for (h = f(h); h != t; h = f(h), ++l);
	if (n <= m) {
		ll ans = x;
		while (--n) x = f(x), ans += x;
		printf("%lld\n", ans);
	}
	else {
		ll ans = 0, loop = 0;
		while (m--) ans += x, x = f(x), --n;
		for (int i = l; i > 0; --i) loop += x, x = f(x);
		for (int k = n%l; k--; ans += x, x = f(x));
		printf("%lld\n", ans+loop*(n/l));
	}
}