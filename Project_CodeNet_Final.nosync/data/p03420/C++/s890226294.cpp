#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define str string
#define fi first
#define se second
#define pb push_back
#define SET(a, b) memset(a, b, sizeof(a))
#define eps 1e-6
#define pi atan(1) * 4
#define mod 1000000007
#define inf 1000000000
#define llinf 1000000000000000000
#define FOR(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define FORD(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define FORl(i, a, b, c) for (ll i = (a); i <= (b); i += (c))
#define FORDl(i, a, b, c) for (ll i = (a); i >= (b); i -= (c))
using namespace std;
ll solve (int n, int k) {
	ll res = 0;
	FOR(i, k + 1, n, 1) {
		int low = (n - i + 1) / i + 1;
		int high = (n - k) / i + 1;
		if (low + 1 < high) {
			res += (ll)(low + 1 + high - 1) * (high - 1 - (low + 1) + 1) / 2;
		}
		if (low == high) {
			int rl = (n - i + 1) % i;
			int rh = (n - k) % i;
			res += (ll)(rh - rl + 1) * low;
		} else {
			int rl = i - ((n - i + 1) % i);
			int rh = ((n - k) % i) + 1;
			res += (ll)rl * low + (ll)rh * high;
		}
	}
	if (k == 0) res -= n;
	return res;
}
int main () {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%lld\n", solve(n, k));
	return 0;
}