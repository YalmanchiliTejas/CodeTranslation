#include "bits/stdc++.h"
using namespace std;
#define PIGRECO 3.141592653589793

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c> {i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
	~debug() { cerr << endl; }
	eni( != ) cerr << boolalpha << i; ris;
}
eni( == ) ris << range(begin(i), end(i));
}
sim, class b dor(pair < b, c > d) {
	ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
	*this << "[";
	for (auto it = d.b; it != d.e; ++it)
		*this << ", " + 2 * (it == d.b) << *it;
	ris << "]";
}
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////
#define int long long

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	cin >> n;

	vector<int>a(n + 1);

	for (int i = 1; i <= n; i++)cin >> a[i];

	vector<vector<int>>dp(n + 1, vector<int>(n + 1));

	for (int l = n; l > 0; l--) {

		for (int r = l; r <= n; r++) {

			if (l == r) {
				dp[l][r] = a[l];
			}
			else {

				dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);


			}

		}
	}

	cout << dp[1][n] << endl;



}