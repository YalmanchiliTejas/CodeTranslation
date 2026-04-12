#include<cstdio>

#include<cstring>

#include<cmath>

#include<ctime>

#include<cstdlib>

#include<string>
#include<assert.h>

#include<queue>

#include<stack>

#include<bitset>

#include<algorithm>

#define pr pair<int,int>

#define FR first

#define SE second

#define MP make_pair

#define PB push_back
#define fo(i,l,r) for(register int i=(l),I=(r);i<=I;i++)
#define fd(i,l,r) for(register int i=(l),I=(r);i>=I;i--)

namespace mine

{

	typedef long long ll;

	ll qread()

	{

		ll ret=0,f=1;char c=getchar();

		while(c<'0' or c>'9'){if(c=='-')f=-1;c=getchar();}

		while('0'<=c and c<='9') ret=ret*10+c-'0',c=getchar();return ret*f;

	}

	void write(ll num){if(num<0)putchar('-'),num=-num;if(num>=10)write(num/10);putchar('0'+num%10);}

	void write1(ll num){write(num);putchar(' ');}

	void write2(ll num){write(num);putchar('\n');}

	

	const int MOD=998244353;

	ll qpower(ll x,ll e,const ll mod=MOD)	{assert(e>=0);ll ans=1;while(e){if(e&1)ans=ans*x%mod;x=x*x%mod;e>>=1;}return ans;}

	ll invm(ll x,const ll mod=MOD){return qpower(x,mod-2,mod);}

	template<typename T> void add(T &x,const int y){x=(x+y<MOD?x+y:x+y-MOD);}


	const int N=1e7+10;

	ll fac[N],facinv[N],inv[N];ll C(int n,int m){return n<m?0:fac[n]*facinv[m]%MOD*facinv[n-m]%MOD;}

    void main()

	{
		inv[1]=1;fo(i,2,N-1) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;

        fac[0]=1;fo(i,1,N-1) fac[i]=fac[i-1]*i%MOD;
		facinv[N-1]=invm(fac[N-1]);fd(i,N-1,1) facinv[i-1]=facinv[i]*i%MOD;

        int n=qread(),ans=0;
		ll down=1;fo(i,n-n/2+1,n) down=down*i%MOD;
		ll now=0;fo(y,0,n/2) add(now, C(n-n/2,y) );

        for(int x=n/2;x>=0;x--)
		{
			add(ans, down*now%MOD*facinv[x]%MOD );
			down=down*inv[n-x+1]%MOD;now=(now*2+MOD-C(n-x,n/2))%MOD;
		}write(ans);

	}

};

int main()

{
	//freopen("z.txt","r",stdin);
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);

	srand(time(0));

	mine::main();

}



