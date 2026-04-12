//解説模写AC
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long int ll;
typedef pair<int, int> P;
#define INF 1e9 + 7

const int nmax=8;
bool graph[nmax][nmax];

int dfs(int v, int n, bool visited[nmax]){
    bool all_visited = true;
    rep(i,n){
        if(!visited[i]) all_visited = false;
    }
    
    if(all_visited) return 1;
    
    int ret = 0;
    
    rep(i,n){
        if(visited[i]) continue;
        if(!graph[v][i]) continue;
        
        visited[i] = true;
        ret += dfs(i,n,visited);
        visited[i] = false;
    }
    
    return ret;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        graph[a-1][b-1] = graph[b-1][a-1] = true;
    }
    
    bool visited[nmax];
    rep(i,n) visited[i] = false;
    visited[0]  =true;
    
    cout << dfs(0, n, visited) << endl;

    return 0;
}