#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

int dp[200][200][200];//sx,sy,ex
int x[]{ 1,1,0,0 }, y[]{ 0,1,0,1 };
int dx[]{ 1,0 }, dy[]{ 0,1 };
int a[200][200];
int main() {
	int h, w; scanf("%d%d", &h, &w);
	rep(i, h)rep(j, w)scanf("%d", &a[i][j]);
	dp[0][0][0] = a[0][0];
	rep(i, h)rep(j, w)rep(k, h) {
		if (i + j - k < 0 || i + j - k >= w)continue;
		if ((i || j) && i == k&&j == i + j - k)continue;
		rep(t, 4) {
			int sx = i + dx[x[t]], sy = j + dy[x[t]], ex = k + dx[y[t]], ey = i + j - k + dy[y[t]];
			if (0 <= sx&&sx < h && 0 <= sy&&sy < w && 0 <= ex&&ex < h && 0 <= ey&&ey < w)
				dp[sx][sy][ex] = max(dp[sx][sy][ex], dp[i][j][k] + a[sx][sy] + a[ex][ey]);
		}
	}
	printf("%d\n", dp[h - 1][w - 1][h - 1] - a[h - 1][w - 1]);
}