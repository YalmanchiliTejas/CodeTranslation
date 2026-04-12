#pragma GCC optimize ("Ofast")
#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>
	
#define int long long
#define double long double 
#define PI 3.141592653589793
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
// Use for file I/O;
#define FIN string _fname = "homework"; \
			string _is = _fname + ".in", _os = _fname + ".out"; \
			freopen(_is.c_str(), "r", stdin); \
			freopen(_os.c_str(), "w", stdout);

using namespace std;
	
int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

const int INF = 4e18 + 10;
const int INF2 = 2e18 + 10;
const int INF3 = 2e10;
const int MAXN = 303;
const int LOGN = 19;
const int MOD = 1e9 + 7;
const int EPS = 1e-9;
const int MULT = 2e5;
const int MCNST = MOD * MOD * 8;

int dp[2][3000][3000];

int32_t main() {
	FAST;
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			dp[0][j][k] = -INF;
		}
	}
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			dp[1][j][k] = INF;
		}
	}

	for (int i = 0; i < n; i++) {
		dp[0][i][i] = a[i];
		dp[1][i][i] = -a[i];
	}

	for (int l = 2; l <= n; l++) {
		for (int i = 0; i <= n - l; i++) {
			dp[0][i][i + l - 1] = max(dp[1][i][i + l - 2] + a[i + l - 1], dp[1][i + 1][i + l - 1] + a[i]);
			dp[1][i][i + l - 1] = min(dp[0][i][i + l - 2] - a[i + l - 1], dp[0][i + 1][i + l - 1] - a[i]);

		}
	}

	cout << dp[0][0][n - 1];
}