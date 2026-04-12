#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#define MN 801000

int l[MN], r[MN];
long long Min[MN], lazy[MN], f[MN];
typedef std::pair<int, int> P;
std::vector<P> v[MN];

void add(int x, long long v)
{
	lazy[x] += v; Min[x] += v;
}

void pushdown(int x)
{
	if(lazy[x])
	{
		add(x << 1, lazy[x]);
		add(x << 1 | 1, lazy[x]);
		lazy[x] = 0;
	}
}

void build(int x, int L, int R)
{
	l[x] = L; r[x] = R;
	if(L == R) return;
	build(x << 1, L, L + R >> 1);
	build(x << 1 | 1, (L + R >> 1) + 1, R);
}

void modify(int x, int L, int R, long long v)
{
	if(l[x] == L && r[x] == R) {add(x, v); return;}
	pushdown(x); int mid = l[x] + r[x] >> 1;
	if(R <= mid) modify(x << 1, L, R, v);
	else if(L > mid) modify(x << 1 | 1, L, R, v);
	else modify(x << 1, L, mid, v), modify(x << 1 | 1, mid + 1, R, v);
	Min[x] = std::min(Min[x << 1], Min[x << 1 | 1]);
}

long long query(int x, int L, int R)
{
	if(l[x] == L && r[x] == R) return Min[x];
	pushdown(x); int mid = l[x] + r[x] >> 1;
	if(R <= mid) return query(x << 1, L, R);
	else if(L > mid) return query(x << 1 | 1, L, R);
	else return std::min(query(x << 1, L, mid), query(x << 1 | 1, mid + 1, R));
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	
	long long sum = 0;
	for(int i = 1; i <= m; i++)
	{
		int l, r, a; scanf("%d%d%d", &l, &r, &a);
		v[r].push_back(P(l, a));
		sum += a;
	}
	
	build(1, 0, n);
	
	for(int i = 1; i <= n + 1; i++)
	{
		f[i] = query(1, 0, i - 1);
		if(i != n + 1) modify(1, i, i, f[i]);
		int S = v[i].size();
		for(int j = 0; j < S; j++)
		{
			modify(1, 0, v[i][j].first - 1, v[i][j].second);
		}
	}
	
	printf("%lld\n", sum - f[n + 1]);
}