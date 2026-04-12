#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;

const int maxn = 105;
int f[maxn][maxn][maxn], d[maxn][maxn], ans[maxn][maxn][3];
int A, B, mxA, mxB, n;
set<pair<pair<int,int>,int> > s;

int main() {
	scanf("%d%d", &A, &B);
	rep (i, 1, A) rep (j, 1, B) scanf("%d", &d[i][j]);
	rep (a, 0, 100) rep (b, 0, 100) rep (c, 0, 100) if (a + b + c <= 100) {
		rep (i, 1, A) if (!f[a][b][c])
			rep (j, 1, B) if (a * i + b * j + c < d[i][j]) {
				//printf("%d %d %d\n", a, b, c);
				f[a][b][c] = 1; break;
			}
	}
	rep (i, 1, A) rep (j, 1, B) {
		int flag = 0;
		rep (a, 0, 100) if (!flag)
			rep (b, 0, 100) if (!flag && a * i + b * j <= d[i][j]) 
				rep (c, 0, 100) if (a * i + b * j + c == d[i][j] && !f[a][b][c]) {
					ans[i][j][0] = a; ans[i][j][1] = b; ans[i][j][2] = c;
					mxA = max(mxA, a); mxB = max(mxB, b); flag = 1; break;
				}				
		if (!flag) return puts("Impossible"), 0;
	}
	puts("Possible");
	n = mxA + mxB + 2;
	rep (i, 1, mxA) s.insert(make_pair(make_pair(i, i+1), -1));
	rep (i, n-mxB, n-1) s.insert(make_pair(make_pair(i, i+1), -2));
	rep (i, 1, A) rep (j, 1, B) {
		s.insert(make_pair(make_pair(ans[i][j][0]+1, n-ans[i][j][1]), ans[i][j][2]));
		//printf("# %d %d   %d %d %d\n", i, j, ans[i][j][0], ans[i][j][1], ans[i][j][2]);
	}
	printf("%d %d\n", n, (int)s.size());
	for (auto x : s)
		if (x.second == -1) printf("%d %d X\n", x.first.first, x.first.second);
		else if (x.second == -2) printf("%d %d Y\n", x.first.first, x.first.second);
		else printf("%d %d %d\n", x.first.first, x.first.second, x.second);
	printf("%d %d\n", 1, n);
	return 0;
}