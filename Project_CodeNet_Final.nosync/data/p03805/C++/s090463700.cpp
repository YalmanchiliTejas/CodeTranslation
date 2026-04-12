#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int N,M;

int DFS(vector<vector<int>> &load, int now, vector<bool> visited){
    
    bool end=true;
    
    //ベースケース
    for(int i=1; i<=N; i++){
        if(visited[i]==false){
            end=false;
        }
    }
    if(end) return 1;
    
    int ret=0;
    for(int i:load[now]){
        
        //道が無い、探索済
        if(visited[i]) continue;
        
        visited[i]=true;
        ret += DFS(load, i, visited);
        visited[i]=false;
        
    }
    return ret;
}


int main(){
    
    cin >> N >> M;
    
    vector<vector<int>> load(N+1,vector<int>());
    rep(z,M){
        int a,b;
        cin >> a >> b;
        load[a].push_back(b);
        load[b].push_back(a);
    }
    
    vector<bool> visited(N+1,false);
    visited[1] = true;
    int ans = DFS(load, 1, visited);
    cout << ans << endl;
    
}
