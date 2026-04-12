#pragma GCC optimize ("Ofast")
#include "bits/stdc++.h"
	
#define PI 3.141592653589793
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
// Use for file I/O;
#define FIN string _fname = "paintbarn"; \
			string _is = _fname + ".in", _os = _fname + ".out"; \
			freopen(_is.c_str(), "r", stdin); \
			freopen(_os.c_str(), "w", stdout);

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

using namespace std;

const ll INF = 1e9 + 10;
const ll INF2 = 3e18 + 10;
const int MOD = 1e9 + 7;
const ld EPS = 1e-4;

const int LOGN = 19;
const int MAXN = 305;

int dp[10000][100][2];

inline void add_self(int &a, int b) {
	a = (a + b) % MOD;
}

int main() {
	FAST;

	vector<int> a;
	int n, d;
	{
		string s;
		cin >> s >> d;
		n = s.size();
		a.resize(n);
		for (int i = 0; i < n; i++) {
			a[i] = (int) (s[i] - '0');
		}
	}
	for (int i = 0; i < a[0]; i++) {
		dp[0][i % d][0] += 1;
	}
	dp[0][a[0] % d][1] += 1;

	for (int i = 1; i < n; i++) {
		for (int k = 0; k < d; k++) {
			//cout << i << ' ' << k << endl;
			for (int j = 0; j < 10; j++) {
				add_self(dp[i][k][0], dp[i - 1][(k + 10*d - j) % d][0]);
			}
			for (int j = 0; j < a[i]; j++) {
				add_self(dp[i][k][0], dp[i - 1][(k + 10*d - j) % d][1]);
			}
			add_self(dp[i][k][1], dp[i - 1][(k + 10*d - a[i]) % d][1]);
		}
	}

	int ans = MOD - 1;
	for (int j = 0; j < 2; j++) {
		add_self(ans, dp[n - 1][0][j]);
	}
	cout << ans;
}