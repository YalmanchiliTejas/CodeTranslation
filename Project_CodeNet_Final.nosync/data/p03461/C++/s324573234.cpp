#include <iostream>
#include <cstdio>
#include <cstring>

char buf[1<<21], *p1, *p2;
#define getc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin)), p1 == p2 ? EOF : *p1++)
#define lint long long
#define isnum(x) ('0' <= (x) && (x) <= '9')
template<typename tint>
inline void readint(tint& x) {
	int f = 1; char ch = getc(); x = 0;
	for(; !isnum(ch); ch = getc()) if(ch == '-') f = -1;
	for(; isnum(ch); ch = getc()) x = x * 10 + ch - '0';
	x *= f;
}
using namespace std;
const int maxa = 12;
const int maxn = 204;

// dist[x][y] = min{i * x + j * y + f[i][j]}
// dist[x][y] - i * x - j * y <= f[i][j]
// f[i][j] = max{dist[x][y] - i * x - j * y}

// f[i][j] = max{dist[x][y] - i * x - j * y}

int n = 202, m = 100;
int A, B;
int dist[maxa][maxa], f[maxn][maxn];
int edge[maxn][maxn];
int now[maxn];
bool vis[maxn];

int main() {
	memset(f, -1, sizeof(f)), memset(edge, -1, sizeof(edge));
	readint(A), readint(B);
	for(int i=1; i<=A; i++) {
		for(int j=1; j<=B; j++) readint(dist[i][j]);
	}

	int cnt = 0;
	for(int i=0; i<=m; i++) {
		for(int j=0; j<=m; j++) {
			for(int x=1; x<=A; x++) {
				for(int y=1; y<=B; y++) {
					f[i][j] = max(f[i][j], dist[x][y] - i * x - j * y);
				}
			}
			// i个x, j个y的最短路
			edge[i + 1][202 - j] = f[i][j];
			if(edge[i + 1][202 - j] != -1) cnt++;
		}
	}


	for(int a=1; a<=A; a++) {
		for(int b=1; b<=B; b++) {
			for(int i=1; i<=100; i++) edge[i][i+1] = a;
			for(int i=102; i<=201; i++) edge[i][i+1] = b;
			memset(vis, 0, sizeof(vis)), memset(now, 0x3f, sizeof(now));
			now[1] = 0;
			while(true) {
				int x = 0;
				for(int i=1; i<=n; i++) if(!vis[i] && now[i] < now[x]) x = i;
				if(x == 0) break;
				vis[x] = 1;
				for(int y=1; y<=n; y++)
					if(edge[x][y] != -1 && now[y] > now[x] + edge[x][y]) now[y] = now[x] + edge[x][y];
			}
			if(now[n] != dist[a][b]) { puts("Impossible"); return 0; }
		}
	}

	puts("Possible");
	printf("%d %d\n", n, cnt + 200);
	for(int i=1; i<=100; i++) printf("%d %d X\n", i, i+1);
	for(int i=102; i<=201; i++) printf("%d %d Y\n", i, i+1);
	for(int i=0; i<=m; i++) {
		for(int j=0; j<=m; j++) {
			if(f[i][j] == -1) continue;
			printf("%d %d %d\n", i + 1, 202 - j, f[i][j]);
		}
	}
	printf("%d %d\n", 1, 202);
	// [1, 101] [102, 202]
	//
	
	
	
	
	return 0;
}

// Y
// X + 1
// X + X
// 3

// x = 2, y = 3
