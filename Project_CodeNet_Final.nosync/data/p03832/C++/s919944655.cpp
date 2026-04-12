#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define M 1000000007
ll dp[1005][1005],kai[1005];
ll n,a,b,c,d;
ll pw(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1)res=res*x%M;
        y>>=1;
        x=x*x%M;
    }
    return res;
}
ll cm(ll x,ll y){
    return kai[x]*pw(kai[y],M-2)%M*pw(kai[x-y],M-2)%M;
}
ll dfs(ll x,ll y){
    if(x==0)return 1;
    if(y==b+1)return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    ll s=dfs(x,y+1),t=1;
    for(ll i=1;i<c&&i*y<=x;i++)t=t*cm(x-(i-1)*y,y)%M;
    for(ll i=c;i<=d&&i*y<=x;i++){
        t=t*cm(x-(i-1)*y,y)%M;
        s=(s+t*pw(kai[i],M-2)%M*dfs(x-i*y,y+1)%M)%M;
    }
    return dp[x][y]=s;
}
int main(void){
    scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
    kai[0]=1;
    for(ll i=1;i<=n;i++)kai[i]=kai[i-1]*i%M;
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=-1;
    printf("%lld\n",dfs(n,a));
}