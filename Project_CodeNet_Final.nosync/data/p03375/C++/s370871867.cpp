#include<bits/stdc++.h>
using namespace std;
const int N=3300;
int n,mod,f[N][N],c[N][N],ans;
int qpw(int x,int n,int mod=::mod){
    int ret=1; for(;n;n>>=1,x=1ll*x*x%mod)
    if(n&1) ret=1ll*ret*x%mod; return ret;
}
main(){
    scanf("%d%d",&n,&mod), f[0][0]=c[0][0]=1;
    for(int i=1;i<=n+1;i++) for(int j=0;j<=i;j++)
        f[i][j]=j?(f[i-1][j-1]+1ll*j*f[i-1][j])%mod:0,
        c[i][j]=j?(c[i-1][j-1]+c[i-1][j])%mod:1;
    for(int i=0;i<=n;i++){
        int res=0,tmp=qpw(2,n-i),k=1;
        for(int j=0;j<=i;j++,k=1ll*k*tmp%mod)
            (res+=1ll*k*f[i+1][j+1]%mod)%=mod;
        (ans+=(i&1?-1ll:1ll)*c[n][i]*qpw(2,qpw(2,n-i,mod-1))%mod*res%mod)%=mod;
    }
    printf("%d\n",(ans+mod)%mod);
}
