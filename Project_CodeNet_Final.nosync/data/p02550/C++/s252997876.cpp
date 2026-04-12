#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int go[1000005][40];
LL val[1000005][40];
void solve(){
    LL n;
    int x,m;
    scanf("%lld %d %d",&n,&x,&m);
    for(int i = 0;i<m;i++){
        val[i][0]=i;
        go[i][0]=i*1ll*i%m;
    }
    for(int i = 1;i<40;i++){
        for(int j  =0;j<m;j++){
            go[j][i]=go[go[j][i-1]][i-1];
            val[j][i]=val[j][i-1]+val[go[j][i-1]][i-1];
        }
    }
    int now=x;
    LL ans=0;
    for(int i = 0;i<40;i++){
        if((1ll<<i)&n){
            ans+=val[now][i];
            now=go[now][i];
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    int T=1;
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/
