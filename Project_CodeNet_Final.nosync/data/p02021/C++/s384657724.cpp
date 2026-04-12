#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <stdio.h>
#include <vector>
#define int long long
#define endre getchar();getchar();return 0
using namespace std;
bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return (y, x%y);
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int kai(int n) {
	if (n == 0)return 1;
	return kai(n - 1)*n;
}
int mod_pow(int x, int y, int mod) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x%mod;
		}
		x = x * x%mod;
		y >>= 1;
	}
	return res;
}
int n, a, cnt, ans=100000;
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		cnt += a;
		ans = min(ans, cnt / i);
	}
	cout << ans << endl;
	endre;
}
