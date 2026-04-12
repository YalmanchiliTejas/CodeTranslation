// Tenshi ni Fureta yo!

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> pii;

#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#define MP make_pair
#define fst first
#define snd second
#define SZ(u) ((int) (u).size())
#define ALL(u) (u).begin(), (u).end()

inline void proc_status()
{
	ifstream t("/proc/self/status");
	cerr << string(istreambuf_iterator<char>(t), istreambuf_iterator<char>()) << endl;
}

template<typename T> inline int chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline int chkmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
template<typename T> inline T sqr(const T &val) { return val * val; }

namespace fastIO
{
	const int MAX_BUFFER_SIZE = 1 << 16;

	char buffer[MAX_BUFFER_SIZE], *cur = buffer, *ed = buffer;

	inline char getc() { return *(cur == ed ? ed = buffer + fread(buffer, 1, MAX_BUFFER_SIZE, stdin), cur = buffer : cur)++; }
}
using fastIO::getc;

template<typename T> inline T read()
{
	register T sum(0), fg(1);
	register char ch(getc());
	for(; !isdigit(ch); ch = getc()) if(ch == '-') fg = -1;
	for(;  isdigit(ch); ch = getc()) sum = sum * 10 - '0' + ch;
	return sum * fg;
}

// END tpl.

int MOD;

inline int fpm(int x, int y, int M = MOD)
{
	int res = 1;
	for(; y; y >>= 1, x = (LL) x * x % M) if(y & 1) res = (LL) res * x % M;
	return res;
}

inline int inv(int x) { assert(x); return fpm(x, MOD - 2); }

namespace MATH
{
	const int n = (int) 3e3;

	int fac[n + 5], ifac[n + 5];
	int S2[n + 5][n + 5];

	inline void init()
	{
		fac[0] =1;
		for(int i = 1; i <= n; ++i) fac[i] = (LL) fac[i - 1] * i % MOD;
		ifac[n] = inv(fac[n]);
		for(int i = n - 1; i >= 0; --i) ifac[i] = (LL) ifac[i + 1] * (i + 1) % MOD;

		S2[0][0] = 1;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= i; ++j)
				S2[i][j] = (S2[i - 1][j - 1] + (i == j ? 0 : (LL) S2[i - 1][j] * j % MOD)) % MOD;
	}

	inline int C(int N, int M) { return N < 0 || M < 0 || N < M ? 0 : (LL) fac[N] * ifac[N - M] % MOD * ifac[M] % MOD; }
}
using MATH::C;
using MATH::S2;

const int MAXN = (int) 3e3;

int n;

inline void input()
{
	n = read<int>(), MOD = read<int>();
}

inline void solve()
{
	static int D[MAXN + 5][MAXN + 5];

	for(int k = 0; k <= n; ++k)
		for(int j = 0; j <= k; ++j)
			D[k][j] = ((LL) S2[k][j + 1] * (j + 1) % MOD + S2[k][j]) % MOD;

	int ans = 0;
	for(int k = 0; k <= n; ++k)
	{
		static int pw[MAXN + 5];

		pw[0] = 1;
		for(int pw2 = fpm(2, n - k), i = 1; i <= k; ++i) pw[i] = (LL) pw[i - 1] * pw2 % MOD;

		int res = 0;
		for(int j = 0; j <= k; ++j) (res += (LL) D[k][j] * pw[j] % MOD) %= MOD;
		res = (LL) res * fpm(2, fpm(2, n - k, MOD - 1)) % MOD;
		(ans += (LL) (k & 1 ? -1 : +1) * C(n, k) * res % MOD) %= MOD;
	}
	printf("%d\n", (ans + MOD) % MOD);
}

int main()
{
#ifdef K_ON
	freopen("E.in", "r", stdin);
	freopen("E.out", "w", stdout);
#endif

	input();
	MATH::init();
	solve();

	return 0;
}


