//Night's template
//orzakyrt
#include <bits/stdc++.h>
#define R register
#define LL long long
#ifdef __DEBUG__
	#define Debug (fprintf(stderr,"orzyrt\n"),fflush(stderr))
	#define debug(__a...) (fprintf(stderr,__a),fflush(stderr))
	#define setfile(__a) ('orzyrt')
	#define Compile(__a) system("g++ "__a".cpp -lm -o "__a)
#else
	#define Debug ('orzyrt')
	#define debug(__a...) ('orzyrt')
	#define setfile(__a) freopen(__a".in","r",stdin);freopen(__a".out","w",stdout)
	#define Compile(__a) ('orzyrt')
#endif
template<class TT>inline TT Max(R TT a,R TT b){return a<b?b:a;}
template<class TT>inline TT Min(R TT a,R TT b){return a<b?a:b;}
template<class TT>inline TT Abs(R TT a){return a<0?-a:a;}
template<class TT>inline TT cmin(R TT &a,R TT b){(b<a)&&(a=b);}
template<class TT>inline TT cmax(R TT &a,R TT b){(a<b)&&(a=b);}
using namespace std;
template<class TT>inline void read(R TT &x){
	x=0;R bool f=false;R char c=getchar();
	for(;c<48||c>57;c=getchar())f|=(c=='-');
	for(;c>47&&c<58;c=getchar())x=(x<<1)+(x<<3)+(c^48);
	(f)&&(x=-x);
}
//end template

namespace Night{
	const int mod = 1e9+7;
	const int maxn = 1111;
	inline int qpow(R int a,R int b){
		R int ret=1;
		for(;b;b>>=1){
			if(b&1)ret=1ll*ret*a%mod;
			a=1ll*a*a%mod;
		}
		return ret;
	}
	int f[maxn][maxn];
	int n,a,b,c,d;
	int fac[maxn],ifac[maxn]; 
	int main(){
		read(n);read(a);read(b);read(c);read(d);
		for(R int i=*fac=1;i<maxn;++i){
			fac[i]=1ll*i*fac[i-1]%mod;
		}
		ifac[maxn-1]=qpow(fac[maxn-1],mod-2);
		for(R int i=maxn-2;~i;i--){
			ifac[i]=1ll*(i+1)*ifac[i+1]%mod;
		}
		for(R int i=0;i<maxn;++i){
			if(ifac[i]!=qpow(fac[i],mod-2))Debug;
		}
		f[a-1][0]=1;
		for(R int i=a;i<=b;++i){
			for(R int j=0;j<=n;++j){
				if(!f[i-1][j])continue;
				(f[i][j]+=f[i-1][j])%=mod;
				for(R int k=c,limk=Min((n-j)/i,d)+1;k<limk;++k){
					(f[i][j+i*k]+=1ll*f[i-1][j]*fac[n-j]%mod*ifac[n-j-i*k]%mod*qpow(ifac[i],k)%mod*ifac[k]%mod)%=mod;
				}
			}
		}
		cout<<f[b][n];
		return 0;
	}
}
int main(){
	return Night::main();
}