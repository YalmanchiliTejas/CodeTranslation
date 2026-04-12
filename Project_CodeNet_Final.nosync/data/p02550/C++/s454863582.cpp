#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define fi first
#define se second

typedef long long lli;
typedef pair<int, int> ii;
typedef pair<lli, lli> ll;

lli pref[100005], urutan[100005];

int main() {
	lli n, x, m, value, cycle, ans, hasil, sisa;
	scanf("%lld %lld %lld", &n, &x, &m);
	memset(urutan, 0, sizeof urutan);
	pref[0] = 0;
	for (lli i = 1; i <= n; i++) {
		if (urutan[x] < 1) {
			urutan[x] = i;
			pref[i] = pref[i - 1] + x;
			x = (x * x) % m;
		}
		else {
			cycle = i - urutan[x];
			ans = pref[urutan[x] - 1];
			value = pref[i - 1] - ans;
			n -= (urutan[x] - 1);
			hasil = n / cycle;
			sisa = n % cycle;
			ans += (hasil * value);
			ans += (pref[urutan[x] + sisa - 1] - pref[urutan[x] - 1]);
			printf("%lld\n", ans);
			return 0;
		}
	}
	printf("%lld\n", pref[n]);
	return 0;
}