#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=8e3+5;
const int M=2e2+5;
const int mod=998244353;
int n,m,f[N<<3],g1[N<<3],g2[N<<3],fac[N],inv[N],dp[N][M];

inline int mul(int x,int y) {return 1ll*x*y%mod;}
template <typename _Tp> inline void IN(_Tp&x) {
    char ch;bool flag=0;x=0;
    while(ch=getchar(),!isdigit(ch)) if(ch=='-') flag=1;
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    if(flag) x=-x;
}

namespace Poly {
    int filp[N<<3];
    inline int modpow(int x,int y,int res=1) {
        for(;y;y>>=1,x=mul(x,x)) if(y&1) res=mul(res,x);
        return res;
    }
    inline void NTT(int*f,int limit,short inv) {
        for(int i=0;i<limit;++i) if(i<filp[i]) swap(f[i],f[filp[i]]);
        for(int p=2;p<=limit;p<<=1) {
            int len=p>>1,tmp=modpow(3,(mod-1)/p);
            for(int k=0;k<limit;k+=p) {
                int buf=1;
                for(int l=k;l<k+len;++l,buf=mul(buf,tmp)) {
                    int t=mul(f[l+len],buf);
                    f[l+len]=(f[l]-t+mod)%mod,f[l]=(f[l]+t)%mod;
                }
            }
        }
        if(inv==1) return;
        int sl=modpow(limit,mod-2);reverse(f+1,f+limit);
        for(int i=0;i<limit;++i) f[i]=1ll*f[i]*sl%mod;
    }
}using namespace Poly;

int limit=1,cnt=0;
inline int C(int n,int m) {return mul(fac[n],mul(inv[m],inv[n-m]));}
inline void solve(int j) {
    memset(g1,0,sizeof(g1));
    memset(g2,0,sizeof(g2));
	for(int i=1;i<=n;++i) g1[i]=inv[i+2];
	for(int i=0;i<=n;++i) g2[i]=mul(dp[i][j-1],inv[i]);
	for(int i=0;i<=n;++i) dp[i][j]=(dp[i][j]+mul(dp[i][j-1],(1+i+C(i,2))%mod))%mod;
	NTT(g1,limit,1),NTT(g2,limit,1);
	for(int i=0;i<limit;++i) f[i]=mul(g1[i],g2[i]);
	NTT(f,limit,-1);
	for(int i=1;i<=n;++i) dp[i][j]=(dp[i][j]+mul(f[i],fac[i+2]))%mod;
}

int main() {
    IN(n),IN(m),fac[0]=inv[0]=1;
	for(int i=1;i<=n+2;++i) fac[i]=mul(fac[i-1],i);
	for(int i=1;i<=n+2;++i) inv[i]=modpow(fac[i],mod-2);
	while(limit<((n+1)<<1)) limit<<=1,++cnt;
	for(int i=0;i<limit;++i) filp[i]=(filp[i>>1]>>1)|((i&1)<<(cnt-1));
	dp[0][0]=1;
	for(int j=1;j<=m;++j) solve(j);
	int ans=0;
	for(int i=0;i<=n;++i) ans=(ans+mul(C(n,i),dp[i][m]))%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}