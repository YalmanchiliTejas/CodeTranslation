#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;

namespace zyt
{
	template<typename T>
	inline bool read(T &x)
	{
		char c;
		bool f = false;
		x = 0;
		do
			c = getchar();
		while (c != EOF && c != '-' && !isdigit(c));
		if (c == EOF)
			return false;
		if (c == '-')
			f = true, c = getchar();
		do
			x = x * 10 + c - '0', c = getchar();
		while (isdigit(c));
		if (f)
			x = -x;
		return true;
	}
	template<typename T>
	inline void write(T x)
	{
		static char buf[20];
		char *pos = buf;
		if (x < 0)
			putchar('-'), x = -x;
		do
			*pos++ = x % 10 + '0';
		while (x /= 10);
		while (pos > buf)
			putchar(*--pos);
	}
	typedef long long ll;
	const int N = 8e3 + 10, M = 2e2 + 10, P = 998244353;
	int power(int a, int b)
	{
		int ans = 1;
		while (b)
		{
			if (b & 1)
				ans = (ll)ans * a % P;
			a = (ll)a * a % P;
			b >>= 1;
		}
		return ans;
	}
	int inv(const int a)
	{
		return power(a, P - 2);
	}
	namespace Polynomial
	{
		const int LEN = N << 2, G = 3;
		int rev[LEN], omega[LEN], winv[LEN];
		void init(const int n, const int lg2)
		{
			int w = power(G, (P - 1) / n), wi = inv(w);
			omega[0] = winv[0] = 1;
			for (int i = 1; i < n; i++)
			{
				omega[i] = (ll)omega[i - 1] * w % P;
				winv[i] = (ll)winv[i - 1] * wi % P;
			}
			for (int i = 0; i < n; i++)
				rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) << (lg2 - 1)));
		}
		void ntt(int *const a, const int *const w, const int n)
		{
			for (int i = 0; i < n; i++)
				if (i < rev[i])
					swap(a[i], a[rev[i]]);
			for (int l = 1; l < n; l <<= 1)
				for (int i = 0; i < n; i += (l << 1))
					for (int k = 0; k < l; k++)
					{
						int x = a[i + k], y = (ll)a[i + l + k] * w[n / (l << 1) * k] % P;
						a[i + k] = (x + y) % P;
						a[i + l + k] = (x - y + P) % P;
					}
		}
		void mul(const int *const a, const int *const b, int *const c, const int n)
		{
			static int x[LEN], y[LEN];
			int m = 1, lg2 = 0;
			while (m < n + n)
				m <<= 1, ++lg2;
			memcpy(x, a, sizeof(int[n]));
			memset(x + n, 0, sizeof(int[m - n]));
			memcpy(y, b, sizeof(int[n]));
			memset(y + n, 0, sizeof(int[m - n]));
			init(m, lg2);
			ntt(x, omega, m), ntt(y, omega, m);
			for (int i = 0; i < m; i++)
				x[i] = (ll)x[i] * y[i] % P;
			ntt(x, winv, m);
			int invm = inv(m);
			for (int i = 0; i < n; i++)
				c[i] = (ll)x[i] * invm % P;
		}
	}
	int n, m, f[M][N], fac[N], finv[N], A[N];
	void init()
	{
		fac[0] = 1;
		for (int i = 1; i < N; i++)
			fac[i] = (ll)fac[i - 1] * i % P;
		finv[N - 1] = inv(fac[N - 1]);
		for (int i = N - 1; i > 0; i--)
			finv[i - 1] = (ll)finv[i] * i % P;
		for (int i = 0; i + 2 < N; i++)
			A[i] = finv[i + 2];
	}
	int C(const int n, const int m)
	{
		return (ll)fac[n] * finv[m] % P * finv[n - m] % P;
	}
	int work()
	{
		using Polynomial::mul;
		init();
		read(n), read(m);
		f[0][0] = 1;
		for (int i = 1; i <= m; i++)
		{
			static int B[N];
			for (int j = 0; j <= n; j++)
				B[j] = (ll)f[i - 1][j] * finv[j] % P;
			mul(A, B, f[i], n + 1);
			for (int j = 0; j <= n; j++)
				f[i][j] = (((ll)f[i][j] * fac[j + 2] - 
					(ll)f[i - 1][j] * C(j + 2, 2) + f[i - 1][j] * ll(1 + j * ll(j + 1) / 2 % P)) % P + P) % P;
		}
		int ans = 0;
		for (int i = 0; i <= n; i++)
			ans = (ans + (ll)f[m][i] * C(n, i)) % P;
		write(ans);
		return 0;
	}
}
int main()
{
	return zyt::work();
}