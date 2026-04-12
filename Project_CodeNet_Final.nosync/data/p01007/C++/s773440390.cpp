#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef pair<int, int>P;

int dx[]{ 1,-1,0,0 }, dy[]{ 0,0,1,-1 };
int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<vector<int>>p(n, vector<int>(n));
	rep(i, n)rep(j, n)scanf("%d", &p[i][j]);
	rep(i, m) {
		int a; scanf("%d", &a);
		if (a == 0) {
			int r, c, s, t; scanf("%d%d%d%d", &r, &c, &s, &t); r--; c--;
			rep(i, t / 90) {
				vector<vector<int>>u = p;
				rep(i, s)rep(j, s)u[i + r][j + c] = p[s - j - 1 + r][i + c];
				p = u;
			}
		}
		if (a == 1) {
			int r, c, s; scanf("%d%d%d", &r, &c, &s); r--; c--;
			rep(i, s)rep(j, s)p[r + i][c + j] = !p[r + i][c + j];
		}
		if (a == 2) {
			int r; scanf("%d", &r); r--;
			rotate(p[r].begin(), p[r].begin() + 1, p[r].end());
		}
		if (a == 3) {
			int r; scanf("%d", &r); r--;
			rotate(p[r].rbegin(), p[r].rbegin() + 1, p[r].rend());
		}
		if (a == 4) {
			int r, c; scanf("%d%d", &r, &c); r--; c--;
			queue<P>que; que.push(P(r, c));
			int b = p[r][c]; p[r][c] = !p[r][c];
			while (!que.empty()) {
				P a = que.front(); que.pop();
				rep(i, 4) {
					int nx = a.first + dx[i], ny = a.second + dy[i];
					if (0 <= nx&&nx < n && 0 <= ny&&ny < n&&p[nx][ny] == b) {
						p[nx][ny] = !p[nx][ny]; que.push(P(nx, ny));
					}
				}
			}
		}
	}
	rep(i, n) {
		rep(j, n) {
			if (j)printf(" ");
			printf("%d", p[i][j]);
		}
		printf("\n");
	}
}