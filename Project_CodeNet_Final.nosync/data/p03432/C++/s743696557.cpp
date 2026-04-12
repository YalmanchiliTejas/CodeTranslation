#include <bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int N=8005,M=205,mod=998244353,L=(1<<14)+5;
int f[N][M],p[L],q[L],fac[N],ifac[N];
inline int _add(ri x,ri y){
	return (x+=y)>=mod?x-mod:x;
}
inline int fpow(ri a,ri b){
	ri ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
namespace ntt{
	int rt[L],rev[L],inv[L],lim,l;
	
	inline void init(ri n){
	    ri w,i;
		lim = 1; l = 0;
	    while(lim<=n) lim <<= 1, ++l;
	    w = fpow(3,(mod-1)/lim);
	    rt[lim>>1] = 1;
	    for(i=(lim>>1)+1;i!=lim;++i) rt[i] = (ll)rt[i-1]*w%mod;
	    for(i=(lim>>1)-1;i;--i) rt[i] = rt[i<<1];
	    inv[1]=1;
	    for(i=2;i<=lim;++i) inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	    for(i=1;i^lim;++i) rev[i]=(ntt::rev[i>>1]>>1)|((i&1)<<l-1);
	}
	
	inline void transform(int *f,ri lim,ri type,ri siz){
	    if(type==-1) reverse(f+1,f+lim);
	    static unsigned long long a[L];
	    ri x,shift = siz-__builtin_ctz(lim),i,mid,j,k;
	    for(i=0;i^lim;++i) a[rev[i]>>shift] = f[i];
	    for(mid=1;mid^lim;mid<<=1)
	        for(j=0;j^lim;j+=mid<<1)
	            for(k=0;k^mid;++k)
	                x = a[j|k|mid]*rt[mid+k]%mod,
	                a[j|k|mid] = a[j|k]-x+mod,
	                a[j|k] += x;
	    for(i=0;i^lim;++i) f[i] = a[i]%mod;
	    if(type==1) return;
	    x = inv[lim];
	    for(ri i=0;i!=lim;++i) f[i] = (ll)f[i]*x%mod;
	}
}
inline int C(ri n,ri m){
	return m<0||n<m?0:(ll)fac[n]*ifac[m]%mod*ifac[n-m]%mod; 
} 
int main(){
	ri n,m,i,j,ans;
	scanf("%d%d",&n,&m);
	ntt::init(n<<1);
	fac[0]=1;
	for(i=1;i<=n+2;++i) fac[i]=(ll)fac[i-1]*i%mod;
	ifac[n+2]=fpow(fac[n+2],mod-2);
	for(i=n+2;i;--i) ifac[i-1]=(ll)ifac[i]*i%mod;
	f[0][0]=1;
	for(j=1;j<=m;++j){
		f[0][j]=1;
		for(i=1;i<=n;++i)
			f[i][j]=f[i][j-1],
			f[i][j]=(f[i][j]+(ll)f[i][j-1]*i*(i+1)/2)%mod;
		for(i=0;i<=n;++i)
			p[i]=(ll)f[i][j-1]*ifac[i]%mod;
		for(i=1;i<=n;++i)
			q[i]=ifac[i+2];
		ntt::transform(p,ntt::lim,1,ntt::l);
		ntt::transform(q,ntt::lim,1,ntt::l);
		for(i=0;i^ntt::lim;++i) p[i]=(ll)p[i]*q[i]%mod;
		ntt::transform(p,ntt::lim,-1,ntt::l);
		for(i=1;i<=n;++i)
			f[i][j]=(f[i][j]+(ll)p[i]*fac[i+2])%mod;
		for(i=0;i^ntt::lim;++i) p[i]=q[i]=0;
	}
	ans=0;
	for(i=0;i<=n;++i) ans=(ans+(ll)C(n,i)*f[i][m])%mod;
	printf("%d\n",ans);
	return 0;
}