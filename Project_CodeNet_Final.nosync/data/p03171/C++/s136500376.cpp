#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sim template < class c
#define ris return *this
#define dor > debug & operator <<
#define eni(x) sim > typename \
	enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
	ris << "(" << d.first << ", ", d.second << ")";
}
sim dor(rge<c> d) {
	*this << "[";
	for (auto it = d.b; it != d.e; it++)
		*this << ", " + 2 * (it == d.b) << *it;
	ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int N = 3010;
int n;
ll a[N], dp[N][N][2];
bool vis[N][N][2];

ll solve(int l, int r, int p) {
	if (l > r) {
		return 0;
	}
	if (vis[l][r][p]) {
		return dp[l][r][p];
	}
	vis[l][r][p] = true;
	if (p == 0) {
		dp[l][r][p] = max(a[l] + solve(l + 1, r, 1), a[r] + solve(l, r - 1, 1));
	} else {
		dp[l][r][p] = min(-a[l] + solve(l + 1, r, 0), -a[r] + solve(l, r - 1, 0));
	}
	return dp[l][r][p];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	ll ans = solve(0, n - 1, 0);
	cout << ans;
	
	return 0;
}
