#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 1010;
typedef long long ll;
const int mod = 1e9 + 7;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int fac[maxn], ifac[maxn], inv[maxn];
int dp[maxn];
int n, a, b, c, d;
inline int C(int x,int y) {
	return (ll) fac[x] * ifac[x - y] % mod * ifac[y] % mod;
}
std::map<int, int> map[maxn][maxn];
inline int calc(int n,int x,int c) {
	if(!c) return 1;
	if(map[n][x].count(c)) return map[n][x][c];
	return map[n][x][c] = (ll) calc(n - x, x, c - 1) * C(n, x) % mod;
}
int main() {
	fac[0] = ifac[0] = fac[1] = ifac[1] = inv[1] = 1;
	for(int i = 2;i < maxn;++i) {
		inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
		fac[i] = (ll) fac[i - 1] * i % mod;
		ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
	}
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> a >> b >> c >> d;
	dp[0] = 1;
	rep(i, a, b) {
		for(int j = n;j >= i * c;--j) {
			for(int k = c;k <= d && i * k <= j;++k) {
				dp[j] = (dp[j] + (ll) dp[j - k * i] * calc(n - j + k * i, i, k) % mod * ifac[k]) % mod;
			}
		}
	}
	cout << dp[n] << '\n';
}
