#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
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
#include <memory>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v, w; };

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int H, W; cin >> H >> W;
	vector<string> a(H);
	rep(y, H) cin >> a[y];
	int y = 0, x = 0;
	a[y][x] = '.';
	for (;;)
		if (y + 1 < H && a[y + 1][x] == '#') {
			y++;
			a[y][x] = '.';
		}
		else if (x + 1 < W && a[y][x + 1] == '#') {
			x++;
			a[y][x] = '.';
		}
		else break;
	bool ok = true;
	rep(y, H) rep(x, W)
		if (a[y][x] == '#')
			ok = false;
	cout << (ok ? "Possible" : "Impossible") << endl;
}
