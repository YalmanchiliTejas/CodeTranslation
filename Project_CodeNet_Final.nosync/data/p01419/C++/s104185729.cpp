#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

const int dx[]={1,0,0,-1};
const int dy[]={0,1,-1,0};

const int N = 55;
queue<int> q;
vector<int> path;
char mp[N][N];
int vis[N][N], pre[N][N], t[N*N];
int val[N][N], op[N][N], cl[N][N];
int n, m, K, X[N*N], Y[N*N];
void BFS(int sx, int sy, int ex, int ey) {
	while(!q.empty()) q.pop();
	memset(vis, -1, sizeof vis);
	memset(pre, -1, sizeof pre);

	vis[sx][sy] = 0;
	q.push(sx*N+sy);
	while(!q.empty()) {
		int tmp = q.front(); q.pop();
		int x = tmp / N, y = tmp % N;
		if(x == ex && y == ey) break;//continue;
		
		for(int di = 0; di < 4; di ++) {
			int nx = x + dx[di], ny = y + dy[di];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(vis[nx][ny] != -1 || mp[nx][ny] == '#') continue;
			
			vis[nx][ny] = vis[x][y] + 1;
			pre[nx][ny] = x*N+y;
			q.push(nx*N+ny);
		}
	}
	
	int size = 0, x = ex, y = ey;
	while(pre[x][y] != -1) {
		int tmp = pre[x][y];
		t[size++] = tmp;
		x = tmp / N;
		y = tmp % N;
	}
	for(int i = size-1; i >= 0; i --) path.push_back(t[i]);

}
void input() {
	for(int i = 0; i < n; i ++)
		scanf("%s", mp[i]);

	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			scanf("%d", &val[i][j]);
		}
	}
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			scanf("%d", &op[i][j]);
		}
	}
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			scanf("%d", &cl[i][j]);
		}
	}
	for(int i = 0; i < K; i ++) {
		scanf("%d%d", &X[i], &Y[i]);
	}
}
int main() {
	while(~scanf("%d%d%d", &n, &m, &K)) {
		input();
		//
		path.clear();
		for(int i = 1; i < K; i ++) {
			BFS(X[i-1], Y[i-1], X[i], Y[i]);
		}
		path.push_back(X[K-1]*N+Y[K-1]);
		
		memset(pre, -1, sizeof pre);
		int ans = 0;
		for(int i = 0; i < (int)path.size(); i ++) {
			int x = path[i]/N, y = path[i]%N;
			if(pre[x][y] == -1) {
				ans += op[x][y] + cl[x][y];
			} else {
				int tmp = (i - pre[x][y]) * val[x][y];
				tmp = min(tmp, op[x][y] + cl[x][y]);
				ans += tmp;
			}
			pre[x][y] = i;
		}
		
		printf("%d\n", ans);
	}
	return 0;
}