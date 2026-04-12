#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

vector<ll> to[100010];
ll cn,n;
vector<bool> seen(8,0);

void dfs(ll v,ll dep=1){
    if(dep==n){
        cn++;
        return;
    }
    seen.at(v)=1;
    for(auto nv:to[v]){
        if(seen.at(nv)==0)dfs(nv,dep+1);
    }
    seen.at(v)=0;
}

int main(){
    ll m;cin>>n>>m;
    rep(i,0,m){
        ll a,b;cin>>a>>b;
        a--;b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    dfs(0);
    cout<<cn<<endl;
}





