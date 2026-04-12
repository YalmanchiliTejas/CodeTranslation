#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 100005
#define INF 0x3f3f3f3f
#define p 1000000007
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int d, cnt, num[MAXN], f[MAXN][105];
char k[MAXN];

int solve(int x, int res, int lead, int lim)
{
	if(x==cnt+1) return ((!lead) && res==0);
	if(f[x][res]!=-1 && !lim && !lead) return f[x][res];
	int temp=0;
	for(rint i=0; i<=(lim?num[x]:9); ++i)
	{
		int t=(res+d*10-i)%d;
		temp=(temp+solve(x+1, t, lead&&(i==0), lim&&(i==num[x])))%p;
	}
	if(!lim && !lead) f[x][res]=temp;
	return temp;
}

int main()
{
	memset(f, -1, sizeof(f));
	scanf("%s%d", k+1, &d);
	cnt=strlen(k+1);
	for(rint i=1; i<=cnt; ++i) num[i]=k[i]-'0';
	printf("%d\n", solve(1, 0, 1, 1));
	return 0;
}