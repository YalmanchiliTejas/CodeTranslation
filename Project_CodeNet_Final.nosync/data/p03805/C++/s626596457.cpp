#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, ans;
int mem[64][64], use[64][64];

int bfs(int pos, int vis[8]){
    int c = 0;
    for(int i = 0; i < n; i++){
        if(vis[i] == 1) ++c;
    }
    if(c == n){
        ++ans;
        return 0;
    }
    for(int i = 1; i < n; i++){
        if(mem[pos][i] == 1 && vis[i] != 1){
            vis[i] = 1;
            bfs(i, vis);
            vis[i] = 0;
        }
    }
}

int main(){
    cin  >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        mem[a-1][b-1] = mem[b-1][a-1] = 1;
    }
    int visited[8] = {};
    visited[0] = 1;
    bfs(0,visited);
    
    cout << ans << endl;
}