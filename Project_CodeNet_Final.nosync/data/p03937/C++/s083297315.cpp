#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <iomanip>
#include <vector>
#include <queue>
#include <functional>
#include <random>
#include <time.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
ll inf = 1e9;
ll r, c, sy, sx, gy, gx, dis[55][55], nx, ny;
ll dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
char yan[55][55];
ll habatan() {
	queue<P> yojo;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) dis[i][j] = inf;
	}
	yojo.push(P(sx, sy));
	dis[sx][sy] = 1;
	while (!yojo.empty()) {
		P siri = yojo.front();
		yojo.pop();
		if (siri.first == gx && siri.second == gy)break;
		for (int i = 0; i < 4; i++) {
			nx = siri.first + dx[i], ny = siri.second + dy[i];
			if (nx&&ny&&yan[nx][ny] == '#'&&dis[nx][ny] == inf) {
				yojo.push(P(nx, ny));
				dis[nx][ny] = dis[siri.first][siri.second] + 1;
			}
		}
	}
	return dis[gx][gy];
}
int main() {

	cin >> r >> c;
	sx = sy = 1;
	gx = r; gy = c;
	ll cnt = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> yan[i][j];
			if (yan[i][j] == '#')cnt++;
		}
	}
	for (int i = 0; i <= r + 1; i++)yan[0][i] = yan[r + 1][i] = '.';
	for (int i = 0; i <= c + 1; i++)yan[i][0] = yan[i][c + 1] = '.';
	if (habatan() == cnt && cnt == r + c - 1)cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}