#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<string.h>
#include<math.h>
#include<cassert>
#include<iomanip>
#include<utility>
#include<bitset>
#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#include<functional>
#include<algorithm>
#include<assert.h>
#include<numeric>
#include<limits.h>
using namespace std;
int n,m;
int a[10],g[10][10];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x-1][y-1]=1;
		g[y-1][x-1]=1;
	}
	for(int i=0;i<n;i++)a[i]=i;
	int ans=0;
	do
	{
		if(a[0]!=0)continue;
		int f=1;
		for(int i=1;i<n;i++)if(g[a[i-1]][a[i]]==0)f=0;
		if(f)ans++;
	}while(next_permutation(a,a+n));
	printf("%d\n",ans);
	return 0;
}