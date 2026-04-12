#include <bits/stdc++.h>
// #define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

struct _in {
	const _in operator,(int&a)const {
		a = 0; char k = getchar(); int f = 1;
		for(;!isdigit(k); k = getchar()) if (k == '-') f = -1;
		for(; isdigit(k); k = getchar()) a = a * 10 + k - '0';
		a *= f; return*this;
	}
}in;

int mod;
int fpow (int base, int v, int mm = mod) {
	int tot = 1;
	while (v) {
		if (v & 1) tot = 1LL * tot * base % mm;
		base = 1LL * base * base % mm;
		v >>= 1;
	}
	return tot;
}
const int N = 3000 + 5;
int n, S[N][N], C[N][N], powmod[N];

signed main ()
{
	in, n, mod;
	powmod[0] = 1;
	rep (i, 1, n) powmod[i] = (long long)powmod[i - 1] * 2 % (mod - 1);
	S[0][0] = 1;
	rep (i, 1, n + 1) rep (j, 1, i) S[i][j] = (S[i - 1][j - 1] + (long long)j * S[i - 1][j] % mod) % mod;
	rep (i, 0, n) C[i][0] = 1;
	rep (i, 1, n) rep (j, 1, n) C[i][j] = (C[i - 1][j - 1] + (long long)C[i - 1][j]) % mod;
	int ans = 0;
	rep (i, 0, n) {
		int ret = i % 2 ? mod - 1 : 1;
		ret = 1LL * ret * C[n][i] % mod;
		int dl1 = fpow (2, powmod[n - i]), dl3 = fpow (2, n - i), dl2 = 1;
		rep (j, 0, i) {
			int tmp = S[i + 1][j + 1];
			tmp = (long long) tmp * dl1 % mod;
			tmp = (long long) tmp * dl2 % mod;
			ans = (ans + (long long)tmp * ret % mod) % mod;
			dl2 = (long long)dl2 * dl3 % mod;
		}
	}
	printf ("%d\n", ans);
	return 0;
}