#include <bits/stdc++.h>
#define ll long long
#define str string
#define pll pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define SET(a, b) memset(a, b, sizeof(a))
#define ff fflush(stdout)
using namespace std;
pll num[400005];
ll taken[200005];
int main () {
	ll a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q;
	scanf("%lld", &a);
	for (i = 1; i <= a; i++) {
		scanf("%lld %lld", &b, &c);
		num[i * 2 - 1] = {b, i};
		num[i * 2] = {c, i};
	}
	sort(num + 1, num + a + a + 1);
	SET(taken, 0); d = 0; f = 0;
	for (i = 1; i <= a * 2; i++) {
		if (taken[num[i].se]) {
			if (!f) f = i;
			continue;
		}
		taken[num[i].se] = 1; d++;
		if (d == a) break;
	}
	if (!f) f = i + 1;
	e = (num[i].fi - num[1].fi) * (num[a + a].fi - num[f].fi);
	SET(taken, 0); d = 0; f = 0;
	for (i = a * 2; i >= 1; i--) {
		if (taken[num[i].se]) {
			if (!f) f = i;
			continue;
		}
		taken[num[i].se] = 1; d++;
		if (d == a) break;
	}
	if (!f) f = i - 1;
	g = (num[a + a].fi - num[i].fi) * (num[f].fi - num[1].fi);
	e = min(e, g);
	SET(taken, 0); d = 0;
	for (i = 2, j = 2; i <= a * 2; i++) {
		while (d < a && j <= a * 2) {
			taken[num[j].se]++;
			if (taken[num[j].se] == 1) d++;
			j++;
		}
		if (d < a) break;
		e = min(e, (num[a + a].fi - num[1].fi) * (num[j - 1].fi - num[i].fi));
		taken[num[i].se]--;
		if (taken[num[i].se] == 0) d--;
	}
	printf("%lld\n", e);
	return 0;
}