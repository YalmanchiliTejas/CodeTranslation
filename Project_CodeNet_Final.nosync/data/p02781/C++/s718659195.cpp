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
#define mod 1000000007
#define INF 1145141919364364
#define int long long
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

string s;
int k;
int dp[110][2][4];

signed main() {
	cin >> s >> k;
	dp[0][0][0] = 1;
	for (int i = 1; i <= (int)s.size(); i++) {
		int x = s[i - 1] - '0';
		if (!x) {
			dp[i][0][0] = dp[i - 1][0][0];
			dp[i][0][1] = dp[i - 1][0][1];
			dp[i][0][2] = dp[i - 1][0][2];
			dp[i][0][3] = dp[i - 1][0][3];
		}
		else {
			dp[i][0][0] = 0;
			dp[i][0][1] = dp[i - 1][0][0];
			dp[i][0][2] = dp[i - 1][0][1];
			dp[i][0][3] = dp[i - 1][0][2];
			dp[i][1][0] += dp[i - 1][0][0];
			dp[i][1][1] += dp[i - 1][0][1] + dp[i - 1][0][0] * (x - 1);
			dp[i][1][2] += dp[i - 1][0][2] + dp[i - 1][0][1] * (x - 1);
			dp[i][1][3] += dp[i - 1][0][3] + dp[i - 1][0][2] * (x - 1);
		}
		dp[i][1][0] += dp[i - 1][1][0];
		dp[i][1][1] += dp[i - 1][1][1] + dp[i - 1][1][0] * 9;
		dp[i][1][2] += dp[i - 1][1][2] + dp[i - 1][1][1] * 9;
		dp[i][1][3] += dp[i - 1][1][3] + dp[i - 1][1][2] * 9;
	}
	cout << dp[(int)s.size()][0][k] + dp[(int)s.size()][1][k] << endl;
}