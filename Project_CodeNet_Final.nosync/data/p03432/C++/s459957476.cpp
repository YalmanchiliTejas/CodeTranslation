#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define p 998244353
using namespace std;

int N,n,m,i,j,k,ans,sum;
int fac[10005],fac_inv[10005],pow2[10005];
int f[10005],a[100005],b[100005];

struct complex
{
	double num,inum;
	complex(double A=0.0,double B=0.0){num=A,inum=B;}
};
complex operator !(const complex &A){return complex(A.num,-A.inum);}
complex operator +(const complex &A,const complex &B){return complex(A.num+B.num,A.inum+B.inum);}
complex operator -(const complex &A,const complex &B){return complex(A.num-B.num,A.inum-B.inum);}
complex operator *(const complex &A,const complex &B){return complex(A.num*B.num-A.inum*B.inum,A.num*B.inum+A.inum*B.num);}
struct Fast_Fourier_Transform
{
	#define size 300005
	#define pi 3.141592653589793238462643383
	
	int N,rev[size];
	complex *W,w[2][size];
	
	void prepare(int n)
	{
		if(N==n)return;
		int i,k,x,y;N=n;
		for(i=0;i<n;++i)
		{
			for(x=i,y=0,k=1;k<n;x>>=1,k<<=1)(y<<=1)|=x&1;
			rev[i]=y;
		}
		for(i=0;i<n;++i)
		{
			w[0][i]=complex(cos(2*pi*i/n),sin(2*pi*i/n));
			w[1][i]=complex(cos(2*pi*i/n),-sin(2*pi*i/n));
		}
	}
	void work(complex *A,int n)
	{
		if(n==1)return;
		int i,j,k,l,t;
		complex x,y;
		for(i=0;i<n;++i)if(i<rev[i])swap(A[i],A[rev[i]]);
		for(i=1;i<n;i<<=1)
		for(j=0,t=n/(i<<1);j<n;j+=i<<1)
		for(k=l=0;k<i;++k,l+=t)
		{
			x=W[l]*A[j+k+i];
			y=A[j+k];
			A[j+k]=y+x;
			A[j+k+i]=y-x;
		}
	}
	
	void DFT(complex *A,int n){prepare(n);W=w[0];work(A,n);}
	void IDFT(complex *A,int n)
	{
		prepare(n);W=w[1];work(A,n);
		for(int i=0;i<n;++i)A[i].num/=n,A[i].inum/=n;
	}
	
	void mult(int n,double *a,double *b,double *c)
	{
		int i,j,k;if(n==1)n=2;
		prepare(n>>1);
		static complex f[size],g[size],t[size];
		for(i=0;i<n;++i)
		if(i&1)f[i>>1].inum=a[i],g[i>>1].inum=b[i];
		else f[i>>1].num=a[i],g[i>>1].num=b[i];
		DFT(f,n>>1);DFT(g,n>>1);
		for(i=0;i<(n>>1);++i)
		{
			j=i?(n>>1)-i:0;
			t[i]=((complex){4,0}*!(f[j]*g[j])-(!f[j]-f[i])*(!g[j]-g[i])*((complex){1,0}+w[0][i]))*(complex){0,0.25};
		}
		IDFT(t,n>>1);
		for(i=0;i<n;++i)c[i]=(i&1)?t[i>>1].num:t[i>>1].inum;
	}
	
	void mult_mod(int n,int *a,int *b,int *c)
	{
		int i,j,k;
		static complex f[size],g[size],t[size],r[size];
		for(i=0;i<n;++i)
		{
			f[i]=complex(a[i]>>15,a[i]&32767);
			g[i]=complex(b[i]>>15,b[i]&32767);
		}
		DFT(f,n);DFT(g,n);
		for(i=0;i<n;++i)
		{
			int j=i?n-i:0;
			t[i]=( (f[i]+!f[j])*(!g[j]-g[i]) + (!f[j]-f[i])*(g[i]+!g[j]) )*(complex){0,0.25};
			r[i]=(!f[j]-f[i])*(!g[j]-g[i])*(complex){-0.25,0} +(complex){0,0.25}*(f[i]+!f[j])*(g[i]+!g[j]);
		}
		IDFT(t,n);IDFT(r,n);
		for(i=0;i<n;++i)c[i]=( (((long long)(t[i].num+0.5))%p<<15) + (long long)(r[i].num+0.5) + (((long long)(r[i].inum+0.5))%p<<30) )%p; 
	}
	
	#undef size
	#undef pi
}FFT;

int C(int n,int m){return (long long)fac[n]*fac_inv[m]%p*fac_inv[n-m]%p;}
int Power(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(long long)a*a%p)if(b&1)ans=(long long)ans*a%p;
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(fac[0]=i=1;i<=n+100;++i)fac[i]=(long long)fac[i-1]*i%p;
	for(i=0;i<=n+100;++i)fac_inv[i]=Power(fac[i],p-2);
	for(i=0;i<=n+100;++i)f[i]=C(n,i);
	for(pow2[0]=i=1;i<=n;++i)pow2[i]=pow2[i-1]*2%p;
	
	for(N=1;N<=n;N<<=1);N<<=1;
	for(;m;--m)
	{
		/*
		for(i=1;i<=n;++i)
		{
			for(k=i;k>=1;--k)
			{
				sum=C(i+2,k+2);
				f[i-k]=(f[i-k]+(long long)sum*f[i])%p;
			}
			f[i]=(f[i]+(long long)f[i]*C(i+1,2))%p;
		}
		*/
		for(i=0;i<N;++i)a[i]=b[i]=0;
		for(i=0;i<=n;++i)a[n-i]=(long long)f[i]*fac[i+2]%p;
		for(i=1;i<=n;++i)b[i]=fac_inv[i+2];
		FFT.mult_mod(N,a,b,a);
		for(i=1;i<=n;++i)f[i]=(f[i]+(long long)f[i]*C(i+1,2))%p;
		for(i=0;i<=n;++i)f[i]=(f[i]+(long long)a[n-i]*fac_inv[i])%p;
	}
	printf("%d\n",f[0]);
}