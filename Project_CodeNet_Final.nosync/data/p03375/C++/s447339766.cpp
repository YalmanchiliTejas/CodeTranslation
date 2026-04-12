//by achhhy
#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
inline int in()
{
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return f*x;
}

//need changing
const int inf=(1<<30);
const int N=3010;
const int M=3000;
LL n,mod;
LL S[N][N],f[N],fac[N],inv[N],mi[N*N];
LL ksm(LL a,LL b,LL p)
{
	LL ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ret;
}

LL C(LL a,LL b)
{
	return fac[a]*inv[b]%mod*inv[a-b]%mod;
}


int main()
{
	n=in(),mod=in();
	fac[0]=inv[0]=mi[0]=1;
	rep(i,1,M*M) mi[i]=mi[i-1]*2%mod;
	rep(i,1,M) fac[i]=fac[i-1]*i%mod;
	inv[M]=ksm(fac[M],mod-2,mod);
	per(i,M-1,1) inv[i]=inv[i+1]*(i+1)%mod;
	rep(i,0,M) S[i][0]=1;
	rep(i,1,M) rep(j,1,i) S[i][j]=(S[i-1][j-1]+S[i-1][j]*(j+1))%mod;
	rep(i,0,n)
	{
		rep(j,0,i) (f[i]+=S[i][j]*mi[(n-i)*j])%=mod;
		f[i]=f[i]*ksm(2,ksm(2,n-i,mod-1),mod)%mod;
	}
	LL ans=0;
	rep(i,0,n) (ans+=(i&1?-1ll:1ll)*C(n,i)*f[i]%mod)%=mod;
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}
