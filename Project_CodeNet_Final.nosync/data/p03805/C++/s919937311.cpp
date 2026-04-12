#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long int i=0;i<n;++i)
typedef long long int ll;

int n,m;
vector<int> a[9];
vector<bool> vis(9,false);
ll ans = 0;

void dfs(int node){
    if(vis[node]){
        return ;
    }
    vis[node]=true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            break;
        }
        if(i==n){
            ans++;
        }
    }
    for(int i=0;i<a[node].size();i++){
        dfs(a[node][i]);
    }
    vis[node]=false;
}

int main(){

    cin >> n >> m;

    rep(i,m){
        int s,t;
        cin >> s >> t;
        a[s].push_back(t);
        a[t].push_back(s);
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}