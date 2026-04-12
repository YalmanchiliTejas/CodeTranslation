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
	const int N = 3e3 + 10;
	int C[N][N], S[N][N], P, n;
	int power(int a, int b, const int P)
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
	void init()
	{
		S[0][0] = 1;
		for (int i = 0; i < N; i++)
		{
			C[i][0] = 1;
			for (int j = 1; j <= i; j++)
			{
				C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
				S[i][j] = ((ll)j * S[i - 1][j] + S[i - 1][j - 1]) % P;
			}
		}
	}
	int work()
	{
		read(n), read(P);
		init();
		int ans = 0;
		for (int i = 0; i <= n; i++)
		{
			int pow = power(2, n - i, P), sum = 0;
			for (int j = 0, tmp = 1; j <= i; j++, tmp = (ll)tmp * pow % P)
				sum = (sum + (ll)S[i + 1][j + 1] * tmp) % P;
			ans = (ans + (ll)sum * 
					C[n][i] % P * ll(i & 1 ? P - 1 : 1) % P * power(2, power(2, n - i, P - 1), P) % P) % P;
		}
		write(ans);
		return 0;
	}
}
int main()
{
	return zyt::work();
}