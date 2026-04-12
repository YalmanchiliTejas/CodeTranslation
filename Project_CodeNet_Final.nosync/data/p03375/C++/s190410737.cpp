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
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
const int N=3005;
int s[N][N],c[N][N],power[N],pk[N];
inline int fpow(ri a,ri b,ri mod){
	ri ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1) ans=(ll)ans*a%mod;
	return ans;
}
inline int _add(ri x,ri y,ri mod){
	return (x+=y)>=mod?x-mod:x;
}
int main(){
	ri n,mod,i,j,k,ans,res,now;
	scanf("%d%d",&n,&mod);
	s[0][0]=1;
	for(i=1;i<=n;++i)
		for(j=1;j<=i;++j)
			s[i][j]=((ll)s[i-1][j]*j+s[i-1][j-1])%mod;
	for(i=0;i<=n;++i){
		c[i][0]=1;
		for(j=1;j<=i;++j)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	power[0]=1;
	for(i=1;i<=n;++i) power[i]=_add(power[i-1],power[i-1],mod);
	ans=0;
	for(i=0;i<=n;++i){
		pk[0]=1;
		for(k=1;k<=i;++k) pk[k]=(ll)pk[k-1]*power[n-i]%mod;
		now=fpow(2,fpow(2,n-i,mod-1),mod);
		for(k=0;k<=i;++k){
			res=(ll)s[i][k]*pk[k]%mod;
			if(k) res=(res+(ll)s[i][k]*k%mod*pk[k-1])%mod;
			ans=(ans+(i&1?-1ll:1ll)*c[n][i]*now%mod*res)%mod;
		}
	}
	ans=ans<0?ans+mod:ans;
	printf("%d\n",ans);
	return 0;
}