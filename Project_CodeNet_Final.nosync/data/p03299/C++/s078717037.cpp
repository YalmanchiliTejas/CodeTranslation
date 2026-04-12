#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MAX=105;
const ll INF=0x3f3f3f3f;
const ll MOD=1e9+7;
ll N,ans,h[MAX],dp[MAX][MAX],order[MAX],hg[MAX],hg_cnt;
pll g[MAX];
ll power(ll x,ll y){
    if(y==0) return 1;
    ll t=power(x,y/2);
    if(y%2) return t*t%MOD*x%MOD;
    return t*t%MOD;
}
int main(){
    scanf("%lld",&N);
    for(ll i=0;i<N;i++) {
        scanf("%lld",&h[i]);
        g[i].first=h[i],g[i].second=i;
    }
    sort(g,g+N);
    hg[hg_cnt++]=1;
    for(ll i=0;i<N;i++) {
        if(hg[hg_cnt-1]!=g[i].first) hg[hg_cnt++]=g[i].first;
        order[g[i].second]=hg_cnt-1;
    }
    dp[0][order[0]]=2;
    for(ll i=0;i<order[0];i++) dp[0][i]=(power(2,hg[order[0]]-hg[i]+1)-power(2,hg[order[0]]-hg[i+1]+1)+MOD)%MOD;
    for(ll i=1;i<N;i++){
        for(ll j=0;j<=min(order[i],order[i-1])-1;j++) dp[i][j]=dp[i-1][j];
        for(ll j=min(order[i],order[i-1]);j<=order[i-1];j++) dp[i][min(order[i],order[i-1])]+=2*dp[i-1][j],dp[i][min(order[i],order[i-1])]%=MOD;
        if(order[i]>order[i-1]){
            ll t=power(2,hg[order[i]]-hg[order[i-1]]);
            for(ll j=0;j<order[i-1];j++) dp[i][j]=(dp[i][j]*t)%MOD;
            dp[i][order[i]]=dp[i][order[i-1]];
            for(ll j=order[i]-1;j>=order[i-1];j--) dp[i][j]=(power(2,hg[order[i]]-hg[j])-power(2,hg[order[i]]-hg[j+1])+MOD)*dp[i][order[i-1]]%MOD;
        }
    }
    for(ll i=0;i<=order[N-1];i++) ans+=dp[N-1][i],ans%=MOD;
    printf("%lld\n",ans);
    return 0;
}
