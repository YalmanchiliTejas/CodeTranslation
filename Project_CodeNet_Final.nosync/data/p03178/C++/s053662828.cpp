#include <bits/stdc++.h>
#define REP(i, a, b) for(int i(a); i <= (b); ++i)

template <class T> inline bool smin(T&x, const T&y) { return y < x ? x = y, 1 : 0; }
template <class T> inline bool smax(T&x, const T&y) { return x < y ? x = y, 1 : 0; }

typedef long long ll;

const int P(1e9 + 7);
inline void inc(int &x, int y) { if ((x += y) >= P) x -= P; }
char s[10002];
int a, n, f[10002][100];
int dfs(int p, int d, bool lim){
	if (p > n) return !d;
	if (!lim && ~f[p][d]) return f[p][d];
	int up = lim ? s[p] : 9, r = 0;
	REP(i, 0, up) inc(r, dfs(p + 1, (d + i) % a, lim && i == up));
	if(!lim) f[p][d] = r;
	return r;
}
int main() {
	scanf("%s%d", s + 1, &a), n = strlen(s + 1);
	REP(i, 1, n) s[i] ^= '0';
	memset(f, -1, sizeof f);
	std::cout << (dfs(1, 0, 1) + P - 1) % P;
	return 0;
}

