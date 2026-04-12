#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define Mid ((l+r)/2)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define drep(i,a,b) for(int i=(a);i>=(b);--i)
#define file(a) freopen(#a".in","r",stdin),freopen(#a".out","w",stdout);
const int maxn=2e5+5,mod=1e9+7,inf=0x3f3f3f3f;
int n,m,Q,K,T;
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}int a[maxn];
int dsum[maxn];

signed main(){
    //file(a);
    n=read();
    rep(i,1,n)a[i]=read();
    dsum[n]=a[n];
    drep(i,n-1,1)dsum[i]=(dsum[i+1]+a[i])%mod;
    int ans=0;
    rep(i,1,n-1){
        ans=(ans+1ll*a[i]*dsum[i+1]%mod)%mod;
    }printf("%lld\n",ans);


    return 0;
}
