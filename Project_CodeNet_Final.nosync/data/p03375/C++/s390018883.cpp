#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, mod, s[3030][3030], C[3030][3030], f[3030];

ll K(ll x,ll y=mod-2){
    ll t=1;
    for (;y;y>>=1,x=x*x%mod)
        if (y&1) t=t*x%mod;
    return t;
}

int main(){
    cin>>n>>mod;
    s[0][0]=1;
    for (int i=1;i<=n;++i)
        for (int j=0;j<=i;++j){
            s[i][j]=((j? s[i-1][j-1]: 0)+(ll)s[i-1][j]*(j+1))%mod;
        }
    for (int i=0;i<=n;++i){
        C[i][0]=1;
        for (int j=1;j<=i;++j)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    for (int i=0;i<=n;++i){
        --mod; ll t=K(2,i); ++mod;
        f[i]=K(2,t);
    }
    ll ans=0;
    for (int i=0;i<=n;++i)
        for (int j=0;j<=i;++j){
            ans=(ans+ (ll)s[i][j]*C[n][i]%mod*K(mod-1,i)%mod*K(K(2,n-i),j)%mod*f[n-i])%mod;
        }
    cout<<ans<<endl;
}