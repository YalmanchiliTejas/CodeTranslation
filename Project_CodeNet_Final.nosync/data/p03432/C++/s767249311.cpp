#include<iostream>
#include<cstdio>
#include<cstring>

namespace bf
{
	typedef long long ll;
	const int N=8010,M=203,MOD=998244353;
	inline void inc(int a,int &b){b=(a+b)%MOD;}
	ll inv(int x){return x==1?1:(-(MOD/x)*inv(MOD%x)%MOD);}
	ll qpow(ll a,ll b){ll c=1;for(;b;b>>=1,a=a*a%MOD)if(b&1)c=c*a%MOD;return c;}

	int dec[N*4];
	void getdec(int n){for(int i=1;i<n;i++)dec[i]=(dec[i>>1]>>1)+(i&1?n>>1:0);}
	void ntt(int *y,int n,int rag)
	{
		for(int i=0;i<n;i++)
			if(i<dec[i])std::swap(y[i],y[dec[i]]);

		int *y0,*y1,ny0,ny1;
		for(int len=2;len<=n;len<<=1)
		{
			int delta=qpow(3,(MOD-1)/len),h=len>>1,x;
			if(rag<0)delta=inv(delta);

			for(int p=0;p<n;p+=len)
			{
				y0=y+p,y1=y0+h,x=1;
				for(int i=0;i<h;i++)
				{
					ny0=(y0[i]+(ll)x*y1[i])%MOD;
					ny1=(y0[i]-(ll)x*y1[i])%MOD;
					y0[i]=ny0,y1[i]=ny1;
					x=(ll)x*delta%MOD;
				}
			}
		}
	}
	void mul(int *A,int *B,int n)
	{
		getdec(n);
		ntt(A,n,1),ntt(B,n,1);
		for(int i=0;i<n;i++)A[i]=(ll)A[i]*B[i]%MOD;
		ntt(A,n,-1);
		int x=inv(n);
		for(int i=0;i<n;i++)A[i]=(ll)A[i]*x%MOD;
	}

	int fact[N],ifact[N];
	int C(int n,int m){if(n<m)return 0;return (ll)fact[n]*ifact[m]%MOD*ifact[n-m]%MOD;}

	int n,m;
	void initialize()
	{
		scanf("%d%d",&n,&m);

		fact[0]=1;
		for(int i=1;i<N;i++)fact[i]=(ll)fact[i-1]*i%MOD;
		ifact[N-1]=inv(fact[N-1]);
		for(int i=N-1;i;i--)ifact[i-1]=(ll)ifact[i]*i%MOD;
	}

	int f[M][N];
	void dp()
	{
		static int A[N*4],B[N*4];
		f[0][0]=1;
		for(int i=1;i<=m;i++)
		{
			int tot;
			for(tot=1;tot<=n+n+2;tot<<=1);
			memset(A,0,tot*4),memset(B,0,tot*4);
			for(int j=0;j<=n;j++)A[j]=(ll)f[i-1][j]*ifact[j]%MOD;
			for(int j=3;j<=n+2;j++)B[j]=ifact[j];

			mul(A,B,tot);

			for(int j=0;j<=n;j++)f[i][j]=(ll)fact[j+2]*A[j+2]%MOD;

			for(int j=0;j<=n;j++)
			{
//				for(int l=0;l<j;l++)
//					inc((ll)f[i-1][l]*C(j+2,l)%MOD,f[i][j]);
				inc((ll)f[i-1][j]*(1+C(j+1,2))%MOD,f[i][j]);
			}
		}
	}

	int getans()
	{
		int ret=0;
		for(int i=0;i<=n;i++)
			inc((ll)f[m][i]*C(n,i)%MOD,ret);
		return (ret+MOD)%MOD;
	}

	void solve()
	{
		initialize();
		dp();
		printf("%d\n",getans());
	}
}

int main()
{
	bf::solve();
	return 0;
}
