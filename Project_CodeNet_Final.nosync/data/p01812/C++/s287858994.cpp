#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int d[17];
int dk[101];
int g[101][101];
int co[1<<17];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    memset(dk,-1,sizeof(dk));
    rep(i,m){
        cin>>d[i];
        --d[i];
        dk[d[i]]=i;
    }
    int vi;
    rep(i,n){
        rep(j,k){
            cin>>vi;
            --vi;
            g[i][j]=vi;
        }
    }
    rep(i,1<<m) co[i]=1000100010;
    co[(1<<m)-1]=0;
    queue<int> q;
    q.push((1<<m)-1);
    while(!q.empty()){
        int b=q.front();q.pop();
        rep(i,k){
            int nb=0;
            rep(j,m){
                if(b&(1<<j)){
                    if(dk[g[d[j]][i]]>=0) nb|=(1<<dk[g[d[j]][i]]);
                }
            }
            if(co[nb]>co[b]+1){
                co[nb]=co[b]+1;
                if(nb==0){
                    cout<<co[nb]<<endl;
                    return 0;
                }
                q.push(nb);
            }
        }
    }
    return 0;
}
