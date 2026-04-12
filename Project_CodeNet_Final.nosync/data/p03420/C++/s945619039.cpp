#include <bits/stdc++.h>

#define rand() ((rand()<<15)+rand())

using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename Key, typename Value>
using hash_map = cc_hash_table<Key, Value>;
template<typename T, typename Cmp = less<T>>
using oset = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;
*/
typedef long long lint;
typedef complex<double> point;

const int INF = 0x3f3f3f3f;
const lint INFL = 0x3f3f3f3f3f3f3f3fLL;
const double E = 1e-9, pi = 2 * acos(0);

template<typename T, typename U> void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> void amax(T &x, U y) { if (x < y) x = y; }

bool solve(int testNumber) {
	int n, k;
	if (!(cin >> n >> k)) {
		return false;
	}
	lint ans = 0;
	for (int b = k + 1; b <= n; b++) {
		int x = n / b, y = n % b;
		ans += x * (b - k) + max(y - k + 1, 0) - !k;
		//cout << b << ' ' << x * (b - k) << ' ' << max(y - k, 0) << endl;
	}
	cout << ans << endl;
	return true;
}

void init(const char *in = nullptr, const char *out = nullptr) {
	if (in) freopen(in, "r", stdin);
	if (out) freopen(out, "w", stdout);
	srand(unsigned((long long)new char));
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	for (int i=1; solve(i); i++);
	return 0;
}
