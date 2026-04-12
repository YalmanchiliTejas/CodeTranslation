#include <bits/stdc++.h>
#define N 11
using namespace std;
int  n,m,x,y,ans,a[N],f[N][N],v[N];
int pd()
{
	for(int i=1;i<n;i++)if(!f[a[i]][a[i+1]])return 0;
	return 1;
}
void so(int x)
{
	if(x>n)ans+=pd();
	for(int i=2;i<=n;i++)if(!v[i]){
		a[x]=i;v[i]=1;
		so(x+1);v[i]=0;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&x,&y),f[x][y]=f[y][x]=1;
	a[1]=1;so(2);printf("%d",ans);
}