#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>
#include <queue>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
	#define DBG(X) cout << #X << "=" << (X) << '\n';
#else
	#define DBG(X)
#endif

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::pair;
using std::swap;
using std::sort;
using std::lower_bound;
using std::unique;

using int64 = long long int;
using pii   = pair<int, int>;
using pii64 = pair<int64, int64>;

const int NIL = -1;
const int INF = (int)2e9;
const int64 INF64 = (int64)2e18;

const int MOD = (int)1e9 + 7;

int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}

int mult(int x, int y) {
	return (x * 1LL * y) % MOD;
}

int binpow(int x, int y) {
	if(y == 0 || x == 1)
		return 1;

	if(x == 0)
		return 0;

	int rez = binpow(x, y / 2);
	rez = mult(rez, rez);

	if(y & 1)
		rez = mult(rez, x);

	return rez;
}

int divide(int x, int y) {
	return mult(x, binpow(y, MOD - 2));
}

const int MAX_N = 1033;

int dp[MAX_N][MAX_N];
int A, B, C, D, N;

int fact[MAX_N], inv_fact[MAX_N];
int P[MAX_N][MAX_N];

void init_IO() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

void precalc() {
	fact[0] = 1;

	for(int i = 1; i < MAX_N; ++i) {
		fact[i] = mult(i, fact[i - 1]);
	}

	for(int i = 0; i < MAX_N; ++i) {
		inv_fact[i] = divide(1, fact[i]);
	}

	for(int i = 0; i < MAX_N; ++i) {
		for(int j = 0; j < MAX_N; ++j) {
			P[i][j] = divide(1, binpow(fact[i], j));
		}
	}
}

int choose(int k, int n) {
	if(k > n)
		return 0;

	int rez = fact[n];
	rez = mult(rez, inv_fact[k]);
	rez = mult(rez, inv_fact[n - k]);

	return rez;
}

void solve() {
	cin >> N >> A >> B >> C >> D;
	dp[0][0] = 1;

	for(int i = 0; i <= B - A; ++i) {
		int sz = A + i;
		//DBG(i);

		for(int j = 0; j <= N; ++j) {
			if(dp[i][j] == 0)
				continue;

			dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);

			for(int to_add = C; to_add <= D; ++to_add) {
				int j2 = j + sz * to_add;

				if(j2 > N)
					break;

				int ways = choose(sz * to_add, N - j);
				ways = mult(ways, fact[sz * to_add]);
				/*ways = divide(ways, binpow(fact[sz], to_add));
				ways = divide(ways, fact[to_add]);*/

				ways = mult(ways, P[sz][to_add]);
				ways = mult(ways, inv_fact[to_add]);

				/*DBG(to_add); DBG(sz); DBG(N); DBG(j);
				DBG(ways); DBG(j2); DBG(dp[i][j]);*/

				dp[i + 1][j2] = add(dp[i + 1][j2], mult(dp[i][j], ways));
			}
		}
	}

	/*for(int i = 0; i <= B - A + 1; ++i) {
		cout << i << ": ";

		for(int j = 0; j <= N; ++j) {
			cout << dp[i][j] << ' ';
		}

		cout << '\n';
	}*/

	cout << dp[B - A + 1][N] << '\n';
}

int main() {
	init_IO();

	precalc();
	solve();

	return 0;
}
