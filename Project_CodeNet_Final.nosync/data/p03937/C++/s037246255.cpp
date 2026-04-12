#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

char s[10][10];
bool used[10][10];
int dx[]{ 1,0}, dy[]{ 0,1 };
int h, w;

int main() {
	scanf("%d%d", &h, &w);
	rep(i, h)scanf("%s", s[i]);
	int px = 0, py = 0;
	used[0][0] = true;
	while (px != h - 1 || py != w - 1) {
		bool flag = false;
		int xx = -1, yy = -1;
		rep(i, 2) {
			int nx = px + dx[i], ny = py + dy[i];
			if (0 <= nx&&nx < h && 0 <= ny&&ny < w&&s[nx][ny] == '#') {
				if (flag) {
					puts("Impossible"); return 0;
				}
				used[nx][ny] = true;
				flag = true;
				xx = nx, yy = ny;
			}
		}
		if (!~xx || !~yy) {
			puts("Impossible"); return 0;
		}
		px = xx, py = yy;
	}
	rep(i, h)rep(j, w) {
		if (s[i][j] == '#' && !used[i][j]) {
			puts("Impossible");
			return 0;
		}
	}
	puts("Possible");
}