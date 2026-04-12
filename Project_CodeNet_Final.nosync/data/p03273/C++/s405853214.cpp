#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define f(i, l, r) for (int i = l; i <= r; i++)
#define rf(i, r, l) for (int i = r; i >= l; i--)
#define all(x) (x).begin(), (x).end()
#define sf(a) scanf("%d",&a)
#define llsf(a) scanf("%lld", &a)
#define l l
#define r r
#define lch (o << 1)
#define rch (o << 1 | 1)
#define mid ((l + r) >> 1)
#define mem(x, y) memset(x, y, sizeof(x))

const int inf = 2e9 + 7;
const ll INF = INT64_MAX;
double eps = 1e-6;
int mod = 1e9 + 7;
const int N = 1e6 + 10;
const double pi = acos(-1.0);

char s[101][101];
int main() {
#ifdef local
	freopen("in.txt", "r", stdin);
#endif
	int h, w; cin >> h >> w;
	f(i, 1, h)scanf("%s", s[i] + 1);
	f(i, 1, h) {
		bool ok = 1;
		f(j, 1, w)if (s[i][j] == '#')ok = 0;
		if (ok)f(j, 1, w)s[i][j] = 'X';
	}
	f(i, 1, w) {
		bool ok = 1;
		f(j, 1, h)if (s[j][i] == '#')ok = 0;
		if (ok)f(j, 1, h)s[j][i] = 'X';
	}
	f(i, 1, h) {
		bool e = 0;
		f(j, 1, w)if (s[i][j] != 'X')cout << s[i][j],e=1;if(e) cout << '\n';
	}
}