#include "bits/stdc++.h"
using namespace std;

int edge[8][8];
int visited[8];
int ans = 0;
int n;

void dfs(int pos){
    if(visited[pos]) return;
    visited[pos] = 1;
    int ok = 1;
    for(int i = 0; i < n; i++) ok *= visited[i];
    if(ok) ans++;
    for(int i = 0; i < n; i++){
        if(edge[pos][i]==1) dfs(i);
    }
    visited[pos] = 0;
    return;
}

int main(){
    int m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        visited[i] = 0;
        for(int j=0;j<n;j++){
            edge[i][j] = 0;
        }
    }
    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        edge[a-1][b-1] = 1;
        edge[b-1][a-1] = 1;
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}