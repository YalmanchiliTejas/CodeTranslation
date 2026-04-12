#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include <vector>
#define int long long
#define endre getchar();getchar();return 0
constexpr auto INF = 1000000007;
using namespace std;
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
int mypow(int x, int y) {
	if (y == 0)return 1;
	if (y % 2)return mypow(x, y - 1)*x;
	else return mypow(x, y / 2)*mypow(x, y / 2);
}
int Max(int x, int y) {
	if (x > y)return x;
	else return y;
}
int Min(int x, int y) {
	if (x < y)return x;
	else return y;
}
int kai(int x) {
	int cnt = 1;
	if (x == 0)return 1;
	cnt = kai(x - 1);
	return x * cnt;
}
int prime(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}
/*Library End!*/

signed main() {
	int n;
	cin >> n;
	if (n == 3 || n == 5 || n == 7)cout << "YES" << endl;
	else cout << "NO" << endl;
	endre;
}
