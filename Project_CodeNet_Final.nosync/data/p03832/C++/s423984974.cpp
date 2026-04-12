#include <bits/stdc++.h>
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 1005;
int n, a, b, c, d, dp[N][N], fac[N * N], ifac[N * N], lol[N][N];
void add(int &x, int y) {
	x += y; if (x >= mod) x -= mod;
}
void rem(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}
int mul(int x, int y) {
	return 1ll * x * y % mod;
}
int fpow(int a, int p) {
	if (!p) return 1;
	int tmp = fpow(a, p >> 1);
	tmp = mul(tmp, tmp);
	if (p & 1) tmp = mul(tmp, a);
	return tmp;
}
int inv(int a) {
	return fpow(a, mod - 2);
}
int C(int n, int k) {
	if (n < k || k < 0) return 0;
	return mul(fac[n], mul(ifac[k], ifac[n - k]));
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> a >> b >> c >> d;
	fac[0] = ifac[0] = 1;
	fw (i, 1, N * N) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		ifac[i] = inv(fac[i]);
	}
	
	fw (i, 1, N) fw (j, 1, N) {
		lol[i][j] = mul(fac[i * j], inv(fpow(fac[j], i)));
		lol[i][j] = mul(lol[i][j], inv(fac[i]));
//		if (i < 5 && j < 5) cout << "lol[" << i << "][" << j << "] = " << lol[i][j] << "\n";
	}
	
	dp[0][0] = 1;
	
	fw (i, 1, b + 1) fw (j, 0, n + 1) {
		add(dp[i][j], dp[i - 1][j]);
		if (i >= a) {
			fw (k, c, d + 1) {
				if (j - k * i < 0) continue;
				add(dp[i][j], mul(dp[i - 1][j - k * i], mul(C(n - j + k * i, k * i), lol[k][i])));
			}
		}
//		cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << "\n";
	}
	cout << dp[b][n];
	return 0;
}