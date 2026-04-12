#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 2;

int compress(int n, vector<int>& a, vector<int>& b) {
	vector<int> c;
	for (int i = 0; i < n; i++) {
		c.push_back(a[i]);
		c.push_back(b[i]);
	}
	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
		b[i] = lower_bound(c.begin(), c.end(), b[i]) - c.begin();
	}
	return c.size();
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void dfs(int x, int y, vector< vector<bool> >& a) {
	int h = a.size(), w = a[0].size();
	a[y][x] = true;
	for (int k = 0; k < 4; k++) {
		int _x = x + dx[k], _y = y + dy[k];
		if (_x >= 0 && _x < w && _y >= 0 && _y < h && !a[_y][_x])
			dfs(_x, _y, a);
	}
}

int main() {
	for (;;) {
		int n; cin >> n;
		if (n == 0) break;
		vector<int> l(n), t(n), r(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> l[i] >> t[i] >> r[i] >> b[i];
		int w = compress(n, l, r), h = compress(n, t, b);
		vector< vector<bool> > a(h * 2 + 1, vector<bool>(w * 2 + 1));
		for (int i = 0; i < n; i++) {
			l[i] = l[i] * 2 + 1; t[i] = t[i] * 2 + 1;
			r[i] = r[i] * 2 + 1; b[i] = b[i] * 2 + 1;
			for (int y = b[i]; y <= t[i]; y++)
				a[y][l[i]] = a[y][r[i]] = true;
			for (int x = l[i]; x <= r[i]; x++)
				a[t[i]][x] = a[b[i]][x] = true;
		}
		/*for (int y = 0; y < h * 2 + 1; y++) {
			for (int x = 0; x < w * 2 + 1; x++)
				cout << (a[y][x] ? '#' : '.');
			cout << endl;
		}*/
		int cnt = 0;
		for (int y = 0; y < h * 2 + 1; y++)
			for (int x = 0; x < w * 2 + 1; x++)
				if (!a[y][x]) {
					cnt++;
					dfs(x, y, a);
				}
		cout << cnt << endl;
	}
}