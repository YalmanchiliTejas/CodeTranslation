#include<bits/stdc++.h>
using namespace std;
int n,mod;
int f[3005],ans;
int S[3005][3005],C[3005][3005];
int ksm(int x,int y,int mod){
    int res=1;
    while(y){
        if(y&1) res=1ll*res*x%mod;
        x=1ll*x*x%mod,y/=2;
    }
    return res;
}
void init(){
    C[0][0]=S[0][0]=1;
    for(int i=1;i<=n+1;i++){
        C[i][0]=1,S[i][0]=0;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
            S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j]%mod)%mod;
        }
    }
}
int main(){
    scanf("%d%d",&n,&mod);
    init();
    for(int i=0;i<=n;i++){
        int add=ksm(2,ksm(2,n-i,mod-1),mod);
        int ret=1,rett=ksm(2,n-i,mod);
        for(int j=1;j<=i+1;j++){
            (f[i]+=1ll*S[i+1][j]*ret%mod*add%mod)%=mod;
            ret=1ll*ret*rett%mod;
        }
        f[i]=1ll*f[i]*C[n][i]%mod;
    }
    for(int i=0;i<=n;i++){
        if(i&1) (ans+=mod-f[i])%=mod;
        else (ans+=f[i])%=mod;
    }
    printf("%d",ans);
    return 0;
}
