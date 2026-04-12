#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace __gnu_pbds;
using namespace std;

#define ld long double
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define vii vector<int>
#define f first
#define s second
#define endl "\n"
#define all(container) container.begin(), container.end()
#define onlyunique(v) v.erase(unique(all(v)), v.end());

#define TRACE
#ifdef AYUSH
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }

int const mod = 1e9 + 7;
int const inf = 1e18;

int power(int x, int y, int mod = 2e18) { int ans = 1; x %= mod; while (y) {if (y & 1)ans = (x * ans) % mod; x = (x * x) % mod; y >>= 1;} return ans;}
int modinv(int a, int m) {return power(a, m - 2, m);}


int dp[3001][3001][2];
vector<int> a(3001);
int n;
int ans(int l , int r, int chance) {
	trace(l, r, chance);
	if (l <= 0 || l > n || r <= 0 || r > n || l > r) {
		return (chance == 1 ? LLONG_MIN : LLONG_MAX);
	}
	if (l == r) {
		return (chance == 1 ? a[l] : -a[l]);
	}
	if (dp[l][r][chance] != -1)
		return dp[l][r][chance];
	if (chance) {
		return dp[l][r][chance] = max(ans(l + 1, r, 1 - chance) + a[l], ans(l, r - 1, 1 - chance) + a[r]);
	}
	else {
		return dp[l][r][chance] = min(ans(l + 1, r, 1 - chance) - a[l], ans(l, r - 1, 1 - chance) - a[r]);
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << ans(1, n, 1) << endl;
}
signed main() {
	IOS
	int t = 1, T = 1;
	// cin>>t;
	while (t--) {
		// cout<<"Case #"<<T<<": ";
		solve();
		// ++T;
	}
	return 0;
}