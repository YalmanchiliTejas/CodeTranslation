#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

const int MAXN = 40000 + 1000;
const int MOD = 998244353;
const int PRIMITIVE_ROOT = 3;

int n, m;

int fac[MAXN], ifac[MAXN];

int fpow(int x, int p)
{
	int ret = 1;
	for(; p; p >>= 1, x = (long long)x * x % MOD)
		if(p & 1)
			ret = (long long)ret * x % MOD;
	return ret;
}

int inv(int x)
{
	return fpow(x, MOD - 2);
}

void init()
{
	fac[0] = 1;
	for(int i = 1; i < MAXN; i++)
		fac[i] = (long long)fac[i - 1] * i % MOD;
	ifac[MAXN - 1] = inv(fac[MAXN - 1]);
	for(int i = MAXN - 2; i >= 0; i--)
		ifac[i] = (long long)ifac[i + 1] * (i + 1) % MOD;
}


namespace myNTT
{
	int rev[4 * MAXN], w1[4 * MAXN], w2[4 * MAXN];
	void NTT_core(int n, int *a, int *w)
	{
		for(int i = 0; i < n; i++)
			if(rev[i] < i)
				swap(a[rev[i]], a[i]);
		for(int i = 1; i < n; i <<= 1)
			for(int j = 0; j < n; j += 2 * i)
				for(int k = 0; k < i; k++)
				{
					int x = a[j + k], y = (long long)a[j + k + i] * w[i + k] % MOD;
					a[j + k] = (x + y) % MOD;
					a[j + k + i] = (x - y + MOD) % MOD;
				}
	}
	void NTT(int n, int *a)
	{
		NTT_core(n, a, w1);
	}
	void INTT(int n, int *a)
	{
		NTT_core(n, a, w2);
		int tmp = inv(n);
		for(int i = 0; i < n; i++)
			a[i] = (long long)a[i] * tmp % MOD;
	}
	void init(int n)
	{
		int l = log2(n) + 0.5, half = n / 2;
		rev[0] = 0;
		for(int i = 1; i < n; i++)
			rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
		int wn = fpow(PRIMITIVE_ROOT, (MOD - 1) / n);
		w1[half] = 1;
		for(int i = 1; i < half; i++)
			w1[half + i] = (long long)w1[half + i - 1] * wn % MOD;
		for(int i = half - 1; i >= 0; i--)
			w1[i] = w1[i << 1];
		wn = inv(wn);
		w2[half] = 1;
		for(int i = 1; i < half; i++)
			w2[half + i] = (long long)w2[half + i - 1] * wn % MOD;
		for(int i = half - 1; i >= 0; i--)
			w2[i] = w2[i << 1];
	}
	void conv_ntt(int n, int *a, int m, int *b, int *c)
	{
		static int A[4 * MAXN], B[4 * MAXN], C[4 * MAXN];
		int len = 1;
		while(len < n + m - 1) len <<= 1;
		for(int i = 0; i < len; i++) A[i] = B[i] = C[i] = 0;
		for(int i = 0; i < n; i++) A[i] = a[i];
		for(int i = 0; i < m; i++) B[i] = b[i];
		init(len);
		NTT(len, A), NTT(len, B);
		for(int i = 0; i < len; i++)
			C[i] = (long long)A[i] * B[i] % MOD;
		INTT(len, C);
		for(int i = 0; i < n + m - 1; i++)
			c[i] = C[i];
	}
	void conv_force(int n, int *a, int m, int *b, int *c)
	{
		static int C[4 * MAXN];
		for(int i = 0; i < n + m - 1; i++)
			C[i] = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				C[i + j] = (C[i + j] + (long long)a[i] * b[j]) % MOD;
		for(int i = 0; i < n + m - 1; i++)
			c[i] = C[i];
	}
	void conv(int n, int *a, int m, int *b, int *c)
	{
		if((long long)n * m <= 2333)
			conv_force(n, a, m, b, c);
		else
			conv_ntt(n, a, m, b, c);
	}
}



int P[MAXN];

void calc()
{
	using myNTT::conv;

	static int cur[MAXN], ret[MAXN], tmp[MAXN];
	memcpy(cur, P, sizeof(P));
	memset(ret, 0, sizeof(ret)), ret[0] = 1;
	memset(tmp, 0, sizeof(tmp));
	// for(int i = 0; i <= m; i++)
	// 	cerr << cur[i] << ' ';
	// cerr << endl;
	int t = n;
	while(t)
	{
		if(t & 1)
		{
			conv(m + 1, cur, m + 1, ret, tmp);
			memcpy(ret, tmp, (m + 1) * sizeof(tmp[0]));
		}
		conv(m + 1, cur, m + 1, cur, tmp);
		memcpy(cur, tmp, (m + 1) * sizeof(tmp[0]));
		t >>= 1;
	}
	memcpy(P, ret, sizeof(ret));
}

void solve()
{
	for(int i = 0; i <= m; i++)
		P[i] = ifac[i + 1];
	calc();
	int ans = 0;
	for(int i = 0; i <= m; i++)
		ans = (ans + P[i]) % MOD;
	ans = (long long)ans * fac[n] % MOD;
	ans = (long long)ans * fac[m] % MOD;
	ans = (long long)ans * fac[n + m] % MOD;
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	static char s1[MAXN], s2[MAXN];
	
	init();
	cin >> s1 >> s2;
	int len = strlen(s1);
	n = m = 0;
	for(int i = 0; i <= len - 1; i++)
	{
		n += (s1[i] == '1' && s2[i] == '0');
		m += (s1[i] == '1' && s2[i] == '1');
	}

	solve();

	return 0;
}
