#include <bits/stdc++.h>

#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using ld = long double;
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
// const int mod = 998244353;
const ll inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-7;

const int N = 2e5 + 66;

ll a[N];

map <int, ll> dp[N];

map <int, bool> was[N];

int n;

ll go (int pos, int last) {
	if (last == 0) return 0ll;
	if ((n - pos + 2) / 2 < last || pos > n) return -INF;
	if (was[pos][last]) return dp[pos][last];
	was[pos][last] = true;
	ll mx = -INF;
	for (int i = pos + 1; i <= pos + 5 ; ++ i) {
		mx = max (mx, go (i, last));
		if (i > pos + 1)
			mx = max (mx, go (i, last - 1) + a[pos]);
	}
	return dp[pos][last] = mx;
}

void solve () {
	cin >> n;
	for (int i = 1 ; i <= n ; ++ i) {
		cin >> a[i];
	}
	cout << go (1, n / 2);
}

int main () {
	ios;
	// double start_time = clock();
	// cout << fixed << setprecision (10);
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
		cout << "\n";
	}
	// cerr << (clock() - start_time) / CLOCKS_PER_SEC;
}