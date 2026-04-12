#include<bits/stdc++.h>

#define fec(i, x, y) (int i = head[x], y = g[i].to; i; i = g[i].ne, y = g[i].to)
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define File(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)
#define fi first
#define se second
#define pb push_back

template<typename A, typename B> inline char smax(A &a, const B &b) {return a < b ? a = b , 1 : 0;}
template<typename A, typename B> inline char smin(A &a, const B &b) {return b < a ? a = b , 1 : 0;}

typedef long long ll; typedef unsigned long long ull; typedef std::pair<int, int> pii;

template<typename I>
inline void read(I &x) {
	int f = 0, c;
	while (!isdigit(c = getchar())) c == '-' ? f = 1 : 0;
	x = c & 15;
	while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + (c & 15);
	f ? x = -x : 0;
}

const int N = 3000 + 7;

int n, P;
int S[N][N], C[N][N];

inline int smod(int x) { return x >= P ? x - P : x; }
inline void sadd(int &x, const int &y) { x += y; x >= P ? x -= P : x; }
inline int fpow(int x, int y, const int &P = ::P) {
	int ans = 1;
	for (; y; y >>= 1, x = (ll)x * x % P) if (y & 1) ans = (ll)ans * x % P;
	return ans;
}

inline void ycl() {
	S[0][0] = C[0][0] = 1;
	for (int i = 1; i <= n + 1; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) S[i][j] = (S[i - 1][j - 1] + (ll)S[i - 1][j] * j) % P, C[i][j] = smod(C[i - 1][j - 1] + C[i - 1][j]);
	}
}

inline void work() {
	ycl();
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		int cnt = 0, ni22 = fpow(2, fpow(2, n - i, P - 1)), fn1 = fpow(2, n - i), fn = 1;
		for (int j = 0; j <= i; ++j) sadd(cnt, (ll)S[i + 1][j + 1] * ni22 % P * fn % P), fn = (ll)fn * fn1 % P;
//		dbg("i = %d, ni22 = %d, fn1 = %d, cnt = %d\n", i, ni22, fn1, cnt);
		if (i & 1) sadd(ans, P - (ll)cnt * C[n][i] % P);
		else sadd(ans, (ll)cnt * C[n][i] % P);
	}
	printf("%d\n", ans);
}

inline void init() {
	read(n), read(P);
}

int main() {
#ifdef hzhkk
	freopen("hkk.in", "r", stdin);
#endif
	init();
	work();
	fclose(stdin), fclose(stdout);
	return 0;
}