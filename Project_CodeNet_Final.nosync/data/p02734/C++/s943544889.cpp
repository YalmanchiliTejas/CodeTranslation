#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
// #pragma comment(linker, "/stack:200000000"]
 
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <random>
#include <fstream>
#include <sstream>
 
#define fr first
#define se second
#define pb push_back
#define ll long long
#define ld long double
#define hm unordered_map 
#define pii pair<int, int>
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define cinv(v) for (auto& x: v) cin >> x
#define forn(i, n) for (int i = 0; i < n; ++i)
#define forln(i, l, n) for (int i = l; i < n; ++i)

#define int ll

using namespace std;

#ifdef __LOCAL
	#define dbg(x) cerr << #x << " : " << x << '\n'
	const int maxn = 20;
#else 
	#define dbg(x)
	const int maxn = 2e5 + 20;
#endif

//tg: @galebickosikasa
 
const ll inf = (ll) 2e9;
const ld pi = 3.14159265358979323846264;
const ld eps = 1e-8;
const ll mod = 998244353;
const ll ns = 97;
const int maxc = 3000 + 20;

random_device rd;
mt19937 SuperRandom(rd());

int dp[maxc][maxc];

signed main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, s;
	cin >> n >> s;
	vector<int> goo (n);
	cinv (goo);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int x = goo[i - 1];
		dp[i][x] = i;
		for (int j = 0; j <= s; ++j) {
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
			if (j - x >= 0) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % mod;
			}
		}
		ans = (ans + dp[i][s]) % mod;
	}
	cout << ans;









}