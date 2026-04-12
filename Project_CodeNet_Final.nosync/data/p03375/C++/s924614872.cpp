/*
 * Code be weshen zyk :'(
 * I won't surrender quietly
 */
//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using orderd_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define S second
#define F first
#define pb push_back

using ii = pair<int, int>;
using ll = long long;
using db = long double;

const int N = 3e3 + 5, K = 12, MOD = 998244353;
const ll MX = 1e15;
ll S[N][N], C[N][N];
ll p2[N], p2p[N];
ll n, m;
void init() {
	p2[0] = p2p[0] = 1;
	for (int i = 1; i < N; i++) {
		p2[i] = (p2[i-1] + p2[i-1]) % m;
		p2p[i] = (p2p[i-1] + p2p[i-1]) % (m - 1);
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			if (i == j || j == 0)
				C[i][j] = 1;
			else
				C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % m;
	S[0][0] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				S[i][j] = 1;
			else
				S[i][j] = (S[i - 1][j] * (j + 1) + S[i - 1][j - 1]) % m;
		}
	}

}
ll fast(ll b, ll e, ll m) {
	if (!e)
		return 1;
	if (e & 1)
		return b * fast(b, e - 1, m) % m;
	return fast(b * b % m, e >> 1, m);
}
ll solve(int once) {
	ll ret = 0;
	///number of ways to partition once numbers on j sets
	for (int i = 0; i <= once; i++) {
		ret += S[once][i] * fast(2, p2p[n - once], m) % m
				* fast(p2[n - once], i, m) % m; ///number of partitions * number of remaining sets of what is left
		///number of remaining toppings = (n - once)
		///2 ^ (2 ^ toppings)
		if (ret >= m)
			ret -= m;
	}
//	cout << ret << '\n';
	return ret * C[n][once] % m;
}
int main() {
#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#endif
	cin >> n >> m;
	init();
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		if (i & 1) {
			ans -= solve(i);
		} else
			ans += solve(i);
		if (ans >= m)
			ans -= m;
		if (ans < 0)
			ans += m;
	}

	cout << ans << '\n';

	return 0;
}
