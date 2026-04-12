#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <bitset>
#include <functional>
#include <iomanip>
#include <random>

#include <atcoder/all>

#define FOR_LT(i, beg, end) for (decltype(end) i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (decltype(end) i = beg; i <= end; i++)
#define FOR_DW(i, beg, end) for (decltype(beg) i = beg; end <= i; i--)
#define REP(n)              for (decltype(n) repeat_index = 0; repeat_index < n; repeat_index++)

using namespace std;

int64_t e() {
	return -1;
}

int64_t op(int64_t lhs, int64_t rhs)
{
	return max(lhs, rhs);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);

	int n, q; cin >> n >> q;
	atcoder::segtree<int64_t, op, e> segt(n);
	FOR_LT(i, 0, n) {
		int64_t a; cin >> a;
		segt.set(i, a);
	}

	REP(q) {
		int op; cin >> op;
		if (op == 1) {
			int64_t x, a; cin >> x >> a;
			x--;
			segt.set(x, a);
		}
		if (op == 2) {
			int l, r; cin >> l >> r;
			cout << segt.prod(l - 1, r) << endl;;
		}
		if (op == 3) {
			int64_t x, v; cin >> x >> v; x--;
			int64_t ans = segt.max_right(x, [&](int64_t val) { return (val < v); });
			cout << ans + 1 << endl;
		}
	}

	return 0;
}