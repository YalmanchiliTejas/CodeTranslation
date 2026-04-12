#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

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
	#define size 140005
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
	
	void mult(int n,int *a,int *b,int *c,int p)
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

int N,n,m,a,b,i,j,k,ans;
int f[100005],g[100005],fac[100005],fac_inv[100005];
char A[100005],B[100005];

#include <string.h>
#define p 998244353

int Power(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(long long)a*a%p)if(b&1)ans=(long long)ans*a%p;
	return ans;
}

int main()
{
	scanf("%s",A+1);n=strlen(A+1);
	scanf("%s",B+1);
	for(i=1;i<=n;++i)
	if(A[i]=='1')
	{
		if(B[i]=='1')++a;
		else ++b;
	}
	for(fac[0]=i=1;i<=n;++i)fac[i]=(long long)fac[i-1]*i%p;
	for(i=0;i<=n;++i)fac_inv[i]=Power(fac[i],p-2);
	
	m=a+b;
	for(i=0;i<=a;++i)g[i]=(long long)fac_inv[i+1]%p;
	f[0]=1;
	for(N=1;N<=a;N<<=1);N<<=1;
	for(k=b;k;k>>=1)
	{
		if(k&1)FFT.mult(N,f,g,f,p);
		FFT.mult(N,g,g,g,p);
		for(i=a+1;i<N;++i)f[i]=g[i]=0;
	}
	
	for(i=0;i<=a;++i)ans=(ans+(long long)f[i]%p)%p;
	
	ans=(long long)ans*fac[m]%p*fac[b]%p*fac[a]%p;
	printf("%d\n",ans);
}