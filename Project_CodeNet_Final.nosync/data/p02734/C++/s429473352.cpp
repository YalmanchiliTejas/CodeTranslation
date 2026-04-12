// Etavioxy
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<cmath>
#define il inline
#define ll long long
#define rep(i,s,t) for(register int i=(s);i<=(t);i++)
#define rev_rep(i,s,t) for(register int i=(s);i>=(t);i--)
#define each(i,u) for(int i=head[u];i;i=bow[i].nxt)
#define file(s) freopen(s".in" ,"r",stdin),freopen(s".out","w",stdout)
#define pt(x) putchar(x)
using namespace std;
il int ci(){
	register char ch;int f=1;
	while(!isdigit(ch=getchar()))f=ch=='-'?-1:1;
	register int x=ch^'0';
	while(isdigit(ch=getchar()))x=(x*10)+(ch^'0');
	return f*x;
}

const int mod = 998244353;
enum{N=3023};

ll f[N];
int main(){
	int n=ci(), s=ci();
	ll ans = 0;
	rep(i,1,n){
		int x=ci();
		if( x>s ) continue;
		ans = (ans+(n-i+1)*(f[s-x]+(x==s?i:0)))%mod;
		rev_rep(j,s,x) f[j] = (f[j]+f[j-x])%mod;
		f[x] = (f[x]+i)%mod;
	}
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}
