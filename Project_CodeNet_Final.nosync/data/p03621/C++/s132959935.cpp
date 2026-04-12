#include <cstdio>
#include <algorithm>
const long long MOD = 998244353;
int N, S, L = 1;
char _i[10001], _j[10001];
long long inv[10001], fc[10001], fi[10001], O;
long long ans[32768], bit[32768], Fbit[32768];
long long POWER(long long a, long long b)
{
	long long r = 1;
	for (; b; b >>= 1)
	{
		if (b & 1)
			r = r * a % MOD;
		a = a * a % MOD;
	}
	return r;
}
void FFT(long long *a, int f = 1)
{
	static int p[32768];
	for (int i = 1; i < L; i++)
		p[i] = i & 1 ? p[i - 1] | L >> 1 : p[i >> 1] >> 1;
	for (int i = 0; i < L; i++)
		if (i < p[i])
			std::swap(a[i], a[p[i]]);
	for (int i = 1; i < L; i <<= 1)
	{
		long long w, wn = POWER(3, (MOD - 1) / i / 2), x, y;
		if (f == -1)
			wn = POWER(wn, MOD - 2);
		for (int j = 0; j < L; j += i + i)
		{
			w = 1;
			for (int k = j; k < j + i; k++)
			{
				x = a[k];
				y = a[k + i] * w % MOD;
				a[k] = x + y < MOD ? x + y : x + y - MOD;
				a[k + i] = x - y < 0 ? x - y + MOD : x - y;
				w = w * wn % MOD;
			}
		}
	}
	if (f == -1)
	{
		long long d = POWER(L, MOD - 2);
		for (int i = 0; i < L; i++)
			a[i] = a[i] * d % MOD;
	}
}
void FFT(long long *i, long long *o, int f = 1)
{
	std::copy(i, i + L, o);
	FFT(o, f);
}
int main()
{
	fc[0] = fi[0] = inv[1] = 1;
	for (int i = 2; i <= 10000; i++)
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	for (int i = 1; i <= 10000; i++)
	{
		fc[i] = fc[i - 1] * i % MOD;
		fi[i] = fi[i - 1] * inv[i] % MOD;
	}
	scanf("%s%s", _i, _j);
	for (int i = 0; _i[i]; i++)
	{
		if (_i[i] == '1')
		{
			N++;
			if (_j[i] == '1')
				S++;
		}
	}
	while (L <= S + S)
		L <<= 1;
	for (int i = 0; i <= S; i++)
		ans[i] = i == 0;
	if (S < N)
	{
		for (int i = 0; i <= S; i++)
			bit[i] = fi[i + 1];
		FFT(bit, Fbit);
		for (int _ = N - S; _; _ >>= 1)
		{
			if (_ & 1)
			{
				FFT(ans);
				for (int i = 0; i < L; i++)
					ans[i] = ans[i] * Fbit[i] % MOD;
				FFT(ans, -1);
				std::fill(ans + S + 1, ans + L, 0);
			}
			for (int i = 0; i < L; i++)
				Fbit[i] = Fbit[i] * Fbit[i] % MOD;
			FFT(Fbit, bit, -1);
			std::fill(bit + S + 1, bit + L, 0);
			FFT(bit, Fbit);
		}
	}
	for (int j = 0; j <= S; j++)
		O = (O + ans[j] * fc[S]) % MOD;
	printf("%lld\n", O * fc[N] % MOD * fc[N - S] % MOD);
	return 0;
}
