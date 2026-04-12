#include <bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = (x << 1) + (x << 3) + (c & 15); x *= f;
	}
	// print a signed integer
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	// no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} 
using io :: gi;
using io :: putc;
using io :: print;
const int N=105,mod=1e9+7;
int h[N],f[N][N],a[N],pos[N];
// f[i][j] 表示第i列前a[i]个格子没有出现 xx/oo ，前a[i+1]个格子出现了 xx/oo 
inline int fpow(ri a,ri b){
	ri ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1) ans=(ll)ans*a%mod;
	return ans;
}
inline void add(int &x,ri y){
	x=(x+=y)>=mod?x-mod:x;
}
inline int calc(ri x){  
	return (fpow(2,x)-1+mod)%mod; 
}
inline int solve(ri l,ri r){
	ri i,j,k,m,res;
	m=0;
	for(i=l;i<=r;++i) a[++m]=h[i];
	sort(a+1,a+1+m);
	m=unique(a+1,a+1+m)-a-1;
	for(i=l;i<=r;++i) pos[i]=lower_bound(a+1,a+1+m,h[i])-a;
	f[l][0]=2ll*calc(a[1]-1)*fpow(2,h[l]-a[1])%mod; 
	for(i=1;i<pos[l];++i)
		f[l][i]=2ll*calc(a[i+1]-a[i])*fpow(2,h[l]-a[i+1])%mod;
	f[l][pos[l]]=2; 
	for(i=l+1;i<=r;++i){ 
		if(h[i]<=h[i-1]){
			for(j=0;j<pos[i];++j)
				f[i][j]=f[i-1][j];
			for(k=pos[i];k<=pos[i-1];++k)
				add(f[i][j],f[i-1][k]*2ll%mod);
		}
		else{
			for(j=0;j<pos[i-1];++j)
				f[i][j]=(ll)f[i-1][j]*fpow(2,h[i]-h[i-1])%mod;
			for(;j<pos[i];++j)
				f[i][j]=(ll)f[i-1][pos[i-1]]*2*calc(a[j+1]-a[j])%mod*fpow(2,h[i]-a[j+1])%mod;
			f[i][pos[i]]=f[i-1][pos[i-1]]*2ll%mod;
		}
	//	for(j=0;j<=pos[i];++j)
	//		printf("dp %d %d %d\n",i,j,f[i][j]);
	} 
	res=0;
	for(i=0;i<=m;++i)
		add(res,f[r][i]);
	return res;
}
int main(){
	ri n,i,last,ans;
	gi(n);
	for(i=1;i<=n;++i) gi(h[i]);
	last=0;ans=1;
	for(i=1;i<=n;++i)
		if(h[i]==1){
			ans=(ans<<1)%mod;
			if(last+1<=i-1) ans=(ll)ans*solve(last+1,i-1)%mod;
			last=i; 
		}
	if(last+1<=n) ans=(ll)ans*solve(last+1,n)%mod;
	printf("%d\n",ans);
	return 0;
}