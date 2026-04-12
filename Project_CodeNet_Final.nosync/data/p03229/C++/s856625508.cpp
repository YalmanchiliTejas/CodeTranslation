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
int inf = 1000000000;
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
void prime_factor(int n) {
	int cnt = 1;
	map<int, int>res;
	int m = n;
	for (int i = 2; i <= n; i++) {
		if (prime(i)) {
			while (m%i == 0) {
				++res[i];
				m /= i;
			}
		}
	}
	cout << n << ":" << endl;
	for (int i = 2; i <= n; i++) {
		if (res[i]) {
			cout << i << " " << res[i] << endl;
		}
	}
	cout << endl;
}
/*Library End!*/

int n, a[100005], memo, maememo, cnt,maecnt;
signed main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	if (n % 2) {
		maememo = a[n / 2];
		maecnt = maememo;
		for (int j = 1; j < n; j++) {
			if (j % 2) {
				cnt += abs(maecnt - a[n - 1 - j / 2]);
				maecnt = a[n - 1 - j / 2];
				memo += abs(maememo - a[j / 2]);
				maememo = a[j / 2];
			}
			else {
				cnt += abs(maecnt - a[j / 2 - 1]);
				maecnt = a[j / 2 - 1];
				memo += abs(maememo - a[n - j / 2]);
				maememo = a[n - j / 2];
			}
		}
		cnt = max(memo, cnt);
	}
	else {
		maecnt = a[n / 2 - 1];
		maememo = a[n / 2];
		for (int j = 1; j < n; j++) {
			if (j % 2) {
				cnt += abs(maecnt - a[n - 1 - j / 2]);
				maecnt = a[n - 1 - j / 2];
				memo += abs(maememo - a[j / 2]);
				maememo = a[j / 2];
			}
			else {
				cnt += abs(maecnt - a[-1 + j / 2]);
				maecnt = a[-1 + j / 2];
				memo += abs(maememo - a[n - j / 2]);
				maememo = a[n - j / 2];
			}
		}
		cnt = max(cnt, memo);
	}
	cout << cnt << endl;
	endre;
}
