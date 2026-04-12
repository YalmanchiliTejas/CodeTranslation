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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int R, C;
string a[50];
int b[50][50][3];
int r[1000], c[1000];
vector<int> v[50][50];
bool vis[50][50];

bool dfs(int& t, int x, int y, int xt, int yt) {
	vis[y][x] = true;
	if (x == xt && y == yt)
		return true;
	for (int k = 0; k < 4; k++) {
		int _x = x + dx[k], _y = y + dy[k];
		if (_x < 0 || _x >= C || _y < 0 || _y >= R || a[_y][_x] == '#' || vis[_y][_x])
			continue;
		if (dfs(t, _x, _y, xt, yt)) {
			v[_y][_x].push_back(t++);
			return true;
		}
	}
	return false;
}

int main() {
	int M; cin >> R >> C >> M;
	for (int y = 0; y < R; y++)
		cin >> a[y];
	for (int k = 0; k < 3; k++)
		for (int y = 0; y < R; y++)
			for (int x = 0; x < C; x++)
				cin >> b[y][x][k];
	for (int i = 0; i < M; i++)
		cin >> r[i] >> c[i];
	int t = 0;
	for (int i = 0; i + 1 < M; i++) {
		fill(vis[0], vis[0] + 50 * 50, false);
		dfs(t, c[i + 1], r[i + 1], c[i], r[i]);
		v[r[i + 1]][c[i + 1]].push_back(t);
	}
	int sum = 0;
	for (int y = 0; y < R; y++)
		for (int x = 0; x < C; x++) {
			if (v[y][x].empty()) continue;
			sum += b[y][x][1] + b[y][x][2];
			for (int j = 0; j + 1 < v[y][x].size(); j++) {
				int dt = v[y][x][j + 1] - v[y][x][j];
				sum += min(b[y][x][0] * dt, b[y][x][1] + b[y][x][2]);
			}
		}
	cout << sum << endl;
}