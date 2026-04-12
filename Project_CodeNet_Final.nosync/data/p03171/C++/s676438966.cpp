#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL memo[3005][3005][2];
LL datas[3005];
const LL INF=1e15;
LL solve(int L, int R, bool con)
{
	if(L>R) return 0;
	if(memo[L][R][con]!=-INF) return memo[L][R][con];
	if(!con)
	{
		return memo[L][R][con]=max(datas[L]+solve(L+1, R, con^1), datas[R]+solve(L, R-1, con^1));
	}
	else
	{
		return memo[L][R][con]=min(solve(L+1, R, con^1)-datas[L], solve(L, R-1, con^1)-datas[R]);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int a=1;a<=n;a++)
	{
		scanf("%lld", &datas[a]);
	}
	for(int a=1;a<=n;a++)
	{
		for(int b=1;b<=n;b++)
		{
			memo[a][b][0]=-INF;
			memo[a][b][1]=-INF;
		}
	}
	printf("%lld\n", solve(1, n, 0));
	return 0;
}