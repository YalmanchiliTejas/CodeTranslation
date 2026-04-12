#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=3010;
ll ksm(ll x,ll y,ll mod) {
	ll res=1;
	while (y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod; y>>=1;
	} return res;
}
int n,c[maxn][maxn],s[maxn][maxn];
ll mod,tmp,ans,cnt,mi[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(mod);
	mi[0]=1;
	for (int i=1;i<=n;i++) mi[i]=mi[i-1]*2%mod;
	s[0][0]=c[0][0]=1;
	for (int i=1;i<=n+1;i++) {
		c[i][0]=1;
		for (int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod,
			s[i][j]=((ll)s[i-1][j]*j+s[i-1][j-1])%mod;
	}
	for (int i=0;i<=n;i++) {
		tmp=c[n][i]*ksm(2,ksm(2,n-i,mod-1),mod)%mod;
		cnt=0;
		for (int j=0;j<=i;j++) {
			cnt=(cnt+(ll)s[i+1][j+1]*ksm(mi[n-i],j,mod))%mod;
		}
		tmp=tmp*cnt%mod;
		if (i&1) ans=ans+mod-tmp;
		else ans+=tmp;
		if (ans>=mod) ans-=mod;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/