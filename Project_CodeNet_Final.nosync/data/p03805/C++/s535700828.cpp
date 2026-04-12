#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <math.h>
#include <complex>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int INF = 2e9;



int main() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	rep(i, 0, n) a[i] = i;
	int edge[11][11] = {};
	rep(i, 0, m) {
		int x, y; cin >> x >> y;
		x--; y--;
		edge[x][y] = edge[y][x] = 1;
	}
	int ans = 0;
	do
	{
		bool flag = true;
		if (a[0]) break;
		rep(i, 1, n) if (edge[a[i - 1]][a[i]] == 0) flag = false;
		if (flag) ans++;
	} while (next_permutation(a.begin(),a.end()));
	printf("%d", ans);
	return 0;
}
