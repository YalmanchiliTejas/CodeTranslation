/*input
7 2 3 1 3
*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N 1005
// const int INF = 1e18;
const int mod = 1e9 + 7;

int n, a, b, c, d;
int dp[N][N];
int fac[N];
int infac[N];

#define pow binPow
long long binPow(long long a, long long q) {
	long long ret = 1;
	for (int i = 0; (1LL << i) <= q; i++) {
		if (q & (1LL << i)) ret = (ret * a) % mod;
		a = (a * a) % mod;
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> a >> b >> c >> d;
	fac[1] = 1; infac[1] = 1;
	for (int i = 2; i <= 1000; i++) fac[i] = (fac[i - 1] * i) % mod, infac[i] = binPow(fac[i], mod - 2);
	for (int i = a; i <= b; i++) dp[0][i] = 1;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = a; j <= b; j++) {
			if (j == a) {
				dp[i][j] = dp[i][0];
				for (int k = c; i - k * j >= 0 && k <= d; k++) {
					int t = ((dp[i - k * j][0] * binPow(binPow(fac[j], k), mod - 2)) % mod * infac[k]) % mod;
					dp[i][j] = (dp[i][j] + t) % mod;
				}
			}
			else {
				dp[i][j] = dp[i][j - 1];
				for (int k = c; i - k * j >= 0 && k <= d; k++) {
					int t = ((dp[i - k * j][j - 1] * binPow(binPow(fac[j], k), mod - 2)) % mod * infac[k]) % mod;
					dp[i][j] = (dp[i][j] + t) % mod;
				}
			}
		}
	}
	cout << dp[n][b]*fac[n] % mod << endl;
}