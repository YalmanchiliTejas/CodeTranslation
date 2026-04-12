#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define Mod 1000000007
using namespace std;
int fpow(int a,int b)
{
	int ans=1,t=a;
	while(b)
	{
		if(b&1)ans=(long long)ans*t%Mod;
		t=(long long)t*t%Mod;
		b>>=1;
	}
	return ans;
}
//2^a+...+2^{b-1}
int solve(int a,int b)
{
	return (fpow(2,b)-fpow(2,a)+Mod)%Mod;
}
int h[110],H[110];
int f[110][110];
void add(int& x,int y)
{
	x+=y;
	if(x>=Mod)x-=Mod;
	return ;
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		H[i]=h[i];
	}
	H[0]=1;
	sort(H,H+n+1);int N=unique(H,H+n+1)-H;
	for(int i=1;i<=n;i++)
		h[i]=lower_bound(H,H+N,h[i])-H;
	f[0][1]=1;
	for(int i=1;i<=n;i++)
	{
		if(h[i]<=h[i-1]){
			for(int j=1;j<=h[i-1]+1;j++)
				if(j>h[i])add(f[i][h[i]+1],f[i-1][j]*2%Mod);
				else add(f[i][j],f[i-1][j]);
		}
		else{
			for(int j=1;j<=h[i-1];j++)
				add(f[i][j],(long long)f[i-1][j]*fpow(2,H[h[i]]-H[h[i-1]])%Mod);
			for(int j=h[i-1]+1;j<=h[i];j++)
				add(f[i][j],(long long)f[i-1][h[i-1]+1]*solve(H[h[i]]-H[j],H[h[i]]-H[j-1])*2%Mod);
			add(f[i][h[i]+1],f[i-1][h[i-1]+1]*2%Mod);
		}
//		printf("%d:",i);
//		for(int j=1;j<=h[i]+1;j++)
//			printf("%d ",f[i][j]);
//		printf("\n");
	}
	int ans=0;
	for(int i=1;i<=h[n]+1;i++)
		add(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}