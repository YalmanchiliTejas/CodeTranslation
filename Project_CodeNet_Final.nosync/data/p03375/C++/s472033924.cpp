/********************************************************************************
	
	Code by a weak man who named CYJian, and he hopes the code can get more points.

	Algorithm: 

 ********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//{{{ FAST IO AND SOME FUNCTIONS
const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;

#define ge (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
#define ri read_int()
#define rl read_ll()
#define ra read_alpha()
#define FILE(s) freopen(s"in", "r", stdin), freopen(s"out", "w", stdout)

template<typename T>
inline void read(T &x) {
	char ch, t = 0; x = 0;
	while(!isdigit(ch = ge)) t |= ch == '-';
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = ge;
	x = t ? -x : x;
}
inline char read_alpha() { char c = ge; while(!isalpha(c) && c != EOF) c = ge; return c; }
inline int read_int() { int x; return read(x), x; }
inline ll read_ll() { ll x; return read(x), x; }

template<typename T> inline void chkmin(T&a, T b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T&a, T b) { a = a > b ? a : b; }
//}}}

int n, mod;
int S2[2][3010];
int fac[3010];
int ifac[3010];

inline int fsp(int x, int k, int mod) {
	int s = 1;
	while(k) {
		if(k & 1) s = 1LL * s * x % mod;
		x = 1LL * x * x % mod, k >>= 1;
	} return s;
}

int main() {
#ifdef LOCAL
	FILE("");
#endif
	n = ri, mod = ri;
	int res = 0, o = 0, t = 1;
	S2[0][0] = ifac[0] = fac[0] = 1;
	for(int i = 1; i <= n; i++) ifac[i] = fsp(fac[i] = 1LL * fac[i - 1] * i % mod, mod - 2, mod);
	for(int i = 0; i <= n; i++) {
		for(int j = 1; j <= i + 1; j++)
			S2[t][j] = (S2[o][j - 1] + 1LL * S2[o][j] * j) % mod;
		o ^= 1, t ^= 1, S2[t][0] = 0;
		int prd = fsp(2, fsp(2, n - i, mod - 1), mod);
		int p = fsp(2, n - i, mod), mul = 1, s = 0;
		prd = i & 1 ? mod - prd : prd;
		for(int j = 0; j <= i; j++) {
			s = (s + 1LL * S2[o][j + 1] * mul) % mod;
			mul = 1LL * mul * p % mod;
		} res = (res + 1LL * prd * s % mod * ifac[i] % mod * ifac[n - i] % mod * fac[n]) % mod;
	} cout << res << endl;
	return 0;
}