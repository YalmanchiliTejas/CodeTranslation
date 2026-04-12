#include <bits/stdc++.h>

using namespace std;

#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define fst first
#define snd second
#define SZ(u) ((int) (u).size())
#define ALL(u) (u).begin(), (u).end()

inline void proc_status()
{
    ifstream t("/proc/self/status");
    cerr << string(istreambuf_iterator<char>(t), istreambuf_iterator<char>()) << endl;
}

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline T read()
{
	register T sum = 0, fg = 1;
	register char ch(getchar());
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') fg = -1;
	for(;  isdigit(ch); ch = getchar()) sum = (sum << 3) + (sum << 1) - '0' + ch;
	return sum * fg;
}

typedef long long LL;
typedef pair<int, int> pii;

const int MOD = (int) 1e9 + 7;
const int MAXN = 100;

int n;

int a[MAXN + 5];

inline void input()
{
	n = read<int>();
	for(int i = 1; i <= n; ++i) a[i] = read<int>();
}

int m;

int val[MAXN + 5];

inline void discrete()
{
	m = 0;
	for(int i = 1; i <= n; ++i) val[++m] = a[i];
	sort(val + 1, val + m + 1), m = unique(val + 1, val + n + 1) - (val + 1);
	for(int i = 1; i <= n; ++i) a[i] = lower_bound(val + 1, val + m + 1, a[i]) - val;
}

inline int fpm(int base, int exp)
{
	int res = 1;
	for(; exp; exp >>= 1, base = (LL) base * base % MOD) if(exp & 1) res = (LL) res * base % MOD;
	return res;
}

inline void solve()
{
	discrete();

	static int f[MAXN + 5][MAXN + 5] = {0};

	f[0][0] = 1;
	for(int i = 1; i <= n; ++i)
	{
		f[i][0] = f[i - 1][0] * 2 % MOD;
		for(int j = a[i] + 1; j <= a[i - 1]; ++j) (f[i][0] += f[i - 1][j] * 2 % MOD) %= MOD;

		int coef = a[i] <= a[i - 1] ? 1 : fpm(2, val[a[i]] - val[a[i - 1]]);
		for(int j = min(a[i], a[i - 1]); j; --j) f[i][j] = (LL) f[i - 1][j] * coef % MOD;

		for(int j = a[i - 1] + 1; j <= a[i]; ++j)
		{
			coef = (j == 1 ? fpm(2, val[j]) - 2 : fpm(2, val[j] - val[j - 1] + 1) - 2) % MOD;
			(f[i][j] += (LL) f[i - 1][0] * coef % MOD * fpm(2, val[a[i]] - val[j]) % MOD) %= MOD;
		}
	}

	int ans = 0;
	for(int i = 0; i <= a[n]; ++i) (ans += f[n][i]) %= MOD;
	printf("%d\n", (ans + MOD) % MOD);
}

int main()
{
	input();
	solve();

	return 0;
}

