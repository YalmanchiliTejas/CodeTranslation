#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define EXIT(...) printf(__VA_ARGS__), exit(0)

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 10;

int n, m;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	int lstl = 0, lstr = 0;
	REP(i, 0, n)
	{
		static char a[maxn + 5];
		scanf("%s", a);
		int l = m, r = 0;
		REP(j, 0, m) if (a[j] == '#') chkmin(l, j), chkmax(r, j);
		if (l > r) EXIT("Impossible");
		if (l != lstr) EXIT("Impossible");
		REP(j, l, r) if (a[j] != '#') EXIT("Impossible");
		if (!i && l) EXIT("Impossible");
		lstl = l, lstr = r;
	}
	if (lstr != m - 1) EXIT("Impossible");
	puts("Possible");
	return 0;
}
