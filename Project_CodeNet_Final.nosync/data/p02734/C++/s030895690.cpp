#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int Mod=998244353;
void add(int& x,int y)
{
	x+=y;
	if(x>=Mod)x-=Mod;
	return ;
}
int f[3010];
int main()
{
	int n,S;
	scanf("%d %d",&n,&S);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		for(int j=S;j>=x;j--)
			add(f[j],f[j-x]);
		if(x<=S)add(f[x],i);
		add(ans,f[S]);
	}
	printf("%d\n",ans);
	return 0;
}