# include <bits/stdc++.h>
using namespace std;

const int maxn=10000000+7;
const int mod=998244353;
int inv[maxn];
int finv[maxn];
int fpow[maxn];
int fthe[maxn];
int ftwo[maxn];
int n;

int comb(int a,int b){
    return (1ll*fpow[a]*finv[a-b]%mod*finv[b]%mod)%mod;
}

int main(){
    fpow[0]=fpow[1]=1;
    inv[1]=finv[1]=1;
    inv[0]=finv[0]=1;
    fthe[0]=1;fthe[1]=3;
    ftwo[0]=1,ftwo[1]=2;
    for(int i=2;i<maxn;i++){
        inv[i]=(1ll*(mod-mod/i)*inv[mod%i])%mod;
        finv[i]=(1ll*finv[i-1]*inv[i])%mod;
        fpow[i]=(1ll*fpow[i-1]*i)%mod;
        fthe[i]=(1ll*fthe[i-1]*3)%mod;
        ftwo[i]=(1ll*ftwo[i-1]*2)%mod;
    }
    scanf("%d",&n);
    int p=n>>1;
    int ans=0;
    for(int i=p+1;i<=n;i++){
        ans=(1ll*ans+1ll*2*comb(n,i)*ftwo[n-i]%mod)%mod;
        //cout<<comb(n,i)<<" "<<ftwo[n-i]<<endl;
    }
    ans=(1ll*fthe[n]-1ll*ans+1ll*mod)%mod;
    printf("%d\n",ans);
    return 0;
}
