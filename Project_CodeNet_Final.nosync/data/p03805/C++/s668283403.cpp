/*|In The Name of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int n;
int m;
int vis[N];
int res = 0;
vector < int > adj[N];

bool canbeway(){
     int cnt = 0;
     for(int i = 1; i <= n; i++){
         cnt += vis[i];
     }
     return cnt == n;
}

void dfs(int u){
     vis[u] = 1;
     for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(!vis[v]){
            dfs(v);
        }
     }
     if(canbeway()){
        res ++;
     }
     vis[u] = 0;
}

int main(){
    scanf("%d%d" , &n , &m);
    for(int i = 1; i <= m; i++){
        int u , v;
        scanf("%d %d" , &u , &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    printf("%d\n" , res);
}
