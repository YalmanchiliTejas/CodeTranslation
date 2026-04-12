#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define Mp make_pair
#define pb push_back

using ll = long long;
using db = double;
using pii = pair<int, int>;
using vi = vector<int>;
mt19937 mrand(time(0));
ll get(ll r) { return ((ll)mrand() * mrand() % r + r) % r; }
ll get(ll l, ll r) { return get(r - l + 1) + l; }

signed main() {
	int n; cin >> n;
	puts(n >= 30 ? "Yes" : "No");
	fprintf(stderr, "time=%.4f\n", (db)clock()/CLOCKS_PER_SEC);
	return 0;
	/* 取模直接除，爆零两行泪
	 * 不开ll见祖宗
	 */
}