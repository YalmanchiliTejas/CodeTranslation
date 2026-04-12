/***************************************************************
	File name: matrix.cpp
	Author: huhao
	Create time: Thu 16 Jan 2020 10:49:45 AM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
#define i64 long long
const int N=32010,mod=998244353;
i64 n,m;
//int g[N][N];
i64 f[N],F[N];
i64 power(i64 a,i64 b,i64 p)
{
	i64 r=1;
	while(b)
	{
		if(b&1) r=r*a%p;
		a=a*a%p; b>>=1;
	}
	return r;
}
i64 inv(i64 a){ return power(a,mod-2,mod); }
namespace C
{
	i64 f[N<<1],F[N<<1],p[N<<1],P[N<<1];
	void init(int n)
	{
		f[0]=p[0]=1;
		fr(i,1,n){ f[i]=f[i-1]*i%mod; p[i]=p[i-1]*2%mod; }
		F[n]=inv(f[n]); P[n]=inv(p[n]);
		fd(i,n,1){ F[i-1]=F[i]*i%mod; P[i-1]=P[i]*2%mod; }
	}
	i64 C(int a,int b){ return a<0||b<0||a-b<0?0:f[a]*F[b]%mod*F[a-b]%mod; }
}
int &Add(int &a,i64 b){ return a=(a+b)%mod; }
i64 &Add(i64 &a,i64 b){ return a=(a+b)%mod; }
const i64 _g=3,G=inv(3);
int l,r[N];
void init(int n)
{
	while((1<<l)<n) l++;
	fr(i,0,(1<<l)-1) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
}
void NTT(i64 *a,int opt)
{
	fr(i,0,(1<<l)-1) if(i<r[i]) std::swap(a[i],a[r[i]]);
	fr(i,0,l-1)
	{
		i64 wn=power(opt==1?_g:G,(mod-1)>>(i+1),mod);
		for(int j=0;j<(1<<l);j+=(1<<(i+1)))
		{
			i64 w=1;
			fr(k,0,(1<<i)-1)
			{
				i64 x=a[j+k],y=w*a[j+k+(1<<i)]%mod;
				a[j+k]=(x+y)%mod; a[j+k+(1<<i)]=(x-y+mod)%mod; w=w*wn%mod;
			}
		}
	}
	if(opt==-1)
	{
		i64 I=inv(1<<l);
		fr(i,0,(1<<l)-1) a[i]=a[i]*I%mod;
	}
}
i64 A[N],B[N];
int main()
{
	n=read(); m=read(); std::swap(n,m); C::init((N-10)*2);
/*	fr(i,0,m)
	{
		g[i][0]=1+i*(i+1)/2;
		fr(j,1,i) Add(g[i][1],j*(i-j+1));
		fr(j,2,i) g[i][j]=((i+3ll)*i+2)*i%mod*C::f[i-1]%mod*C::F[j+2]%mod*C::F[i-j]%mod;
//		fr(j,2,i) fr(l,j,i) Add(g[i][j],((i-l+1)*(i-l+2)*(i-l+3)/6)%mod*C::C(l-2,j-2));
	}*/
	fr(i,0,m) f[i]=C::C(m,i);
//	fr(i,0,m) fr(j,0,i) printf("%d%c",g[i][j],j==i?'\n':' ');
//	fr(j,0,m) printf("%lld%c",f[j],j==m?'\n':' ');
	init(m+m+2);
	fd(i,n,1)
	{
		fr(j,0,m){ F[j]=f[j]; f[j]=f[j]*(1+j*(j+1)/2)%mod*C::f[j]%mod; }
		fr(j,0,(1<<l)-1) A[j]=B[j]=0;
		fr(j,0,m){ A[j]=(1ll*j*j*j+3ll*j*j+2*j)%mod*(j?C::f[j-1]:1)%mod*F[j]%mod; B[j]=C::F[m-j+2]; }
//		fr(j,0,(1<<l)-1) printf("%lld%c",A[j],j==end_j?'\n':' ');
//		fr(j,0,(1<<l)-1) printf("%lld%c",B[j],j==end_j?'\n':' ');
		NTT(A,1); NTT(B,1);
		fr(j,0,(1<<l)-1) A[j]=A[j]*B[j]%mod;
		NTT(A,-1);
//		fr(j,0,(1<<l)-1) printf("%lld%c",A[j],j==end_j?'\n':' ');
//		putchar(10);
		fr(j,0,m) Add(f[j],A[j+m]);
//		fr(j,0,m) fr(k,m-j,m) Add(f[j+k-m],(1ll*j*j*j+3ll*j*j+2*j)%mod*C::f[j-1]%mod*C::F[m-k+2]%mod*F[j]);//g[j][j-k]*F[j]);
//		fr(j,0,m) printf("%lld%c",f[j],j==m?'\n':' ');
		fr(j,0,m) Add(f[j],-(1ll*j*j*j+3ll*j*j+2*j)%mod*(j?C::f[j-1]:1)%mod*C::F[2]%mod*F[j]%mod+mod);
		fr(j,0,m) f[j]=f[j]*C::F[j]%mod;
	}
	printf("%lld\n",f[0]);
	return 0;
}