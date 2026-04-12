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
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define INF 1145141919810364364
#define all(vec) vec.begin(),vec.end()
#define ggr getchar(); getchar();return 0;
#define ll long long
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
	return kai(x - 1)*x;
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

int n, m, a[100], b[100];
vector<int> g[10];
vector<int> ta;
int ans;
int mu;
int cnt = 1;

signed main() {
	cin >> n >> m;
	rep(i, m) {
		cin >> a[i] >> b[i];
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}
	for (int i = 2; i <= n; i++) {
		ta.push_back(i);
	}
	int c, d;
	do {
		c = 1;
		d = ta[0];
		cnt = 1;
		rep(i, ta.size()) {
			mu = 0;
			rep(j, g[c].size()) {
				if (g[c][j] == d)mu++;
			}
			cnt *= mu;
			c = d;
			if (i != ta.size() - 1)d = ta[i + 1];
		}
		ans += cnt;
	} while (next_permutation(all(ta)));
	cout << ans << endl;
}