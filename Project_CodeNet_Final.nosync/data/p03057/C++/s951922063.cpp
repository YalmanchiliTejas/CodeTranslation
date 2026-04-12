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
	// input a letter
	template <class I>
	inline void get (I &x) {
		for (c = gc(); c < 'A' || c > 'Z'; c = gc()) ;
		x = c;
	}
	// input a string
	inline void read (char *s){
		for(c = gc(); c < 'A' || c > 'Z'; c = gc()) ;
		for(; c >= 'A' && c <= 'Z'; c = gc()) *++s = c;
		*++s = '\0';
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
using io :: get;
using io :: read;
using io :: putc;
using io :: print;
const int N=2e5+5,mod=1e9+7,inf=2e9; 
char s[N];
int n,f[N]; 
inline int solve0(ri n){
	// f[i] 表示 col_i = R 1 ~ i 的染色方案
	f[1]=1; // 强制钦定 col_1 = R 
	for(ri i=2;i<=n;++i) f[i]=(f[i-1]+f[i-2])%mod;
	// BR...R f[n-1]
	// R...RB f[n-1]
	// R....R f[n]
	return ((ll)f[n-1]+f[n-1]+f[n])%mod;
}
int pre[N]; 
inline int solve1(ri r){
	// f[i] 表示 col_i = B 1 ~ i的染色方案 
	ri i,ans;
	for(i=1;i<=n/2;++i){
		if(i<=r/2) f[i]=1;
		f[i]=((ll)f[i]+pre[i-1]-pre[max(0,i-r/2-1)]+mod)%mod;
		pre[i]=(pre[i-1]+f[i])%mod;
	}
	// 首先考虑只有一个 B 的情况
	if(n<=r)
		ans=n;
	else
		ans=0;
	for(i=0;i+1<=n&&i+1<=r;++i) // 枚举 1 ~ i 都为 R 
		ans=((ll)ans+pre[max(0,(n-i-1)/2)]-pre[max(0,(n-r)/2-1)]+mod)%mod; 
	return ans;
}
int main(){
	ri m,i,j,flag,r;
	gi(n);gi(m);
	read(s);
	if(s[1]=='B'){
		for(i=1;i<=m;++i)
			s[i]=s[i]=='B'?'R':'B';
	}
	flag=1;
	for(i=1;i<=m;++i)
		if(s[i]!='R'){
			flag=0;
			break;
		}
	if(flag)
		return printf("%d\n",solve0(n)),0;
	if(n&1) return puts("0"),0;
	r=inf;
	for(i=1;i<=m;++i){
		if(s[i]!='R') continue;
		for(j=i;j+1<=m&&s[j+1]=='R';++j);
		if(i==1) r=min(r,j-i+1+1);
		else if(j==m){
			i=j;
			continue;
		}
		else if(j-i+1&1) r=min(r,j-i+1);
		i=j;
	}
	if(~r&1) --r;
	printf("%d\n",solve1(r+1));
	return 0;
}