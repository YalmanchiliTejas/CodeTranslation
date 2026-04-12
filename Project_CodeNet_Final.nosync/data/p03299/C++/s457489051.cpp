#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 0x3f3f3f3f
#define mod 1000000007
#define maxn 200010
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
int a[maxn];
int n;
ll power(ll a,ll b)
{
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)ans=ans*a%mod;
	return ans;
}
void solve(int l,int r,ll& f,ll& g)
{
	int mn=a[l],mx=a[l];
	for(int i=l+1;i<=r;i++){
		mx=std::max(mx,a[i]);
		mn=std::min(mn,a[i]);
	}
	for(int i=l;i<=r;i++)
		a[i]-=mn;
	if(mx==mn){
		f=(power(2,r-l+1)+mod-2)%mod;
		g=power(2,mn);
		return;
	}
	ll mul1=1,mul2=1;
	int last=l,cnt=0;
	for(int i=l;i<=r;i++)
		if(a[i]&&(!a[i+1]||i==r)){
			ll tf=0,tg=0;
			solve(last,i,tf,tg);
			mul1=mul1*(tf+2*tg)%mod;
			mul2=mul2*tg%mod;
		}
		else if(!a[i]){
			last=i+1;
			++cnt;
		}
	f=(power(2,cnt)*mul1-2*mul2+2*mod)%mod;
	g=power(2,mn)*mul2%mod;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	ll f=0,g=0;
	solve(1,n,f,g);
	writeln((f+g)%mod);
	return 0;
}