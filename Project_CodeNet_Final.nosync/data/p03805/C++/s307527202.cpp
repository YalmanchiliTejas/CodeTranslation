#include <bits/stdc++.h>
using namespace std;

int cnt=1;
int n;
bool color[8];

int dfs(int u,vector<vector<int>> &g){
    bool clear = true;

    int ans = 0;

    for(int i=0; i<n; i++){
        if(!color[i]){
            clear = false;
        }
    }

    if(clear) return 1;

    for(auto a : g[u]){
        if(color[a]) continue;

        color[a] = true;
        ans += dfs(a,g);
        color[a] = false;
    }

    return ans;
}

int main(){
    int m;
    cin>>n>>m;
    vector<vector<int>> g(n,vector<int>());

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=0; i<n; i++){
        color[i] = false;
    }

    color[0] = true;

    cout<<dfs(0,g)<<endl;

    return 0;
}