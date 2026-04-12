#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 998244353
#define int long long
#define INF 1145141919810364364
#define all(vec) vec.begin(),vec.end()
#define P pair<int,int>
#define S second
#define F first

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)return false;
	}
	return true;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}

int n, s;
int dp[3010][3010];
int ans;

signed main() {
	cin >> n >> s;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		for (int j = 0; j <= s; j++) {
			dp[i][j] += dp[i - 1][j];
			if (j - a >= 0) {
				if (j - a == 0)dp[i][j] += dp[i - 1][j - a] * i;
				else dp[i][j] += dp[i - 1][j - a];
			}
			dp[i][j] %= mod;
		}
	}
	for (int i = 1; i <= n; i++) {
		ans += (dp[i][s] - dp[i - 1][s] + mod) * (n - i + 1);
		ans %= mod;
	}
	cout << ans << endl;
}