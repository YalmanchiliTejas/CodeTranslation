#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
typedef long long ll;
using namespace std;
int n;
vector<vector<int>> v(8);
ll dfs(int x,vector<bool>& used){
    bool ok=true;
    rep(i,n)if(!used[i])ok=false;
    if(ok)return 1;
    ll now=0;
    rep(i,v[x].size()){
        int y=v[x][i];
        if(used[y])continue;
        auto u=used;
        u[y]=true;
        now+=dfs(y,u);
    }
    return now;
}

int main(void){
    int m;cin>>n>>m;
    rep(i,m){
        int a,b;cin>>a>>b;a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<bool> used(8,false);
    used[0]=true;
    ll res=dfs(0,used);
    cout<<res<<endl;
}
