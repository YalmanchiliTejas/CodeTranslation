#include <bits/stdc++.h>

using namespace std;
 
#define PB(x)	push_back(x)
#define ALL(x)	(x).begin(), (x).end()
#define ALLR(x)	(x).rbegin(), (x).rend()
#define MP(x)	make_pair(x)
 
#define debug(_x)		cerr << #_x << '=' << _x << endl;
#define debug2(_x, _y)	cerr << #_x << '=' << _x << ' ' << #_y << '=' << _y << endl;
#define debugn(_a)		cerr << #_a << ": "; for (const auto _x: _a) cerr << _x << ' '; cerr << endl;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0)

#define int long long int

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef unsigned long long ull;

const int INF = LONG_LONG_MAX>>1;
const int NINF = LONG_LONG_MIN/2;

const int N = 200005;

vi a;
int dp[N][2];
int vis[N][2];

int solve(int n, int cnt) {
	if (!(cnt == n/2 || cnt == (n+1)/2)) return NINF;
	
	if (n <= 0) return 0;
	
	if (cnt == n/2 && vis[n][0]) return dp[n][0];
	else if (cnt == (n+1)/2 && vis[n][1]) return dp[n][1];
	
	int ans1 = solve(n-1, cnt);
	int ans2 = solve(n-2, cnt-1) + a[n-1];
	
	if (cnt == n/2) {
		vis[n][0] = true;
		return dp[n][0] = max(ans1, ans2);
	} else {
		vis[n][1] = true;
		return dp[n][1] = max(ans1, ans2);
	}
}

int32_t main() {
	FAST_IO;

	int n;
	cin >> n;
	
	a.resize(n);
	for (int& x: a) cin >> x;
	
	cout << solve(n, n/2) << endl;
	
}

// g++ -Wall -Wextra -Wshadow -fsanitize=undefined
