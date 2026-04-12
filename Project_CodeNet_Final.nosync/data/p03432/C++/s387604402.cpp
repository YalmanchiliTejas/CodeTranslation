#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
const llint mod = 998244353;

using namespace std;

llint n, m;
llint dp[205][8005];
llint f[1<<14], g[1<<14];
llint F[1<<14], G[1<<14];

const int FACT_MAX = 200005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < FACT_MAX; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	fact_inv[FACT_MAX-1] = modpow(fact[FACT_MAX-1], mod-2);
	for(int i = FACT_MAX-2; i >= 0; i--){
		fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
	}
}

llint comb(llint n, llint k)
{
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

llint modpow(llint a, llint n, llint mod)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1, mod)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2, mod) % mod;
	}
}

int rev(int x, int n)
{
	int ret = 0;
	for(int i = 0; i < n; i++){
		ret <<= 1;
		ret |= (x>>i) & 1;
	}
	return ret;
}

//f[]とF[]は異なる実体を持たなければならない。rootには1の原始2^n乗根を渡す
void DFT(llint f[], llint F[], int n, llint mod, llint root)
{
	int N = 1<<n;
	for(int i = 0; i < N; i++) F[rev(i, n)] = f[i];
	
	llint a, b, x, z;
	for(int i = 1; i <= n; i++){
		int l = 1<<i;
		z = modpow(root, 1<<(n-i), mod);
		for(int j = 0; j < N/l; j++){
			x = 1;
			for(int k = 0; k < l/2; k++){
				a = F[j*l+k], b = F[j*l+k+l/2];
				F[j*l+k] = a + x * b % mod;
				F[j*l+k+l/2] = a - x * b % mod + mod;
				if(F[j*l+k] >= mod) F[j*l+k] -= mod;
				if(F[j*l+k+l/2] >= mod) F[j*l+k+l/2] -= mod;
				x *= z, x %= mod;
			}
		}
	}
}

//f[]とF[]は異なる実体を持たなければならない。rootには1の原始2^n乗根を渡す
void IDFT(llint F[], llint f[], int n, llint mod, llint root)
{
	int N = 1<<n;
	for(int i = 0; i < N; i++) f[rev(i, n)] = F[i];
	root = modpow(root, mod-2, mod);
	
	llint a, b, x, z;
	for(int i = 1; i <= n; i++){
		int l = 1<<i;
		z = modpow(root, 1<<(n-i), mod);
		for(int j = 0; j < N/l; j++){
			x = 1;
			for(int k = 0; k < l/2; k++){
				a = f[j*l+k], b = f[j*l+k+l/2];
				f[j*l+k] = a + x * b % mod;
				f[j*l+k+l/2] = a - x * b % mod + mod;
				if(f[j*l+k] >= mod) f[j*l+k] -= mod;
				if(f[j*l+k+l/2] >= mod) f[j*l+k+l/2] -= mod;
				x *= z, x %= mod;
			}
		}
	}
	llint Ninv = modpow(N, mod-2, mod);
	for(int i = 0; i < N; i++) f[i] *= Ninv, f[i] %= mod;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n >> m;
	
	llint root = modpow(3, 119*512);
	for(int i = 0; i <= n; i++) g[i] = fact_inv[i+3];
	DFT(g, G, 14, mod, root);
	
	dp[0][0] = 1;
	llint N = 1<<14;
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < N; j++) f[j] = 0;
		for(int j = 0; j <= n; j++) f[j] = dp[i-1][j] * fact_inv[j] % mod;
		DFT(f, F, 14, mod, root);
		for(int j = 0; j < N; j++) F[j] *= G[j], F[j] %= mod;
		IDFT(F, f, 14, mod, root);
		for(int j = 1; j <= n; j++) dp[i][j] = fact[j+2] * f[j-1] % mod;
			
		for(int j = 0; j <= n; j++){
			dp[i][j] += dp[i-1][j], dp[i][j] %= mod;
			if(j > 0) dp[i][j] += dp[i-1][j] * comb(j+1, 2) % mod, dp[i][j] %= mod;
		}
	}
	
	llint ans = 0;
	for(int i = 0; i <= n; i++){
		ans += dp[m][i] * comb(n, i) % mod, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}