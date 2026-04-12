#include <bits/stdc++.h>
using namespace std;

const int INF = 9999999;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n;
int bx[50], by[50], ex[50], ey[50];
unsigned long long g[110][110];

void dfs(int x, int y, unsigned long long c)
{
	g[x][y] = 0;
	for (int dir = 0; dir < 4; dir++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= 110 || ny < 0 || ny >= 110) continue;
		if (g[nx][ny] == c) dfs(nx, ny, c);
	}
}

int main()
{
	while (cin >> n, n){
		vector<int> zx = {-INF, INF}, zy = {-INF, INF};
		for (int i = 0; i < n; i++){
			cin >> bx[i] >> by[i] >> ex[i] >> ey[i];
			swap(by[i], ey[i]);
			zx.push_back(bx[i]);
			zx.push_back(ex[i]);
			zy.push_back(by[i]);
			zy.push_back(ey[i]);
		}
		sort(begin(zx), end(zx));
		sort(begin(zy), end(zy));
		zx.erase(unique(begin(zx), end(zx)), end(zx));
		zy.erase(unique(begin(zy), end(zy)), end(zy));
		for (int i = 0; i < n; i++){
			bx[i] = lower_bound(begin(zx), end(zx), bx[i]) - begin(zx);
			ex[i] = lower_bound(begin(zx), end(zx), ex[i]) - begin(zx);
			by[i] = lower_bound(begin(zy), end(zy), by[i]) - begin(zy);
			ey[i] = lower_bound(begin(zy), end(zy), ey[i]) - begin(zy);
		}
		fill_n(*g, 110 * 110, 1ull << n);
		for (int i = 0; i < n; i++){
			for (int j = bx[i]; j < ex[i]; j++){
				for (int k = by[i]; k < ey[i]; k++){
					g[j][k] |= 1ull << i;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < zx.size(); i++){
			for (int j = 0; j < zy.size(); j++){
				if (g[i][j]){
					dfs(i, j, g[i][j]);
					res++;
				}
			}
		}
		cout << res << endl;
	}
}