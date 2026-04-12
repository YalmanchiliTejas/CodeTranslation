/**
    AUTHOR:JUNSH
    TIME:19/5/25
**/
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rev(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
ll quick_pow(ll a,ll k){
    ll res=1;
    while(k){
        if(k&1)res=(res*a)%mod;
        a=(a*a)%mod;
        k/=2;
    }
    return res;
}
ll inv(ll x){
    return quick_pow(x,mod-2);
}
//ll inv(ll a){
//  ll t=1;
//  while (a>1){
//    t=t*(mod-mod/a)%mod;
//    a=mod%a;
//  }
//  return t;
//}
ll cal(ll n,ll k){
    k=min(k,n-k);
    ll num=1,Div=1;
    for(int i=1;i<=k;++i){
        Div=(Div*i)%mod;
        num=num*(n-i+1)%mod;
    }
    return num*inv(Div)%mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    ll ans=0;
    for(ll i=1;i<=n;++i)
        ans=(ans+(i*(n-i)*m*m))%mod;
    for(ll i=1;i<=m;++i)
        ans=(ans+(i*(m-i)*n*n))%mod;
    ans=(ans*cal(n*m-2,k-2))%mod;
    cout<<ans<<endl;
}
