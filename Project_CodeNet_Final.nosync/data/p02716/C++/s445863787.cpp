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
#include <string.h>
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define int long long
#define INF 1145141919810364364
#define all(vec) vec.begin(),vec.end()
#define P pair<int,int>

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
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

int n, a[200010];
int cum[200010], cum2[200010], ma[200010], ma2[200010];
int ans = -INF;

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i % 2)cum[i] += a[i];
		else cum2[i] += a[i];
		cum[i] += cum[i - 1];
		cum2[i] += cum2[i - 1];
	}
	ma[2] = max(a[1], a[2]);
	for (int i = 4; i <= n; i += 2) {
		ma[i] = max({ ma[i - 2] + a[i], cum[i - 3] + a[i],cum[i - 1] });
	}
	ma2[n - 1] = max(a[n], a[n - 1]);
	for (int i = n - 3; i >= 1; i -= 2) {
		ma2[i] = max({ ma2[i + 2] + a[i], cum[n] - cum[i + 2] + a[i],cum[n] - cum[i] });
	}
	if (n % 2 == 0) {
		cout << ma[n] << endl;
		return 0;
	}
	for (int i = 1; i < n; i++) {
		if (i % 2) {
			ans = max(ans, ma[i - 1] + cum[n] - cum[i + 1]);
		}
		else {
			ans = max(ans, cum[i] + ma2[i + 2]);
		}
	}
	ans = max(ans, ma[n - 1]);
	cout << ans << endl;
}