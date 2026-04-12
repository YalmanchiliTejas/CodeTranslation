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

const int N = 3009;
int dp[N][N];

int32_t main() {
	FAST_IO;
	
	int n;
	cin >> n;
	
	int a[n];
	for (int& x: a) cin >> x;
	
	for (int l = n-1; l >= 0; l--) {
		for (int r = l; r < n; r++) {
			if (l == r) {
				dp[l][r] = a[l];
			} else {
				dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
			}
		}
	}
	
	cout << dp[0][n-1] << endl;
}

// g++ -Wall -Wextra -Wshadow -fsanitize=undefined
