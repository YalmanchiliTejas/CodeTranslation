#include<iostream>
#include<cstdio>
#include<cstring>

namespace test
{
	typedef long long ll;
	const int N=10005,M=N*6,MOD=998244353;
	inline void inc(int a,int &b){b=(a+b)%MOD;}

	ll inv(int x){return x==1?1:(-(MOD/x)*inv(MOD%x)%MOD);}
	ll qpow(ll a,ll b){ll c=1;for(;b;b>>=1,a=a*a%MOD)if(b&1)c=c*a%MOD;return c;}

	int dec[M];
	void getdec(int n){for(int i=1;i<n;i++)dec[i]=(dec[i>>1]>>1)+(i&1?n>>1:0);}
	void ntt(int *y,int n,int rag)
	{
		for(int i=0;i<n;i++)if(i<dec[i])std::swap(y[i],y[dec[i]]);

		int *y0,*y1,ny0,ny1;

		for(int len=2;len<=n;len<<=1)
		{
			int delta=qpow(3,(MOD-1)/len),h=len>>1,x;

			if(rag<0)delta=(inv(delta)+MOD)%MOD;

			for(int p=0;p<n;p+=len)
			{
				y0=y+p,y1=y0+h,x=1;
				for(int i=0;i<h;i++,x=(ll)x*delta%MOD)
				{
					ny0=(y0[i]+(ll)x*y1[i])%MOD;
					ny1=(y0[i]-(ll)x*y1[i])%MOD;
					y0[i]=ny0;
					y1[i]=ny1;
				}
			}
		}
	}

	int fact[N],ifact[N];

	void initialize()
	{
		fact[0]=1;
		for(int i=1;i<N;i++)fact[i]=(ll)fact[i-1]*i%MOD;
		ifact[N-1]=(inv(fact[N-1])+MOD)%MOD;
		for(int i=N-1;i;i--)ifact[i-1]=(ll)ifact[i]*i%MOD;
	}

	int g[M],f[M];

	void mul(int *u,int *v,int len)
	{
		static int A[M],B[M],C[M];

		int n=len*2;
		memcpy(A,u,len*4),memcpy(B,v,len*4);
		for(int i=len;i<n;i++)A[i]=B[i]=0;
		
		ntt(A,n,1),ntt(B,n,1);
		for(int i=0;i<n;i++)C[i]=(ll)A[i]*B[i]%MOD;
		ntt(C,n,-1);

		int dn=(inv(n)+MOD)%MOD;

		for(int i=0;i<len;i++)
			u[i]=(ll)C[i]*dn%MOD;
	}

	void calc(int k,int n)
	{
		getdec(n*2);

		f[0]=1;
		for(;k;k>>=1,mul(g,g,n))
			if(k&1)mul(f,g,n);
	}

	char s[N],t[N];
	int n,m,x,y;

	void solve()
	{
		initialize();

		scanf("%s",s+1);
		scanf("%s",t+1);

		n=strlen(s+1),x=y=0;

		for(int i=1;i<=n;i++)
			if(s[i]=='1' && t[i]=='1')y++;
			else if(s[i]=='1')x++;


		for(int i=0;i<=y;i++)g[i]=ifact[i+1];

		for(m=1;m<=y;m<<=1);

		calc(x,m);

		int ans=0;
		for(int i=0;i<=y;i++)
			inc(f[i],ans);

		ans=((ll)ans*fact[x]%MOD*fact[y]%MOD*fact[x+y]%MOD+MOD)%MOD;

		printf("%d\n",ans);
	}
}

int main()
{
	test::solve();
	return 0;
}
