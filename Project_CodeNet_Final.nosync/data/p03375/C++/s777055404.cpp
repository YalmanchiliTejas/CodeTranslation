#include <bits/stdc++.h>

using namespace std;

#define fst first
#define snd second
#define mp make_pair
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;

template<typename T> inline LL squ(T x) { return (LL) x * x; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

template<typename T> inline T read() {
	T sum = 0, fg = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') fg = -1;
	for (; isdigit(c); c = getchar()) sum = (sum << 3) + (sum << 1) + (c ^ 0x30);
	return fg * sum;
}

const int maxn = 3e3 + 10;

inline int Pow(int x, int y, int mod) {
	int res = 1;
	for (; y; y >>= 1, x = squ(x) % mod) if (y & 1) res = (LL) res * x % mod;
	return res;
}

int n, mod, S[maxn][maxn], C[maxn][maxn], pw[maxn * maxn], pww[maxn];

inline void Add(int &x, int y) { (y < 0 ? y += mod : 0), x += y, (x >= mod ? x -= mod : 0); }

inline void init() {
	S[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			S[i][j] = ((LL) S[i - 1][j] * j + S[i - 1][j - 1]) % mod;
	C[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= i; j++)
			C[i][j] = ((j ? C[i - 1][j - 1] : 0) + C[i - 1][j]) % mod;
	pw[0] = 1;
	for (int i = 1, e = n * n; i <= e; i++) pw[i] = (pw[i - 1] << 1) % mod;
	for (int i = 0; i <= n; i++) pww[i] = Pow(2, Pow(2, i, mod - 1), mod);
}

int main() {

	n = read<int>(), mod = read<int>(), init();

	int ans = 0;
	for (int i = 0; i <= n; i++) {
		int res = 0;
		for (int j = 0; j <= i; j++) Add(res, (LL) pw[(n - i) * j] % mod * (S[i][j] + (LL) S[i][j + 1] * (j + 1) % mod) % mod);
		Add(ans, (i & 1 ? -1LL : 1LL) * C[n][i] * res % mod * pww[n - i] % mod);
	}

	printf("%d\n", ans);

	return 0;
}