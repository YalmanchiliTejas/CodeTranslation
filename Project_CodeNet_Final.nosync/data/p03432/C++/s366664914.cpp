#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 8005;
const int MAXM = 205;
const ll MOD = 998244353;
const ll g = 3;

int n,m,N;
int rev[MAXN << 2];

ll ans,Inv;
ll fac[MAXN];
ll inv[MAXN];
ll f[2][MAXN];
ll a[MAXN << 2];
ll b[MAXN << 2];
ll c[MAXN << 2];
ll wn[2][MAXN << 2];

ll power(ll a,ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			(res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}

void init()
{
	fac[0] = 1;
	for (int i = 1;i <= n;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[n] = power(fac[n],MOD - 2);
	for (int i = n;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
	N = 1;
	while (N < (n << 1))
		N <<= 1;
	Inv = power(N,MOD - 2);
	int half = N >> 1;
	for (int i = 1;i < N;i++)
		rev[i] = (rev[i >> 1] >> 1) + (i & 1) * half;
	for (int i = 0;i < half;i++)
	{
		wn[0][i + half] = power(g,(MOD - 1) * i / N);
		wn[1][i + half] = power((MOD + 1) / g,(MOD - 1) * i / N);
	}
	for (int i = half - 1;i >= 0;i--)
	{
		wn[0][i] = wn[0][i << 1];
		wn[1][i] = wn[1][i << 1];
	}
}

void NTT(ll *v,bool inv)
{
	for (int i = 0;i < N;i++)
		if (i < rev[i])
			swap(v[i],v[rev[i]]);
	for (int i = 1;i < N;i <<= 1)
		for (int j = 0;j < N;j += i << 1)
		{
			ll *l = v + j,*r = v + j + i,*w = wn[inv] + i,A;
			for (int k = 0;k < i;k++,l++,r++,w++)
			{
				A = *r * *w;
				*r = (*l - A) % MOD;
				*l = (*l + A) % MOD;
			}
		}
	if (inv)
	{
		for (int i = 0;i < N;i++)
			(v[i] *= Inv) %= MOD;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	init();
	f[0][0] = 1;
	for (int i = 1;i <= m;i++)
	{
		memset(f[i & 1],0,sizeof(f[i & 1]));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for (int j = 0;j <= n - 2;j++)
		{
			a[j] = inv[j + 2];
			b[j] = inv[j] * (f[~i & 1][j] + f[~i & 1][j + 1] * 2 + f[~i & 1][j + 2]) % MOD;
		}
		NTT(a,0);
		NTT(b,0);
		for (int j = 0;j < N;j++)
			c[j] = a[j] * b[j] % MOD;
		NTT(c,1);
		for (int j = 0;j <= n;j++)
		{
			f[i & 1][j] = (f[~i & 1][j] + j * (f[~i & 1][j - 1] + f[~i & 1][j])) % MOD;
			if (j >= 2)
				(f[i & 1][j] += fac[j] * c[j - 2]) %= MOD;
		}
	}
	for (int i = 0;i <= n;i++)
		(ans += f[m & 1][i] * fac[n] % MOD * inv[i] % MOD * inv[n - i]) %= MOD;
	printf("%lld\n",(ans + MOD) % MOD);
	return 0;
}
