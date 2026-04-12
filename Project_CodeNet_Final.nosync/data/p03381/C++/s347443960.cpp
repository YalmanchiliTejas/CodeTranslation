#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>,
		null_type,
		less<pair<int, int>>,
		rb_tree_tag,
		tree_order_statistics_node_update>
		st;

//find_by_order(k);
//order_of_key(x);


const int MAXN = 220000;
int a[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	st ss;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		ss.insert(make_pair(a[i], i));
	}
	for (int i = 0; i < n; ++i) {
		ss.erase({a[i], i});
		cout << ss.find_by_order((n - 1) / 2)->first << " ";
		ss.insert({a[i], i});
	}
	return 0;
}


