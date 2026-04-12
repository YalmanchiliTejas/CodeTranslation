#include <bits/stdc++.h>
using namespace std;
const int Maxn=3005;
int n,mod,s[Maxn][Maxn],C[Maxn][Maxn];
int ksm(int x,int k,int m=mod){
    int ret=1,tmp=x;
    while(k){
        if(k&1)ret=1ll*ret*tmp%m;
        tmp=1ll*tmp*tmp%m;k>>=1;
    }
    return ret;
}
int main(){
    cin>>n>>mod;
    s[0][0]=1;
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=i;j++)
            s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j)%mod;
    for(int i=0;i<=n;C[i++][0]=1)
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    int ans=0;
    for(int i=0;i<=n;i++){
        int sum=0,w=ksm(2,ksm(2,n-i,mod-1)),base=ksm(2,n-i);
        for(int j=0,coef=1;j<=i;j++,coef=1ll*coef*base%mod)
            sum=(sum+1ll*s[i+1][j+1]*w%mod*coef)%mod;
        ans=(ans+(i&1?-1ll:1)*C[n][i]*sum)%mod;
    }
    cout<<(ans+mod)%mod<<"\n";
    return 0;
}