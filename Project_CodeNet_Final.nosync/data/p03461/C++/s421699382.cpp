#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define E Maxke_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).sze()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int mod = 1e9 + 7;
const int INF = 1e9 + 7;
const int N = 110;
const int M = 2e6 + 10; 
int m,n,a[N][N],b[N][N]; 
bool vis[N][N];
int main()
{
	m = read();
	n = read();
	rep(i, 1, m)
		rep(j, 1, n)
			a[i][j] = read();
	rep(i, 1, m)
		rep(j, 1, n)
			rep(x, 0, 100)
				rep(y, 0, 100)
					b[x][y] = max(b[x][y], a[i][j] - i * x - j * y);
	rep(i, 1, m)
		rep(j, 1, n)
			rep(x, 0, 100)
				rep(y, 0, 100)
					if (b[x][y] == a[i][j] - i * x - j * y) vis[i][j] = 1;

	rep(i, 1, m)
		rep(j, 1, n)
			if(!vis[i][j]) 
			{
				puts("Impossible");
				return 0;
			}
	puts("Possible");
	printf("202 %d\n", 200 + 101 * 101);
	rep(i, 1, 100) printf("%d %d X\n", i, i + 1);
	rep(i, 102, 201) printf("%d %d Y\n",i + 1, i);
	rep(i, 0, 100)
		rep(j, 0, 100) 
			printf("%d %d %d\n", i + 1, j + 102, b[i][j]);
	puts("1 102");
	return 0;
}
