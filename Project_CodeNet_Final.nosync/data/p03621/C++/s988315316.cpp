#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll INF=0x3f3f3f3f;
const ll MOD=998244353;
const ll MAX=10005;
ll ans=0,n,k1,k2;
ll fact[MAX],finv[MAX],cache[MAX];
char a[MAX],b[MAX];
ll power(ll x,ll y){
    if(y==0) return 1;
    ll t=power(x,y/2);
    if(y%2) return t*t%MOD*x%MOD;
    return t*t%MOD;
}
int main(){
    scanf(" %s %s",a,b);
    n=strlen(a);
    for(ll i=0;i<n;i++) {
        if(a[i]==b[i]&&a[i]=='1') k2++;
        else if(a[i]!=b[i]) k1++;
    }
    k1/=2;
    fact[0]=1;
    for(ll i=1;i<=n;i++) fact[i]=i*fact[i-1]%MOD;
    for(ll i=0;i<=n;i++) finv[i]=power(fact[i],MOD-2);
    for(ll i=0;i<=k1;i++) {
        cache[i]=power(k1-i,k1)*fact[k1]%MOD*finv[k1-i]%MOD*finv[i]%MOD;
        if(i%2) cache[i]=(MOD-cache[i])%MOD;
    }
    for(ll i=0;i<=k2;i++){
        ll t=0;
        for(ll i=0;i<=k1;i++){
            t=(t+cache[i])%MOD;
            cache[i]=(cache[i]*(k1-i))%MOD;
        }
        //printf("%lld %lld\n",t,t*fact[k1]%MOD*fact[k2]%MOD*fact[k1+k2]%MOD*finv[k1+i]%MOD);
        ans+=t*fact[k1]%MOD*fact[k2]%MOD*fact[k1+k2]%MOD*finv[k1+i]%MOD;
        ans%=MOD;
    }
    printf("%lld\n",ans);
}
