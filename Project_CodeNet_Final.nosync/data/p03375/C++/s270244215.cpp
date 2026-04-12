#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<string>

#define maxn 3005

using namespace std;

inline int getint()
{
	int num=0,flag=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;
	while(c>='0'&&c<='9')num=num*10+c-48,c=getchar();
	return num*flag;
}

int MOD;
int n,m,q;
int C[maxn][maxn],S[maxn][maxn];

inline int ksm(int num,int k,int p)
{
	int ret=1;
	for(;k;k>>=1,num=1ll*num*num%p)if(k&1)ret=1ll*ret*num%p;
	return ret;
}

int main()
{
	n=getint(),MOD=getint();
	S[0][0]=C[0][0]=1;
	for(int i=1;i<=n+1;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j])%MOD;
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int tmp=ksm(2,ksm(2,n-i,MOD-1),MOD),ret=0;
		if(i&1)tmp=MOD-tmp;
		tmp=1ll*tmp*C[n][i]%MOD;
		for(int j=0;j<=i;j++)ret=(ret+1ll*ksm(2,(n-i)*j,MOD)*S[i+1][j+1])%MOD;
		tmp=1ll*tmp*ret%MOD;
		ans=(ans+tmp)%MOD;
	}
	printf("%d\n",ans);
}