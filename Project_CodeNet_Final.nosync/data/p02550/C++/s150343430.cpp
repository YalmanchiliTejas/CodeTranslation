#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define all(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
#define cps(x) sort(all(x)), (x).erase(unique(all(x)), end(x))
#define cps2(x, y) sort(all(x), y), (x).erase(unique(all(x)), end(x))
#define mem(x, y) memset(& x, y, sizeof(x))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int n0 = 1e5 + 123;
ll n, x, m, used[n0], p[n0], val[n0];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> x >> m;
	memset(& used, -1, sizeof(used));
	ll cur = x;
	p[0] = cur, used[cur] = 0, val[0] = cur;
	for (ll i = 1; i < n; i++) {
		cur = cur * cur % m;
		val[i] = cur;
		p[i] = p[i - 1] + val[i];
		if (used[cur] != -1) {
			ll j = used[cur];
			ll len = i - j, res = 0, bef = 0;
			if (j) bef = p[j - 1];
			res = bef;
			n -= j;
			res += (n / len) * (p[i - 1] - bef);
			n %= len;
			for (ll k = j; k < j + n; k++) res += val[k];
			cout << res;
			return 0;
		}
		used[cur] = i;
	}
	cout << p[n - 1];
}
