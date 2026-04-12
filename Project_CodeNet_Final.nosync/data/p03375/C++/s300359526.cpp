#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=3e3+2;
int n,ans,mo,f[N],g[N][N],C[N][N];

inline int mul(int x,int y) {return x*y%mo;}
int ksm(int x,int y,int mod) {
	int ans=1;
	for(;y;y>>=1,x=x*x%mod) if(y&1) ans=ans*x%mod;
	return ans;
}
signed main() {
    scanf("%lld%lld",&n,&mo);
    for(int i=0;i<=n;++i) {
        C[i][0]=g[i][0]=1;
        for(int j=1;j<=i;++j) 
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo,
            g[i][j]=(g[i-1][j-1]+mul(j+1,g[i-1][j]))%mo;
    }
    for(int i=0;i<=n;++i) {
        int tmp=ksm(2,ksm(2,n-i,mo-1),mo);
        int num=ksm(2,n-i,mo),qaq=1,res=0;
        for(int j=0;j<=i;++j) res=(res+mul(g[i][j],qaq))%mo,qaq=mul(qaq,num);
        ans=(ans+mul(mul((i&1)?mo-C[n][i]:C[n][i],tmp),res))%mo;
    }
    printf("%lld\n",ans);
    return 0;
}