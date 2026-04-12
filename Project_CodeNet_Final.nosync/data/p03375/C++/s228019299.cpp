#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl

const int N=5000;

int MOD;

int Mul(int a,int b)
{
	unsigned long long x=(long long)a*b;
	unsigned xh=(unsigned)(x>>32),xl=(unsigned)x,d,m;
	asm
		(
		 "divl %4;\n\t"
		 :"=a"(d),"=d"(m)
		 :"d"(xh),"a"(xl),"r"(MOD)
		);
	return m;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int& x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,x=Mul(x,x))if(y&1)
		res=Mul(res,x);
	return res;
}

int n,C[N][N],S[N][N],ppw[N],pw[N];

void Prework()
{
	for(int i=0;i<=n;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=U(C[i-1][j-1],C[i-1][j]);
	}
	S[0][0]=1;
	for(int i=1;i<=n+1;++i)
		for(int j=1;j<=i;++j)
			S[i][j]=U(S[i-1][j-1],Mul(j,S[i-1][j]));
	pw[0]=1;
	for(int i=1;i<=n;++i)
		pw[i]=U(pw[i-1],pw[i-1]);
	ppw[0]=2;
	for(int i=1;i<=n;++i)
		ppw[i]=Mul(ppw[i-1],ppw[i-1]);
}

int main()
{
	scanf("%d%d",&n,&MOD);
	Prework();
	int ans=0;
	for(int i=0,sum;i<=n;++i)
	{
		sum=0;
		for(int k=0;k<=i;++k)
			SU(sum,Mul(Qpow(pw[n-i],k),S[i+1][k+1]));
		if(i&1)
			SU(ans,MOD-Mul(C[n][i],Mul(ppw[n-i],sum)));
		else
			SU(ans,Mul(C[n][i],Mul(ppw[n-i],sum)));
	}
	printf("%d",ans);
	return 0;
}
