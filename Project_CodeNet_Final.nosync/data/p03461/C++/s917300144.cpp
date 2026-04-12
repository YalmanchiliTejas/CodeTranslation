#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cctype>
using namespace std;
typedef long long ll;

int a, b;
int d[15][15];
struct edge {
	int x, y, z;
	edge() { x = y = z = 0; }
	edge(int a, int b, int c) { x = a, y = b, z = c; }
}ans[15][15];
int vis[300][300];

int main() {
	scanf("%d%d", &a, &b);
	for(int i = 1; i <= a; i ++)
		for(int j = 1; j <= b; j ++) scanf("%d", &d[i][j]);
	for(int i = 0; i <= 100; i ++)
		for(int j = 0; j <= 100; j ++)
			for(int k = 0; k <= 100; k ++) {
				bool flag = 0;
				for(int t1 = 1; t1 <= a; t1 ++)
					for(int t2 = 1; t2 <= b; t2 ++)
						if(i*t1+j*t2+k < d[t1][t2]) flag = 1;
				if(flag) continue;
				for(int t1 = 1; t1 <= a; t1 ++)
					for(int t2 = 1; t2 <= b; t2 ++)
						if(i*t1+j*t2+k == d[t1][t2]) ans[t1][t2] = edge(i+1, j+1, k);
				break;
			}
	bool chk = 0;
	for(int i = 1; i <= a; i ++)
		for(int j = 1; j <= b; j ++) if(ans[i][j].x == 0) { puts("Impossible"); return 0; }
	puts("Possible"); int n = 200;
	for(int i = 1; i <= a; i ++)
		for(int j = 1; j <= b; j ++) if(!vis[ans[i][j].x][ans[i][j].y]) n ++, vis[ans[i][j].x][ans[i][j].y] = 1;
	printf("202 %d\n", n); memset(vis, 0, sizeof vis);
	for(int i = 1; i < 101; i ++) printf("%d %d X\n", i, i+1);
	for(int i = 102; i < 202; i ++) printf("%d %d Y\n", i, i+1);
	for(int i = 1; i <= a; i ++)
		for(int j = 1; j <= b; j ++) if(ans[i][j].x) {
			if(!vis[ans[i][j].x][ans[i][j].y]) printf("%d %d %d\n", ans[i][j].x, 202-ans[i][j].y+1, ans[i][j].z);
			vis[ans[i][j].x][ans[i][j].y] = 1;
		}
	puts("1 202");
	return 0;
}