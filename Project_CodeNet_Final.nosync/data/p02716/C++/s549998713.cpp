#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define For(i,x,y) for(int i = x; i <= y; ++i)
#define FOR For
#define rev_For(i,x,y) for(int i = x; i >= y; --i)
#define REV_FOR rev_For
#define ll long long
#define Size(v) ((int)v.size())
#define _section "\n--------------------\n"
#define fi first
#define se second
#define pb push_back
using namespace std;
// using namespace __gnu_pbds;


const int nax = 2e5 + 5;
int n, a[nax];
vector<int> dp[nax];
const int INF = 1e18;

int calc(int i, int j) {
	if (i <= 0) return 0;
	if (i > n / 2) return 0;

	if (2 * (i - 1) - 1 > j - 2) {
		return -INF;
	}

	if (dp[i][j - (2 * (i - 1))] != -1) return dp[i][j - (2 * (i - 1))];

	int ret = -INF;
	for (int k = 2 * (i - 1) - 1; k <= j - 2; ++k) {
		ret = max(ret, calc(i - 1, k));
	}

	dp[i][j - (2 * (i - 1))] = ret + a[j];

	return dp[i][j - (2 * (i - 1))];
}

void input() {
	cin >> n;
	FOR (i, 1, n) cin >> a[i];
	FOR (i, 1, nax - 1) {
		dp[i].assign(4, -1);
	}
}

void solve() {
	int ans = -INF;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, calc(n / 2, i));
	}

	cout << ans;
}

signed main() {
#ifdef _DEBUG
	// freopen("INPUT.inp", "r", stdin);
	//freopen("OUTPUT.out", "w", stdout);
	clock_t start, end;
	start = clock();
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//------------------------------------------------------------------------------------
//----------------------------------MAIN PROGRAM--------------------------------------
	int t = 1;
	while (t--) {
		input();
		solve();
	}
//--------------------------------------END-------------------------------------------
//------------------------------------------------------------------------------------
#ifdef _DEBUG
	end = clock();
	cerr << "\n----------\nTime Elapsed: " << fixed << double(end - start) / double(CLOCKS_PER_SEC) << setprecision(6) << '\n';
#endif
	return 0;
}