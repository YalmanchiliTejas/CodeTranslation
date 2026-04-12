#include <bits/stdc++.h>

using namespace std;
 
#define PB	push_back
#define ALL(x)	(x).begin(), (x).end()
#define ALLR(x)	(x).rbegin(), (x).rend()
#define MP	make_pair
 
#define debug(_x)		cerr << #_x << '=' << (_x) << endl;
#define debug2(_x, _y)	cerr << #_x << '=' << (_x) << ' ' << #_y << '=' << (_y) << endl;
#define debugn(_a)		cerr << #_a << ": "; for (const auto _x: _a) cerr << (_x) << ' '; cerr << endl;

#define HERE debug(__LINE__);

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0)

#define int long long int

typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int> vi;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef unsigned long long ull;

const int INF = LONG_LONG_MAX>>1;
const int NINF = LONG_LONG_MIN/2;

vi a;

const int N = 3009;
ii dp[N][N][2];

pair<int, int> solve(int l, int r, bool turn) {
	if (dp[l][r][turn] != ii{INF, INF}) return dp[l][r][turn];
	
	if (l > r) return dp[l][r][turn] = ii{0, 0};
	
	if (turn) {
		ii p = solve(l+1, r, !turn);
		ii q = solve(l, r-1, !turn);
		p.first += a[l];
		q.first += a[r];
		if (p.first - p.second > q.first - q.second) {
			return dp[l][r][turn] = p;
		} else return dp[l][r][turn] = q;
	} else {
		ii p = solve(l+1, r, !turn);
		ii q = solve(l, r-1, !turn);
		p.second += a[l];
		q.second += a[r];
		if (p.first - p.second < q.first - q.second) {
			return dp[l][r][turn] = p;
		} else return dp[l][r][turn] = q;
	}
}

int32_t main() {
	FAST_IO;
	
	int n;
	cin >> n;
	
	a.resize(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < 2; k++) dp[i][j][k] = {INF, INF};
	ii ans = solve(1, n, true);
	
	cout << ans.first - ans.second << endl;
}

// g++ -Wall -Wextra -Wshadow -fsanitize=undefined
