#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

bool occ[1 << 17];

int main() {
	ll n;
	int x, m;
	scanf("%lld %d %d", &n, &x, &m);
	if (n <= 1e5) {
		ll ans = 0;
		rep(i, n) {
			ans += x;
			x = 1LL * x * x % m;
		}
		printf("%lld\n", ans);
		return 0;
	}
	vector <int> v;
	while (!occ[x]) {
		occ[x] = 1;
		v.pb(x);
		x = 1LL * x * x % m;
	}
	int o = 1;
	while (v[v.size() - o] != x) ++ o;
	ll s = 0;
	rep(i, o) s += v[v.size() - i - 1];
	ll ans = (n - v.size() + o) / o * s;
	rep(i, v.size() - o) ans += v[i];
	rep(i, (n - v.size() + o) % o) {
		ans += x;
		x = 1LL * x * x % m;
	}
	printf("%lld\n", ans);
	return 0;
}
