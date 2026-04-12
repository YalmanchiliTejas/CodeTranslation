#include <bits/stdc++.h>
#define ll long long
#define MAX_N 8
using namespace std;

int G[MAX_N][MAX_N];
int n,m;
bool visited[MAX_N];

int dfs(int u, bool visited2[MAX_N]){
    bool flag = true;
    for(int i = 0; i < n; i++){
        if( !visited2[i] ){
            flag = false;
            break;
        }
    }
    if(flag) return 1;
    
    int res = 0;
    for(int v = 0; v < n; v++ ){
        if( G[u][v] == 0 )continue;
        if( !visited[v] ){
            visited2[v] = true;
            res += dfs( v, visited2);
            visited2[v] = false;
        }
    } 
    visited2[u] = true;
    return res;
}

int main(){
    cin>> n >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a][b] = G[b][a] = 1;
    }
    
    visited[0] = true;
    int ans = dfs(0,visited);

    cout<< ans <<endl;
}