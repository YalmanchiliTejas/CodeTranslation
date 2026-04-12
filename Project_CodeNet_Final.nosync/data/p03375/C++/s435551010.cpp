#include <cstdio>
typedef long long ll;

const int N=3005;
int n;
ll mod,f[N][N],c[N][N],ans; 
inline int read() {
	int x=0,flag=0;char ch=getchar();
	while(ch<'0'||ch>'9'){flag|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return flag?-x:x;
}
inline int mx(int x,int y) {return x>y?x:y;}
inline int mn(int x,int y) {return x<y?x:y;}

inline int ksm(ll a,int b,int m=mod) {
	int ans=1;
	while(b) {
		if(b&1) ans=1ll*ans*a%m;
		a=1ll*a*a%m;
		b>>=1;
	}
	return ans;
}
int main() {
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();mod=read();
	c[0][0]=f[0][0]=1;
	for(int i=1;i<=n+1;++i) {
		c[i][0]=1;
		for(int j=1;j<=i;++j)
			f[i][j]=(f[i-1][j-1]+1ll*j*f[i-1][j]%mod)%mod,
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	for(int i=0;i<=n;++i) {
		ll mul=(i&1?mod-1:1),res=0,i2=ksm(2,n-i),j2=1;
		mul=1ll*mul*c[n][i]%mod*1ll*ksm(2,ksm(2,n-i,mod-1))%mod;
		for(int j=0;j<=i;++j)
			res=(res+1ll*j2*f[i+1][j+1]%mod)%mod,
			j2=1ll*j2*i2%mod;
		ans=(ans+1ll*mul*res%mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
