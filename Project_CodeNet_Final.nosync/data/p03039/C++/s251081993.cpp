/* 
chirag11032000
Chirag Thakur
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;

template < typename T > using OrderedSet = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
template < typename T > using MinPriorityQueue = priority_queue < T, vector < T >, greater < T > >;

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std :: endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}
#else
#define trace(...)
#endif

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const db PI = acos(-1);
const ll LINF = LLONG_MAX;
const int INF = INT_MAX, MOD = 1e9 + 7, N = 1e5 + 10;

namespace ModFunctions {
	const int F = 2e5 + 10;

	int fact[F], inv_fact[F];

	inline void add(int &a, int b) {
		a += b;
		if (a >= MOD) {
			a -= MOD;
		}
	}

	inline void sub(int &a, int b) {
		a -= b;
		if (a < 0) {
			a += MOD;
		}
	}

	inline int mul(int a, int b) {
		return int((1ll * a * b) % MOD);
	}

	inline int power(int a, ll b) {
		int res = 1;
		while (b > 0) {
			if (b & 1) {
				res = mul(res, a);
			}
			a = mul(a, a);
			b >>= 1;
		}
		return res;
	}

	inline int inv(int a) {
		a %= MOD;
		if (a < 0) {
			a += MOD;
		}
		int b = MOD, u = 0, v = 1;
		while (a) {
			int t = b / a;
			b -= t * a;
			swap(a, b);
			u -= t * v;
			swap(u, v);
		}
		assert(b == 1);
		if (u < 0) {
			u += MOD;	
		}
		return u;
	}

	void pre_build() {
		fact[0] = 1;
		for (int i = 1; i < F; ++i) {
			fact[i] = mul(fact[i - 1], i);
		}
		inv_fact[F - 1] = inv(fact[F - 1]);
		for (int i = F - 2; i >= 0; --i) {
			inv_fact[i] = mul(inv_fact[i + 1], i + 1);
		}
	}

	int choose(int x, int y) {
		if (x < y) {
			return 0;
		}
		return mul(fact[x], mul(inv_fact[y], inv_fact[x - y]));
	}
}

using namespace ModFunctions;

void testCase();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pre_build();
	testCase();
	cerr << "Time taken: " << int((clock() * 1000.) / CLOCKS_PER_SEC) << "ms\n";
	return 0;
}

void testCase() {
	int n, m, k;
	cin >> n >> m >> k;
	int to_mul = choose(n * m - 2, k - 2);
	int ans = 0;
	for (int r = 1; r <= n; ++r) {
		for (int c = 1; c <= m; ++c) {
			int right = m - c;
			int left = m - right - 1;
			int r_sum = mul(mul(right, right + 1), inv(2));
			int l_sum = mul(mul(left, left + 1), inv(2));
			int tot_sum = 0;
			add(tot_sum, l_sum);
			add(tot_sum, r_sum);
			int to_add = r_sum;
			tot_sum = mul(tot_sum, 2);
			add(tot_sum, mul(n - r + 1, m));
			tot_sum = mul(tot_sum, n - r);
			tot_sum = mul(tot_sum, inv(2));
			add(to_add, tot_sum);
			add(ans, mul(to_add, to_mul));
			// trace(r, c, ans, to_add, to_mul, r_sum, l_sum, tot_sum);
		}
	}
	cout << ans << "\n";
}