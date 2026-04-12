#include <bits/stdc++.h>
#define ll long long
#define MAX_N 8
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;


int M[8][8];
int n,e;

int dfs_visit(int u,int color2[MAX_N]){
    bool all_visited = true;
    for(int i =0;i<n;i++){
        if(color2[i] == WHITE) {
            all_visited = false;
        }
    }
    if(all_visited) return 1;
    int res = 0;

    for(int v = 0; v < n; v++){
        if(M[u][v] == 0)continue;
        if(color2[v] == WHITE){
            color2[v] = GRAY;
            res += dfs_visit(v,color2);
            color2[v] = WHITE;
        }
    }
    color2[u] = BLACK;
    return res;
}

int dfs(){
    int color[MAX_N];
    for(int i=0; i < n ; i++) color[i] = WHITE;
    int u = 0;
    color[u] = GRAY;

    int ans = dfs_visit(u, color);
    return ans;
}

int main(){
    cin>>n>>e;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++)M[i][j] = 0;
    }
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        M[u][v] =M[v][u]= 1;
    }
    cout<< dfs() <<endl;
}
