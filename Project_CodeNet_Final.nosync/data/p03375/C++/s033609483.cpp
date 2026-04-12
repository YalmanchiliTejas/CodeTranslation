#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i = (a); i <= (b); ++ i)
#define rrp(i,a,b) for (int i = (a); i >= (b); -- i)
#define gc() getchar()
#define fir first
#define sec second
typedef pair<int,int> pii;
typedef double db;
typedef long long ll;
template <typename tp>
inline void read(tp& x) {
	x = 0; char tmp; bool key = 0;
	for (tmp = gc(); !isdigit(tmp); tmp = gc())
		key = (tmp == '-');
	for (; isdigit(tmp); tmp = gc())
		x = (x << 3) + (x << 1) + (tmp ^ '0');
	if (key) x = -x;
}
template <typename tp>
inline void ckmn(tp& x,tp y) {
	x = x < y ? x : y;
}
template <typename tp>
inline void ckmx(tp& x,tp y) {
	x = x < y ? y : x;
}

const int N = 3010;
int MOD;

inline void Add(int& x,int y) {
	x = x + y >= MOD ? x + y - MOD : x + y;
}
inline void Sub(int& x,int y) {
	x = x - y < 0 ? x - y + MOD : x - y;
}
int power(int a,int b,int mod = MOD) {
	int ret = 1;
	while (b) {
		if (b&1) ret = 1ll * ret * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return ret;
}

int dp[N][N], n, comb[N][N], ans;
int main() {
	cin >> n >> MOD;
	rep (i, 0, n) dp[i][0] = 1;
	rep (i, 1, n) rep (j, 1, i) {
		dp[i][j] = 1ll * dp[i-1][j] * (j+1) % MOD;
		Add(dp[i][j], dp[i-1][j-1]);
	}
	rep (i, 0, n) comb[i][0] = 1;
	rep (i, 1, n) rep (j, 1, i)
		comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
	rep (a, 0, n) {
		int sgn = (a&1) ? MOD - 1 : 1;
		sgn = 1ll * sgn * comb[n][a] % MOD;
		sgn = 1ll * sgn * power(2, power(2, n-a, MOD - 1)) % MOD;
		int tmp = 0, val = power(2, n-a), t = 1;
		rep (j, 0, a) {
			Add(tmp, 1ll * dp[a][j] * t % MOD);
			t = 1ll * t * val % MOD;
		}
		sgn = 1ll * sgn * tmp % MOD;
		Add(ans, sgn);
	}
	cout << ans << endl;
	return 0;
}