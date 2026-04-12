//#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
/*#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")*/
//#pragma comment(linker, "/STACK:367077216")
#define _CRT_SECURE_NO_WARNINGS
#include <chrono>
#include <set>
#include <map>
#include <deque>
#include <string>
#include <cstdint>
#include <cmath>
#include <queue>
#include <cassert>
#include <random>
#include <bitset>
#include <iomanip>
#include <numeric>
#include <time.h>//////////////
#include <ctime>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
//#define endl '\n'
#define mp make_pair
#define pbc push_back
#define pob pop_back()
#define empb emplace_back
#define queuel queue<long long>
#define sqr(a) ((a) * (a))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pin(p) cin >> p.first >> p.second;
#define uniq(a) sort(all(a));(a).resize(unique(all(a)) - a.begin());
#define rev(v) reverse(v.begin(), v.end());
#define sout(s, c) for (auto i : s) cout << i << c;
#define pout(p) cout << p.first << " " << p.second;
#define er(v, l, r) erase(v.begin() + l, v.begin() + r);
#define vin(v) for (ll i = 0; i < v.size(); ++i) cin >> v[i];
#define vout(v, c) for (int i = 0; i < v.size(); ++i) cout << v[i] << c;
#define pushi(v, a) for (int i = 0; i < a.size(); ++i) v.push_back(a[i]);
#define fastio() ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); srand(time(NULL))
#define dab(v) for(auto i:v)cout<<i<<' ';
#define sp system("pause")
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
using namespace std;
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
const ld EPS = 1e-10;
const ld PI = acos(-1);
const int MOD7 = 1000000007;
const int MOD9 = 1000000009;
const int mod = MOD7;
const int inf = 1e9;
const int MAXN = 1e3 + 2;
int add(int a, int b)
{
	a += b;
	if (a < 0) a += mod;
	if (a >= mod)a -= mod;
	return a;
}
int mul(int a, int b)
{
	return 1ll * a * b % mod;
}
int fact[MAXN];
int ifact[MAXN];
int binpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = mul(res, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}
int inv(int x)
{
	return binpow(x, mod - 2);
}
int cnk(int n, int k)
{
	if (n < k || k < 0) return 0;
	return mul(fact[n], mul(ifact[k], ifact[n - k]));
}
int invs[MAXN];
signed main()
{
	fastio();
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	vector<vector<int>> dp(n + 1, vector<int>(n + 2));
	fact[0] = 1;
	for (int i = 1; i < MAXN; ++i) fact[i] = mul(fact[i - 1], i);
	ifact[MAXN - 1] = inv(fact[MAXN - 1]);
	for (int i = MAXN - 2; i >= 0; --i)	ifact[i] = mul(ifact[i + 1], i + 1);
	for (int i = 1; i < MAXN; ++i) invs[i] = inv(i);
	dp[0][a] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int sz = a; sz <= b; ++sz)
		{
			dp[i][sz + 1] = add(dp[i][sz + 1], dp[i][sz]);
			if (i + c * sz > n) continue;
			int now = 1;
			for (int j = 0; j < c; ++j)
			{
				now = mul(now, cnk(n - i - j * sz, sz));
			}
			now = mul(now, ifact[c]);
			for (int am = c; am <= d; ++am)
			{
				if (am * sz + i > n) break;
				dp[i + am * sz][sz + 1] = add(dp[i + am * sz][sz + 1], mul(dp[i][sz],now));
				now = mul(now, cnk(n - i - am * sz, sz));
				now = mul(now, invs[am + 1]);
			}
		}
	}
	/*for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}*/
	int ans = 0;
	for (int i = a; i <= b+1; ++i)
	{
		ans = add(ans, dp[n][i]);
	}
	cout << ans;
	//sp;
}