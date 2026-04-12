#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
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

#define FOR_LT(i, beg, end) for (int i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (int i = beg; i <= end; i++)
#define FOR_DW(i, beg, end) for (int i = beg; end <= i; i--)

using namespace std;

static const int kRem = 1000000007;

tuple<int64_t, int64_t, int64_t> gcd(int64_t x, int64_t y)
{
	assert(0 < x);
	assert(0 <= y);

	if (x < y) swap(x, y);

	if (y == 0) return make_tuple(x, 1, 0);

	tuple<int64_t, int64_t, int64_t> ret = gcd(y, x % y);

	return make_tuple(get<0>(ret), get<2>(ret), get<1>(ret) - (x / y) * get<2>(ret));
}

int64_t divide_rem(int64_t divident, int64_t dividor, int64_t rem)
{
	int64_t ret = get<2>(gcd(rem, dividor));
	while (ret < 0) ret += rem;

	ret *= divident;
	ret %= rem;

	return ret;
}

int64_t nCr(int64_t n, int64_t r, int64_t rem) {
	if (n == 0) return 0;
	if (r > n) return 0;

	if (n - r < r) r = n - r;

	int64_t ret = 1;
	for (int64_t i = 0; i < r; i++) {
		ret *= (n - i);
		ret %= kRem;
		ret = divide_rem(ret, i + 1, rem);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64_t n, m, k; cin >> n >> m >> k;

	int64_t cases = nCr(n * m - 2, k - 2, kRem);

	int64_t val = 0;
	FOR_LT(d, 1, n) {
		int64_t cur = cases;
		cur *= d;
		cur %= kRem;
		cur *= (n - d);
		cur %= kRem;
		cur *= m;
		cur %= kRem;
		cur *= m;
		cur %= kRem;
		val += cur;
		val %= kRem;
	}

	FOR_LT(d, 1, m) {
		int64_t cur = cases;
		cur *= d;
		cur %= kRem;
		cur *= (m - d);
		cur %= kRem;
		cur *= n;
		cur %= kRem;
		cur *= n;
		cur %= kRem;
		val += cur;
		val %= kRem;
	}

	cout << val << endl;

	return 0;
}