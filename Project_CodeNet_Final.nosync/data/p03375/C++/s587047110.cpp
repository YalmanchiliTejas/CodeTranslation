#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

const int N = 3005;
int C[N][N], S[N][N], n, P;

int Pow(int x, int t, int P = P)
{
	int res = 1;
	for (; t; t >>= 1, x = 1LL * x * x % P)
		if (t & 1) res = 1LL * res * x % P;
	return res;
}

void init(int n)
{
	for (int i = 0; i <= n; ++i)
	{
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
	}
	
	S[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		S[i][1] = 1;
		for (int j = 1; j <= i; ++j)
			S[i][j] = (S[i - 1][j - 1] + 1LL * j * S[i - 1][j]) % P;
	}
}

int main()
{
	n = read(); P = read();
	init(n + 1);
	
	int ans = 0;
	for (int i = 0; i <= n; ++i)
	{
		int t = 1LL * Pow(2, Pow(2, n - i, P - 1)) * C[n][i] % P;
		int b = Pow(2, n - i);
		int res = 1;
		
		for (int j = 1, c = b; j <= i; ++j)
		{
			res = (res + 1LL * S[i + 1][j + 1] * c % P) % P;
			c = 1LL * c * b % P;
		}
		
		res = 1LL * res * t % P;
		if (i & 1) ans = (ans - res + P) % P;
			else ans = (ans + res) % P;
	}
	
	printf("%d\n", ans);
	
	return 0;
}
