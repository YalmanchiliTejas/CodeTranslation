#include<iostream>
#include<cstring>
#include<cstdio>
#define LL long long
using namespace std;
int n,m;
LL ans;
const int N=8010,M=210,mod=998244353,G=3,Ginv=(mod+1)/3;
int r[N<<2];
LL jc[N],inv[N],f[N][M],A[N<<2],B[N<<2];
LL ksm(LL a,LL b,LL mod)
{
	LL res=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)res=res*a%mod;
	return res;
}
namespace Poly
{
	void NTT(LL *A,int lim,int opt)
	{
		for(int i=0;i<lim;++i)r[i]=(r[i>>1]>>1)|(i&1?lim>>1:0);
		for(int i=0;i<lim;++i)
			if(i<r[i])swap(A[i],A[r[i]]);
		for(int mid=1;mid<lim;mid<<=1)
		{
			LL wn=ksm(opt==1?G:Ginv,(mod-1)/(mid<<1),mod);
			for(int j=0;j<lim;j+=(mid<<1))
			{
				LL w=1;
				for(int k=j;k<j+mid;++k,w=w*wn%mod)
				{
					LL x=A[k],y=w*A[k+mid]%mod;
					A[k]=(x+y)%mod;A[k+mid]=(x-y+mod)%mod;
				}
			}
		}
		if(opt==1)return;
		int ni=ksm(lim,mod-2,mod);
		for(int i=0;i<lim;++i)A[i]=A[i]*ni%mod;
	}
	void MUL(LL *A,int n,LL *B,int m)
	{
		int lim=1;
		while(lim<=(n+m))lim<<=1;
		NTT(A,lim,1);NTT(B,lim,1);
		for(int i=0;i<lim;++i)A[i]=A[i]*B[i]%mod;
		NTT(A,lim,-1);
	}
}
void YYCH(int n)
{
	jc[0]=jc[1]=inv[0]=inv[1]=1;
	for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%mod;
	inv[n]=ksm(jc[n],mod-2,mod);
	for(int i=n-1;i>=1;--i)inv[i]=inv[i+1]*(i+1)%mod;
}
LL C(int n,int m){return jc[n]*inv[m]%mod*inv[n-m]%mod;}
void solve(int j)
{
	memset(A,0,sizeof(A));memset(B,0,sizeof(B));
	for(int i=1;i<=n;++i)A[i]=inv[i+2];
	for(int i=0;i<=n;++i)B[i]=f[i][j-1]*inv[i]%mod;
	Poly::MUL(A,n+1,B,n+1);
	for(int i=0;i<=n;++i)f[i][j]=f[i][j-1]*(1+i+i*(i-1)/2)%mod;
	for(int i=1;i<=n;++i)f[i][j]=(f[i][j]+A[i]*jc[i+2])%mod;
}
int main()
{
	cin>>n>>m;YYCH(n+2);
	f[0][0]=1;
	for(int i=1;i<=m;++i)solve(i);
	for(int i=0;i<=n;++i)(ans+=C(n,i)*f[i][m])%=mod;
	cout<<ans;
	return 0;
}