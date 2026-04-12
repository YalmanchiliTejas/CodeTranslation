#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define fi first
#define se second
#define REP(i, a, n) for (register int i = a, _n = n; i <= _n; ++i)
#define DREP(i, a, n) for (register int i = a, _n = n; i >= _n; --i)
#define FOR(i, a, n) for (register int i = a, _n = n; i < _n; ++i)
#define EREP(i, a) for (register int i = first[a]; i; i = edge[i].nxt)
#define debug(x) cout << #x << " = " << x << endl

char IO;
inline int rd () {
	int res = 0;
	while ((IO = getchar()) && (IO < '0' || IO > '9'));
	while (IO >= '0' && IO <= '9') 
		res = (res << 1) + (res << 3) + (IO ^ 48), IO = getchar();
	return res;
}

const int SIZE = 100005;

int n, a[SIZE];
int b[SIZE], m;
int main () {
	n = rd();
	REP (i, 1, n) a[i] = rd();

	REP (i, 1, n) { // 不上升 len
		int l = 1, r = m, res = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (b[mid] >= a[i]) res = mid, l = mid + 1;
			else r = mid - 1;
		}
		if (res == m) ++m;
		b[res + 1] = a[i];
	}

	printf ("%d\n", m);

	return 0;
}
