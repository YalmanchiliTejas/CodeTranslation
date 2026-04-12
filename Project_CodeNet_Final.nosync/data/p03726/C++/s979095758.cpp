#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100000 + 1000;

int n, a, b;
int F[N], v[N << 1], nex[N << 1], EID = 1;
int f[N], g[N], d[N];

inline int read()
{
	int a = 0;
	char ch;
	int f = 1;
	while(!((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-')));
	if(ch == '-')
		f = -1;
	else
	{
		a = a * 10;
		a += ch - '0';
	}
	while((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-'))
	{
		a = a * 10;
		a += ch - '0';
	}
	return a * f;
}

inline void add(int f, int t)
{
	nex[EID] = F[f];
	v[EID] = t;
	F[f] = EID++;
}

inline void rd(int &x)
{
	x = read();
}

inline void wr()
{
	a = read(), b = read();
	add(a, b);
	add(b, a);
	++d[a], ++d[b];
}

inline void dp(int x, int fa)
{
	
	g[x] = 1, f[x] = 0;
	for(int i = F[x];i;i = nex[i])
	{
		int t = v[i];
		if(t == fa)
			continue;
		dp(t, x);
		g[x] &= f[t];
		f[x] |= g[t];
	}
}

inline void ch(int x, int fa)
{
	if(g[x] == 1)
	{
		printf("First\n");
		exit(0);
	}
	int of = f[x], og = g[x];
	for(int i = F[x];i;i = nex[i])
	{
		int t = v[i];
		if(t == fa)
			continue;
		int uf = f[t], ug = g[t];
		f[x] = 0, g[x] = 1;
		for(int j = F[x];j;j = nex[j])
		{
			int t1 = v[j];
			if(t1 == fa || t1 == t)
				continue;
			f[x] |= g[t1];
			g[x] &= f[t1];
		}
		f[t] |= g[x], g[t] &= f[x];
		ch(t, x);
		f[t] = uf, g[t] = ug;
	}
	f[x] = of, g[x] = og;
}

int main()
{
	rd(n);
	for(int i = 1;i < n;++i)
		wr();
	dp(1, -1);
	ch(1, -1);
	printf("Second\n");
	return 0;
} 