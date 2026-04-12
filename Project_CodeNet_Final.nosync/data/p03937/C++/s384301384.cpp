#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& x) {
	return os << "(" << x.first << "," << x.second << ")";
}
typedef long long ll;
typedef long double ld;
char G[15][15];
int main() {
	int H, W;
	scanf("%d%d", &H, &W);
	for (int i = 0; i < H; ++i) scanf("%s", G[i]);
	int r = 0, c = 0;
	for (;;) {
		assert(G[r][c] == '#');
		G[r][c] = '.';
		if (c != W - 1 && G[r][c + 1] == '#') {
			++c;
		} else if (r != H - 1 && G[r + 1][c] == '#') {
			++r;
		} else break;
	}
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			if (G[i][j] == '#') {
				printf("Impossible\n");
				return 0;
			}
	printf("Possible\n");
}
