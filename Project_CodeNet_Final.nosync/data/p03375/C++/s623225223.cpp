#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=3e3+2;
int n,ans,mod,f[N],g[N][N],C[N][N];

inline int mul(int x,int y) {return 1ll*x*y%mod;}
int modpow(int x,int y,int p,int res=1) {
	for(;y;y>>=1,x=1ll*x*x%p) if(y&1) res=1ll*res*x%p;
	return res;
}
int main() {
    scanf("%d%d",&n,&mod);
    for(int i=0;i<=n;++i) {
        C[i][0]=g[i][0]=1;
        for(int j=1;j<=i;++j) 
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod,
            g[i][j]=(g[i-1][j-1]+mul(j+1,g[i-1][j]))%mod;
    }
    for(int i=0;i<=n;++i) {
        int tmp=modpow(2,modpow(2,n-i,mod-1),mod);
        int num=modpow(2,n-i,mod),qaq=1,res=0;
        for(int j=0;j<=i;++j) res=(res+mul(g[i][j],qaq))%mod,qaq=mul(qaq,num);
        ans=(ans+mul(mul((i&1)?mod-C[n][i]:C[n][i],tmp),res))%mod;
    }
    printf("%d\n",ans);
    return 0;
}