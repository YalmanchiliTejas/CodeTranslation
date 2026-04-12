#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

const LL mod = 1000000007;

// ユークリッドの互除法
LL extgcd(LL a, LL b, LL& x, LL& y)
{
	LL g = a; x = 1; y = 0;
	if (b != 0)
	{
		g = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
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
	for (LL i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % m;
}

// nCk mod p
LL mod_comb(LL n, LL k, LL m)
{
	if (n < k) return 0;
	return fact[n] * mod_inverse(fact[k] * fact[n - k] % m, m) % m;
}

int main()
{
	LL N, M, K;
	in >> N >> M >> K;

	LL ansX = 0, ansY = 0;
	mod_fact(N * M, mod);
	rep(i, M) (ansX += i * (M - i) % mod) %= mod;
	rep(i, N) (ansY += i * (N - i) % mod) %= mod;
	(ansX *= N * N % mod) %= mod;
	(ansY *= M * M % mod) %= mod;

	out << (ansX + ansY) % mod * mod_comb(N * M - 2, K - 2, mod) % mod << std::endl;
}
