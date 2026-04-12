#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

const LL mod = 1000000007;

// ユークリッドの互除法
LL extgcd(LL a, LL b, LL &x, LL &y)
{
	LL g = a; x = 1; y = 0;
	if (b != 0)
	{
		g = extgcd(b, a%b, y, x);
		y -= (a / b)*x;
	}
	return g;
}

// 逆元
LL mod_inverse(LL a, LL m)
{
	LL x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

// 階乗
std::vector<LL>fact;
void mod_fact(LL n, LL m)
{
	fact.resize(n + 1);
	fact[0] = 1;
	for (LL i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i%m;
}

// nCk mod p
LL mod_comb(LL n, LL k, LL m)
{
	if (n < k) return 0;
	return fact[n] * mod_inverse(fact[k] * fact[n - k] % m, m) % m;
}

LL N, A, B, C, D;
std::vector<std::vector<LL>>memo;
LL dp(LL i, LL j)
{
	if (i == 0) return 1;
	if (j > B) return 0;
	if (memo[i][j] != -1) return memo[i][j];
	LL res = dp(i, j + 1), c = 1;
	for (LL k = 1; k < C; ++k) c = (c*mod_comb(i - j * (k - 1), j, mod)) % mod;
	for (LL k = C; k <= D; ++k)
	{
		if (j*k > i) break;
		c = (c*mod_comb(i - j * (k - 1), j, mod)) % mod;
		res += ((dp(i - j * k, j + 1)*c) % mod)*mod_inverse(fact[k], mod);
		res %= mod;
	}
	return memo[i][j] = res;
}

int main()
{
	in >> N >> A >> B >> C >> D;

	mod_fact(N, mod);
	memo.resize(N + 1);
	rep(i, memo.size()) memo[i].resize(N + 1, -1);
	out << dp(N, A) << std::endl;
}
