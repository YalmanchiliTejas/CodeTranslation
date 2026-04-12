#include <bits/stdc++.h>
using namespace std;
#define ri register int
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
const int N=105,mod=1e9+7;
int h[N];
struct segtree{
	#define pii pair<int,int>
	#define fi first
	#define se second
	#define mp make_pair
	pii res[N<<2];
	#define lc x<<1
	#define rc x<<1|1
	inline void build(ri x,ri l,ri r){
		if(l==r){
			res[x]=mp(h[l],l);
			return;
		}
		ri mid=l+r>>1;
		build(lc,l,mid);
		build(rc,mid+1,r);
		res[x]=min(res[lc],res[rc]); 
	}
	inline pii query(ri x,ri l,ri r,ri ql,ri qr){
		if(ql<=l&&r<=qr)
			return res[x];
		pii ans=mp(2e9,2e9);
		ri mid=l+r>>1;
		if(ql<=mid) ans=query(lc,l,mid,ql,qr);
		if(qr> mid) ans=min(ans,query(rc,mid+1,r,ql,qr));
		return ans;
	}
	#undef lc
	#undef rc
}seg;
int n,size,tl[N],tr[N],t[N];
vector<int> e[N];
inline int build(ri l,ri r){
	ri x=++size,lst,i;
	tl[x]=l;tr[x]=r;
	t[x]=seg.query(1,1,n,l,r).fi;
	vector<int> v;
	pii now;
	for(i=l;i<=r;i=now.se+1){
		now=seg.query(1,1,n,i,r);
		if(now.fi>t[x]) break;
		v.push_back(now.se);
	}
	v.push_back(r+1);
	lst=l-1;
	for(int p:v){
		if(lst+1<=p-1)
			e[x].push_back(build(lst+1,p-1)),
			t[e[x].back()]-=t[x];
		lst=p;
	}
	return x;
}
inline int mu(ri x,ri y){
	return (long long)x*y%mod;
}
inline int add(ri x,ri y){
	return (x+=y)>=mod?x-mod:x;
}
inline int sub(ri x,ri y){
	return (x-=y)<0?x+mod:x;
}
inline int fpow(ri a,ri b){
	ri ans=1;
	for(;b;b>>=1,a=mu(a,a))
		if(b&1)
			ans=mu(ans,a);
	return ans;
}
int f[N][2];
inline void dfs(ri x){
	ri len=tr[x]-tl[x]+1;
	for(int y:e[x])
		dfs(y),
		len-=tr[y]-tl[y]+1;
	f[x][0]=fpow(2,len);
	f[x][1]=2;
	for(int y:e[x])
		f[x][0]=mu(f[x][0],add(f[y][0],mu(2,f[y][1]))),
		f[x][1]=mu(f[x][1],f[y][1]);
	f[x][0]=sub(f[x][0],f[x][1]);
	f[x][1]=mu(f[x][1],fpow(2,t[x]-1));
	// f[x][0] 非01相间的方案数
	// f[x][1]   01相间的方案数 
}
int main(){
	ri i;
	gi(n);
	for(i=1;i<=n;++i)
		gi(h[i]);
	seg.build(1,1,n);
	build(1,n);
	dfs(1);
	printf("%d\n",add(f[1][0],f[1][1])); 
	return 0;
}