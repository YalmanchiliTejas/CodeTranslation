#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <thread>
#include <atomic>
#include <mutex>
#include <future>
#define int long long
#define endre getchar();getchar();return 0
#define INF 1000000007
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
	return (kai(n - 1)*n) % INF;
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
int mystoi(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		cnt += (int)(s[i] - '0') * pow(10, s.size() - i - 1);
	}
	return cnt;
}
int h, w;
char c[105][105];
bool x[105], y[105];
signed main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> c[i][j];
			if (c[i][j] == '#')x[i] = true;
		}
	}
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (c[j][i] == '#')y[i] = true;
		}
	}
	for (int i = 0; i < h; i++) {
		if (!x[i])continue;
		for (int j = 0; j < w; j++) {
			if (!y[j])continue;
			cout << c[i][j];
		}
		cout << endl;
	}
	endre;
}