#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int a[10][10], b[10][10], c[10][10];
int dx[]{ 1,-1,0,0 }, dy[]{ 0,0,1,-1 };
int main() {
	int n; scanf("%d", &n);
	rep(i, n) {
		rep(i, 10)rep(j, 10)scanf("%d", &a[i][j]);
		rep(i, 1 << 10) {
			rep(j, 10)rep(k, 10)b[j][k] = a[j][k];
			memset(c, 0, sizeof(c));
			rep(j, 10)rep(k, 10) {
				if (!j) {
					if (i >> k & 1)continue;
				}
				else if (!b[j - 1][k])continue;
				c[j][k] = 1; b[j][k] = !b[j][k];
				rep(t, 4) {
					int nx = j + dx[t], ny = k + dy[t];
					if (0 <= nx&&nx < 10 && 0 <= ny&&ny < 10)b[nx][ny] = !b[nx][ny];
				}
			}
			bool ok = true;
			rep(j, 10)rep(k, 10) {
				if (b[j][k]) { ok = false; break; }
			}
			if (!ok)continue;
			rep(j, 10) {
				rep(k, 10) {
					if (k)printf(" ");
					printf("%d", c[j][k]);
				}
				printf("\n");
			}
		}
	}
}