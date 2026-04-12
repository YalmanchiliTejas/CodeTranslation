#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m;
vector<int> adj[8];
unordered_set<string> ans;
void dfs(int i,vector<int> visited,int time){
    visited[i] = time;
    if(time == n){
        string str = "";
        for(int k=0;k<n;k++){
            str += to_string(visited[k]);
        }
        ans.insert(str);
        return;
    }
    for(auto j : adj[i]){
        if(visited[j] == -1){
            dfs(j,visited,time+1);
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,vector<int>(n,-1),1);
    cout<<ans.size()<<"\n";
    return 0;

}


