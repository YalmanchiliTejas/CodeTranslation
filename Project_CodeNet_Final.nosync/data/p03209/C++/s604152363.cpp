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

void init_IO() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

const int MAX_N = 51;

int64 sz[MAX_N], cnt[MAX_N];

void precalc() {
	sz[0] = cnt[0] = 1;

	for(int i = 1; i < MAX_N; ++i) {
		sz[i]  = 2 * sz[i - 1] + 3;
		cnt[i] = 2 * cnt[i - 1] + 1; 
	}
}

std::map<pair<int, int64>, int64> mem;

int64 get(int layer, int64 x) {
	auto arg = std::make_pair(layer, x);

	if(mem.count(arg)) {
		return mem[arg];
	}

	if(layer == 0) {
		return (mem[arg] = x);
	}

	if(x > 0) {
		if(x == sz[layer]) {
			return (mem[arg] = cnt[layer]);
		} else {
			int64 rez = 0;

			rez += get(layer - 1, std::min(x - 1, sz[layer - 1]));

			if(x >= sz[layer - 1] + 2) {
				++rez;
				rez += get(layer - 1, std::min(x - sz[layer - 1] - 2, sz[layer - 1]));
			}

			return (mem[arg] = rez);
		}
	}

	return (mem[arg] = 0);
}

void solve() {
	int n;
	int64 x;

	cin >> n >> x;
	cout << get(n, x) << '\n';
}

int main() {
	init_IO();

	precalc();
	solve();

	return 0;
}
