#include<iostream>
#include<cstring> 
#include<cstdio>
#define MN 8200
#define MM 200
#define mod 998244353
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,f[MM+5][MN+5],p[MN+5],inv[MN+5],w[2][MN*2+5],A[MN*2+5],B[MN*2+5],N,Inv;
inline int C(int n,int m){return m<=n?1LL*p[n]*inv[m]%mod*inv[n-m]%mod:0;}
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}
inline int pow(int x,int k)
{
	int sum=1;
	for(;k;k>>=1,x=1LL*x*x%mod) if(k&1) sum=1LL*sum*x%mod;
	return sum;	
}
void FFT(int*x,int r)
{
	for(int i=0,j=0;i<N;++i)
	{
		if(i>j) swap(x[i],x[j]);
		for(int k=N>>1;(j^=k)<k;k>>=1);	
	}
	for(int i=2;i<=N;i<<=1)for(int j=0;j<N;j+=i)for(int k=0;k<i>>1;++k)
	{
		int t=1LL*w[r][N/i*k]*x[j+k+(i>>1)]%mod;
		x[j+k+(i>>1)]=(x[j+k]-t+mod)%mod;
		x[j+k]=(x[j+k]+t)%mod;
	}
	if(r)for(int i=0;i<N;++i)x[i]=1LL*x[i]*Inv%mod;
}
int main()
{
	n=read();m=read();p[0]=p[1]=inv[0]=inv[1]=1;
	for(N=1;N<=n;N<<=1);N<<=1;Inv=pow(N,mod-2);
	for(int i=2;i<=n+2;++i) p[i]=1LL*p[i-1]*i%mod,inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n+2;++i) inv[i]=1LL*inv[i-1]*inv[i]%mod;
	for(int i=0;i<=n;++i) f[m][i]=C(n,i);int g=pow(3,(mod-1)/N);
	for(int i=0,j=1;i<=N;++i,j=1LL*j*g%mod) w[0][i]=w[1][N-i]=j;
	for(int i=0;i<=n;++i) B[n-i]=inv[i+2];FFT(B,0);
	for(int i=m;i;--i)
	{
		memset(A,0,sizeof(A));
		for(int j=0;j<=n;++j) A[j]=1LL*f[i][j]*p[j+2]%mod;FFT(A,0);
		for(int j=0;j<N;++j) A[j]=1LL*A[j]*B[j]%mod;FFT(A,1);
		for(int j=0;j<=n;++j) f[i-1][j]=1LL*A[n+j]*inv[j]%mod;
		for(int j=0;j<=n;++j) f[i-1][j]=(f[i-1][j]-1LL*f[i][j]*((j+1)*(j+2)/2-(j+1)*j/2-1)%mod+mod)%mod; 
	}
	printf("%d\n",f[0][0]);
	return 0;
}
