#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 200000 + 100;
int N, ans[maxn];
struct data { int v, p; }X[maxn];

const int cmp(const data &A, const data &B)
{ return A.v < B.v; }

void Init()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &X[i].v), X[i].p = i;
}

void Solve()
{
	sort(X+1, X+N+1, cmp);
	int mid = N >> 1;
	for(int i = 1; i <= N; ++i)
		if(i <= mid) ans[X[i].p] = X[mid+1].v;
		else ans[X[i].p] = X[mid].v;
	for(int i = 1; i <= N; ++i)
		printf("%d\n", ans[i]);
}

int main()
{
	Init(), Solve();
}