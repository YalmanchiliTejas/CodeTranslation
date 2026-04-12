// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O2")
// #pragma GCC optimization ("unroll-loops")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// #define int ll
#define pb push_back
#define pob pop_back
#define __bp __builtin_popcount
using pii = pair<int,int>;
using pil = pair<int,ll>;
using pli = pair<ll,int>;
using pdd = pair<ld,ld>;
using vint = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
#define F first
#define S second
const int N = 2e5+5;//(1 << 18) + 5;
//const ll inf = 1e18+7;
const int Inf = 1e9+7;
const ll INF = 1e18+7;
const int Mod = 998244353;
const ld eps = 1e-9;
#ifndef M_PI
#define M_PI 3.1415926535
#endif

void io()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr.tie(NULL);
//	freopen("sweets.in", "r", stdin);
//	freopen("sweets.out", "w", stdout);
//	cout << setprecision(7) << fixed;
}

ll n, x, m;
bool used[N];

void solve()
{
	cin >> n >> x >> m;
	ull ans = 0;
	vint pos;
	for (;n; --n)
	{
		pos.pb(x);
		if (used[x])
			break;
		used[x] = 1;
		ans += x;
		x *= x;
		x %= m;
	}
	// cerr << n << endl;
	if (!used[x])
	{
		cout << ans << '\n';
		return;
	}
	reverse(pos.begin(), pos.end());
	ll cycle_sum = pos[0];
	ll cycle_size = 1;
	for (;; ++cycle_size)
	{
		if (pos[cycle_size] == x)
			break;
		cycle_sum += pos[cycle_size];
	}
	ll cycle_cnt = n / cycle_size;
	ans += ull(cycle_sum) * cycle_cnt;
	n %= cycle_size;
	// cerr << cycle_size << endl;
	// cerr << cycle_sum << endl;
	// cerr << cycle_cnt << endl;
	for (int i = 0; i < n; ++i)
	{
		ans += x;
		x *= x;
		x %= m;
	}
	cout << ans << '\n';
}

signed main()
{
	io();
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		// solve();
		solve();
//		cerr << '\n';

	}
}