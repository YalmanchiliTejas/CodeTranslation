#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 0x3f3f3f3f
#define mod 998244353
#define maxn 10000010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
inline void write(ll x)
{
	static char buf[20];
	int len=0;
	if(x<0)putchar('-'),x=-x;
	for(;x;x/=10)buf[len++]=x%10+'0';
	if(!len)putchar('0');
	else while(len)putchar(buf[--len]);
}
inline void writesp(ll x){write(x); putchar(' ');}
inline void writeln(ll x){write(x); putchar('\n');}
ll fac[maxn],inv[maxn],p2[maxn],p3[maxn];
int n;
ll C(int n,int m){return (n<0||m<0||m>n)?0:fac[n]*inv[m]%mod*inv[n-m]%mod;}
ll power(ll a,ll b)
{
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)ans=ans*a%mod;
	return ans;
}
int main()
{
	n=read();
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	inv[0]=fac[0]=p2[0]=p3[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
		inv[i]=inv[i-1]*inv[i]%mod;
		p2[i]=p2[i-1]*2%mod; p3[i]=p3[i-1]*3%mod;
	}
	ll ans=p3[n];
	for(int i=n/2+1;i<=n;i++)
		ans=(ans-2*C(n,i)*p2[n-i]%mod+mod)%mod;
	writeln(ans);
	return 0;
}