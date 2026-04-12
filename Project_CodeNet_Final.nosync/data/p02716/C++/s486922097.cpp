#include<bits/stdc++.h>
#define del(a,i) memset(a,i,sizeof(a))
#define ll long long
#define inl inline
#define il inl void
#define it inl int
#define ill inl ll
#define re register
#define ri re int
#define rl re ll
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define INF 0x3f3f3f3f
using namespace std;
template<class T>il read(T &x){
	int f=1;char k=getchar();x=0;
	for(;k>'9'||k<'0';k=getchar()) if(k=='-') f=-1;
	for(;k>='0'&&k<='9';k=getchar()) x=(x<<3)+(x<<1)+k-'0';
	x*=f;
}
template<class T>il _print(T x){
	if(x/10) _print(x/10);
	putchar(x%10+'0');
}
template<class T>il print(T x){
	if(x<0) putchar('-'),x=-x;
	_print(x);
}
ll mul(ll a,ll b,ll mod){long double c=1.;return (a*b-(ll)(c*a*b/mod)*mod)%mod;}
it qpow(int x,int m,int mod){
	int res=1,bas=x;
	while(m){
		if(m&1) res=(1ll*res*bas)%mod;
		bas=(1ll*bas*bas)%mod,m>>=1;
	}
	return res;
}
const int N = 2e5+5;
const ll inf = 1e18;
int n,val[N];
ll f[N][3];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n);
	for(ri i=1;i<=n;++i) read(val[i]);
	for(ri i=0;i<=n;++i) for(ri j=0;j<=2;++j) f[i][j]=-inf;
	f[0][0]=0,f[1][0]=val[1];
	for(ri i=2;i<=n;++i){
		for(ri j=0;j<=2;++j){
			f[i][j]=f[i-2][j]+val[i];
			if(i-3>=0&&j) f[i][j]=max(f[i][j],f[i-3][j-1]+val[i]);
		}
	}
	if(n%2==1){
		ll ans=f[n-2][0];
		ans=max(ans,max(f[n-1][0],f[n-1][1]));
		ans=max(ans,max(f[n][1],f[n][2]));
		int mn=INF;
		for(ri i=1;i<=n;i+=2) mn=min(mn,val[i]);
		ans=max(ans,f[n][0]-mn);
		print(ans);
	}
	else{
		ll ans=f[n-1][0];
		ans=max(ans,max(f[n][0],f[n][1]));
		print(ans);
	}
	return 0;
}