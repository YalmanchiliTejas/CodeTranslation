#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 10100;
typedef long long ll;
const int mod = 998244353;
const int inv2 = mod + 1 >> 1;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int fac[maxn], ifac[maxn], inv[maxn];
inline ll c(int x,int y){ return (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod; }
int f[maxn][maxn], n;
std::string s0, s1;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	fac[0] = ifac[0] = fac[1] = ifac[1] = inv[1] = 1;
	for(int i = 2;i < maxn;++i) {
		inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
		fac[i] = (ll) fac[i - 1] * i % mod;
		ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
	}
	int c0 = 0, c1 = 0, n;
	cin >> s0 >> s1, n = s0.size();
	for(int i = 0;i < n;++i) {
		c0 += s0[i] == '1' && s1[i] == '1';
		c1 += s0[i] == '0' && s1[i] == '1';
	}
	for(int i = 0;i <= c1;++i) {
		f[0][i] = (ll) fac[i] * fac[i] % mod;
	}
	for(int i = 1;i <= c0;++i) {
		for(int j = 1;j <= c1;++j) {
			f[i][j] = ((ll) f[i - 1][j] * i * j + (ll) f[i][j - 1] * j * j) % mod;
		}
	}
	int ans = 0;
	for(int i = 0;i <= c0;++i) {
		ans = (ans + (ll) f[i][c1] * c(c0, i) % mod * c(c0 + c1, c0 - i) % mod * fac[c0 - i] % mod * fac[c0 - i]) % mod;
	}
	cout << ans << '\n';
}
