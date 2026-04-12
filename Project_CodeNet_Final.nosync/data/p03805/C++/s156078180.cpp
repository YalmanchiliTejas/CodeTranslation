#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>>g;
vector<int>seen;

int dfs(int v,int depth){
    if(seen[v]==1)return 0;
    else if(depth==n)return 1;
    seen[v]=1;
    int ans=0;
    for(auto x:g[v]){
        if(seen[x]==1)continue;
        else ans+=dfs(x,depth+1);
    }
    seen[v]=0;
    return ans;
}

int main(){
    cin>>n>>m;
    g.resize(n);
    seen.resize(n,0);
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout<<dfs(0,1)<<endl;
}