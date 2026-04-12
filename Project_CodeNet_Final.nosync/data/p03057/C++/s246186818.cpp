#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define mem(x,v) memset(x,v,sizeof(x))
#define fi first
#define se second
#define lowbit(x) ((x)&-(x))
#define debug(x) cout << #x " = " << x << endl;
namespace IO{
	const int L = 1 << 15;
	char ibuf[L|1],*iS=ibuf,*iT=ibuf;
	char obuf[L|1],*oS=obuf,*oT=obuf+L;
	char c,st[66];int tp=0,f;
	inline char gc(){
		if(iS==iT) iT=(iS=ibuf)+fread(ibuf,sizeof(char),L,stdin);
		return (*iS++);
	}
	inline void flush() {
		fwrite(obuf,sizeof(char),oS-obuf,stdout);
		oS = obuf;
	}
	inline void pc(char c){*oS++=c;if(oS==oT) flush();}
	#define gc getchar
	#define pc putchar
	inline ll read(){
		ll x=0;f=1,c=gc();
		for(;!isdigit(c);c=gc())if(c=='-')f=-1;
		for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c&15);
		return x*f;
	}
	void write(ll x){
		if(!x) pc('0');if(x<0) pc('-'),x=-x;
		while(x) st[++tp]=x%10+'0',x/=10;
		while(tp) pc(st[tp--]);
	}
	void wri(ll x){write(x);pc(' ');}
	void writeln(ll x){write(x);pc('\n');}
	struct IOflusher{~IOflusher(){flush();}}_ioflusher_;
}
using IO::read;
using IO::writeln;
using IO::wri;
inline void gg(string s){cout << s << endl;exit(0);}
inline void gg(ll x){writeln(x);exit(0);}
const int maxn = 2e5+233;
const int mod = 1e9+7;
int n,m,k,f[maxn],ans;char s[maxn];
int main(){
#ifdef LOCAL
	freopen("1.in","r",stdin);
#endif
	
	n = read(),m = read();
	scanf("%s",s + 1);
	k = n;while(m && s[m]==s[1])--m;
	if(!m) ans = 1;
	for(int i=1,j=1;i<=m;i=j+1){
		j = i;
		if(s[i]==s[1]){
			while(j<m&&s[j+1]==s[1]) ++j;
			if(i==1){
				if((j-i+1)&1) k=min(k,j-i+1); else k=min(k,j-i+2);
			}else{
			 	if((j-i+1)&1) k=min(k,j-i+1);
			}
		}
	}
	if(k==n){
		for(int i=f[0]=1,j=0;i<=n;++i){
			f[i] = j;
			j = (j + f[i-1]) % mod;
		}
		Rep(i,2,n){
			ans = (ans + 1ll * i * f[n-i]) % mod;
		}
	} else{
		++k;
		for(int i=2,j=f[0]=1;i<=n;i+=2){
			f[i] = j;
			j = (j + f[i]) % mod;
			if(i>=k) j = (j - f[i-k] + mod) % mod;
		}
		for(int i=2;i<=k;i+=2) ans = (ans + 1ll * i * f[n-i]) % mod;
	}writeln(ans);
	return 0;
}