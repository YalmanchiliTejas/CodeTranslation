#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
//#define MOD 998244353
#define MOD 1000000007

int main(){
    int h,w;
    cin>>h>>w;
    char map[110][110];
    bool bani[110]={},banj[110]={};
    rep(i,0,h){
        scanf("%s",map[i]);
        bool f=1;
        rep(j,0,w){
            if(map[i][j]=='#'){
                f=0;
                break;
            }
        }
        if(f)bani[i]=1;
    }
    rep(i,0,w){
        bool f=1;
        rep(j,0,h){
            if(map[j][i]=='#'){
                f=0;
                break;
            }
        }
        if(f)banj[i]=1;
    }
    rep(i,0,h){
        if(bani[i])continue;
        rep(j,0,w){
            if(banj[j])continue;
            else cout<<map[i][j];
        }
        puts("");
    }
}