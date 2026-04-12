#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,sum[N][21],ans;
int x,m,nex[N][21];
int main(){
    scanf("%lld%d%d",&n,&x,&m);
    for(int i=0;i<m;++i){
        nex[i][0]=1ll*i*i%m;
        sum[i][0]=nex[i][0];
    }
    for(int i=1;i<=20;++i){
        for(int j=0;j<m;++j){
            nex[j][i]=nex[nex[j][i-1]][i-1];
            sum[j][i]=sum[j][i-1]+sum[nex[j][i-1]][i-1];
        }
    }
    n--;
    ll a=n/(1<<20),b=n%(1<<20);
    ll ans=x;int now=x;
    for(int i=1;i<=a;++i){
        ans+=sum[now][20];
        now=nex[now][20];
    }
    for(int j=19;j>=0;--j){
        if(b>>j&1){
            ans+=sum[now][j];
            now=nex[now][j];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
