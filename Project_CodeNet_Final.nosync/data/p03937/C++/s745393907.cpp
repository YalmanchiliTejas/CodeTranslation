#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 10;
int a[N][N], l[N], r[N];
int main() {
	int H, W; scanf("%d%d",&H,&W);
	rep(i,1,H) {
		rep(j,1,W) {
			char c = getchar();
			while (c != '#' && c != '.') c = getchar();
			if (c == '#') { if (!l[i]) l[i] = j; r[i] = j; a[i][j] = 1; } else a[i][j] = 0;
		}
		rep(j,l[i],r[i]) if (!a[i][j]) { printf("Impossible\n"); return 0; }
		if (i == 1) {
			if (l[i] > 1) { printf("Impossible\n"); return 0; }
		} else if (l[i] != r[i - 1]) { printf("Impossible\n"); return 0; }
		if (i == H && r[i] != W) { printf("Impossible\n"); return 0; }
	}
	printf("Possible\n");
	return 0;
}