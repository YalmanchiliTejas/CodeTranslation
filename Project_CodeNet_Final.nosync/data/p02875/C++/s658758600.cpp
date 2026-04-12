#include<cstdio>
#include<algorithm>
#define RI register int
#define CI const int&
using namespace std;
const int N=1e7+5,mod=998244353;
int n,ret,fact[N],inv[N],pw[N];
inline void inc(int& x,CI y)
{
	if ((x+=y)>=mod) x-=mod;
}
inline int quick_pow(int x,int p=mod-2,int mul=1)
{
	for (;p;p>>=1,x=1LL*x*x%mod) if (p&1) mul=1LL*mul*x%mod; return mul;
}
inline void init(CI n)
{
	RI i; for (fact[0]=i=1;i<=n;++i) fact[i]=1LL*fact[i-1]*i%mod;
	for (inv[n]=quick_pow(fact[n]),i=n-1;~i;--i) inv[i]=1LL*inv[i+1]*(i+1)%mod;
	for (pw[0]=i=1;i<=n;++i) pw[i]=2LL*pw[i-1]%mod;
}
inline int C(CI n,CI m)
{
	return 1LL*fact[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
	RI i,j; for (scanf("%d",&n),init(n),i=(n>>1)+1;i<=n;++i)
	inc(ret,1LL*C(n,i)*pw[n-i+1]%mod);
	return printf("%d",(quick_pow(3,n)-ret+mod)%mod),0;
}