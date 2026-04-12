#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
long ans=0;
void dfs(long n,long node,const vector<vector<long>> &G,vector<bool> &seen){
    seen[node]=true;
    if(count(seen.begin(),seen.end(),true)==n){
        ans++;
    }
    for(auto next:G[node]){
        if(seen[next])continue;
        dfs(n,next,G,seen);
        seen[next]=false;
    }
}

int main(){
    long n,m;
    cin >> n >> m;
    vector<vector<long>> G(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    vector<bool> seen(n,false);
    dfs(n,0,G,seen);
    cout << ans;
    return 0;
}