#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

const int MaxN = 10000;
const int MaxNL = MaxN * 2;
const int M = 998244353;

inline int modpow(int a, const int &n)
{
	int res = 1;
	for (int i = n; i; i >>= 1)
	{
		if (i & 1)
			res = (s64)res * a % M;
		a = (s64)a * a % M;
	}
	return res;
}

int n;
char a[MaxN + 2];
char b[MaxN + 2];

int fact[MaxNL + 1];
int rfact[MaxNL + 1];

inline void init_fact(int n = MaxNL)
{
	fact[0] = 1;
	for (int i = 1; i <= n; ++i)
		fact[i] = (s64)fact[i - 1] * i % M;

	rfact[n] = modpow(fact[n], M - 2);
	for (int i = n; i; --i)
		rfact[i - 1] = (s64)rfact[i] * i % M;
}

int f[MaxN + 1];

int main()
{
	init_fact();

	scanf("%s", a + 1);
	scanf("%s", b + 1);
	n = strlen(a + 1);

	int x = 0, y = 0;
	for (int i = 1; i <= n; ++i)
		if (a[i] == '1')
			b[i] == '0' ? ++x : ++y;

	f[0] = 1;
	for (int i = 1; i <= x; ++i)
		for (int j = 1; j <= y; ++j)
			f[j] = (f[j] + (s64)i * f[j - 1]) % M;

	int res = 0;
	for (int i = 0; i <= y; ++i)
		res = (res + (s64)f[i] * rfact[i + x]) % M;

	res = (s64)res * fact[x] % M * fact[x] % M;
	res = (s64)res * fact[y] % M;
	res = (s64)res * fact[x + y] % M;

	cout << res << endl;

	return 0;
}