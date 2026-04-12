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
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define INF 1145141919364364
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

int kai(int x) {
	if (x == 1)return 1;
	return kai(x - 1)*x%mod;
}

int mod_pow(int x, int y, int moder) {
	int res = 1;
	while (y > 0) {
		if (y & 1)res = res * x%moder;
		x = x * x%moder;
		y >>= 1;
	}
	return res;
}

int comb(int x, int y) {
	if (y > x)return 0;
	if (x == y)return 1;
	return kai(x)* mod_pow(kai(x - y), mod - 2, mod) % mod * mod_pow(kai(y), mod - 2, mod) % mod;
}

int n, a[100010];
vector<int> ta;
bool bl;

int ni(int n, int s) {
	int l = 0;
	int r = n - 1;
	int c = n - 1;
	bl = true;
	while (1) {
		int d = c;
		c = (l + r) / 2;
		if (ta[c] >= s) {
			if (d - c == 1 && bl)return d;
			l = c;
			bl = false;
		}
		else {
			r = c;
			bl = true;
		}
		if (c == d && !bl)return c + 1;
		else if (c == d)return c;
	}
}

signed main() {
	cin >> n;
	rep(i, n)cin >> a[i];
	ta.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		if (ta[ta.size() - 1] >= a[i])ta.push_back(a[i]);
		else ta[ni(ta.size(), a[i])] = a[i];
	}
	cout << ta.size() << endl;
}