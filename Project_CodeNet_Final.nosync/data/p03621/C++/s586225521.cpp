#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1 << 15 | 1;
const int Mod = 998244353;
const int G = 3;

void Chkadd(int &x, const int &y) { if ((x += y) >= Mod) x -= Mod; }
void Chksub(int &x, const int &y) { if ((x -= y) < 0) x += Mod; }

int Cadd(int x, int y) { Chkadd(x, y); return x; }
int Csub(int x, int y) { Chksub(x, y); return x; }

int Power(int a, int k)
{
	int x = 1;
	for (; k; k >>= 1)
	{
		if (k & 1) x = 1ll * x * a % Mod;
		a = 1ll * a * a % Mod;
	}
	return x;
}

int wn[maxn], iv[maxn];

void Prepare(int N)
{
	int g = Power(G, (Mod - 1) / N);
	wn[0] = 1;
	for (int i = 1; i <= N; ++ i) wn[i] = 1ll * wn[i - 1] * g % Mod;
	for (int i = 0; i <= N; ++ i) iv[i] = wn[N - i];
}

void Transform(int n, int *a, int *wn, bool f)
{
	for (int i = 0, j = 0; i < n; ++ i)
	{
		if (i < j) swap(a[i], a[j]);
		for (int t = n >> 1; (j ^= t) < t; t >>= 1);
	}
	int *b = a + n;
	for (int i = 2, m = 1, t = n >> 1; i <= n; i = (m = i) << 1, t >>= 1)
	{
		for (int *j = a; j != b; j += i)
		{
			int *x = j, *y = x + m, *z = y;
			for (int *p = wn; x != z; ++ x, ++ y, p += t)
			{
				int tmp = 1ll * *y * *p % Mod;
				*y = Csub(*x, tmp);
				Chkadd(*x, tmp);
			}
		}
	}
	if (f)
	{
		int inv = Power(n, Mod - 2);
		for (int *i = a; i != b; ++ i)
			*i = 1ll * *i * inv % Mod;
	}
}

char A[maxn], B[maxn];
int fac[maxn], inv[maxn];
int a[maxn], b[maxn], c[maxn];

int main()
{
	scanf("%s%s", A, B);
	int n = strlen(A), x = 0, y = 0;
	for (int i = 0; i < n; ++ i)
		if (A[i] == '1') B[i] == '1' ? ++ x : ++ y;
	n = x + y;
	
	fac[0] = 1;
	for (int i = 1; i <= n + 1; ++ i) fac[i] = 1ll * fac[i - 1] * i % Mod;
	inv[n + 1] = Power(fac[n + 1], Mod - 2);
	for (int i = n + 1; i >= 1; -- i) inv[i - 1] = 1ll * inv[i] * i % Mod;
	
	for (int i = 0; i <= x; ++ i) a[i] = inv[i + 1];
	int N = 1;
	while (N <= x * 2) N <<= 1;
	Prepare(N);
	
	b[0] = 1;
	for (int k = y; k; k >>= 1)
	{
		if (k & 1)
		{
			copy(a, a + N, c);
			Transform(N, c, wn, 0);
			Transform(N, b, wn, 0);
			for (int i = 0; i < N; ++ i)
				b[i] = 1ll * b[i] * c[i] % Mod;
			Transform(N, b, iv, 1);
			fill(b + x + 1, b + N, 0);
		}
		Transform(N, a, wn, 0);
		for (int i = 0; i < N; ++ i)
			a[i] = 1ll * a[i] * a[i] % Mod;
		Transform(N, a, iv, 1);
		fill(a + x + 1, a + N, 0);
	}
	
	int ans = 0;
	for (int i = 0; i <= x; ++ i) Chkadd(ans, b[i]);
	ans = 1ll * ans * fac[x] % Mod * fac[n] % Mod * fac[y] % Mod;
	
	printf("%d\n", ans);
	return 0;
}
