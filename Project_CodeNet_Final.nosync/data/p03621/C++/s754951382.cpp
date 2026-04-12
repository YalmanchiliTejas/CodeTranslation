#include <bits/stdc++.h>
using namespace std;
const int N = 20000;
const int MOD = 998244353;
char A[N], B[N];
int n, X, Y, ans;
int powi(int a, int b)
{
    int c = 1;
    for (; b; b >>= 1, a = 1ll * a * a % MOD)
        if (b & 1) c = 1ll * c * a % MOD;
    return c;
}
int fac[N], inv[N];
struct poly
{
    int d[N];
    poly () {memset(d, 0, sizeof d);}
} P, Q;
int L;

int tmpA[N * 4], tmpB[N * 4];
void NTT(int A[], int n, int fl)
{
	for (int i = 1; i < n; ++ i)
	{
		int d = 0;
		for (int j = 1, k = n >> 1; k; j <<= 1, k >>= 1)
			if (i & j) d |= k;
		if (d < i) swap(A[d], A[i]);
	}
	for (int i = 2; i <= n; i <<= 1)
	{
		int w0 = powi(3, (MOD - 1) / i);
		if (fl < 0) w0 = powi(w0, MOD - 2);
		for (int j = 0; j < n; j += i)
		{
			int w = 1;
			for (int k = j; k < j + (i >> 1); ++ k)
			{
				int u = A[k], v = 1ll * A[k + (i >> 1)] * w % MOD;
				A[k] = (u + v) % MOD; A[k + (i >> 1)] = (u - v + MOD) % MOD;
				w = 1ll * w * w0 % MOD;
			}
		}
	}
	if (fl < 0)
    {
        int inv = powi(n, MOD - 2);
        for (int i = 0; i < n; ++ i) A[i] = 1ll * A[i] * inv % MOD;
    }
}

poly operator * (const poly &a, const poly &b)
{
    poly c;
    int nn = 1; while (nn <= L) nn *= 2; nn *= 2;
    for (int i = 0; i < L; ++ i) tmpA[i] = a.d[i]; for (int i = L; i < nn; ++ i) tmpA[i] = 0;
    for (int i = 0; i < L; ++ i) tmpB[i] = b.d[i]; for (int i = L; i < nn; ++ i) tmpB[i] = 0;
    NTT(tmpA, nn, 1); NTT(tmpB, nn, 1);
    for (int i = 0; i < nn; ++ i) tmpA[i] = 1ll * tmpA[i] * tmpB[i] % MOD;
    NTT(tmpA, nn, -1);
    for (int i = 0; i < L; ++ i) c.d[i] = tmpA[i];
    return c;
}
poly operator ^ (poly a, int b)
{
    poly c; c.d[0] = 1;
    for (; b; b >>= 1, a = a * a)
        if (b & 1) c = c * a;
    return c;
}
int C(int a, int b)
{
    return 1ll * fac[a] * inv[b] % MOD * inv[a - b] % MOD;
}
int main()
{
    scanf("%s%s", A, B); n = strlen(A);
    for (int i = 0; i < n; ++ i)
        if (A[i] == '1' && B[i] == '1') X ++;
        else if (A[i] == '1') Y ++;
    fac[0] = 1;
    for (int i = 1; i < N; ++ i) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = powi(fac[N - 1], MOD - 2);
    for (int i = N - 2; ~i; -- i) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;

    L = X + Y + 1;
    for (int i = 1; i < L; ++ i) P.d[i] = inv[i];
    Q = P ^ Y;
    for (int i = 0; i < L; ++ i) P.d[i] = 1;
    Q = Q * P;
    ans = 1ll * Q.d[X + Y] * fac[X] % MOD * fac[Y] % MOD * fac[X + Y] % MOD;
    printf("%d\n", ans);
}
