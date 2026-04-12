#include <bits/stdc++.h>
#define rep(i, n) for (rint i = 1; i <= (n); i ++)
#define re0(i, n) for (rint i = 0; i < (int) n; i ++)
#define travel(i, u) for (rint i = head[u]; i; i = e[i].nxt)
#define rint register int
using namespace std;

typedef long long lo;

template<typename tp> inline void read(tp &x) {
    x = 0; char c = getchar(); int f = 0;
    for (; c < '0' || c > '9'; f |= c == '-', c = getchar());
    for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
    if (f) x = -x;
}
#define int long long
const int N = 233;
int n, m;
int vis[N][N];
char str[N][N];

signed main(void) {
	read(n); read(m);
	rep (i, n) scanf("%s", str[i] + 1);
	int x = 1, y = 1;
	while (true) {
		if (!str[x][y] == '#') break;
		vis[x][y] = true;
		if (str[x + 1][y] == '#') {
			++x;
		} else if (str[x][y + 1] == '#') {
			++y;
		} else break;
	}
	if (!(x == n && y == m)) {
		cout << "Impossible\n";
		return 0;
	}
	rep (i, n) rep (j, m) if (str[i][j] == '#' && !vis[i][j]) {
		cout << "Impossible\n";
		return 0;
	}
	cout << "Possible\n";
}
