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
#include <functional>
#include <iomanip>

#define FOR_LT(i, beg, end) for (int i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (int i = beg; i <= end; i++)
#define FOR_DW(i, beg, end) for (int i = beg; end <= i; i--)

using namespace std;

static const int64_t kRem = 998244353;

int64_t pow_rem(int64_t x, int64_t m, int64_t rem)
{
	if (m == 0) {
		return 1;
	}
	if (m == 1) {
		return x;
	}

	if (m & 1) {
		int64_t val = pow_rem(x, m / 2, rem);
		val = val * val;
		val %= rem;
		val *= x;
		val %= rem;
		return val;
	}
	else {
		int64_t val = pow_rem(x, m / 2, rem);
		val = val * val;
		val %= rem;
		return val;
	}
}

int64_t pow_remdiv(int64_t val, int64_t rem)
{
	return pow_rem(val, rem - 2, rem);
}

int64_t divide_rem(int64_t divident, int64_t dividor, int64_t rem)
{
	int64_t ret = pow_remdiv(dividor, rem);
	ret *= divident;
	ret %= rem;

	return ret;
}


vector<int64_t> factors;
vector<int64_t> finvs;
void precalc_nCr(int n, int64_t rem) {
	factors = vector<int64_t>(n + 1);
	finvs = vector<int64_t>(n + 1);

	{
		int64_t f = 1;
		factors[0] = 1;
		FOR_LE(i, 1, n) {
			f *= i;
			f %= rem;
			factors[i] = f;
		}
	}
	{
		int64_t inv = divide_rem(1, factors[n], rem);
		finvs[n] = inv;
		FOR_DW(i, n - 1, 0) {
			inv *= i + 1;
			inv %= rem;
			finvs[i] = inv;
		}
	}
}

int64_t nCr(int n, int k) {
	int64_t val = factors[n];
	val *= finvs[n - k];
	val %= kRem;
	val *= finvs[k];
	val %= kRem;
	return val;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64_t n; cin >> n;

	precalc_nCr(n, kRem);

	int64_t ans = 0;
	FOR_LE(k, n / 2 + 1, n) {
		int64_t val = nCr(n, k);
		val *= pow_rem(2, n - k, kRem);
		val %= kRem;
		ans += val;
		ans %= kRem;
	}

	ans *= 2;
	ans %= kRem;

	ans = pow_rem(3, n, kRem) - ans;
	if (ans < 0) ans += kRem;

	cout << ans << endl;

	return 0;
}